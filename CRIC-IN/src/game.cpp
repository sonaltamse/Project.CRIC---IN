#include "game.h"
using namespace std;

Game::Game(){
	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "Aniket";
	players[1] = "Bhuvan";
	players[2] = "Chetan";
	players[3] = "Daniel";
	players[4] = "Elish";
	players[5] = "Fenny";
	players[6] = "Gordan";
	players[7] = "Henry";
	players[8] = "Ishant";
	players[9] = "Javed";
	players[10] = "Kamal";

	isFirstInnings = false;
	TeamA.name = "Team-A";
	TeamB.name = "Team-B";
}

void Game::welcome(){
	cout<<"\t\t--------------------------------"<<endl;
	cout<<"\t\t|============CRIC-IN============|"<<endl;
	cout<<"\t\t|Welcome To Virtual Cricket Game|"<<endl;
	cout<<"\t\t--------------------------------\n\n"<<endl;

	cout<<"\t\t|-------------------------------------------|"<<endl;
	cout<<"\t\t|===========================================|"<<endl;
	cout<<"\t\t|----------------INSTRUCTIONS---------------|"<<endl;
	cout<<"\t\t|===========================================|"<<endl;
	cout<<"\t\t|-------------------------------------------|"<<endl;
	cout<<"\t\t|1.Create 2 teams(Team-A and Team-B) with 4 |"<<endl;
	cout<<"\t\t|  players form a given pool of 11 players. |"<<endl;
	cout<<"\t\t|2.Lead the toss and decide the play type.  |"<<endl;
	cout<<"\t\t|3.Each innings of 6 balls.                 |"<<endl;
	cout<<"\t\t|-------------------------------------------|"<<endl;
}

void Game::showAllPlayers(){

	cout<<"\t\t--------------------------------"<<endl;
	cout<<"\t\t|========Pool of Players========|"<<endl;
	cout<<"\t\t--------------------------------"<<endl;
	for(int i=0; i<totalPlayers;++i){
			cout<<"\t\t\t"<<"["<<i<<"]"<<"  "<<players[i]<<"\n";
	}
}

int Game::takeIntegerInput(){

	int n;
	while(!(cin>>n)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"\n\t\tInvalid input! Please enter the valid input:";
	}

	return n;
}

bool Game::validatePlayer(int index){
	int n;

	std::vector<Player>players;
	//validating TeamA
	players = TeamA.players;
	n = players.size();
	for(int i = 0; i < n; i++)
	{
		if(players[i].id == index){
			return false;
		}
	}

	//validating TeamB
	players = TeamB.players;
	n = players.size();

	for (int i = 0;i < n; i++)
	{
		if(players[i].id == index){
			return false;
		}
	}
	return true;
}
void Game::selectPlayers(){

	cout<<"\n\n\t\t******************************************"<<endl;
	cout<<"\t\t|========Create Team-A AND Team-B========|"<<endl;
	cout<<"\t\t******************************************"<<endl;

	for (int i =0; i<playersPerTeam;i++)
	{
		//TeamA players
		teamASelection:
		cout<<"\n\t\tSelect Player "<<i+1 <<"of Team-A  -";
		int playerIndexTeamA = takeIntegerInput();

		if(playerIndexTeamA < 0 || playerIndexTeamA >10){
					cout<<"\t\tThere is no Player with this number.Please Select from the given Players pool"<<endl;
					goto teamASelection;
				}
		else if (!validatePlayer(playerIndexTeamA)){
					cout<<"This player has already been chosen.";
					goto teamASelection;
				}
		else{
			Player teamAPlayer;
		teamAPlayer.id = playerIndexTeamA;
		teamAPlayer.name = players[playerIndexTeamA];
		TeamA.players.push_back(teamAPlayer);
		}


		//TeamB players
		teamBSelection:
		cout<<"\n\t\tSelect Player "<<i+1 <<" of Team-B  -";
		int playerIndexTeamB = takeIntegerInput();

		if(playerIndexTeamB < 0 || playerIndexTeamB>10){
			cout<<"There is no Player with this number.\nPlease Select from the given Players pool"<<endl;
			goto teamBSelection;
		}
		else if (!validatePlayer(playerIndexTeamB)){
			Player teamBPlayer;
			cout<<"This player has already been chosen.";
			goto teamBSelection;
		}
		else{
			Player teamBPlayer;
		teamBPlayer.id = playerIndexTeamB;
		teamBPlayer.name = players[playerIndexTeamB];
		TeamB.players.push_back(teamBPlayer);
		}
	}
}

