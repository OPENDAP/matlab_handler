// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1999
// Please read the full copyright statement in the file COPYRIGHT.
//
// Authors: James Gallagher

#ifndef _matfloat32_h
#define _matfloat32_h 1

#ifdef __GNUG__
#pragma interface
#endif

#include "Float32.h"
extern Float32 * NewFloat32(const string &n = "");

class MATFloat32: public Float32 {
public:
    MATFloat32(const string &n = "");
    virtual ~MATFloat32() {}

    virtual BaseType *ptr_duplicate();
    
    virtual bool read(const string &dataset);
};

// $Log: MATFloat32.h,v $
// Revision 1.3  2000/10/10 00:03:07  jimg
// Moved CVS Logs to the end of each file.
// Added code to handle exceptions thrown by the dap library.
// Added exceptions to the read methods.
// Changed the definition of the read methods to match the dap library.
//
// Revision 1.2  1999/05/04 03:30:50  jimg
// Merged no gnu changes
//
// Revision 1.1  1999/03/29 19:21:45  jimg
// Added
//

#endif

