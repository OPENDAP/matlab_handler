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

// malab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

// $Log: MATSequence.cc,v $
// Revision 1.2  1997/01/15 16:42:10  reza
// Added (array to) sequence server.
//
// Revision 1.1  1996/10/31 14:43:30  reza
// First release of DODS-matlab servers.
//
//
//

static char rcsid[]={"$Id: MATSequence.cc,v 1.2 1997/01/15 16:42:10 reza Exp $"};

#ifdef _GNUG_
#pragma implementation
#endif

#include "MATSequence.h"

Sequence *
NewSequence(const String &n)
{
    return new MATSequence(n);
}

// protected

BaseType *
MATSequence::ptr_duplicate()
{
    return new MATSequence(*this);
}

// public

MATSequence::MATSequence(const String &n) : Sequence(n)
{
}

MATSequence::~MATSequence()
{
}

bool 
MATSequence::read(const String &, int &)
{
  #include "MatSeq.h"

  bool status = true;
  char filename[255];

  MATFile *fp;
  Matrix *mp;
  double *DataPtr;

  if(row == 0){

    if (read_p())  // Nothing to do
      return true;
    
    memcpy(filename, (const char *)dataset, ((String)dataset).length()+1);
    fp = matOpen(filename, "r");
    if (fp == NULL){
      sprintf(Msgt, "MATSequence: Could not open file %s",filename);
      ErrMsgT(Msgt);
      return false;
    }
    mp = matGetMatrix(fp,name());
    DataPtr = mxGetPr(mp); // get the matrix structure

    if (DataPtr == NULL) {
      sprintf(Msgt, "MATArray: Error reading matrix");
      ErrMsgT(Msgt);
      return false;
    }  

    nVars = mxGetN(mp);
    int nRec = mxGetM(mp);
 
    int Tcount = 0;
    *varValues = new dods_float64 [nVars]; 
  
    for(int column = 0; column <= mxGetN(mp)-1 ; column++){
      *(VarValues+Tcount) = (dods_float64) *(DataPtr+row+column*mxGetM(mp));  
      Tcount++;
    }

  }

  else{   
    int Tcount = 0;
    for(int column = 0; column <= mxGetN(mp)-1 ; column++){
      *(VarValues+Tcount) = (dods_float64) *(DataPtr+row+column*mxGetM(mp));  
      Tcount++;
    }
  }
  row++;

  if (row < nRec ) {
     
    for(Pix p = first_var(); p; next_var(p)) {
      if (var(p)->type_name() == "Sequence") {
	status = read_seq(dataset, (MATSequence *)var(p));
	var(p)->set_read_p(status);
      }
      else status = status && var(p)->read(dataset,error);
    }
  }
  else {
    error = -1;  // Reached the end of the Sequence, exit.
    status = false;
  }
  
  // mxFreeMatrix(mp);
  //matClose(fp);
   
  return status;
}

bool
MATSequence::read_Seq(const String &dataset, MATSequence *seq)
{
  bool status = true;
  int error;
  
  for(Pix p = seq->first_var(); p; seq->next_var(p)) {
    if (seq->var(p)->type_name() == "Sequence") {
      status = read_seq(dataset, (MATSequence *)seq->var(p));
      seq->set_read_p(status);
    }
    else status = status && seq->var(p)->read(dataset,error);
  }
  
  return status;
}



