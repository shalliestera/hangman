#include <iostream>
#include "Hangman.h"
int main(){
    char choice;
	Hangman hm;
	std::cout << "**---Hangman Game---**\n";
    do {
        hm.Guess();
        
        std::cout << "Would you like play again? [y/n]";
        std::cin >> choice;
	}while(choice == 'y');
	return 0;
}