void Game :: showTeamPlayers(){

    cout << "--------------------------\t\t--------------------------" << endl;
    cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl;
    cout << "--------------------------\t\t--------------------------" << endl;

    for (int i = 0; i < playersPerTeam; i++) {
        cout << "|\t";
        cout << "[" <<i << "] " << TeamA.players[i].name << "\t |";
        cout << "\t\t|\t";
        cout << "[" << i<< "] " << TeamB.players[i].name << "\t |";
        cout << endl;
    }
    cout << "--------------------------\t\t--------------------------"<< endl;
}

void Game :: toss(){
	cout<<"\n\n\t\t******************************************"<<endl;
	cout<<"\t\t|===============Let's Toss=============|"<<endl;
	cout<<"\t\t******************************************"<<endl;

	int randomValue;
	srand(time(NULL));
	randomValue = rand()%2;

	cout<<"\t\tTossing the coin...\n\n"<<endl;
	sleep(5);
	switch(randomValue){
	case 0:cout<<"\t\tTeam-A won the toss\n"<<endl;
			tossChoice(TeamA);
			break;
	case 1:cout<<"\t\tTeam-B won the toss\n"<<endl;
		tossChoice(TeamB);
			break;
	}
}

void Game::tossChoice(Team tossWinnerTeam){
	cout<<"\t\tEnter 1 to Bat or 2 to Ball first."<<endl;
	cout<<"\t\t\t1.Bat"<<endl;
	cout<<"\t\t\t2.Ball"<<endl;

	int tossInput = takeIntegerInput();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	switch(tossInput){
	case 1:cout<<"\t\t"<<tossWinnerTeam.name<<" won the toss and elected to bat first."<<endl;
			if(tossWinnerTeam.name.compare("Team-A") == 0) //team A is the winner
			{
				battingTeam = &TeamA;
				bowlingTeam = &TeamB;
			}
			else{
				battingTeam = &TeamB;
				bowlingTeam = &TeamA;
			}
			break;
	case 2:cout<<"\t\t"<<tossWinnerTeam.name<<" won the toss and elected to ball first."<<endl;
			if(tossWinnerTeam.name.compare("Team-A") == 0) //team A is the winner
						{
							bowlingTeam = &TeamA;
							battingTeam = &TeamB;
						}
						else{
							bowlingTeam = &TeamB;
							battingTeam = &TeamA;
						}
			break;
	default:cout<<"\t\tInvalid input.Give another try"<<endl;
			tossChoice(tossWinnerTeam);
			break;
	}
}

void Game::startFirstInnings()
{
	cout<<"\n\n\t\t|||==============First Inning Starts===========|||"<<endl;
	isFirstInnings = true;
	initializePlayers();
	playInnings();
}

void Game::initializePlayers(){

	batsman = &battingTeam -> players[0];
	bowler = &bowlingTeam ->players[0];

	cout<<"\t\t"<<battingTeam->name<<" - "<<batsman->name<<" is batting"<<endl;
	cout<<"\t\t"<<bowlingTeam->name<<" - "<<bowler->name<<" is bowling"<<endl;
}

void Game::playInnings(){
	for(int i = 0; i<maxBalls;i++){
		cout<<"\t\tPress Enter to bowl."<<endl;
	getchar();
	cout<<"\t\tbowling..."<<endl;
	sleep(2);
	bat();
	validateInning();
	}
}

void Game::bat(){
	srand(time(NULL));
	int runsScored = rand()%7;

	//update batsman and batting team data
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed+1;

	//update bowler and bowling team data
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;

	if(runsScored != 0){
		cout<<"\t\t"<<bowler->name<<" to "<<batsman->name<<" "<<runsScored<<" runs!"<<endl;
		showGameScoreCard();
	}
	else{
		cout<<"\t\t"<<bowler->name<<" to "<<batsman->name<<" OUT!"<<endl;
		battingTeam->totalwktsLost = battingTeam->totalwktsLost + 1;
		bowler->wktsTaken = bowler->wktsTaken + 1;

		showGameScoreCard();
		//shifting the player
		int indexNextPlayer = battingTeam->totalwktsLost;
		batsman = &battingTeam->players[indexNextPlayer];
	}
}

