/*
  Copyright 1996,1997 The University of Rhode Island and The Massachusetts
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

// Matlab server utility routines
//
// ReZa 9/28/96
//

// $Log: MatLabUtil.cc,v $
// Revision 1.5  1997/06/06 03:56:36  jimg
// Changed read_descriptors() so that String casts to const char * worked
// properly.
//
// Revision 1.4  1997/05/01 18:35:59  jimg
// Added configureation header.
// Merged changes from interim 2.1.2 version onto main trunk.
//
// Revision 1.3  1996/12/16 22:32:55  reza
// Made array indices always consistent (i.e. Row, Column).
//
// Revision 1.2  1996/11/13 05:13:07  reza
// Added complex matrix capability.
//
// Revision 1.1  1996/10/31 14:43:40  reza
// First release of DODS-matlab servers.

static char rcsid[]={"$Id: MatLabUtil.cc,v 1.5 1997/06/06 03:56:36 jimg Exp $"};

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <iostream.h>
#include <stdiostream.h>

#include "config_mat.h"
#include "DAS.h"
#include "DDS.h"
#include "MATArray.h"
#include "cgi_util.h"
#include "mat.h"

DDS dds_table;
DAS das;
static char Msgt[255];

void 
MakeMatrix(String name, int row, int column)
{
  Array *ar; 
  String DimName;

  // complex matrices have common rows and columns
  if (name.contains("_Real"))
    DimName = name.before("_Real");
  else{
    if (name.contains("_Imaginary"))
      DimName = name.before("_Imaginary");
    else
      DimName = name;
  }

  BaseType *bt = NewFloat64(name);    
  ar = NewArray(name);
  ar->add_var(bt);
  ar->append_dim(row,DimName+"_row");
  ar->append_dim(column,DimName+"_column");
  dds_table.add_var(ar);
}

DDS &
read_descriptors(const char *filename)
{
  MATFile *fp;
  Matrix *mp;
  
  // dataset name
  dds_table.set_dataset_name(name_path(filename));
 
  fp = matOpen((char *)filename, "r");
  if (fp == NULL){
    sprintf(Msgt, "mat_dds: Could not open file %s", filename);
    ErrMsgT(Msgt);
    exit(1);
  }

  // Read all the matrices in file
  while ((mp = matGetNextMatrix(fp)) != NULL) {
    // String types are used as attributes
    if(mxIsNumeric(mp)){
      if(mxIsComplex(mp)){
	String Real = (String)mxGetName(mp) + "_Real";
	MakeMatrix(Real, mxGetM(mp),mxGetN(mp)); // real part
	String Imag = (String)mxGetName(mp) + "_Imaginary";
	MakeMatrix(Imag, mxGetM(mp),mxGetN(mp)); // imaginary part
      }
      else
	MakeMatrix((String)mxGetName(mp),mxGetM(mp),mxGetN(mp)); 
    }
    mxFreeMatrix(mp);
  }
  matClose(fp);
  return dds_table;
}


// Read the matlab string variables as attributes in memory

DAS &
read_attributes(const char *filename)
{
  MATFile *fp;
  Matrix *mp;
  char *str_rep;
  AttrTable  *attr_table;
 
  attr_table = das.add_table("MAT_GLOBAL", new AttrTable);
 
  fp = matOpen((char *)filename, "r");

  if (fp == NULL){
    sprintf(Msgt, "mat_das: Could not open file %s",filename);
    ErrMsgT(Msgt);
    exit(1);
  }

  // Read all the matrices in file
  while ((mp = matGetNextMatrix(fp)) != NULL) {
    // String types are used as attributes
    if(mxIsString(mp)){
      // get size
      int X = mxGetN(mp);
      int Y = mxGetM(mp);

      str_rep = new char [X*Y+3];
      
      // quote the string for parser
      *str_rep = '"'; 
      mxGetString(mp,str_rep+1,X*Y+1);
      *(str_rep + X*Y + 1) = '"';
      *(str_rep + X*Y + 2 )= '\0';

      if (attr_table->append_attr(mxGetName(mp), "String",str_rep) == 0){
	sprintf (Msgt,"SaveAttTa: Couldn't output attribute \"%s\"", mxGetName(mp));
	ErrMsgT(Msgt);
	exit(1);
      }
      delete [] str_rep;
    }
    mxFreeMatrix(mp);
  }
  matClose(fp);
  return das;
}
