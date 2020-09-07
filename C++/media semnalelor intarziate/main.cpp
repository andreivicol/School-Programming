#include <iostream>
#include <vector>
#include <cmath>
int nbSignals, cnt;
float signalValue, avgCalculator=0;
std::vector<std::vector<float>> inputValues, delayedValues;
std::vector<float> placeHolder;

int main() {
//    std::cin>>nbSignals;
//    for (int i = 0; i != nbSignals; ++i){
//        while (std::cin>>signalValue)
//            placeHolder.push_back(signalValue);
//
//        inputValues.push_back(placeHolder);
//        placeHolder.clear();
//    }
    nbSignals=3;
    inputValues= {{4, 3, 2, 1, 0, -1, -2, -3, -4, -3}, {3, 2, 1, 0, -1, -2, -3, -4, -3, -2}, {2, 1, 0, -1, -2, -3, -4, -3, -2, -1}};

    for(int delay=0; delay!=3; ++delay) { //3 sets are needed: not delayed, 1st and 2nd delays
        if (delay>0) { //first set of signals is not delayed
            for (int i = 0; i != nbSignals; ++i) {
                cnt=i; //decide how many zeroes to add to each signal
                while (cnt>0){
                    inputValues[i].insert(inputValues[i].begin(), 0); // each signal in vector has 'index' zeroes added in front
                    --cnt;
                }
            }
        }
        for (int signal = 0; signal != 10; ++signal) {
            for (int i = 0; i != nbSignals; ++i) {
                avgCalculator += inputValues[i][signal];
            }
            float x = std::ceil((avgCalculator/nbSignals) * 100.0)/100.0; //ceil returns next highest int => approximation to 2 decimals(wont return 1.50 or 1.00 etc)
            avgCalculator=0;
            placeHolder.push_back(x);
        }

        delayedValues.push_back(placeHolder);
        placeHolder.clear(); //clear vector to not get duplicate values
    }

    for (auto signal : delayedValues){
        for (auto value : signal)
            std::cout<<value<<" ";
        std::cout<<std::endl;
    }
    return 0;
}