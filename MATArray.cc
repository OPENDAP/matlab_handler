
// (c) COPYRIGHT 1996-2000 URI
// 
// See the file COPYRIGHT.

// matlab sub-class implementation for MATByte,..MATGrid.
//
// ReZa 9/28/96

#include "config_mat.h"

static char rcsid[] not_used ={"$Id: MATArray.cc,v 1.9 2003/02/10 22:42:05 jimg Exp $"};

#ifdef __GNUG__
#pragma implementation
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include <iostream>
#include <string>

#include "cgi_util.h"
#include "dods-datatypes.h"
#include "Error.h"
#include "MATArray.h"

#include <mat.h>

static char Msgt[255]; // Used by ErrMsgT

Array *
NewArray(const string &n, BaseType *v)
{
    return new MATArray(n, v);
}

BaseType *
MATArray::ptr_duplicate()
{
    return new MATArray(*this);
}

MATArray::MATArray(const string &n, BaseType *v) : Array(n, v)
{
}

MATArray::~MATArray()
{
}

bool
MATArray::read(const string &dataset)
{
    int start, stride, stop;
    int start_p, stride_p, stop_p;
    int nline, npix; 
    size_t pos;
    MATFile *fp;
    Matrix *mp;
    double *DataPtr;

    if (read_p())  // Nothing to do
	return false;

    fp = matOpen((char *)dataset.c_str(), "r");
    if (fp == NULL){
	sprintf(Msgt, "MATArray: Could not open file %s", dataset.c_str());
	ErrMsgT(Msgt);
	throw Error(cannot_read_file, "Could not open dataset.");
    }
  
    Pix p = first_dim();
    start = dimension_start(p,true);
    stride = dimension_stride(p, true);
    stop = dimension_stop(p, true); 

    next_dim(p);
    start_p = dimension_start(p,true);
    stride_p = dimension_stride(p, true);
    stop_p = dimension_stop(p, true); 



    if ((pos = name().find("_Real")) != name().npos) {    // get real part of the complex  matrix  
	string Rname = name().substr(0,pos);
	mp = matGetMatrix(fp,Rname.c_str());
	DataPtr = mxGetPr(mp); 
    }
    else{
	if ((pos = name().find("_Imaginary")) != name().npos) { // get Img part of the complex matrix  
	    string Iname = name().substr(0,pos);
	    mp = matGetMatrix(fp,Iname.c_str());
	    DataPtr = mxGetPi(mp); 
	}
	else{
	    mp = matGetMatrix(fp,name().c_str());
	    DataPtr = mxGetPr(mp); // get the matrix structure
	}
    }

    if (DataPtr == NULL) {
	sprintf(Msgt, "MATArray: Error reading matrix");
	ErrMsgT(Msgt);
	throw Error(unknown_error, Msgt);
    }  

    if(start+stop+stride == 0){ //default rows
	start = 0;
	stride = 1;
	stop = mxGetM(mp)-1;
    }
    if(start_p+stop_p+stride_p == 0){ //default columns
	start_p = 0;
	stride_p = 1;
	stop_p = mxGetN(mp)-1;
    }

    int Len = (((stop-start)/stride)+1)*(((stop_p-start_p)/stride_p)+1);
  
    int Tcount = 0;
    dods_float64 *BufFlt64 = new dods_float64 [Len]; 	
  
    for (int row = start; row <= stop; row +=stride) {	  
	for(int column = start_p; column <= stop_p; column+=stride_p){
	    *(BufFlt64+Tcount) = (dods_float64) *(DataPtr+row+column*mxGetM(mp));  
	    Tcount++;
	}
    }

    set_read_p(true);      
    val2buf((void *)BufFlt64);
    delete [] BufFlt64;
	  
    mxFreeMatrix(mp);
    matClose(fp);
    return false;
}

// $Log: MATArray.cc,v $
// Revision 1.9  2003/02/10 22:42:05  jimg
// Merged with 3.2.6.
//
// Revision 1.8.4.4  2002/06/21 00:31:40  jimg
// I changed many files throughout the source so that the 'make World' build
// works with the new versions of Connect and libdap++ that use libcurl.
// Most of these changes are either to Makefiles, configure scripts or to
// the headers included by various C++ files. In a few places the oddities
// of libwww forced us to hack up code and I've undone those and some of the
// clients had code that supported libwww's generous tracing capabilities
// (that's one part of libwww I'll miss); I had to remove support for that.
// Once this code compiles and more work is done on Connect, I'll return to
// each of these changes and polish them.
//
// Revision 1.8.4.3  2002/05/10 20:24:54  jimg
// I found and fixed several calls to string::data(). In each case we should
// have been using c_str(). This will fix problems that are otherwise very
// hard to diagnose.
//
// Revision 1.8.4.2  2002/04/05 16:19:08  edavis
// Changed include for "mat.h" to <mat.h> so dependencies wouldn't get
// included in the Makefile.in depend list.
//
// Revision 1.8.4.1  2001/10/09 22:35:49  jimg
// Removed
//
// Revision 1.8  2000/10/10 00:03:07  jimg
// Moved CVS Logs to the end of each file.
// Added code to handle exceptions thrown by the dap library.
// Added exceptions to the read methods.
// Changed the definition of the read methods to match the dap library.
//
// Revision 1.7  1999/05/04 03:30:49  jimg
// Merged no gnu changes
//
// Revision 1.6.4.2  1999/05/03 00:39:15  brent
// convert String.h code to new standard lib <string>
//
// Revision 1.6.4.1  1999/04/09 05:29:00  brent
// convert String.h code to new standard lib <string>
//
// Revision 1.6  1998/08/06 16:32:57  jimg
// Fixed misuse of the read(...) member function. Return true if more data
// is to be read, false is if not and error if an error is detected
//
// Revision 1.5  1997/05/01 18:30:59  jimg
// Resurrected version 1.4's fix of the row-major -vs- column-major bug-fix.
// Added a configuration header.
//
// Revision 1.4  1996/12/18 21:07:45  reza
// Made array indices always consistent (i.e. Row, Column).
//
// Revision 1.3  1996/12/16 21:40:50  reza
// *** empty log message ***
//
// Revision 1.2  1996/11/13 05:13:06  reza
// Added complex matrix capability.
//
// Revision 1.1  1996/10/31 14:43:16  reza
// First release of DODS-matlab servers.

