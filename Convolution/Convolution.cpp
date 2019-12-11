//
// Created by saeed on 2019-12-09.
//
#include <iostream>
#include <string>
#include <fstream>
#include "Convolution.h"
#include <sstream>

using namespace std;

Convolution::Convolution(string pathOfInputSignal_fx, string pathOfFilterCoefficients_fx, string pathOfInputSignal_fp,
                         string pathOfFilterCoefficients_fp) {
    _pathOfInputSignal_fx = pathOfInputSignal_fx;
    _pathOfFilterCoefficients_fx = pathOfFilterCoefficients_fx;

    _pathOfInputSignal_fp = pathOfInputSignal_fp;
    _pathOfFilterCoefficients_fp = pathOfFilterCoefficients_fp;


    fstream fin;
    string line, word;
    // Open an existing file
    fin.open(_pathOfInputSignal_fp, ios::in);
    getline(fin, line);
    // used for breaking words
    stringstream f_fp(line);
    while (getline(f_fp, word, ',')) {

        // add all the column data
        // of a row to a vector
        _inputSignal_fp.push_back(stod(word));
    }

    fin.close();

    // Open an existing file
    fin.open(_pathOfInputSignal_fx, ios::in);
    getline(fin, line);
    // used for breaking words
    stringstream f_fx(line);
    while (getline(f_fx, word, ',')) {

        // add all the column data
        // of a row to a vector
        _inputSignal_fx.push_back(stod(word));
    }

    fin.close();

    // Open an existing file
    fin.open(_pathOfFilterCoefficients_fp, ios::in);
    getline(fin, line);
    // used for breaking words
    stringstream c_fp(line);
    while (getline(c_fp, word, ',')) {

        // add all the column data
        // of a row to a vector
        _filterCoefficients_fp.push_back(stod(word));
    }

    fin.close();

    // Open an existing file
    fin.open(_pathOfFilterCoefficients_fx, ios::in);
    getline(fin, line);
    // used for breaking words
    stringstream c_fx(line);
    while (getline(c_fx, word, ',')) {

        // add all the column data
        // of a row to a vector
        _filterCoefficients_fx.push_back(stod(word));
    }

    fin.close();
}

void Convolution::floatingPointArithmetics(vector<ac_float<8, 3, 2, AC_RND>> *outputSignal_fp) {
    int const inputSignalLength = _inputSignal_fp.size();
    int const filterLength = _filterCoefficients_fp.size();
    int const outputSignalLength = filterLength + inputSignalLength - 1;

    outputSignal_fp->clear();
    outputSignal_fp->resize(outputSignalLength);

    int i;
    for (i = 0; i < outputSignalLength; ++i)
        outputSignal_fp->at(i) = 0;

    // The convolution sum
    for (auto i(0); i < outputSignalLength; ++i) {
        int const jmn = (i >= filterLength - 1) ? i - (filterLength - 1) : 0;
        int const jmx = (i < inputSignalLength - 1) ? i : inputSignalLength - 1;
        for (auto j(jmn); j <= jmx; ++j) {

            outputSignal_fp->at(i) += (_inputSignal_fp[j] * _filterCoefficients_fp[i - j]);
        }
    }

}

void Convolution::fixedPointArithmetics(vector<ac_fixed<8, 3, true>> *outputSignal_fx) {
    int const inputSignalLength = _inputSignal_fx.size();
    int const filterLength = _filterCoefficients_fx.size();
    int const outputSignalLength = filterLength + inputSignalLength - 1;

    outputSignal_fx->clear();
    outputSignal_fx->resize(outputSignalLength);

    int i;
    for (i = 0; i < outputSignalLength; ++i)
        outputSignal_fx->at(i) = 0;

    // The convolution sum
    for (auto i(0); i < outputSignalLength; ++i) {
        int const jmn = (i >= filterLength - 1) ? i - (filterLength - 1) : 0;
        int const jmx = (i < inputSignalLength - 1) ? i : inputSignalLength - 1;
        for (auto j(jmn); j <= jmx; ++j) {

            outputSignal_fx->at(i) += (_inputSignal_fx[j] * _filterCoefficients_fx[i - j]);
        }
    }
}

