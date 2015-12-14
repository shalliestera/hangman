#include <iostream>
#include <cstdlib>	// std::rand();
#include <ctime>	// std::time()
#include "Hangman.h"
Hangman::Hangman(int chances){
	init(chances);
}

void Hangman::init(int chances){
	// 随机抽一个单词
	std::srand(std::time(nullptr));
	m_word = wordList[std::rand()%NUM];
	// 掩盖掉字母，用----提示长度
	m_show = m_word;
    for(unsigned int i = 0; i<m_show.length(); ++i){
        m_show[i] = '-';
	}
  m_wrong = "\0";	// 初始化 错误字符记录
	m_usrChances = m_chances = chances;	// 初始化可猜次数
}

// 控制猜测流程
void Hangman::Guess(){
	// 输入一个字符, 丢弃多余的字符
    char input;
	while(m_chances > 0){
		Tips();
		std::cout << "Input a letter you guess: ";
    std::cin >> input;
		while(std::cin.get()!='\n'){
			continue;
		}
		
    Check(input);	// 检查字母，并处理内部字符串
		// 猜对整个单词没？
		if(m_show == m_word){
			YouWin();
			return;
		}
	}
	// 机会为0时
	GameOver();
}

// 检查所猜的字母对不对
void Hangman::Check(char ch){
  auto pos = m_word.find(ch);
	// 先看有没有猜过，看猜对 的 和猜错的
  bool guessed;
	if((m_show.find(ch)!=std::string::npos)||(m_wrong.find(ch)!=std::string::npos)){
		guessed = true;
	}
	
	if(!guessed){	// 没猜过
		if(pos == std::string::npos){	// 猜错，减机会，记录猜错的字母
        --m_chances;
        m_wrong += ch;
		}
		while(pos!=std::string::npos){	// 猜对，把猜对的字母翻转
			m_show[pos] = ch;
			pos = m_word.find(ch, pos+1);
		}
	}
	else{	// 猜过了。
		std::cout << "You've guessed " << ch <<" before. Try another letter\n";
	}
}

// private methods
void Hangman::Tips() const {
	std::cout << "   You guess: " << m_show << std::endl;
	std::cout << "  Wrong char: " << m_wrong << std::endl;
	std::cout << "chances left: " << m_chances << std::endl;
}

void Hangman::YouWin() {
	// Win and init
	std::cout << "Congratuations!!! You Got It!!!\n";
	std::cout << "The word is " << RightWord() << std::endl;
	init(m_usrChances);
}

void Hangman::GameOver() {
	// GameOver and init
	std::cout << "You lose. The right word is " << RightWord() << std::endl;
	std::cout << "You guess " << YouGuess() << std::endl;
	init(m_usrChances);
}
