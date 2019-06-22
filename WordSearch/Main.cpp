#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> wordsToCount;
	vector<string>* paragraph = new vector<string>;

	ifstream wordsFile("words.txt");
	ifstream paragraphFile("paragraph.txt");

	string input = "";

	if (wordsFile.is_open())
	{
		// Run algorithm
		while (getline(wordsFile, input))
		{
			wordsToCount.push_back(input);
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

	for (string word : *paragraph)
	{
		int count = 0;
		for (string wordFind : wordsToCount)
		{
			transform(word.begin(), word.end(), word.begin(), toupper);
			transform(wordFind.begin(), wordFind.end(), wordFind.begin(), toupper);
			
			if (word == wordFind)
			{
				cout << wordFind << endl;
			}
		}
	}
	cout << endl;
	system("pause");
	return 0;
}