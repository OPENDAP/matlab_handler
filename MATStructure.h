// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGH.  
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

/* $Log: MATStructure.h,v $
/* Revision 1.1  1996/10/31 14:43:35  reza
/* First release of DODS-matlab servers.
/*
 *
*/

#ifndef _MATStructure_h
#define _MATStructure_h 1

#ifdef _GNUG_
#pragma interface
#endif

#include "Structure.h"
extern Structure * NewStructure(const String &n = (char *)0);

class MATStructure: public Structure {
public:
    MATStructure(const String &n = (char *)0);
    virtual ~MATStructure();

    virtual BaseType *ptr_duplicate();

    virtual bool read(const String &dataset, int &error);
};

#endif
