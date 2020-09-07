#include <iostream>
#include <string>
#include <vector>
#include "SmallRestaurant.h"
#include "MediumRestaurant.h"
#include "FastFood.h"

std::string placeHolder, dish;
int time, type;
std::vector<std::string> orders;

int main() {
//    std::cin>> type;
//    if (type == 0)
//        SmallRestaurant restaurant;
//    else if (type == 1)
//        MediumRestaurant restaurant;

        FastFood restaurant;

    while (std::cin>>placeHolder){
        if (placeHolder == "+")
        {
            std::cin>>time;
            std::cin>>dish;
            restaurant.setOrders(dish, time);

        }else if (placeHolder == "-"){
            std::cin>>time;
            restaurant.checkReady(time);

        } else
            restaurant.printStatus();
    }
    return 0;
}
