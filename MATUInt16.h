
// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1999
// Please read the full copyright statement in the file COPYRIGHT.
//
// Authors: James Gallagher

// $Log: MATUInt16.h,v $
// Revision 1.2  1999/05/04 03:30:51  jimg
// Merged no gnu changes
//
// Revision 1.1  1999/03/29 19:21:44  jimg
// Added
//


#ifndef _MATUInt16_h
#define _MATUInt16_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include "UInt16.h"
extern UInt16 * NewUInt16(const string &n = "");

class MATUInt16: public UInt16 {
public:
    MATUInt16(const string &n = "");
    virtual ~MATUInt16() {}

    virtual BaseType *ptr_duplicate();
    
    virtual bool read(const string &dataset, int &error);
};

#endif

