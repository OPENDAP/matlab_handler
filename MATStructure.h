// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGHT.
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

#ifndef _matstructure_h
#define _matstructure_h 1

#ifdef _GNUG_
#pragma interface
#endif

#include "Structure.h"
extern Structure * NewStructure(const string &n = "");

class MATStructure: public Structure {
public:
    MATStructure(const string &n = "");
    virtual ~MATStructure();

    virtual BaseType *ptr_duplicate();

    virtual bool read(const string &dataset);
};

/* 
 * $Log: MATStructure.h,v $
 * Revision 1.3  2000/10/10 00:03:07  jimg
 * Moved CVS Logs to the end of each file.
 * Added code to handle exceptions thrown by the dap library.
 * Added exceptions to the read methods.
 * Changed the definition of the read methods to match the dap library.
 *
 * Revision 1.2  1999/05/04 03:30:51  jimg
 * Merged no gnu changes
 *
 * Revision 1.1.20.1  1999/04/09 05:29:02  brent
 * convert String.h code to new standard lib <string>
 *
 * Revision 1.1  1996/10/31 14:43:35  reza
 * First release of DODS-matlab servers.
 */

#endif
