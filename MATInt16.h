// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1999
// Please read the full copyright statement in the file COPYRIGHT.
//
// Authors: James Gallagher

// $Log: MATInt16.h,v $
// Revision 1.1  1999/03/29 19:21:44  jimg
// Added
//

#ifndef _MATInt16_h
#define _MATInt16_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include "Int16.h"
extern Int16 * NewInt16(const String &n = (char *)0);

class MATInt16: public Int16 {
public:
    MATInt16(const String &n = (char *)0);
    virtual ~MATInt16() {}

    virtual BaseType *ptr_duplicate();
    
    virtual bool read(const String &dataset, int &error);
};

#endif

