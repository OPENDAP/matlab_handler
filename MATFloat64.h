// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGH.  
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

/* $Log: MATFloat64.h,v $
/* Revision 1.1  1996/10/31 14:43:22  reza
/* First release of DODS-matlab servers.
/*
 *
 */

#ifndef _MATFloat64_h
#define _MATFloat64_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include "Float64.h"
extern Float64 * NewFloat64(const String &n = (char *)0);

class MATFloat64: public Float64 {
public:
    MATFloat64(const String &n = (char *)0);
    virtual ~MATFloat64() {}

    virtual BaseType *ptr_duplicate();
    
    virtual bool read(const String &dataset, int &error);
};

typedef MATFloat64 * MATFloat64Ptr;

#endif

