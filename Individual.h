#include <vector>
#include <random>

using namespace std;

#pragma once
/// <summary>
/// Represents a single member of a population, 
/// can produce a mutated version of itself 
/// </summary>
class Individual
{
public:
	Individual(int textLength);
	Individual(vector<char> text);
	Individual Mutate(int mutationFactor);
	vector<char> getText() { return text; };
	int score = 0;

private:
	int textLength;
	vector<char> text;
};

