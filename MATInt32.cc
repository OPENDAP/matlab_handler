
// (c) COPYRIGHT 1996-2000 URI
// 
// See the file COPYRIGHT.

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/26/96

#include "config_mat.h"

static char rcsid[] not_used ={"$Id: MATInt32.cc,v 1.8 2003/12/08 18:09:05 edavis Exp $"};

#ifdef __GNUG__
#pragma implementation
#endif

#include <string>

#include "InternalErr.h"
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
MATInt32::read(const string &)
{
  throw InternalErr(__FILE__, __LINE__, "Unimplemented read method called.");
}

// $Log: MATInt32.cc,v $
// Revision 1.8  2003/12/08 18:09:05  edavis
// Merge release-3-4 into trunk
//
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

