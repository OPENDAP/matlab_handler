
// (c) COPYRIGHT 1996-2000 URI
// 
// See the file COPYRIGHT.

// matlab sub-class implementation for MATByte,...MATGrid.
//
// ReZa 9/25/96

#include "config_mat.h"

static char rcsid[] not_used ={"$Id: MATGrid.cc,v 1.6 2003/02/10 22:42:05 jimg Exp $"};

#include <string>

#include "MATGrid.h"

Grid *
NewGrid(const string &n)
{
    return new MATGrid(n);
}

// protected

BaseType *
MATGrid::ptr_duplicate()
{
    return new MATGrid(*this);
}

// public

MATGrid::MATGrid(const string &n) : Grid(n)
{
}

MATGrid::~MATGrid()
{
}

bool
MATGrid::read(const string &dataset)
{
    bool status;

    if (read_p()) // nothing to do
        return false;

    // read array elements
    if (!(status = array_var()->read(dataset))) 
        return status;

    // read maps elements
    for (Pix p = first_map_var(); p; next_map_var(p)) {
	if(!(status = map_var(p)->read(dataset)))
            break;
    }

    if (!status) 
	set_read_p(true);

    return status;
}

// $Log: MATGrid.cc,v $
// Revision 1.6  2003/02/10 22:42:05  jimg
// Merged with 3.2.6.
//
// Revision 1.5.4.1  2001/10/09 22:35:49  jimg
// Removed
//
// Revision 1.5  2000/10/10 00:03:07  jimg
// Moved CVS Logs to the end of each file.
// Added code to handle exceptions thrown by the dap library.
// Added exceptions to the read methods.
// Changed the definition of the read methods to match the dap library.
//
// Revision 1.4  1999/05/04 03:30:50  jimg
// Merged no gnu changes
//
// Revision 1.3.4.1  1999/04/09 05:29:00  brent
// convert String.h code to new standard lib <string>
//
// Revision 1.3  1998/08/06 16:32:59  jimg
// Fixed misuse of the read(...) member function. Return true if more data
// is to be read, false is if not and error if an error is detected
//
// Revision 1.2  1997/05/01 18:35:44  jimg
// Added configureation header.
// Merged changes from interim 2.1.2 version onto main trunk.
//
// Revision 1.1  1996/10/31 14:43:24  reza
// First release of DODS-matlab servers.

