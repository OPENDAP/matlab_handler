
// -*- mode: c++; c-basic-offset:4 -*-

// This file is part of libdap, A C++ implementation of the OPeNDAP Data
// Access Protocol.

// Copyright (c) 2002,2003 OPeNDAP, Inc.
// Author: James Gallagher <jgallagher@opendap.org>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// You can contact OPeNDAP, Inc. at PO Box 112, Saunderstown, RI. 02874-0112.
 
#include "config_mat.h"

static char rcsid[] not_used ={"$Id: mat_handler.cc,v 1.2 2003/12/08 18:09:05 edavis Exp $"};

#include <iostream>
#include <string>

#include "DAS.h"
#include "DDS.h"
#include "DataDDS.h"
#include "Error.h"
#include "DODSFilter.h"

#include "ObjectType.h"
#include "cgi_util.h"

extern bool read_attributes(DAS &das, string filename, string *error);
extern bool read_descriptors(DDS &dds, string filename, string *err_msg);

const string cgi_version = DODS_SERVER_VERSION;

int 
main(int argc, char *argv[])
{
    try {
	DODSFilter df(argc, argv);
	if (df.get_cgi_version() == "")
	    df.set_cgi_version(cgi_version);

	switch (df.get_response()) {
	  case DODSFilter::DAS_Response: {
	      DAS das;

	      string errMsg;
	      if (!read_attributes(das, df.get_dataset_name(), &errMsg))
		  throw Error(errMsg);

	      df.read_ancillary_das(das);
	      df.send_das(das);
	      break;
	  }

	  case DODSFilter::DDS_Response: {
	      DDS dds;
	      dds.filename(df.get_dataset_name());

	      string errMsg;
	      if(!read_descriptors(dds, df.get_dataset_name(), &errMsg))
		  throw Error(errMsg);

	      df.read_ancillary_dds(dds);
	      df.send_dds(dds, true);
	      break;
	  }

	  case DODSFilter::DataDDS_Response: {
	      DDS dds;

	      dds.filename(df.get_dataset_name());
	      // Read the dataset descriptor in memory
	      string errMsg;
	      if (!read_descriptors(dds, df.get_dataset_name(), &errMsg))
		  throw Error(errMsg);

	      df.read_ancillary_dds(dds);
	      df.send_data(dds, stdout);
	      break;
	  }

	  case DODSFilter::Version_Response: {
	      df.send_version_info();

	      break;
	  }

	  default:
	    df.print_usage();	// Throws Error
	}
    }

    catch (Error &e) {
	set_mime_text(cout, dods_error, cgi_version);
	e.print(cout);
	return 1;
    }

    return 0;
}

// $Log: mat_handler.cc,v $
// Revision 1.2  2003/12/08 18:09:05  edavis
// Merge release-3-4 into trunk
//
// Revision 1.1  2003/05/14 22:45:01  jimg
// Added
//
