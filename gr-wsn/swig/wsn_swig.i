/* -*- c++ -*- */

#define WSN_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "wsn_swig_doc.i"

%{
#include "wsn/sync_detection.h"
%}


%include "wsn/sync_detection.h"
GR_SWIG_BLOCK_MAGIC2(wsn, sync_detection);
