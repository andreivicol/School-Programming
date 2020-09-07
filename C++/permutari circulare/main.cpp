#include<iostream>
#include <bitset>
#include <string>

int number, max = 0;
std::string binary;

int main() {

    std::cin >> number;
    binary = std::bitset<17>(number).to_string();
    std::cout<<binary<<'\n';

    int length = binary.end() - binary.begin();

    for (auto it = binary.begin(); it != binary.end(); ++it){
        if (*it != 0){
            binary = std::string(it, binary.end());
            break;
        }
    }
    std::cout<<binary<<'\n';

    for (int i = 0; i != length; ++i) {
        binary = *(binary.end() - 1) + binary.substr(1, length - 1);
        //std::cout<< binary<<'\n';
        if (max < std::stoi(binary, 0, 2)) {
            max = std::stoi(binary, 0, 2);
        }
    }

    std::cout << max;
    return 0;
}
