// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGHT.
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

#ifndef _matsequence_h
#define _matsequence_h 1

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

  virtual bool read(const string &dataset);
};

/* 
 * $Log: MATSequence.h,v $
 * Revision 1.7  2003/12/08 18:09:05  edavis
 * Merge release-3-4 into trunk
 *
 * Revision 1.6  2003/02/10 22:42:05  jimg
 * Merged with 3.2.6.
 *
 * Revision 1.5.4.1  2001/10/09 22:35:49  jimg
 * Removed
 *
 * Revision 1.5  2000/10/10 00:03:07  jimg
 * Moved CVS Logs to the end of each file.
 * Added code to handle exceptions thrown by the dap library.
 * Added exceptions to the read methods.
 * Changed the definition of the read methods to match the dap library.
 *
 * Revision 1.4  1999/05/04 03:30:51  jimg
 * Merged no gnu changes
 *
 * Revision 1.3.18.1  1999/04/09 05:29:02  brent
 * convert String.h code to new standard lib <string>
 *
 * Revision 1.3  1997/05/01 18:35:50  jimg
 * Added configureation header.
 * Merged changes from interim 2.1.2 version onto main trunk.
 *
 * Revision 1.2  1997/01/15 16:42:11  reza
 * Added (array to) sequence server.
 *
 * Revision 1.1  1996/10/31 14:43:31  reza
 * First release of DODS-matlab servers.
 */

#endif
