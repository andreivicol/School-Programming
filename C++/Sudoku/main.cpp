#include <iostream>
#include <map>
#include <vector>

std::vector<std::vector<int>> game;
std::vector<int> placeHolder;
std::map<int, int> horizontalLine, verticalLine, innerSquare;
int number;

int main() {

    for (int i = 0; i < 81; ++i) {
        std::cin >> number;
        placeHolder.push_back(number);
        if ( (i + 1) % 9 == 0){
            game.push_back(placeHolder);
            placeHolder.clear();
        }
    }

    for (int i = 0; i < 9; ++i) {
        //horizontal line
        for ( auto entry : game[i]){
            auto ret = horizontalLine.insert(std::make_pair(entry, 1));
            if (!ret.second){
                std::cout<<"Gresit";
                exit(1);
            }
        }
        horizontalLine.clear();
        //vertical line
        for (int j = 0; j < 9; ++j) {
            auto ret = verticalLine.insert(std::make_pair(game[i][j], 1));
            if (!ret.second){
                std::cout<<"Gresit";
                exit(1);
            }
        }
        verticalLine.clear();
    }
    //inner square
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 9; ++k) {
                auto ret = innerSquare.insert(std::make_pair(game[3 * i + j][3 * j + k % 3], 1));
                if (k % 3 == 2)
                    ++j;
                
                if (!ret.second){
                    std::cout<<"Gresit";
                    exit(1);
                }
            }
            innerSquare.clear();
        }
    }
    std::cout<<"Corect";

    return 0;
}
