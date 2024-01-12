// includes
#include <iostream>
#include <string>

std::string trim(std::string const randomString) {

    std::string tempString = "";

    for(char chr : randomString) {
        if(chr == ' ' || chr == '\t' || chr == '\n' || chr == '\r') {
            continue;
        } else {
            tempString += chr;
        }
    }
    
    return tempString;
}

int sumEven(std::string const cardNumber) {

    std::string tempStr = "";
    int evenSum = 0;
    int tempoverload = 0;

    for(int i = 0; i < cardNumber.size(); i += 2) {
        tempoverload = ((int)cardNumber[i] - '0')*2;
        tempStr += std::to_string(tempoverload);
    }

    for(char chr : tempStr) evenSum += (int)chr - '0';

    return evenSum;
}

int sumOdd(std::string const cardNumber) {

    std::string tempStr = "";
    int oddSum = 0;
    int tempoverload = 0;

    for(int i = 1; i < cardNumber.size(); i += 2) {
        tempoverload = ((int)cardNumber[i] - '0');
        tempStr += std::to_string(tempoverload);
    }

    for(char chr : tempStr) oddSum += (int)chr - '0';

    return oddSum;
}

// main loop
int main() {

    bool isOver = false;
    bool wrongSign = false;

    do {
        std::string cardNumber;
        std::cout << " **** Card number validation program ****" << std::endl;
        std::cout << "Your 16-digit card number: ";
        std::getline(std::cin >> std::ws, cardNumber);
        char inputAnotherNumber = ' ';
        int OddEvenSum = 0;

        if(trim(cardNumber).size() == 16) {
            OddEvenSum = sumEven(trim(cardNumber)) + sumOdd(trim(cardNumber));
            if(OddEvenSum % 10 == 0) {
                std::cout << "Card number has 16 digits & is valid!" << std::endl;
            } else {
                std::cout << "Card number is not valid!" << std::endl;
            }
        } else {
            std::cout << "Card number has not enough digits!" << std::endl;
        }

        do {
            std::cout << "Do you want to check another card number? (y/n): ";
            std::cin >> inputAnotherNumber;

            switch(inputAnotherNumber) {
            case 'y' : 
                wrongSign = false;
                isOver = false;
                system("cls");
                break;
            case 'n' :
                isOver = true;
                wrongSign = false;
                break;
            default :
                wrongSign = true;
                system("cls");
                std::cout << "  |--> Error! <--|" << std::endl;
                std::cout << "Enter y/n only please!" << std::endl;
                system("pause");
                system("cls");
            }

        } while(wrongSign == true);
    } while(!isOver);
    
    return 0;
}
