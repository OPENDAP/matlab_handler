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

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/26/96

// $Log: MATInt32.cc,v $
// Revision 1.5  1999/05/04 03:30:50  jimg
// Merged no gnu changes
//
// Revision 1.4.4.1  1999/04/09 05:29:00  brent
// convert String.h code to new standard lib <string>
//
// Revision 1.4  1998/08/06 16:32:59  jimg
// Fixed misuse of the read(...) member function. Return true if more data
// is to be read, false is if not and error if an error is detected
//
// Revision 1.3  1997/05/01 18:35:46  jimg
// Added configureation header.
// Merged changes from interim 2.1.2 version onto main trunk.
//
// Revision 1.2  1996/11/02 18:46:20  jimg
// Messd up while making MATUInt32.cc; fixed and resubmitted.

static char rcsid[]={"$Id: MATInt32.cc,v 1.5 1999/05/04 03:30:50 jimg Exp $"};

#ifdef __GNUG__
#pragma implementation
#endif

#include <assert.h>
#include <string>

#include "config_mat.h"
#include "MATInt32.h"

Int32 *
NewInt32(const string &n)
{
    return new MATInt32(n);
}

MATInt32::MATInt32(const string &n) : Int32(n)
{
}

BaseType *
MATInt32::ptr_duplicate()
{
    return new MATInt32(*this);
}

bool
MATInt32::read(const string &, int &error)
{
    error = 1;
    return false;
}
