#include <iostream>
#include <vector>
#include "array2d.h"

int main() {
    array2d<int, 3, 3> array2D ;
    array2D.fill(1);

    array2D.print();
    array2D.insert(2, 6);
    array2D.print();

    std::cout<<*(array2D.begin()+2)<<std::endl;

    return 0;
}
