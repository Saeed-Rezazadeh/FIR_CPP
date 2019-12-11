//
// Created by saeed on 2019-12-09.
//

#ifndef FIR_CPP_CONVOLUTION_H
#define FIR_CPP_CONVOLUTION_H

#include "ac_fixed.h"
#include "ac_float.h"
#include <vector>
#include <string>

using namespace std;

class Convolution {
private:
    vector<ac_fixed<8, 1, true>> _filterCoefficients_fx;
    vector<ac_fixed<8, 4, true >> _inputSignal_fx;


    string _pathOfFilterCoefficients_fx;
    string _pathOfInputSignal_fx;

    vector<ac_float<8, 0, 2, AC_RND>> _filterCoefficients_fp;
    vector<ac_float<8, 3, 2, AC_RND>> _inputSignal_fp;
    string _pathOfFilterCoefficients_fp;
    string _pathOfInputSignal_fp;
public:
    // The Convolution class constructor

    /**
     * @param path to the csv file containing the input signal using fixed points arithmetics
     * @param path to the csv file containing the filter tap coefficients using fixed point arithmetics
     * @param path to the csv file containing the quantized input signal
     * @param path to the csv file containing the quantized filter tap coefficients
     * */
    Convolution(string pathOfInputSignal_fx, string pathOfFilterCoefficients_fx, string pathOfInputSignal_fp,
                string pathOfFilterCoefficients_fp);

    // Implements the filter convolution using floating points arithmetics
    void floatingPointArithmetics(vector<ac_float<8, 3, 2, AC_RND>> *outputSignal_fp);

    // Implements the filter convolution using fixed points arithmetics
    void fixedPointArithmetics(vector<ac_fixed<8, 3, true>> *outputSignal_fx);


    ~Convolution() {
        _pathOfInputSignal_fp.clear();
        _pathOfFilterCoefficients_fp.clear();
        _inputSignal_fp.clear();
        _filterCoefficients_fp.clear();

        _pathOfInputSignal_fx.clear();
        _pathOfFilterCoefficients_fx.clear();
        _inputSignal_fx.clear();
        _filterCoefficients_fx.clear();
    }

};

#endif //FIR_CPP_CONVOLUTION_H
