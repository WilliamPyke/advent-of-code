#include <iostream>
#include <ctype.h>
#include "/Users/williampyke/Documents/Code/AOC/advent-of-code/2015/utils/utils.h"

class Calcs {
public:
    void getSides(std::vector<std::string>& lineFile) {
        int l[10000];
        int w[10000];
        int h[10000];
        int x = 0; //counts for x
        std::string s = "";      
        for (int i = 0; i < lineFile.size(); i++) {
            for (int j = 0; j < lineFile[i].size(); j++) {
                if (std::isdigit(lineFile[i][j])) {
                    s += lineFile[i][j];
                } else {
                    x++;
                    if (x == 1) {
                        l[i] = std::stoi(s);
                    } else {
                        w[i] = std::stoi(s);       
                    }
                    s = "";
                }
            }
            h[i] = std::stoi(s);
            s = "";
            x = 0;
        }
        for (int i = 0; i < lineFile.size(); i++) {
            std::cout << l[i] << " " << w[i] << " " << h[i] << std::endl;
        }
    }


};

int main() {
    Calcs calc;
    Utils utils;
    std::string filepath = "/Users/williampyke/Documents/Code/AOC/advent-of-code/2015/day_2/input.txt";
    std::vector<std::string> lineFile = utils.readLineFile(filepath);
    calc.getSides(lineFile);
    return 0;
}


