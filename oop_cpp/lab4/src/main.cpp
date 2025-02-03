#include <iostream>
#include <fstream>
#include <string>
#include "CSVParser.h"
#include "Printer.h"

int main(){

    using namespace std;
    
    ifstream file("test.csv");
    if (!file.is_open()){
        cerr << "Failed to open file.\n";
        return 1;
    }

    try {
        CSVParser<int, string, string> parser(file, 0/*,',', '"'*/);
        for (const auto& rs : parser){
            cout << rs << endl;
        }

        // for (auto it = parser.begin(); it != parser.end(); ++it){
        //     const auto& rs = *it;  //const tuple<int, string, string>&
        //     cout << rs << endl;
        // }

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    file.close();
    return 0;
}