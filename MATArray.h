// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGHT.
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

//
// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

#ifndef _matarray_h
#define _matarray_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include "Array.h"
extern Array * NewArray(const string &n , BaseType *v);

class MATArray: public Array {
public:
    MATArray(const string &n = "", BaseType *v = 0);
    virtual ~MATArray();

    virtual BaseType *ptr_duplicate();

    virtual bool read(const string &dataset);
};

/* 
 * $Log: MATArray.h,v $
 * Revision 1.5  2003/05/02 16:55:27  jimg
 * Removed default parameter specification for NewArray. These are already given
 * elsewhere.
 *
 * Revision 1.4  2003/02/10 22:42:05  jimg
 * Merged with 3.2.6.
 *
 * Revision 1.3.4.1  2001/10/09 22:35:49  jimg
 * Removed
 *
 * Revision 1.3  2000/10/10 00:03:07  jimg
 * Moved CVS Logs to the end of each file.
 * Added code to handle exceptions thrown by the dap library.
 * Added exceptions to the read methods.
 * Changed the definition of the read methods to match the dap library.
 *
 * Revision 1.2  1999/05/04 03:30:50  jimg
 * Merged no gnu changes
 *
 * Revision 1.1.20.1  1999/04/09 05:29:01  brent
 * convert String.h code to new standard lib <string>
 *
 * Revision 1.1  1996/10/31 14:43:17  reza
 * First release of DODS-matlab servers.
 */

#endif


