
// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGH.  
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

/* $Log: MATUrl.h,v $
/* Revision 1.1  1996/10/31 14:43:37  reza
/* First release of DODS-matlab servers.
/*
 *
*/

#ifndef _MATUrl_h
#define _MATUrl_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include "Url.h"
extern Url * NewUrl(const String &n = (char *)0);

class MATUrl: public Url {
public:
    MATUrl(const String &n = (char *)0);
    virtual ~MATUrl() {}

    virtual BaseType *ptr_duplicate();
    
    virtual bool read(const String &dataset, int &error);
};

typedef MATUrl * MATUrlPtr;

#endif

