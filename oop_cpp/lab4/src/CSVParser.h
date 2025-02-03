#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <stdexcept>
#include "Converter.h"
using namespace std;

template <typename... Args>
class CSVParser {
private:
    ifstream& file;
    char column_;
    char shielding_;

public:
    class Iterator {
        ifstream* file;
        string currentLine;
        size_t NumLine;
        bool endOfFile;
        char column_;
        char shielding_;

    public:
        Iterator(ifstream* file, char column, char shielding, bool end = false) : file(file), column_(column), shielding_(shielding), endOfFile(end), NumLine(0) {
            if (!end && file && file->is_open()) {
                ++(*this);
            }
        }

        Iterator& operator++() {
            if (file && getline(*file, currentLine)) {
                NumLine++;
            } else {
                endOfFile = true;
            }
            return *this;
        }

        // bool operator==(const Iterator& other) const {
        //     return endOfFile == other.endOfFile;
        // }

        bool operator!=(const Iterator& other) const {
            return endOfFile != other.endOfFile;
        }

        auto operator*() const {
            if (endOfFile) {
                throw out_of_range("invalid using operator * in end of file");
            } else {
                return parse(currentLine);
            }
        }

    private:
        tuple<Args...> parse(const string& line) const {
            auto str_vector = spliting(line, column_, shielding_);
            if (str_vector.size() != sizeof...(Args)) {
                throw out_of_range("invalid column count at line " + to_string(NumLine) + ", column " + to_string(str_vector.size()));
            }
            auto converteredToTuple = convertVectorToTuple<Args...>(str_vector);
            return converteredToTuple;
        }

        vector<string> spliting(const string& str, char column, char shielding) const {
            vector<string> str_vector;
            stringstream one_element;
            bool isShielding = false;

            for (char ch : str) {
                //если встретим знак экранирования
                if (ch == shielding) { 
                    //установим флаг что идет экранизация
                    isShielding = !isShielding; 
                //если разделитель и не в экранизации то
                } else if ((ch == column || ch == '\n') && !isShielding) {
                    str_vector.push_back(one_element.str());
                    //очищаем строковый поток пустой строкой
                    one_element.str("");
                    one_element.clear();
                } else {
                    one_element << ch;
                }
            }
            str_vector.push_back(one_element.str());
            return str_vector;
        }
    };

    CSVParser(ifstream& input, size_t skip, char column = ',', char shielding = '"') : file(input), column_(column), shielding_(shielding) {
        for (size_t i = 0; i < skip && file.is_open(); ++i) {
            string line;
            getline(file, line);
        }
    }

    Iterator begin() {
        return Iterator(&file, column_, shielding_);
    }

    Iterator end() {
        return Iterator(&file, column_, shielding_, true);
    }
};