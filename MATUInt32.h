
// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGH.  
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

/* $Log: MATUInt32.h,v $
/* Revision 1.1  1996/11/02 05:36:16  jimg
/* Added.
/*
 */

#ifndef _MATUInt32_h
#define _MATUInt32_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include "UInt32.h"
extern UInt32 * NewUInt32(const String &n = (char *)0);

class MATUInt32: public UInt32 {
public:
    MATUInt32(const String &n = (char *)0);
    virtual ~MATUInt32() {}

    virtual BaseType *ptr_duplicate();
    
    virtual bool read(const String &dataset, int &error);
};

typedef MATUInt32 * MATUInt32Ptr;

#endif

