#include <iostream>
#include <vector>
#include <utility>
#include <string>

void showMenu(){
    std::cout << "**********MENU**********" << std::endl; 
    std::cout << "1. Check Balance" << std::endl;
    std::cout << "2. Deposit" << std::endl;
    std::cout << "3. Withdraw" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "5. Transaction History" << std::endl;
    std::cout << "************************" << std::endl; 

};

std::vector<std::pair<std::string, double>> transactions;

int main(){

    int option;
    double balance = 500;

    do{
        showMenu();
        std::cout << "Option: ";
        std::cin >> option;
        system("cls"); 

        switch(option){
        case 1: 
            std::cout << "Balance is: $" << balance << std::endl;
            break;
        case 2: 
            std::cout << "Deposit Amount: ";
            double depositAmount;
            while (!(std::cin >> depositAmount) || depositAmount < 0){
                std::cout << "Invalid input. Please enter a positive number: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            balance += depositAmount;
            transactions.push_back({"Deposit: ", depositAmount});
            std::cout <<"Balance is: $" << balance << std::endl;
            break;
        case 3: 
            std::cout << "Withdraw Amount: ";
            double withdrawAmount;
            while(!(std::cin >> withdrawAmount) || withdrawAmount < 0 || withdrawAmount > balance){
                if(withdrawAmount < 0){
                    std::cout << "Invalid input. Please enter a positive number: ";
                } else if(withdrawAmount > balance){
                    std::cout << "Withdraw amount cannot be greater than the balance.";
                } else {
                    std::cout << "Invalid input.";
                } 
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            balance -= withdrawAmount;
            transactions.push_back({"Withdrawal: ", withdrawAmount});
            std::cout << "Balance is: $" << balance << std::endl;
            break;
        case 4:
            std::cout << "Exiting program..." << std::endl;
            break;
        case 5:
            std::cout << "Transaction History:" << std::endl;
            for (auto t : transactions){
                std::cout << t.first << "$" << t.second << std::endl;   
            }
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
            break;
        }
    }while (option != 4);

    system("pause");
}