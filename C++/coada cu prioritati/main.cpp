#include <iostream>
#include <vector>
#include "PriorityQueue.h"
#include <map>

std::vector<std::string> vec;
std::string placeHolder;
std::map<int, Patient> map;
int cnt=0;


int main() {
    PriorityQueue line;
    Patient patient;

    while (std::cin>>placeHolder){
        if (placeHolder == "-") {
            line.Pop(map);
            std::cout<<"Pop"<<std::endl;
        }else if (placeHolder == "*"){
            exit(0);
        } else{
            if (placeHolder == "+")
                continue;
            vec.push_back(placeHolder);
            ++cnt;
            std::cout<<"Push"<<std::endl;
        }
        if (cnt == 5){
            std::cout<<"cnt == 5"<<std::endl;
            cnt = 0;
            line.setPatient(vec, &patient);
            line.Push(map, std::stoi(vec[4]), patient);
            vec.clear();
        }

    }

    return 0;
}
