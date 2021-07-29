#include "Population.h"

/// <summary>
/// Creates a new population with random individuals
/// </summary>
/// <param name="size"> - the number of random individuals to create</param>
/// <param name="targetLength"> - the target string the population is scored against</param>
Population::Population(int size, int targetLength)
{
	members.clear();
	for (int i = 0; i < size; i++) {
		Individual indiv(targetLength);
		members.push_back(indiv);
	}
}

/// <summary>
/// Creates a new population from the provided Individuals
/// </summary>
/// <param name="members"> - Vector of Individuals for the population</param>
Population::Population(const vector<Individual> &members)
{
	Population::members = members;
}

/// <summary>
/// Finds and returns the best scoring individual in the population
/// </summary>
Individual &Population::GetBestIndividual()
{
	int bestIndex = 0;
	int bestScore = 0;
	for (int i = 0; i < size(); i++) {
		if (bestScore < GetIndividual(i).score) {
			bestScore = GetIndividual(i).score;
			bestIndex = i;
		}
	}
	return GetIndividual(bestIndex);
}

/// <summary>
/// Calculates and assigns scores for each Individual in the population
/// </summary>
/// <param name="target">- The target characters to score against</param>
void Population::ScoreMembers(vector<char> &target)
{
	for (int i = 0; i < size(); i++) 
	{
		Individual &indiv = GetIndividual(i);
		vector<char> text = indiv.getText();
		int length = text.size();
		indiv.score = 0;
		for (int j = 0; j < length; j++) {
			if (text[j] == target[j]) indiv.score++;
		}
	}
}
