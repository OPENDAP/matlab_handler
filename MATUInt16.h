
// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1999
// Please read the full copyright statement in the file COPYRIGHT.
//
// Authors: James Gallagher

#ifndef _matuint16_h
#define _matuint16_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include "UInt16.h"
extern UInt16 * NewUInt16(const string &n = "");

class MATUInt16: public UInt16 {
public:
    MATUInt16(const string &n = "");
    virtual ~MATUInt16() {}

    virtual BaseType *ptr_duplicate();
    
    virtual bool read(const string &dataset);
};

// $Log: MATUInt16.h,v $
// Revision 1.5  2003/12/08 18:09:05  edavis
// Merge release-3-4 into trunk
//
// Revision 1.4  2003/02/10 22:42:05  jimg
// Merged with 3.2.6.
//
// Revision 1.3.4.1  2001/10/09 22:35:49  jimg
// Removed
//
// Revision 1.3  2000/10/10 00:03:07  jimg
// Moved CVS Logs to the end of each file.
// Added code to handle exceptions thrown by the dap library.
// Added exceptions to the read methods.
// Changed the definition of the read methods to match the dap library.
//
// Revision 1.2  1999/05/04 03:30:51  jimg
// Merged no gnu changes
//
// Revision 1.1  1999/03/29 19:21:44  jimg
// Added
//

#endif

