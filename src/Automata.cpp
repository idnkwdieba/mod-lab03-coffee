// Copyright 2022 UNN-IASR
#include "Automata.h"

Automata::Automata() {
	cash = 0;
	menu = { "Coffee", "Tea", "HotWater" };
	prices = { 60, 35, 15 };
	state = OFF;
}

void Automata::on() {
 if (state != OFF) {
  return;
 }
 state = WAIT;
}

void Automata::off() {
 if (state != WAIT) {
  return;
 }

 state = OFF;
}

void Automata::coin(int coins) {
 if ((state != WAIT && state != ACCEPT) || coins <= 0) {
  return;
 }

 state = ACCEPT;
 cash += coins;
}

std::vector<std::string> Automata::getMenu() {
 return menu;
}

STATES Automata::getState() {
 return state;
}

void Automata::choice(int choice) {
 if (state != ACCEPT || choice < 0 || choice >= menu.size()) {
  return;
 }

 check(choice);
}

void Automata::check(int choice) {
 state = CHECK;

 if (cash < prices[choice]) {
  cancel();
  }

 cook(choice);
}

void Automata::cancel() {
 if (state != ACCEPT && state != CHECK) {
  return;
 }

 state = WAIT;
}

void Automata::cook(int choice) {
 state = COOK;
 cash -= prices[choice];

 finish();
}

void Automata::finish() {
	state = WAIT;
}
