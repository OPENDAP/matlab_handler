/*
  Copyright 1996 The University of Rhode Island and The Massachusetts
  Institute of Technology

  Portions of this software were developed by the Graduate School of
  Oceanography (GSO) at the University of Rhode Island (URI) in collaboration
  with The Massachusetts Institute of Technology (MIT).

  Access and use of this software shall impose the following obligations and
  understandings on the user. The user is granted the right, without any fee
  or cost, to use, copy, modify, alter, enhance and distribute this software,
  and any derivative works thereof, and its supporting documentation for any
  purpose whatsoever, provided that this entire notice appears in all copies
  of the software, derivative works and supporting documentation.  Further,
  the user agrees to credit URI/MIT in any publications that result from the
  use of this software or in any product that includes this software. The
  names URI, MIT and/or GSO, however, may not be used in any advertising or
  publicity to endorse or promote any products or commercial entity unless
  specific written permission is obtained from URI/MIT. The user also
  understands that URI/MIT is not obligated to provide the user with any
  support, consulting, training or assistance of any kind with regard to the
  use, operation and performance of this software nor to provide the user
  with any updates, revisions, new versions or "bug fixes".

  THIS SOFTWARE IS PROVIDED BY URI/MIT "AS IS" AND ANY EXPRESS OR IMPLIED
  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
  EVENT SHALL URI/MIT BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL
  DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
  PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTUOUS
  ACTION, ARISING OUT OF OR IN CONNECTION WITH THE ACCESS, USE OR PERFORMANCE
  OF THIS SOFTWARE.
*/

// matlab sub-class implementation for MATByte,..MATGrid.
//
// ReZa 9/28/96

// $Log: MATArray.cc,v $
// Revision 1.3  1996/12/16 21:40:50  reza
// *** empty log message ***
//
// Revision 1.2  1996/11/13 05:13:06  reza
// Added complex matrix capability.
//
// Revision 1.1  1996/10/31 14:43:16  reza
// First release of DODS-matlab servers.
//
//
//

static char rcsid[]={"$Id: MATArray.cc,v 1.3 1996/12/16 21:40:50 reza Exp $"};

#ifdef __GNUG__
#pragma implementation
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream.h>
#include <assert.h>

#include "cgi_util.h"
#include "MATArray.h"
#include "mat.h"

static char Msgt[255]; // Used by ErrMsgT

Array *
NewArray(const String &n, BaseType *v)
{
    return new MATArray(n, v);
}

BaseType *
MATArray::ptr_duplicate()
{
    return new MATArray(*this);
}

MATArray::MATArray(const String &n, BaseType *v) : Array(n, v)
{
}

MATArray::~MATArray()
{
}

bool
MATArray::read(const String &dataset, int &)
{
  
  int start, stride, stop;
  int start_p, stride_p, stop_p;
  int nline, npix; 
  char filename[255];

  MATFile *fp;
  Matrix *mp;
  double *DataPtr;

  if (read_p())  // Nothing to do
    return true;

  memcpy(filename, (const char *)dataset, ((String)dataset).length()+1);
  fp = matOpen(filename, "r");
  if (fp == NULL){
    sprintf(Msgt, "MATArray: Could not open file %s",filename);
    ErrMsgT(Msgt);
    return false;
  }
  
  Pix p = first_dim();
  start = dimension_start(p,true);
  stride = dimension_stride(p, true);
  stop = dimension_stop(p, true); 

  next_dim(p);
  start_p = dimension_start(p,true);
  stride_p = dimension_stride(p, true);
  stop_p = dimension_stop(p, true); 



  if(name().contains("_Real")){    // get real part of the complex  matrix 
    String Rname = name().before("_Real");
    mp = matGetMatrix(fp,Rname);
    DataPtr = mxGetPr(mp); 
  }
  else{
    if(name().contains("_Imaginary")){ // get Img part of the complex matrix  
    String Iname = name().before("_Imaginary");
    mp = matGetMatrix(fp,Iname);
    DataPtr = mxGetPi(mp); 
    }
    else{
      mp = matGetMatrix(fp,name());
      DataPtr = mxGetPr(mp); // get the matrix structure
    }
  }

  if (DataPtr == NULL) {
    sprintf(Msgt, "MATArray: Error reading matrix");
    ErrMsgT(Msgt);
    return false;
  }  

  if(start+stop+stride == 0){ //default rows
    start = 0;
    stride = 1;
    stop = mxGetM(mp)-1;
  }
  if(start_p+stop_p+stride_p == 0){ //default columns
    start_p = 0;
    stride_p = 1;
    stop_p = mxGetN(mp)-1;
  }

  int Len = (((stop-start)/stride)+1)*(((stop_p-start_p)/stride_p)+1);
  
  int Tcount = 0;
  dods_float64 *BufFlt64 = new dods_float64 [Len]; 	
  
    for (int iline = start; iline <= stop; iline+=stride) {	  
      for(int ipix = start_p; ipix <= stop_p; ipix+=stride_p){
	*(BufFlt64+Tcount) = (dods_float64) *(DataPtr+ipix+iline*mxGetN(mp));  
	Tcount++;
      }
    }

    set_read_p(true);      
    val2buf((void *)BufFlt64);
    delete [] BufFlt64;
	  
    mxFreeMatrix(mp);
    matClose(fp);
    return true;
}
