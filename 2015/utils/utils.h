#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#ifndef UTILS_H
#define UTILS_H

class Utils {
public:
    std::vector<char> readCharFile(std::string& filePath) {

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


    std::vector<std::string> readLineFile(std::string& filePath) //function to read and store data from text file
    {
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
};

#endif