// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGH.  
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

/* $Log: MATSequence.h,v $
/* Revision 1.4  1999/05/04 03:30:51  jimg
/* Merged no gnu changes
/*
/* Revision 1.3.18.1  1999/04/09 05:29:02  brent
/* convert String.h code to new standard lib <string>
/*
/* Revision 1.3  1997/05/01 18:35:50  jimg
/* Added configureation header.
/* Merged changes from interim 2.1.2 version onto main trunk.
/*
 * Revision 1.2  1997/01/15 16:42:11  reza
 * Added (array to) sequence server.
 *
 * Revision 1.1  1996/10/31 14:43:31  reza
 * First release of DODS-matlab servers.
 *
 *
*/

#ifndef _MATSequence_h
#define _MATSequence_h 1

#ifdef _GNUG_
#pragma interface
#endif

#include "Sequence.h"
extern Sequence * NewSequence(const string &n = "");

class MATSequence: public Sequence {
public:
  MATSequence(const string &n = "");
  virtual ~MATSequence();

  virtual BaseType *ptr_duplicate();

  virtual bool read(const string &dataset, int &error);
};

#endif
