#include <iostream>
#include <vector>
#include <string>

namespace extd {
    // ---------------------------------------------------------------------------- Universal Methods

    template<typename T>
    void printArray(std::vector<T> array, std::string splitter = " ") {
        for (T i : array) {std::cout << i << splitter;}
    };

    // ---------------------------------------------------------------------------- String Methods

    std::vector<std::string> split_string(std::string target_string, std::string splitter, int count = false, bool StartFromEnd = false) {
        using namespace std;

        vector<string> Result;
        string Current = "";
        int current_count = 0;

        if (count == false) {count = target_string.size();}

        if (!StartFromEnd) {
            for (int i = 0; i<target_string.size(); i+=1) {
                bool check = false;
                if (current_count == count) {
                    for (int j = i; j<target_string.size(); j+=1) {
                        Current += target_string[j];
                    }
                    break;
                }
                if (target_string[i] == splitter[0]) {
                    check = true;
                    for (int j = 0; j<splitter.size(); j+=1) {
                        if (i+j >= target_string.size()) {check = false; break;}
                        if (splitter[j] != target_string[i+j]) {check = false; break;}
                    }
                }
                if (check) {Result.push_back(Current); Current = ""; i+=splitter.size()-1; current_count+=1;}
                else {Current += target_string[i];}
            }
            if (Current != "") {Result.push_back(Current);}
        }
        else {
            for (int i = target_string.size()-1; i>-1; i-=1) {
                bool check = false;
                if (current_count == count) {
                    for (int j = i; j>-1; j-=1) {
                        Current = string(1, target_string[j]) + Current;
                    }
                    break;
                }
                if (target_string[i] == splitter[0]) {
                    check = true;
                    for (int j = 0; j<splitter.size(); j+=1) {
                        if (i-j <= -1) {check = false; break;}
                        if (splitter[j] != target_string[i-j]) {check = false; break;}
                    }
                }
                if (check) {Result.insert(Result.begin(), Current); Current = ""; i-=splitter.size()-1; current_count+=1;}
                else {Current = string(1, target_string[i]) + Current;}
            }
            if (Current != "") {Result.insert(Result.begin(), Current);}
        }
        
        return Result;
    }

    std::string remove_prefix(std::string target_string, std::string prefix) {
        if (prefix.size() > target_string.size()) {return target_string;}

        for (int i = 0; i<prefix.size(); i+=1) {
            if (prefix[i] != target_string[i]) {return target_string;}
        }

        std::string Result = "";
        for (int i = prefix.size(); i<target_string.size(); i+=1) {
            Result += target_string[i];
        }

        return Result;
    };

    std::string remove_suffix(std::string target_string, std::string suffix) {
        if (suffix.size() > target_string.size()) {return target_string;}

        for (int i = 0; i<suffix.size(); i+=1) {
            if (suffix[i] != target_string[i + target_string.size()-suffix.size()]) {return target_string;}
        }

        std::string Result = "";
        for (int i = 0; i<target_string.size()-suffix.size(); i+=1) {
            Result += target_string[i];
        }

        return Result;
    };

    int in_string(std::string target_string, std::string find) {
        int count = 0;

        for (int i = 0; i<target_string.size(); i+=1) {
            if (target_string[i] == find[0]) {
                bool check = true;
                int j;
                for (j = 1; j<find.size(); j+=1) {
                    if (i+j >= target_string.size()) {return count;}
                    if (target_string[i+j] != find[j]) {check = false; break;}
                }
                if (check) {count += 1; i += find.size()-1;}
            }
        }
        return count;
    };

    int in_string_array(std::vector<std::string> target_array, std::string find) {
        int count = 0;

        for (std::string i : target_array) {
            if (i == find) {count += 1;}
        }
        return count;
    };
}