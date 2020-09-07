#include <iostream>
#include <vector>
#include <string>
#include "BankSystem.h"
#include "Method.h"

std::string inputWord, placeHolder;
std::vector<std::string> clientInfo;
std::vector<std::vector<std::string>> dataBase;
int cnt=0;

int main() {
    BankSystem bank;
    Method method;

//    dataBase={{"Haslett", "bankcard", "5602230536569837", "13/03/2019", "655.19"},{"Salvidor", "maestro", "5018089331172231", "01/05/2017" ,"-12.34"},{"Cob", "mastercard", "5108754368312270", "22/09/2017", "-90.10"}};

    std::cin>>inputWord;
   // method.findMethod(inputWord, dataBase);

    while (std::cin>>placeHolder){ //repeated input until EOF
        clientInfo.push_back(placeHolder);
        ++cnt;
        //std::cout<<placeHolder<<std::endl;

        if (cnt==5) { // end of seq
            dataBase.push_back(clientInfo); //add each client to dataBase
            clientInfo.clear();//clear client info
            cnt=0;
        }
    }

//    bank.setCommand(inputWord);
//    method.findMethod(bank.getCommand(),dataBase);

    return 0;
}