#include <iostream>
#include <vector>
#include <string>

namespace extd {
    // Universal Methods

    template<typename T>
    void printArray(std::vector<T> array, std::string splitter = " ") {
        for (T i : array) {std::cout << i << splitter;}
    };

    // String Methods

    std::vector<std::string> split_string(std::string target, std::string splitter, int count = false, bool StartFromEnd = false) {
        using namespace std;

        vector<string> Result;
        string Current = "";
        int size_of_splitter = splitter.size();
        int size_of_current_read = 0;

        if (!StartFromEnd) {
            for (char i : target) {
                bool check = false;
                if (i == splitter[0]) {
                    for (int j = 1; j<size_of_splitter; j+=1) {
                        if (splitter[j] != target[i+j]) {continue;}
                    }
                    check = true;
                }
                if (check) {Result.push_back(Current);}
                else {Current += i;}
            }
        }
        else {

        }
    }
}