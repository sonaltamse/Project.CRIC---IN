//============================================================================
// Name        : CRIC-IN.cpp
// Author      : SONAL TAMSE
// Copyright   : Your copyright notice
// Description : Building Cricket Game Applictaion
//============================================================================

#include "game.h"
using namespace std;

int main() {
	Game g;
	g.welcome();
	cout<<"\n\n\t\t\tPress Enter to continue"<<endl;
	cin.get();
	g.showAllPlayers();
	cout<<"\n\n\t\t\tPress Enter to continue"<<endl;
	cin.get();
	g.selectPlayers();
	cout<<"\n\n";
	g.showTeamPlayers();
	cout<<"\n\n";
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout<<"\n\n\t\t\tPress Enter to continue"<<endl;
	cin.get();
	g.toss();
	g.startFirstInnings();
	cout<<"\n\n";
	g.startSecondInnings();
	return 0;
}
