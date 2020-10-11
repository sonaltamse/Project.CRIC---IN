#include<vector>
#include "player.h" //<string>
class Team{
public:
	Team();
	std::string name;
	int totalRunsScored,totalwktsLost,totalBallsBowled;//totalBallsPlayedByOppositeTeam
	std::vector<Player> players;
};
