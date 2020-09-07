#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

int size, placeHolder;
std::vector<int> numbers, plays, diff;


int main() {
    std::cin>>size;

    for(int  i=0; i!=std::pow(size, 2);++i) {
        std::cin>>placeHolder;
        numbers.push_back(placeHolder);
    }

    while (std::cin>>placeHolder)
        plays.push_back(placeHolder);

    std::sort(numbers.begin(), numbers.end());
    std::sort(plays.begin(), plays.end());
    std::set_difference(numbers.begin(), numbers.end(),plays.begin(), plays.end(),std::inserter(diff, diff.begin()));

    if (plays.size()-diff.size()==numbers.size())
        std::cout<<"BINGO!"<<std::endl;
    else{
        for(auto i : diff )
            std::cout<<i<<std::endl;
    }


    return 0;
}
