// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1999
// Please read the full copyright statement in the file COPYRIGHT.
//
// Authors: James Gallagher

// $Log: MATUInt16.cc,v $
// Revision 1.1  1999/03/29 19:21:44  jimg
// Added
//

static char rcsid[]={"$Id: MATUInt16.cc,v 1.1 1999/03/29 19:21:44 jimg Exp $"};

#ifdef __GNUG__
#pragma implementation
#endif

#include "config_mat.h"
#include "MATUInt16.h"

UInt16 *
NewUInt16(const String &n)
{
    return new MATUInt16(n);
}

MATUInt16::MATUInt16(const String &n) : UInt16(n)
{
}

BaseType *
MATUInt16::ptr_duplicate(){

    return new MATUInt16(*this);
}

bool
MATUInt16::read(const String &, int &error)
{
    error  = 1;
    return false;
}
