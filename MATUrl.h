
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
/* Revision 1.2  1999/05/04 03:30:51  jimg
/* Merged no gnu changes
/*
/* Revision 1.1.20.1  1999/04/09 05:29:02  brent
/* convert String.h code to new standard lib <string>
/*
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
extern Url * NewUrl(const string &n = "");

class MATUrl: public Url {
public:
    MATUrl(const string &n = "");
    virtual ~MATUrl() {}

    virtual BaseType *ptr_duplicate();
    
    virtual bool read(const string &dataset, int &error);
};

typedef MATUrl * MATUrlPtr;

#endif

