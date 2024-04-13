#include <iostream>
#include "Automata.h"

std::string convertStateToString(STATES state) {
	switch (state) {
	case 0:
		return "OFF";
	case 1:
		return "WAIT";
	case 2:
		return "ACCEPT";
	case 3:
		return "CHECK";
	case 4:
		return "COOK";
	default:
		return "UNDEFINED";
	}
}

void printState(STATES state) {
	std::cout << convertStateToString(state) << std::endl;
}

int main() {
	Automata automata;
	std::vector<std::string> menu = automata.getMenu();
	int menuCount = menu.size();

	for (int index = 0; index < menuCount; index++) {
		std::cout << index << ": " << menu[index] << std::endl;
	}
	std::cout << std::endl;

	printState(automata.getState());
	automata.on();
	printState(automata.getState());
	automata.coin(50);
	printState(automata.getState());
	automata.coin(50);
	printState(automata.getState());
	automata.choice(1);
	printState(automata.getState());
	automata.off();
	printState(automata.getState());

	return 0;
}
