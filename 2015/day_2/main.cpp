#include <iostream>
#include <ctype.h>
#include "/Users/williampyke/Documents/Code/AOC/advent-of-code/2015/utils/utils.h"

class Calcs {
public:
    void getSides(std::vector<std::string>& lineFile) { //function to parse sides into three arrays, (l, w, h)
        int total_area = 0;                             //as well as to calculate the total area + required ribbon length and print result
        int total_ribbon = 0;
        int size = lineFile.size();
        int l[size];
        int w[size];
        int h[size];
        int x = 0; //value to count no. of times x has been encountered, e.g. 5x21x9 has 2 x's therefore x would have a max value of 2.
        std::string s = "";      
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < lineFile[i].size(); j++) {
                if (std::isdigit(lineFile[i][j])) {
                    s += lineFile[i][j];    
                } else {
                    x++;
                    if (x == 1) {   //if it is the first time an x is encountered, therefore s must hold the first number value, length
                        l[i] = std::stoi(s);
                    } else {        //else it must be the width value (this only works for values such as 4x12x6, not 4x54x2x5, more "else if x==2" etc. statements would be required to accommodate more values)
                        w[i] = std::stoi(s);       
                    }
                    s = "";         //resets s to blank string after each iteration.
                }
            }
            h[i] = std::stoi(s);    //there is no x after the last numerical value to separate it, therefore whatever is in s at the end of lineFile[i] must be the last value, h
            s = "";
            x = 0;  //resets the x counter to zero
        }

        for (int i = 0; i < size; i++) {
            total_area += calcArea(l[i], w[i], h[i]);
            total_ribbon += calcRibbon(l[i], w[i], h[i]);
            //std::cout << total_ribbon << std::endl;   - to see length of total ribbon summed after each iteration
        }
        std::cout << "Total area of wrapping paper required: " << total_area << " ft²." << std::endl;   //prints result
        std::cout << "Total length of ribbon required: " << total_ribbon << " ft." << std::endl;
    }

//wanted to return total_area and total_ribbon as a tuple to main (or l, w and h arrays to split parsing into array and summing the total area + ribbon length into separate functions) for printing but could not figure out how to get C++17 working in VS Code for Mac to use std::tuple.

    int calcArea(int l, int w, int h) {
        Utils utils;
        int area = 0;
        int lw = l * w;
        int wh = w * h;
        int hl = h * l;
        std::vector<int> areas; //stores lw, wh and hl in vector
        areas.push_back(lw);
        areas.push_back(wh);
        areas.push_back(hl);
        int smallest = utils.smallest(areas);       //utils function to find the smallest of the values stored in the vector
        area = 2 * lw + 2 * wh + 2 * hl + smallest; //area calculation
        return area;
    }

    int calcRibbon(int l, int w, int h) {
        Utils utils;
        int len = 0;
        std::vector<int> lengths; //stores l, w and h in vector
        lengths.push_back(l);
        lengths.push_back(w);
        lengths.push_back(h);
        int smallest = utils.smallest(lengths); //utils function to find the smallest of the values stored in the vector
        int second_smallest = utils.second_smallest(lengths);   //utils function to find the second smallest of the values stored in the vector
        len = 2 * smallest + 2 * second_smallest + l * w * h;   //length calculation

        //std::cout << l << " " << w << " " << h << std::endl;    //prints values for debugging purposes
        //std::cout << second_smallest << " " << smallest << std::endl;
        //std::cout << len << std::endl;

        return len;
    }
};

int main() {
    Utils utils;
    Calcs calc;
    std::string filepath = "/Users/williampyke/Documents/Code/AOC/advent-of-code/2015/day_2/input.txt";
    std::vector<std::string> lineFile = utils.readLineFile(filepath);   //utils function that reads file and stores each line in a string vector
    calc.getSides(lineFile);
    return 0;
}


