// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGHT.
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 8/25/96

#ifndef _matstr_h
#define _matstr_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include "Str.h"

extern Str * NewStr(const string &n = "");

class MATStr: public Str {
public:
    MATStr(const string &n = "");
    virtual ~MATStr() {}

    virtual BaseType *ptr_duplicate();
    
    virtual bool read(const string &dataset);
};

/* 
 * $Log: MATStr.h,v $
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
 * Revision 1.1  1996/10/31 14:43:33  reza
 * First release of DODS-matlab servers.
 */

#endif

