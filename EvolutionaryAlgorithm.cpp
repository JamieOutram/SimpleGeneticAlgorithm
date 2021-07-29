/**
* Simple Evolutionary Algorithm 
* 
* Starting from a population of random strings, 
* uses random mutations and natural selection to match the target string.
* 
* For each new child, Two parents are selected at random and compete to reproduce.
* The winning parent creates a mutated copy of itself as a child for the next generation.
* 
* Individuals are scored according to how many of their letters match the target string.
*/

#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <string.h>
#include "Population.h"
#include "Individual.h"

#define POPULATION 100
#define MUTATION_FACTOR 70 //inverse of the mutation rate, effects the chance of a letter being mutated

using namespace std;

string charsToString(vector<char> input); 
vector<char> stringToChars(string input); 
void outputIndividuals(Population pop); 

int main()
{
	//Set seed
	//srand(0);
	srand(time(NULL));

	//Initialize target and population
	string targetString = "Methinks it is like a weasel";
	vector<char> targetChars = stringToChars(targetString);
	Population pop(POPULATION, targetChars.size());
	pop.ScoreMembers(targetChars);
	Individual* best = &pop.GetBestIndividual();
	//outputIndividuals(pop);

	//Loop for each generation until max fitness achieved
	int genCount = 0;
	int maxFittness = 0;
	while (static_cast<size_t>(best->score) < targetChars.size()) {
		//Initialize vector for new population
		vector<Individual> children;
		children.reserve(POPULATION);

		//Generate Children from current population
		for (int i = 0; i < POPULATION; i++) 
		{
			//Select two parents randomly
			int indexA = rand() % POPULATION;
			int indexB = rand() % POPULATION;
			while (indexA == indexB) indexB = rand() % POPULATION;
			Individual &memberA = pop.GetIndividual(indexA);
			Individual &memberB = pop.GetIndividual(indexB);

			//Pit the two against one another and allow winner to reproduce by comparing score
			if (memberA.score > memberB.score) 
			{
				children.push_back(memberA.Mutate(MUTATION_FACTOR));
			}
			else 
			{
				children.push_back(memberB.Mutate(MUTATION_FACTOR));
			}
		}

		//Replace old population with newly generated population and score new population
		pop = Population(children);
		pop.ScoreMembers(targetChars);
		best = &pop.GetBestIndividual();

		//Output progress every 500 generations
		if (genCount % 500 == 0) {
			cout << "Generation: " << genCount << " MaxFittness: " << best->score << endl;
		}
		genCount++;
	}

	//Output final population and best performing individual
	cout << "Displaying Final Population\n";
	outputIndividuals(pop);
	cout << "Final Gen Count: " << genCount << " Best: " << charsToString(best->getText());
	return 0;
}

/// <summary>
/// Converts a vector of chars into a string
/// </summary>
string charsToString(vector<char> input) {
	string out(input.begin(), input.end());
	return out;
}

/// <summary>
/// Converts a string into a vector of chars 
/// </summary>
vector<char> stringToChars(string input) {
	vector<char> out(input.begin(), input.end());
	return out;
}

/// <summary>
/// Prints the index, text and score of every individual
/// </summary>
void outputIndividuals(Population pop) {
	for (int j = 0; j < POPULATION; j++) {
		cout << j << ". " << charsToString(pop.GetIndividual(j).getText()) << " Fit:" << pop.GetIndividual(j).score << endl;
	}
}