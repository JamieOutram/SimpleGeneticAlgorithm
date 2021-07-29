#include "Individual.h"

/// <summary>
/// Creates a new random individual with a given text length
/// </summary>
/// <param name="textLength"> - Text length of the new individual</param>
Individual::Individual(int textLength)
{
	Individual::score = 0;
	Individual::textLength = textLength;
	for (int i = 0; i < textLength; i++) {
		text.push_back(rand() % (126 - 31) + 31);
	}
}

/// <summary>
/// Creates a new individual with the given text
/// </summary>
/// <param name="text">- Text of the individual</param>
Individual::Individual(vector<char> text)
{
	Individual::score = 0;
	Individual::textLength = text.size();
	Individual::text = text;
}

/// <summary>
/// Creates a copy of the individual with mutations
/// </summary>
/// <param name="mutationFactor">Inverse of mutation rate, effects how often mutations occur</param>
Individual Individual::Mutate(int mutationFactor)
{
	vector<char> output;
	output.reserve(textLength);

	for (int i = 0; i < textLength; i++) {
		if (rand() % mutationFactor == 0) {
			output.push_back(rand() % (126 - 31) + 31);
		}
		else {
			output.push_back(text[i]);
		}
	}
	return Individual(output);
}
