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
extern Sequence * NewSequence(const String &n = (char *)0);

class MATSequence: public Sequence {
public:
  MATSequence(const String &n = (char *)0);
  virtual ~MATSequence();

  virtual BaseType *ptr_duplicate();

  virtual bool read(const String &dataset, int &error);
};

#endif
