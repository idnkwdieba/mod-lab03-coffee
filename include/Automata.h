#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <string>
#include <vector>

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
private:
	int cash;
	std::vector<std::string> menu;
	std::vector<int> prices;
	STATES state;
public:
	Automata();
	void on();
	void off();
	void coin(int coins);
	std::vector<std::string> getMenu();
	STATES getState();
	void choice(int choice);
	void cancel();
private:
	void check(int choice);
	void cook(int choice);
	void finish();
};

#endif // INCLUDE_AUTOMATA_H_
