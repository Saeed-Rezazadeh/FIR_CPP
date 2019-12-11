//
// Created by saeed on 2019-12-10.
//

#ifndef FIR_CPP_SQNR_H
#define FIR_CPP_SQNR_H

#include "ac_fixed.h" // useful functions for fixed point arithmetics
#include "ac_float.h" // useful functions for floating point arithmetics
#include <vector>

using namespace std;

void calculateSQNR(vector<ac_float<8, 3, 2, AC_RND>> *outputSignal_fp, vector<ac_fixed<8, 3, true>> *outputSignal_fx) {
    double signalPower_fp = 0;
    double signalPower_fx = 0;
    int signalLength = outputSignal_fp->size();
    for (int i = 0; i < signalLength; i++) {
        signalPower_fp += pow(outputSignal_fp->at(i).to_double(), 2);
        signalPower_fx += pow((outputSignal_fp->at(i).to_double() - outputSignal_fx->at(i).to_double()), 2);
    }

    signalPower_fp /= signalLength;
    signalPower_fx /= signalLength;


    double SQNR = signalPower_fp / signalPower_fx;
    cout << "The SQNR value (Linear) is: " << SQNR << endl;
    cout << "The SQNR value (dB) is: " << 20 * log10(SQNR) << endl;
}

#endif //FIR_CPP_SQNR_H
