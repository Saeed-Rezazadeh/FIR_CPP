#include <iostream>
#include "Convolution.h"
#include "ReadWriteCSV.h" // useful functions for read/writing from/to a csv file.
#include "ac_fixed.h" // useful functions for fixed point arithmetics
#include "ac_float.h" // useful functions for floating point arithmetics
#include "SQNR.h" // Contains the SQNR function

using namespace std;


int main() {


    Convolution firFilter("../CSVFiles/quantizedInputSignal.csv", "../quantizedFIR_coefficients.csv",
                          "../CSVFiles/inputSignalTimeDomain.csv",
                          "../CSVFiles/FIR_coefficients.csv");

    // Implement the filter convolution using floating point arithmetics.
    vector<ac_float<8, 3, 2, AC_RND>> *outputSignal_fp = new vector<ac_float<8, 3, 2, AC_RND>>;
    firFilter.floatingPointArithmetics(outputSignal_fp);

    // Implement the filter convolution using fixed point arithmetics.
    vector<ac_fixed<8, 3, true>> *outputSignal_fx = new vector<ac_fixed<8, 3, true>>;
    firFilter.fixedPointArithmetics(outputSignal_fx);


    // Save the output signal in a .csv file. (Floating point arithmetics)
    string path = "../CSVFiles/output_fp_data.csv";
    ReadWriteCSV readWriteCSV(path, ",", 0);

    readWriteCSV.WriteCSV(path, outputSignal_fp);

    // Save the output signal in a .csv file. (Fixed point arithmetics)
    path = "../CSVFiles/output_fx_data.csv";
    readWriteCSV.WriteCSV(path, outputSignal_fx);


    // Calculate the SQNR using the floating point arithmetics as the reference.
    calculateSQNR(outputSignal_fp, outputSignal_fx);
    return 0;
}
