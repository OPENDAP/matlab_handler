/*
  Copyright 1996,1997 The University of Rhode Island and The Massachusetts
  Institute of Technology

  Portions of this software were developed by the Graduate School of
  Oceanography (GSO) at the University of Rhode Island (URI) in collaboration
  with The Massachusetts Institute of Technology (MIT).

  Access and use of this software shall impose the following obligations and
  understandings on the user. The user is granted the right, without any fee
  or cost, to use, copy, modify, alter, enhance and distribute this software,
  and any derivative works thereof, and its supporting documentation for any
  purpose whatsoever, provided that this entire notice appears in all copies
  of the software, derivative works and supporting documentation.  Further,
  the user agrees to credit URI/MIT in any publications that result from the
  use of this software or in any product that includes this software. The
  names URI, MIT and/or GSO, however, may not be used in any advertising or
  publicity to endorse or promote any products or commercial entity unless
  specific written permission is obtained from URI/MIT. The user also
  understands that URI/MIT is not obligated to provide the user with any
  support, consulting, training or assistance of any kind with regard to the
  use, operation and performance of this software nor to provide the user
  with any updates, revisions, new versions or "bug fixes".

  THIS SOFTWARE IS PROVIDED BY URI/MIT "AS IS" AND ANY EXPRESS OR IMPLIED
  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
  EVENT SHALL URI/MIT BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL
  DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
  PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTUOUS
  ACTION, ARISING OUT OF OR IN CONNECTION WITH THE ACCESS, USE OR PERFORMANCE
  OF THIS SOFTWARE.
*/

// Matlab server utility routines
//
// ReZa 9/28/96
//

// $Log: MatLabUtil.cc,v $
// Revision 1.8  1999/05/04 03:30:51  jimg
// Merged no gnu changes
//
// Revision 1.7.8.2  1999/05/03 00:39:15  brent
// convert String.h code to new standard lib <string>
//
// Revision 1.7.8.1  1999/04/09 05:29:01  brent
// convert String.h code to new standard lib <string>
//
// Revision 1.7  1997/12/30 22:47:26  jimg
// Modified the read_descriptions() and read_attributes() functions so that they
// return boolean conditions, error messages and DAS/DDS objects. These work
// better with the new filter main()s using the DODSFilter class.
//
// Revision 1.6  1997/10/04 00:33:17  jimg
// Release 2.14c fixes
//
// Revision 1.5.6.1  1997/09/03 22:19:02  jimg
// Removed the global objects das and dds_table. Now the function sin this file
// allocate pointer objects and return those pointers.
//
// Revision 1.5  1997/06/06 03:56:36  jimg
// Changed read_descriptors() so that String casts to const char * worked
// properly.
//
// Revision 1.4  1997/05/01 18:35:59  jimg
// Added configureation header.
// Merged changes from interim 2.1.2 version onto main trunk.
//
// Revision 1.3  1996/12/16 22:32:55  reza
// Made array indices always consistent (i.e. Row, Column).
//
// Revision 1.2  1996/11/13 05:13:07  reza
// Added complex matrix capability.
//
// Revision 1.1  1996/10/31 14:43:40  reza
// First release of DODS-matlab servers.

static char rcsid[]={"$Id: MatLabUtil.cc,v 1.8 1999/05/04 03:30:51 jimg Exp $"};

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <iostream.h>
#include <stdiostream.h>
#include <string>

#include "config_mat.h"
#include "DAS.h"
#include "DDS.h"
#include "MATArray.h"
#include "cgi_util.h"
#include "mat.h"

static char Msgt[255];

void 
MakeMatrix(DDS *dds_table, string name, int row, int column)
{
    Array *ar; 
    string DimName;
    size_t pos;

    // complex matrices have common rows and columns
    if ((pos = name.find("_Real")) != name.npos)
	DimName = name.substr(0, pos);
    else{
	if ((pos = name.find("_Imaginary")) != name.npos)
	    DimName = name.substr(0, pos);
	else
	    DimName = name;
    }

    BaseType *bt = NewFloat64(name);    
    ar = NewArray(name);
    ar->add_var(bt);
    ar->append_dim(row,DimName+"_row");
    ar->append_dim(column,DimName+"_column");

    assert(dds_table);

    dds_table->add_var(ar);
}

bool
read_descriptors(DDS &dds_table, string filename, string *err_msg)
{
    MATFile *fp;
    Matrix *mp;

    // dataset name
    dds_table.set_dataset_name(name_path(filename));
 
    fp = matOpen((char *)(filename.data()), "r");
    if (fp == NULL) {
	sprintf(Msgt, "mat_dds: Could not open file %s", filename.data());
	ErrMsgT(Msgt);
	*err_msg = "\"" + (string)Msgt + "\""; 
	return false;
    }

    // Read all the matrices in file
    while ((mp = matGetNextMatrix(fp)) != NULL) {
	// String types are used as attributes
	if(mxIsNumeric(mp)) {
	    if(mxIsComplex(mp)) {
		string Real = (string)mxGetName(mp) + "_Real";
		// real part
		MakeMatrix(&dds_table, Real, mxGetM(mp),mxGetN(mp)); 
		string Imag = (string)mxGetName(mp) + "_Imaginary";
		// imaginary part
		MakeMatrix(&dds_table, Imag, mxGetM(mp),mxGetN(mp)); 
	    }
	    else
		MakeMatrix(&dds_table, (string)mxGetName(mp), mxGetM(mp),
			   mxGetN(mp)); 
	}
	mxFreeMatrix(mp);
    }
    matClose(fp);

    return true;
}

// Read the matlab string variables as attributes in memory

bool
read_attributes(DAS &das_table, string filename, string *err_msg)
{
    MATFile *fp;
    Matrix *mp;
    char *str_rep;
    AttrTable  *attr_table;

    attr_table = das_table.add_table("MAT_GLOBAL", new AttrTable);
    
    fp = matOpen((char *)filename.c_str(), "r");

    if (fp == NULL){
	sprintf(Msgt, "mat_das: Could not open file %s", filename.data());
	ErrMsgT(Msgt);
	*err_msg = "\"" + (string)Msgt + " \"";
	return false;
    }

    // Read all the matrices in file
    while ((mp = matGetNextMatrix(fp)) != NULL) {
	// String types are used as attributes
	if(mxIsString(mp)){
	    // get size
	    int X = mxGetN(mp);
	    int Y = mxGetM(mp);

	    str_rep = new char [X*Y+3];
      
	    // quote the string for parser
	    *str_rep = '"'; 
	    mxGetString(mp,str_rep+1,X*Y+1);
	    *(str_rep + X*Y + 1) = '"';
	    *(str_rep + X*Y + 2 )= '\0';

	    if (attr_table->append_attr(mxGetName(mp), "String",str_rep) == 0){
		sprintf (Msgt,"SaveAttTa: Couldn't output attribute \"%s\"", mxGetName(mp));
		ErrMsgT(Msgt);
		*err_msg = "\"" + (string)Msgt + "\"";
		return false;
	    }
	    delete [] str_rep;
	}
	mxFreeMatrix(mp);
    }
    matClose(fp);

    return true;
}
