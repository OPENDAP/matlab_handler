// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGH.  
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

/* $Log: MATGrid.h,v $
/* Revision 1.2  1999/05/04 03:30:50  jimg
/* Merged no gnu changes
/*
/* Revision 1.1.20.1  1999/04/09 05:29:02  brent
/* convert String.h code to new standard lib <string>
/*
/* Revision 1.1  1996/10/31 14:43:25  reza
/* First release of DODS-matlab servers.
/*
 *
*/


#ifndef _MATGrid_h
#define _MATGrid_h 1

#ifdef _GNUG_
#pragma interface
#endif

#include "Grid.h"
extern Grid * NewGrid(const string &n = "");

class MATGrid: public Grid {
public:
    MATGrid(const string &n = "");
    virtual ~MATGrid();
    
    virtual BaseType *ptr_duplicate();

    virtual bool read(const string &dataset, int &error);

};

#endif





