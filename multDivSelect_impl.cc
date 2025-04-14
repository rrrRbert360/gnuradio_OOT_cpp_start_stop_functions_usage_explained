/* -*- c++ -*- */
/*
 * Test code to demonstrate start() and stop() functions of a OOT block.
 * Scroll down to and search for the added start() and stop() functions
 * See also the added lines in the related modified file multDivSelect_impl.h
 *
 * This is example is based on the great GNU Radio example "Creating C++ OOT with gr-modtool"
 * https://wiki.gnuradio.org/index.php?title=Creating_C%2B%2B_OOT_with_gr-modtool
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */
#include "multDivSelect_impl.h"
#include <gnuradio/io_signature.h>
#include <iostream>  // Required for std::cout


namespace gr {
namespace customModule {

using input_type = gr_complex;
using output_type = gr_complex;
multDivSelect::sptr multDivSelect::make(bool selector)
{
    return gnuradio::make_block_sptr<multDivSelect_impl>(selector);
}

/*
 * The private constructor
 */
multDivSelect_impl::multDivSelect_impl(bool selector)
    : gr::sync_block("multDivSelect",
                     gr::io_signature::make(
                         2 /* min inputs */, 2 /* max inputs */, sizeof(input_type)),
                     gr::io_signature::make(
                         1 /* min outputs */, 1 /*max outputs */, sizeof(output_type)))
{
    _selector = selector;
}

/*
 * Our virtual destructor.
 */
multDivSelect_impl::~multDivSelect_impl() {}




/*
 * The start function, THIS CODE WAS ADDED TO THE TUTORIAL 
 */
bool multDivSelect_impl::start() {
std::cout << "Hello GNU Radio World, flowgraph started" << std::endl;	//THIS TEXT APPEARS IN THE TERMINAL WINDOW OF GNURADIO COMPANION



/* 
    // Add hardware initialization code here

 */
    return true; // Return true if initialization is successful
}


/*
 * The stop function,  THIS CODE WAS ADDED TO THE TUTORIAL 
 */
bool multDivSelect_impl::stop() {
std::cout << "Flowgraph stops, see you next time!" << std::endl; 		//THIS TEXT APPEARS IN THE TERMINAL WINDOW OF GNURADIO COMPANION

    return true; // Return true if de-initialization is successful
}





int multDivSelect_impl::work(int noutput_items,
                             gr_vector_const_void_star& input_items,
                             gr_vector_void_star& output_items)
{
    auto in0 = static_cast<const input_type*>(input_items[0]);
    auto in1 = static_cast<const input_type*>(input_items[1]);
    auto out = static_cast<output_type*>(output_items[0]);

    for (int index = 0; index < noutput_items; index++) {
        if (_selector) { out[index] = in0[index] * in1[index]; }
        else{ out[index] = in0[index] / in1[index]; }
    }

    // Tell runtime system how many output items we produced.
    return noutput_items;
}

} /* namespace customModule */
} /* namespace gr */
