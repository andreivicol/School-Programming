#include <iostream>
#include <string>
#include <iomanip>

double password, generator;
double product, sum = 0;
std::string encryptedPassword;

int main() {

    std::cin >> password;
    std::cin >> generator;
    product = password * generator;

    encryptedPassword = std::to_string(product);

    while (encryptedPassword.size() > 1){
        for (const auto& ch : encryptedPassword){
            sum += ch - 48;
        }
        encryptedPassword = std::to_string(sum);
        sum = 0;
    }

    std::cout << encryptedPassword;

    return 0;
}
