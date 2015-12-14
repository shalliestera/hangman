#include <iostream>
#include "Hangman.h"
int main(){
    char choice;
	Hangman hm(10); // 传入参数决定最多猜错几次 # max chances for guessing wrong
	std::cout << "**---Hangman Game---**\n";
    do {
			// 仅仅调用 Hangman类里的Guess() # just call Guess()
      hm.Guess();
      // 可以再次开始游戏
      std::cout << "Would you like to play again? [y/n]";
      std::cin >> choice;
	}while(choice == 'y');
	
	std::cout << "See you next time!!\n";
	return 0;
}
