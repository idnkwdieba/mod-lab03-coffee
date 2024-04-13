// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataOnTest, ChangesState) {
	Automata automata;

	automata.on();

	EXPECT_EQ(WAIT, automata.getState());
}

TEST(AutomataOnTest, HandlesWrongState) {
	Automata automata;
	automata.on();
	automata.coin(1);

	automata.on();

	EXPECT_EQ(ACCEPT, automata.getState());
}

TEST(AutomataOffTest, ChangesState) {
	Automata automata;
	automata.on();

	automata.off();

	EXPECT_EQ(OFF, automata.getState());
}

TEST(AutomataOffTest, HandlesWrongState) {
	Automata automata;
	automata.on();
	automata.coin(1);

	automata.off();

	EXPECT_EQ(ACCEPT, automata.getState());
}

TEST(AutomataCoinTest, HandlesWrongState) {
	Automata automata;

	automata.coin(1);

	EXPECT_EQ(OFF, automata.getState());
}

TEST(AutomataCoinTest, HandlesWrongValue) {
	Automata automata;
	automata.on();

	automata.coin(-1);

	EXPECT_EQ(WAIT, automata.getState());
}

TEST(AutomataCoinTest, ChangesState) {
	Automata automata;
	automata.on();

	automata.coin(1);

	EXPECT_EQ(ACCEPT, automata.getState());
}

TEST(AutomataChoiceTest, HandlesWrongState) {
	Automata automata;

	automata.choice(1);

	EXPECT_EQ(OFF, automata.getState());
}

TEST(AutomataChoiceTest, HandlesWrongChoice) {
	Automata automata;
	automata.on();
	automata.coin(1);

	automata.choice(-1);

	EXPECT_EQ(ACCEPT, automata.getState());
}

TEST(AutomataCancelTest, HandlesWrongState) {
	Automata automata;

	automata.cancel();

	EXPECT_EQ(OFF, automata.getState());
}
