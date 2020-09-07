#include <iostream>

int arrangements, k, number;

float factorial(float x){
    if (x > 1)
        return x * factorial(x-1);
    else
        return 1;
}

float diffFactoarial(int x, int y){
    float prod=1;
    for (int i = 1; i <= x-y; ++i)
        prod*=i;
    return prod;
}

int main() { // not working

    std::cin>>k>>arrangements;
    number=k;

    while(true){
        if (arrangements >= factorial(number)/diffFactoarial(number, k))
            ++number;
        else
            break;
    }
    if (number==k)
        std::cout<<0;
    else
        std::cout<<number;

    return 0;
}
