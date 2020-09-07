#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

std::string inputCode, zeroCode = "0", oneCode = "1", placeHolder;
int bits, seqLength, len = 0;
char digit;

int main() {

    std::cin >> bits >> seqLength;

    while (std::cin >> digit) {
        inputCode += digit;
    }

    (bits % seqLength == 0) ? (len = bits / seqLength) : (len = bits / seqLength + 1);
    // check if 'bits' is a multiple of 'seqLength' and divide it into 'len' sequences
    // to read: ternary operators

    for (int i = 0; i != len; ++i) { // for each sequence
        placeHolder = inputCode.substr(i * seqLength, seqLength); // 'placeHolder' is 'seqLength' long

        if (placeHolder.end() - placeHolder.begin() < seqLength) { // if it's < 'seqLength' it means its incomplete
            zeroCode += '1' + placeHolder; // treat is as incorrect
            oneCode += '0' + placeHolder;
            break; // break to not add twice
        }

        // zeroCode
        if (std::find(placeHolder.begin(), placeHolder.end(), '1') != placeHolder.end()) { // check if there's a '1'
            zeroCode += '1' + placeHolder; // add corresponding code
        } else { // else, compress the code
            zeroCode += '0';
        }

        // onceCode
        if (std::find(placeHolder.begin(), placeHolder.end(), '0') != placeHolder.end()) {
            oneCode += '0' + placeHolder;
        } else {
            oneCode += '1';
        }
    }


    if (zeroCode.end() - zeroCode.begin() <= oneCode.end() - oneCode.begin()) { // find the shortest encoding
        std::cout << std::fixed << std::setprecision(2) << float(bits) / float(zeroCode.end() - zeroCode.begin())
                  << '\n'; // fixed 2 decimals ratio
        for (auto it : zeroCode) { // print each digit on new line;
            std::cout << it << '\n'; // to read: std::endl vs '\n'
        }
    } else {
        std::cout << std::fixed << std::setprecision(2) << float(bits) / float(oneCode.end() - oneCode.begin()) << '\n';
        for (auto it : oneCode) {
            std::cout << it << '\n';
        }
    }

    return 0;
}
