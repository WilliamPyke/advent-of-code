#include <iostream>
#include "/Users/williampyke/Documents/Code/AOC/advent-of-code/2015/utils/utils.h"

class Calcs {
public:
    int calcFloor(std::vector<char>& charFile) {
        int floor = 0;
        bool basement = false;
        for(int i = 0; i < charFile.size(); i++) {
            if (charFile[i] == '(') {
                floor++;
            } else if (charFile[i] == ')')  {
                floor--;
            }
            if (floor == -1 && basement == false) {
                basement = true;
                std::cout << "Santa first enters the basement at character position: " << i+1 << '.' << std::endl;
            } 
        }
        return floor;
    };
};

int main() {
    Calcs calc;
    Utils utils;
    int floor;
    std::string filepath = "/Users/williampyke/Documents/Code/AOC/advent-of-code/2015/day_1/input.txt";
    std::vector<char> charFile = utils.readCharFile(filepath);
    floor = calc.calcFloor(charFile);
    std::cout << "The instructions take Santa to floor: " << floor << '.' << std::endl;
    return 0;
}