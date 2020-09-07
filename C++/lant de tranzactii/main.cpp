#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Transaction {
    std::string expeditor;
    std::string destinatar;
    int bani;

    Transaction(const std::string &expeditor, const std::string &destinatar, const int &bani) {
        this->expeditor = expeditor;
        this->destinatar = destinatar;
        this->bani = bani;
    } // use constructor so you can costruct inplace => push_back would copy each struct inside 'tranzactii'
};

std::vector<Transaction> tranzactii, lantTemporar, lantFinal;

int numarTranzactii, suma;
std::string expeditor, destinatar;

int main() {
    std::cin >> numarTranzactii;

    for (int i = 0; i != numarTranzactii; ++i) {
        std::cin >> expeditor >> destinatar >> suma;
        tranzactii.emplace_back(Transaction(expeditor, destinatar, suma)); // make vector of structs
    }

    for (auto &tranzactie : tranzactii) { // for each transaction, iterate over the vector until you reach the end of the chain
        destinatar = tranzactie.destinatar;
        suma = tranzactie.bani;
        lantTemporar.emplace_back(tranzactie);

        auto it = tranzactii.begin();

        while (it != tranzactii.end()){
            if (destinatar == it->expeditor) { // when destinatar == expeditor
                destinatar = it->destinatar; // update destinatar
                lantTemporar.emplace_back(*it); // add to vector
                suma = std::min(suma, it->bani); // update sum to be the min amount
                it = tranzactii.begin(); // restart iteration
                continue; // continue to not increment iterator
            }
            ++it;
        }

        lantTemporar.back().bani = suma; // update amount for the last entry

        if (lantFinal.size() < lantTemporar.size()) { // choose the longest chain
            lantFinal = lantTemporar;
        }
        if (lantFinal.size() == lantTemporar.size()) { // if they're equal
            if (lantFinal.back().bani < lantTemporar.back().bani) {
                lantFinal = lantTemporar; // pick the one with the highest amount
            }
        }

        lantTemporar.clear(); // clear vector
    }

    for (const auto &person : lantFinal) {
        std::cout << person.expeditor << " "; // print each expeditor
    }
    std::cout << lantFinal.back().destinatar << '\n' << lantFinal.back().bani << '\n'; // print destinatar and money

    return 0;
}
