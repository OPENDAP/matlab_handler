// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGH.  
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 8/25/96

/* $Log: MATStr.h,v $
/* Revision 1.2  1999/05/04 03:30:51  jimg
/* Merged no gnu changes
/*
/* Revision 1.1.20.1  1999/04/09 05:29:02  brent
/* convert String.h code to new standard lib <string>
/*
/* Revision 1.1  1996/10/31 14:43:33  reza
/* First release of DODS-matlab servers.
/*
 *
*/

#ifndef _MATStr_h
#define _MATStr_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include <limits.h>

#include "Str.h"
extern Str * NewStr(const string &n = "");

class MATStr: public Str {
public:
    MATStr(const string &n = "");
    virtual ~MATStr() {}

    virtual BaseType *ptr_duplicate();
    
    virtual bool read(const string &dataset, int &error);
};

typedef MATStr * MATStrPtr;

#endif

