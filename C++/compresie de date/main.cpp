#include <iostream>
#include <vector>

int numberOfLines, cnt=0;
std::vector<std::string> lines;
std::vector<char> placeHolder;
std::string letter, mem;
std::string print;
//necesita formatarea output-ului

int main() {

    std::cin>>numberOfLines;
    for (int i = 0; i < numberOfLines ; ++i) {
        while (std::cin>>letter){
            for (auto plm : letter) {
                if (plm != ',') {
                    placeHolder.push_back(plm);
                }
            }
        }
        for (auto current = placeHolder.begin(); current != placeHolder.end(); ++current){
            if (current+1==placeHolder.end()){
                if (mem=="0") {
                    print+=", ";
                    print += *current;
                }else{
                    if (*current=='0')
                        ++cnt;
                    print += "(" + mem + "," + std::to_string(cnt) + ")";
                    cnt=0;
                }
            }
            else{
                if (*current != '0' and *(current+1) != '0') //no seq to be compressed
                {
                    print += *current;
                    print += ",";
                }
                if (*current != '0' and *(current+1) == '0') //beginning of compression
                    mem=*current;
                if (*current== '0')
                    ++cnt;
                if (*current == '0' and *(current+1) != '0'){ //end of compressed seq having cnt zeroes
                    {
                        print += "(" + mem + "," + std::to_string(cnt) + "),";
                        mem='0';
                        cnt=0;
                    }                }
                }
            }
        lines.push_back(print);
        placeHolder.clear();
        print="";
        }

    for(const auto& line : lines){
        std::cout<<line<<std::endl;
    }

    return 0;
}
