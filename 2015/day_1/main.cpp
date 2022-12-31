#include <iostream>
#include "/Users/williampyke/Documents/Code/AOC/advent-of-code/2015/utils/utils.h"

class Calcs {
public:
    int calcFloorAndCharPos(std::vector<char>& charFile) {
        int floor = 0;
        int char_pos = 0;
        bool basement = false;
        for(int i = 0; i < charFile.size(); i++) {
            if (charFile[i] == '(') {
                floor++;
            } else if (charFile[i] == ')')  {
                floor--;
            }
            if (floor == -1 && basement == false) {
                basement = true;
                char_pos = i+1;
            } 
        }
        std::cout << "The instructions take Santa to floor: " << floor << '.' << std::endl;
        return char_pos;
    };
};

int main() {
    Calcs calc;
    Utils utils;
    int char_pos;
    std::string filepath = "/Users/williampyke/Documents/Code/AOC/advent-of-code/2015/day_1/input.txt";
    std::vector<char> charFile = utils.readCharFile(filepath);
    char_pos = calc.calcFloorAndCharPos(charFile);
    std::cout << "Santa first enters the basement at character position: " << char_pos << '.' << std::endl;
    return 0;
}