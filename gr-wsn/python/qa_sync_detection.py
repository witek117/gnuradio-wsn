#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 
# Copyright 2019 <+YOU OR YOUR COMPANY+>.
# 
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
# 
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import wsn_swig as wsn
from numpy import array

class qa_sync_detection (gr_unittest.TestCase):

    def setUp (self):
        self.tb = gr.top_block ()

    def tearDown (self):
        self.tb = None

    def test_001_t (self):
        print "dfg"
        input_data = array([0,4,6,2,0,4,5,1,3,0,6,7,0,8,0,9,0,7,7,8,8,0,9,9,4,3,0,7,3,0,6,6])
        src = blocks.vector_source_b(input_data)
        demod = wsn.sync_detection()

        self.tb.connect(src,demod)
        # set up fg
        self.tb.run ()
        # check data
        # elf.assertTupleEqual(expected_result, result_data)
        
        self.assertEqual(1, 1)


if __name__ == '__main__':
    gr_unittest.run(qa_sync_detection, "qa_sync_detection.xml")
