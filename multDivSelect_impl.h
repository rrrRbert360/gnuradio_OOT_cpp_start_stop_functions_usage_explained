/* -*- c++ -*- */
/*
 * Test header file to demonstrate start() and stop() functions of a OOT block.
 * Below you find the required declarations of the added start() and stop() functions
 * See also the added lines in the related modified source code file multDivSelect_impl.cc
 *
 * This is example is based on the great GNU Radio example "Creating C++ OOT with gr-modtool"
 * https://wiki.gnuradio.org/index.php?title=Creating_C%2B%2B_OOT_with_gr-modtool
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_CUSTOMMODULE_MULTDIVSELECT_IMPL_H
#define INCLUDED_CUSTOMMODULE_MULTDIVSELECT_IMPL_H

#include <gnuradio/customModule/multDivSelect.h>

namespace gr {
namespace customModule {

class multDivSelect_impl : public multDivSelect
{
private:
    bool _selector;

public:
    multDivSelect_impl(bool selector);
    ~multDivSelect_impl();

    bool start() override; // The start function,  THIS CODE WAS ADDED 
    bool stop() override;  // The stop function, THIS CODE WAS ADDED 

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items);
};

} // namespace customModule
} // namespace gr

#endif /* INCLUDED_CUSTOMMODULE_MULTDIVSELECT_IMPL_H */