bool Game::validateInning(){

	if(isFirstInnings){
		if(battingTeam->totalwktsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls){
			cout<<"\n\n\t\t|||==============First Inning Ends===========|||"<<endl;
			cout<<"\t\t"<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "<<battingTeam->totalwktsLost<<"("<<
					bowlingTeam->totalBallsBowled<<")"<<endl;
			cout<<"\t\t"<<bowlingTeam->name<<" needs "<<battingTeam->totalRunsScored+1<<" runs to win the match\n"<<endl;
			return false;
		}
	}
	else{
			while(battingTeam->totalwktsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
			{
				if(battingTeam->totalRunsScored > bowlingTeam->totalRunsScored){
					cout<<"\t\t"<<battingTeam->name<<" won the Match"<<endl;
					break;
				}
				else if(battingTeam->totalRunsScored == bowlingTeam->totalRunsScored){
					cout<<"\t\t"<<"Match Draw"<<endl;
					break;
				}
				else{
						cout<<"\n\t\t"<<bowlingTeam->name<<" Won the match"<<endl;
					}
				return false;
			}
	}
	return true;
}

void Game::showGameScoreCard(){
	cout<<"\t\t**************************************************************\n"<<endl;
	cout<<"\t\t\t"<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<"-"<<battingTeam->totalwktsLost<<"("<<
			bowlingTeam->totalBallsBowled<<")  | "<<batsman->name<<" "<<batsman->runsScored<<" ("<<
			batsman->ballsPlayed<<")\t"<<bowler->name<<" "<<bowler->ballsBowled<<" - "<<bowler->runsGiven<<
			"-"<<battingTeam->totalwktsLost<<endl;
	cout<<"\t\t**************************************************************\n"<<endl;
}

void Game::startSecondInnings()
{
	cout<<"\n\n\t\t|||==============Second Inning Starts===========|||"<<endl;
	isFirstInnings = false;
	//swapping the two teams for the next inning
	tempTeam = battingTeam;
	battingTeam = bowlingTeam;
	bowlingTeam = tempTeam;

	initializePlayers();
	playInnings();
	cout<<"\n\n\t\t==============|||Match Ends|||==========="<<endl;
	scoreBoard();
}

void Game::scoreBoard(){
	cout<<"\t\t"<<TeamA.name<<" "<<TeamA.totalRunsScored<<"-"<<TeamA.totalwktsLost<<" ("<<TeamB.totalBallsBowled<<")"<<endl;
	cout<<"\t\t=============================================="<<endl;
	cout<<"\t\t|PLAYERS\t\tBATTING\t\tBOWLING|"<<endl;
	for (int i=0; i<playersPerTeam;i++)
		{
			cout<<"\t\t|"<<TeamA.players[i].name<<"\t\t\t"<<TeamA.players[i].runsScored<<"("<<TeamA.players[i].ballsPlayed<<")\t\t"<<TeamA.players[i].ballsBowled<<"-"<<TeamA.players[i].runsGiven<<"-"<<TeamA.players[i].wktsTaken<<"|\n";
		}
	cout<<"\n\n";
	cout<<"\t\t"<<TeamB.name<<" "<<TeamB.totalRunsScored<<"-"<<TeamB.totalwktsLost<<" ("<<TeamB.totalBallsBowled<<")"<<endl;
	cout<<"\t\t=============================================="<<endl;
	cout<<"\t\t|PLAYERS\t\tBATTING\t\tBOWLING|"<<endl;
	for (int i=0; i<playersPerTeam;i++)
		{
			cout<<"\t\t|"<<TeamB.players[i].name<<"\t\t\t"<<TeamB.players[i].runsScored<<"("<<TeamB.players[i].ballsPlayed<<")\t\t"<<TeamB.players[i].ballsBowled<<"-"<<TeamB.players[i].runsGiven<<"-"<<TeamB.players[i].wktsTaken<<"|\n";
		}
}
