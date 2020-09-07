#include <string>
#include <iostream>

std::string secretMessage, decodedMessage;

int toInt(char &first, char &second) { // function to transform 2 digit chars into a number
    return (first - '0') * 10 + (second - '0');
}

int main() {

    std::cin >> secretMessage;

    for (auto it = secretMessage.begin(); it != secretMessage.end(); ++it) {
        if (*it == '0') { // if the current char is '0', we either have "00" or "0x"
            if (*(it + 1) != '0') {
                decodedMessage += static_cast<char>(*(it + 1) - '0' + 64); // if it's "0x", ignore 0 and append x
            } else {
                decodedMessage += static_cast<char>(32); // else add a space => ascii for space is 32
            }
            ++it; // move one extra space because we analyzed 2 chars

        } else { // if the current char is not '0'
            if (it != secretMessage.end() - 1) { // if we are not over the last char
                if (toInt(*it, *(it + 1)) <= 26) { // check if number is <= 26
                    decodedMessage += static_cast<char>(toInt(*it, *(it + 1)) + 64); // if it is, append said letter
                    ++it; // move one extra position
                } else {
                    decodedMessage += static_cast<char>(*it - '0' + 64); // else, only use current char
                }
            } else {
                decodedMessage += static_cast<char>(*it - '0' + 64); // if we reach the last char then it can only be a letter <= 9
            }
        }
    }
    std::cout << decodedMessage << '\n';
// decodedMessage += static_cast<char>(*it - '0' + 64); because: *it is always a char [0, 9] so *it - '0' will give
// the decimal value represented by *it; + 64 because 'A' has ascii code 65; read static_cast<>() and ASCII table

}
