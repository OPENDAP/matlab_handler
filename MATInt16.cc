
// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1999
// Please read the full copyright statement in the file COPYRIGHT.
//
// Authors: James Gallagher

// $Log: MATInt16.cc,v $
// Revision 1.1  1999/03/29 19:21:44  jimg
// Added
//

static char rcsid[]={"$Id: MATInt16.cc,v 1.1 1999/03/29 19:21:44 jimg Exp $"};

#ifdef __GNUG__
#pragma implementation
#endif

#include "config_mat.h"
#include "MATInt16.h"

Int16 *
NewInt16(const String &n)
{
    return new MATInt16(n);
}

MATInt16::MATInt16(const String &n) : Int16(n)
{
}

BaseType *
MATInt16::ptr_duplicate()
{
    return new MATInt16(*this);
}

bool
MATInt16::read(const String &, int &error)
{
    error = 1;
    return false;
}
