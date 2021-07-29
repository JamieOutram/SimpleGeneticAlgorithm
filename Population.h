#include "Individual.h"
#include <vector>

using namespace std;

#pragma once
/// <summary>
/// A population contains and scores all of the individuals in a generation 
/// </summary>
class Population
{
public:
	Population(int size, int targetLength);
	Population(const vector<Individual> &members);
	Individual &GetIndividual(int index) { return members[index]; };
	Individual &GetBestIndividual();
	void ScoreMembers(vector<char> &target);
	int size() { return members.size(); };

private:
	vector<Individual> members;
};

