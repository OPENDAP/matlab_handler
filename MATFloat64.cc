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

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/28/96

// $Log: MATFloat64.cc,v $
// Revision 1.2  1997/01/15 16:42:09  reza
// Added (array to) sequence server.
//
// Revision 1.1  1996/10/31 14:43:20  reza
// First release of DODS-matlab servers.
//
//

static char rcsid[]={"$Id: MATFloat64.cc,v 1.2 1997/01/15 16:42:09 reza Exp $"};

#ifdef __GNUG__
#pragma implementation
#endif

#include <assert.h>

#include "MATFloat64.h"
#include "MatSeq.h"

static char Msgt[255]; // Used by ErrMsgT

Float64 *
NewFloat64(const String &n)
{
    return new MATFloat64(n);
}

MATFloat64::MATFloat64(const String &n) : Float64(n)
{
}

BaseType *
MATFloat64::ptr_duplicate()
{
    return new MATFloat64(*this); // Copy ctor calls duplicate to do the work
}
 
bool
MATFloat64::read(const String &dataset, int &)
{
  bool Found = 0;

  for(int j = 0; j < nVars; ++j) {
    if( name() == varName[j] ) {
          Found = 1;
          val2buf((void *) varValue[j]);
          set_read_p(true);
          break;
      }
  }

  if (!Found) {
    sprintf(Msgt, "MATFloat64: Could not locate variable object -  %s",name());
    ErrMsgT(Msgt);
    return false;
  }
  else return true;
  
}








