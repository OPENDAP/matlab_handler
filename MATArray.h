// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGH.  
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

//
// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

/* $Log: MATArray.h,v $
/* Revision 1.2  1999/05/04 03:30:50  jimg
/* Merged no gnu changes
/*
/* Revision 1.1.20.1  1999/04/09 05:29:01  brent
/* convert String.h code to new standard lib <string>
/*
/* Revision 1.1  1996/10/31 14:43:17  reza
/* First release of DODS-matlab servers.
/*
 *
 */

#ifndef _MATArray_h
#define _MATArray_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include "Array.h"
extern Array * NewArray(const string &n = "", BaseType *v = 0);

class MATArray: public Array {
public:
    MATArray(const string &n = "", BaseType *v = 0);
    virtual ~MATArray();

    virtual BaseType *ptr_duplicate();

    virtual bool read(const string &dataset, int &error);
};

#endif


