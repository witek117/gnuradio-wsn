/* -*- c++ -*- */
/* 
 * Copyright 2019 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <iostream>

#include <gnuradio/io_signature.h>
#include "sync_detection_impl.h"

namespace gr {
  namespace wsn {
    
    uint16_t sync_detection_impl::sync = 0b1101111010101101;
    uint16_t sync_detection_impl::last_16_bits = 0;

    sync_detection::sptr
    sync_detection::make()
    {
      return gnuradio::get_initial_sptr
        (new sync_detection_impl());
    }

    /*
     * The private constructor
     */
    sync_detection_impl::sync_detection_impl()
      : gr::sync_block("sync_detection",
              gr::io_signature::make(1, 1, sizeof(uint8_t)),
              gr::io_signature::make(0, 0, 0))
    {}

    /*
     * Our virtual destructor.
     */
    sync_detection_impl::~sync_detection_impl()
    {
    }

    int
    sync_detection_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const uint8_t *in = (const uint8_t *) input_items[0];

      for (int i =0; i < noutput_items; i ++) {
        
        last_16_bits >>= 1;
        if (in[i] > 0) {
          last_16_bits |= (1 << 15);
        }

        if (last_16_bits == sync) {
          printf("mam!");
        }
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace wsn */
} /* namespace gr */

