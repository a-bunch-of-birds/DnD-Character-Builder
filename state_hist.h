#ifndef STATE_HIST_H
#define STATE_HIST_H

#include <vector>

class state_history
{
private:
	std::vector<int> scores_rolled;
	std::vector<int> scores_sorted;
	int species_selec;
	int subspecies_selec;
	int clss_selec;
	int level;
	bool rolled;
	bool sorted;
	bool species;
	bool subspecies;
	bool clss;
	//bool level;
public:

};


#endif STATE_HIST_H