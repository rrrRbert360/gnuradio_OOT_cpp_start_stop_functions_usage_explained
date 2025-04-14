# gnuradio_OOT_cpp_start_stop_functions_usage_explained
Example to use start() and stop() functions in a GNU Radio C++ OOT block.
Example to use start() and stop() function in a GNU Radio C++ OOT block.
This example builds on the great GNU Radio example "Creating C++ OOT with gr-modtool" with which you build an example module "multDivSelect".

1. First carry out the tutorial and understand it: https://wiki.gnuradio.org/index.php?title=Creating_C%2B%2B_OOT_with_gr-modtool

2. The provided modified files (multDivSelect_impl.cc and multDivSelect_impl.h) contain declarations and use for the start() and stop() functions. 
These functions are used when the OOT module starts and stops. Have a look at these files and notice their modifications.

3. Replace the code (.cc-file) and related header file (.h file)  of the OOT module with the provided versions: 
   gr-customModule/lib/multDivSelect_impl.cc
   gr-customModule/lib/multDivSelect_impl.h

4. Restart the compilation by
   cd cd gr-customModule/
   rm -rf build
   mkdir build
   cmake ..
   make
   sudo make install
   sudo ldconfig

5. Start GNU Radio Companion, load the flowgraph and start the flowgraph

6. In the terminal window the text "Hello GNU Radio World" and "see you next time" appear when the multDivSelect block is started and stopped.
