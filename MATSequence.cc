
// (c) COPYRIGHT 1996-2000 URI
// 
// See the file COPYRIGHT.

// malab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

#include "config_mat.h"

static char rcsid[] not_used ={"$Id: MATSequence.cc,v 1.7 2003/02/10 22:42:05 jimg Exp $"};

#ifdef __GNUG__
#pragma implementation
#endif

#include <string>

#include "InternalErr.h"
#include "MATSequence.h"

Sequence *
NewSequence(const string &n)
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

MATSequence::MATSequence(const string &n) : Sequence(n)
{
}

MATSequence::~MATSequence()
{
}

bool 
MATSequence::read(const string &)
{
  throw InternalErr(__FILE__, __LINE__, "Unimplemented read method called.");
}

// $Log: MATSequence.cc,v $
// Revision 1.7  2003/02/10 22:42:05  jimg
// Merged with 3.2.6.
//
// Revision 1.6.4.1  2001/10/09 22:35:49  jimg
// Removed
//
// Revision 1.6  2000/10/10 00:03:07  jimg
// Moved CVS Logs to the end of each file.
// Added code to handle exceptions thrown by the dap library.
// Added exceptions to the read methods.
// Changed the definition of the read methods to match the dap library.
//
// Revision 1.5  1999/05/04 03:30:50  jimg
// Merged no gnu changes
//
// Revision 1.4.4.1  1999/04/09 05:29:01  brent
// convert String.h code to new standard lib <string>
//
// Revision 1.4  1998/08/06 16:33:00  jimg
// Fixed misuse of the read(...) member function. Return true if more data
// is to be read, false is if not and error if an error is detected
//
// Revision 1.3  1997/05/01 18:35:49  jimg
// Added configureation header.
// Merged changes from interim 2.1.2 version onto main trunk.
//
// Revision 1.2  1997/01/15 16:42:10  reza
// Added (array to) sequence server.
//
// Revision 1.1  1996/10/31 14:43:30  reza
// First release of DODS-matlab servers.

