
// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGH.  
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

/* $Log: MATByte.h,v $
/* Revision 1.1  1996/10/31 14:43:19  reza
/* First release of DODS-matlab servers.
/*
 *
 */

#ifndef _MATByte_h
#define _MATByte_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include "Byte.h"
extern Byte * NewByte(const String &n = (char *)0);

class MATByte: public Byte {
public:
    MATByte(const String &n = (char *)0);
    virtual ~MATByte() {}

    virtual BaseType *ptr_duplicate();

    virtual bool read(const String &dataset, int &error);
};

typedef MATByte * MATBytePtr;

#endif

