// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1999
// Please read the full copyright statement in the file COPYRIGHT.
//
// Authors: James Gallagher

// $Log: MATFloat32.cc,v $
// Revision 1.2  1999/05/04 03:30:50  jimg
// Merged no gnu changes
//
// Revision 1.1  1999/03/29 19:21:45  jimg
// Added
//


static char rcsid[]={"$Id: MATFloat32.cc,v 1.2 1999/05/04 03:30:50 jimg Exp $"};

#ifdef __GNUG__
#pragma implementation
#endif

#include "config_mat.h"
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
MATFloat32::read(const string &, int &error)
{
    error = 1;
    return false;
}
