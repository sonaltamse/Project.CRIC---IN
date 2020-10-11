#include <iostream>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <unistd.h>
#include "team.h" //<string>,<vector>,'player.h'
class Game{
public:
	Game();
	int playersPerTeam,maxBalls,totalPlayers;
	std::string players[11];
	Team TeamA,TeamB;
	Team *battingTeam,*bowlingTeam,*tempTeam;
	Player *batsman,*bowler;
	bool isFirstInnings;
	void welcome();
	void showAllPlayers();
	int takeIntegerInput();
	void selectPlayers();
	bool validatePlayer(int);
	void showTeamPlayers();
	void toss();
	void tossChoice(Team);
	void startFirstInnings();
	void initializePlayers();
	void playInnings();
	void bat();
	bool validateInning();
	void showGameScoreCard();
	void startSecondInnings();
	void scoreBoard();
};


