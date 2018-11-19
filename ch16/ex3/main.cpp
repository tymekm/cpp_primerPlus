#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::tolower;

const int NUM = 26;

int main()
{
    std::srand(std::time(0));
    std::ifstream infile;
    infile.open("./words", std::ios::in);
    vector<string> wordList;
    while (infile)
    {
	string temp;
	infile >> temp;
	wordList.push_back(temp);
    }

    char play;
    cout << "Will you play a game? <y/n> ";
    cin >> play;
    play = tolower(play);
    while (play == 'y')
    {
	string target = wordList[std::rand() % NUM];
	int length = target.length();
	string attempt(length, '-');
	string badchars;
	int guesses = 6;
	cout << "Guess my secret word. It has " << length
	    << " letters, and you guess\n"
	    << "one letter at a time. You get " << guesses
	    << " wrong guesses.\n";
	cout << "Your word: " << attempt << '\n';
	
	while (guesses > 0 && attempt != target)
	{
	    char letter;
	    cout << "Guess a letter: ";
	    cin >> letter;
	    if (badchars.find(letter) != string::npos)
	    {
		cout << "You already guesses that. Try again.\n";
		continue;
	    }
	    int loc = target.find(letter);
	    if (loc == string::npos)
	    {
		cout << "Oh, bad guess!\n";
		--guesses;
		badchars += letter;
	    }
	    else
	    {
		cout << "Good guess!\n";
		attempt[loc] = letter;
		loc = target.find(letter, loc + 1);
		while (loc != string::npos)
		{
		    attempt[loc] = letter;
		    loc = target.find(letter, loc + 1);
		}
	    }
	    cout << "Your word: " << attempt << '\n';
	    if (attempt != target)
	    {
		if (badchars.length() > 0)
		    cout << "Bad choices: " << badchars << '\n';
		cout << guesses << " bad guesses left\n";
	    }
	}
	if (guesses > 0)
	    cout << "That's right!\n";
	else
	    cout << "Sorry, the word is " << target << ".\n";
	cout << "Will you play again? <y/n> ";
	cin >> play;
	play = tolower(play);
    }

    cout << "Bye!\n";
    return 0;
}

