#include <iostream>
#include <vector>
#include <string>

int numbers, placeHolder, cnt=0;
std::vector<int> values(20, 0);
int main() {

    std::cin>>numbers;
    for (int i=0; i!=numbers; ++i) {
        std::cin>>placeHolder;
        values[std::to_string(placeHolder).length()-1]+=1;
    }

    for(auto i : values) {
        ++cnt;
        if (i>0) {
            std::cout << cnt <<" "<<i<< std::endl;
        }
    }

    return 0;
}
