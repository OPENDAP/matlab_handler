
// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGH.  
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

/* $Log: MATInt32.h,v $
/* Revision 1.1  1996/10/31 14:43:27  reza
/* First release of DODS-matlab servers.
/*
 *
*/

#ifndef _MATInt32_h
#define _MATInt32_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include "Int32.h"
extern Int32 * NewInt32(const String &n = (char *)0);

class MATInt32: public Int32 {
public:
    MATInt32(const String &n = (char *)0);
    virtual ~MATInt32() {}

    virtual BaseType *ptr_duplicate();
    
    virtual bool read(const String &dataset, int &error);
};

typedef MATInt32 * MATInt32Ptr;

#endif

