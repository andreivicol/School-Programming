#include <iostream>
#include <vector>

int words, soldiers, start;

std::vector<int> soldierNames;

int main() {

    std::cin>>words>>soldiers>>start;

    for (int i=0; i!=soldiers; ++i){
        soldierNames.push_back(i+1);
    }
    start-=1;
    while (soldierNames.size()>1){
        for(int i=0; i!=words; ++i){
            start+=1;
            if (start==soldierNames.size()){
                start=0;
            }
        }
        soldierNames.erase(soldierNames.begin()+start);
        if (start==soldierNames.size()){
            start=0;
        }
    }

    std::cout<<soldierNames[0];

    return 0;
}
