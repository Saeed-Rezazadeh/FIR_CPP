//
// Created by saeed on 2019-12-09.
//

#ifndef FIR_CPP_READWRITECSV_H
#define FIR_CPP_READWRITECSV_H

#include <ac_float.h>
#include <ac_fixed.h>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

class ReadWriteCSV {
private:
    string _fileName;
    string _delimeter;
    int _linesCount;

public :
    ReadWriteCSV(string, string, int);

    template<typename T>
    void WriteCSV(string name, T *data) {
        auto first = data->begin();
        auto last = data->end();
        fstream file;
        // Open the file in truncate mode if first line else in Append Mode
        file.open(name, ios::out);

        // Iterate over the range and add each element to file separated by delimeter.
        for (; first != last;) {
            file << (*first).to_double();
            if (++first != last)
                file << _delimeter;
        }
        file << "\n";
        _linesCount++;

        // Close the file
        file.close();
    }

};


#endif //FIR_CPP_READWRITECSV_H
