// 猜单词游戏
#ifndef HANGMAN_H_
#define HANGMAN_H_
#include <string>
class Hangman {
public:
	// 可以在创建时确定最大猜错次数
	explicit Hangman(int chances = 6); // ctors
	// Guess()是主要操作
	void Guess();
private:
	// 内置单词表[a-z] # word list, from a to z
    static const int NUM = 26;
    const char* wordList[NUM] = {
		"apiary", "beetle", "cereal", "danger", "ensign", "florid", "garage",
		"health", "insult", "jackal", "keeper", "loaner", "manage", "nonce",
		"onset", "plaid", "quilt", "remote", "stolid", "train",
		"useful", "valid", "whence", "xenon", "yearn", "zippy"
	};
	// ---
	std::string m_word;	// 保存随机选中的单词 # store the randomly choosing word
	std::string m_show;	// 保存猜对的的字母，同时是提示 # correctly guessing
	std::string m_wrong;	// 保存猜错的字母 # wrong guessing
	int m_chances;	// 最多可以猜错的次数 # max chances
	int m_usrChances;	// 构造时传入的次数 #
	// ---
	// private methods # 不公开的内部方法
  void init(int chances = 6);	// 初始化
	void Check(char ch);	// 检查字母对不对
  void YouWin();
  void GameOver();
  const std::string& RightWord() const {return m_word;}
  const std::string& YouGuess() const {return m_show;}
	void Tips() const;
};
#endif  // HANGMAN_H_
