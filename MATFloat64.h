// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1994-1996
// Please read the full copyright statement in the file COPYRIGHT.
//
// Authors:
//      reza            Reza Nekovei (reza@intcomm.net)

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

#ifndef _matfloat64_h
#define _matfloat64_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include "Float64.h"
extern Float64 * NewFloat64(const string &n = "");

class MATFloat64: public Float64 {
public:
    MATFloat64(const string &n = "");
    virtual ~MATFloat64() {}

    virtual BaseType *ptr_duplicate();
    
    virtual bool read(const string &dataset);
};

/* 
 * $Log: MATFloat64.h,v $
 * Revision 1.5  2003/12/08 18:09:05  edavis
 * Merge release-3-4 into trunk
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
 * Revision 1.1.20.1  1999/04/09 05:29:02  brent
 * convert String.h code to new standard lib <string>
 *
 * Revision 1.1  1996/10/31 14:43:22  reza
 * First release of DODS-matlab servers.
 */

#endif

