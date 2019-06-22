#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	vector<string>* wordsToCount = new vector<string>;
	vector<string>* paragraph = new vector<string>;
	vector<int> wordCount;

	ifstream wordsFile("words.txt");
	ifstream paragraphFile("paragraph.txt");

	string input = "";

	if (wordsFile.is_open())
	{
		// Run algorithm
		while (getline(wordsFile, input))
		{
			wordsToCount->push_back(input);
			wordCount.push_back(0);
		}
		wordsFile.close();
	}
	else
	{
		cout << "File could not be opened\n";
	}

	if (paragraphFile.is_open())
	{
		while (paragraphFile >> input)
		{
			paragraph->push_back(input);
		}
		paragraphFile.close();
	}
	else
	{
		cout << "File could not be opened\n";
	}

	cout << "Welcome to the word counting program!\n\n";
	cout << "we will count some words from a file\n";
	cout << "and see if we can find the words in few paragraphs.\n\n";

	for (string word : *paragraph)
	{
		int count = 0;
		for (string wordFind : *wordsToCount)
		{
			int index = distance(wordsToCount->begin(), find(wordsToCount->begin(), wordsToCount->end(), wordFind));

			transform(word.begin(), word.end(), word.begin(), toupper);
			transform(wordFind.begin(), wordFind.end(), wordFind.begin(), toupper);

			if (word == wordFind)
			{
				if (index != distance(wordsToCount->begin(), wordsToCount->end()))
				{
					wordCount[index] += 1;
				}
			}
		}
	}

	for (string word : *wordsToCount)
	{
		int index = distance(wordsToCount->begin(), find(wordsToCount->begin(), wordsToCount->end(), word));
		if (index != distance(wordsToCount->begin(), wordsToCount->end()))
			cout << word << ": " << wordCount[index] << endl;
	}

	cout << "\n\n";

	system("pause");
	return 0;
}