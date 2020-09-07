#include <iostream>
#include <vector>

float numberOfValues, biggerThanAvg=0, cnt=0, sum=0;
std::vector<float>values;
float placeHolder;

int main() {

    std::cin>>numberOfValues;
    while (std::cin>>placeHolder)
        values.push_back(placeHolder);

    for (auto pos = values.begin(); pos != values.end(); ++pos ){
        if (pos == values.begin()){
            if (*pos > 0 and *pos > *(pos+1)){
                sum+=*pos;
                ++cnt;
            }
        }else if (pos+1 == values.end()){
            if (*pos > 0 and *pos > *(pos-1)){
                sum+=*pos;
                ++cnt;
            }
        } else{
            if (*pos > *(pos-1) and *pos > *(pos+1)){
                sum+=*pos;
                ++cnt;
            }
        }
    }

    placeHolder=sum/cnt;

    for (float x: values){
        if (x>placeHolder)
            ++biggerThanAvg;
    }

    std::cout<<biggerThanAvg;

    return 0;
}
