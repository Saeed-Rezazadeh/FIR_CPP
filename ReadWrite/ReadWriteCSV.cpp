//
// Created by saeed on 2019-12-09.
//

#include "ReadWriteCSV.h"
#include <iostream>


using namespace std;

ReadWriteCSV::ReadWriteCSV(string filename, string delimeter, int lineCounts) : _fileName(filename),
                                                                                _delimeter(delimeter),
                                                                                _linesCount(lineCounts) {}
