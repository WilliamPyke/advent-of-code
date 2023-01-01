#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#ifndef UTILS_H
#define UTILS_H

class Utils {
public:
    std::vector<char> readCharFile(std::string& filePath) { //function that reads a file and returns a char vector that contains all the characters within

        std::vector<char> charFile;
        std::ifstream in(filePath);
        char c;

        if(in.is_open()) {
            while(in.good()) {
                in.get(c);
                if(in.eof()) {
                    break;
                }
                charFile.push_back(c);
            }
        }

        if(!in.eof() && in.fail())
            std::cout << "Error reading " << filePath << std::endl;

        in.close();
        return charFile;
    };

    std::vector<std::string> readLineFile(std::string& filePath) {  //function that reads a file and returns a string vector that contains all the lines within
        std::vector<std::string> lineFile;
        std::ifstream filein; //input filestream operator
        filein.open(filePath);
        std::string line;  //declares string which stores the number that it reads from the .txt file

        if (!filein.is_open())
        {
            std::cout << "Error reading " << filePath << std::endl; //Error message if input file cannot be opened/found
        }
        else
        {
            while (getline(filein, line)) //while there is still data in the file, do the following
            {
                lineFile.push_back(line);
            }

            filein.close(); //closes the input file
        }
        return lineFile;
    };

    int smallest(std::vector<int>& values){ //function that checks for and returns the smallest value in an integer vector
        int smallest = values[0];
        for (int i = 1; i < values.size(); i++) {
            if (values[i] < smallest) {
                smallest = values[i];
            }
        }
        return smallest;
    }

    int second_smallest(std::vector<int>& values){  //function that checks for and returns the second smallest value in an integer vector
        int smallest = values[0];
        int second_smallest = INT_MAX;
        int same_values;
        for (int i = 1; i < values.size(); i++) { //checks for smallest value
            if (values[i] < smallest) {
                smallest = values[i];
            }
        }
        for (int i = 0; i < values.size(); i++) {
            if (values[i] > smallest && values[i] < second_smallest) { //checks over for second smallest value
                second_smallest = values[i];
            }
        }
        for (int i = 0; i < values.size(); i++) {   //checks for any duplicate values, since if there is a case such as 24 24 24
            if (values[i] == smallest) {            //since second_smallest is initialized to INT_MAX, it would not change to 24
                same_values++;                      
            }
        }
        if (same_values == values.size()) { //if all the values are the same, make second_smallest a value in the vector
            second_smallest = values[0];    //such that it does not remain as INT_MAX.
        }
        return second_smallest;
    }
};

#endif