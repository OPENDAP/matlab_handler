// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1999
// Please read the full copyright statement in the file COPYRIGHT.
//
// Authors: James Gallagher

// $Log: MATFloat32.h,v $
// Revision 1.1  1999/03/29 19:21:45  jimg
// Added
//

#ifndef _MATFloat32_h
#define _MATFloat32_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include "Float32.h"
extern Float32 * NewFloat32(const String &n = (char *)0);

class MATFloat32: public Float32 {
public:
    MATFloat32(const String &n = (char *)0);
    virtual ~MATFloat32() {}

    virtual BaseType *ptr_duplicate();
    
    virtual bool read(const String &dataset, int &error);
};

#endif

