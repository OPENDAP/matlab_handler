// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1999
// Please read the full copyright statement in the file COPYRIGHT.
//
// Authors: James Gallagher

#include "config_mat.h"

static char rcsid[] not_used ={"$Id: MATFloat32.cc,v 1.3 2000/10/10 00:03:07 jimg Exp $"};

#ifdef __GNUG__
#pragma implementation
#endif

#include "InternalErr.h"
#include "MATFloat32.h"

Float32 *
NewFloat32(const string &n)
{
    return new MATFloat32(n);
}

MATFloat32::MATFloat32(const string &n) : Float32(n)
{
}

BaseType *
MATFloat32::ptr_duplicate()
{
    return new MATFloat32(*this); // Copy ctor calls duplicate to do the work
}
 
bool
MATFloat32::read(const string &)
{
  throw InternalErr(__FILE__, __LINE__, "Unimplemented read method called.");
}

// $Log: MATFloat32.cc,v $
// Revision 1.3  2000/10/10 00:03:07  jimg
// Moved CVS Logs to the end of each file.
// Added code to handle exceptions thrown by the dap library.
// Added exceptions to the read methods.
// Changed the definition of the read methods to match the dap library.
//
// Revision 1.2  1999/05/04 03:30:50  jimg
// Merged no gnu changes
//
// Revision 1.1  1999/03/29 19:21:45  jimg
// Added
//
