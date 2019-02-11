/*
 * Norman Nguyen
 * CSC215
 * Program: Code Breaker/Keywords: 
 */
#include <iostream>
#include <String>
#include <cstdlib>
#include <ctime>
//Standard Library
using namespace::std;
//Main Function
void main()
{
	//We want to allow our agent to run  this simulation as many times as they need too.

	bool playAgain = false;// This is our flag/ switch to play again or not!

	//Introduction and list of commands
	cout << "\n\nWelcome to the Code Breaking Simulation."; 
	cout << "\n\nType You're now working for the CIA and we need you to unscramble the words given.";
	cout << "\nType 'hint' for Hints.";
	cout << "\nType 'pass' to pass to a different word.";
	//Remember each play is 3 turns.
	//do stuff here over and over as long as play it again = true;
	do
	{

	//Run simulation three times (turns)
	//3 items in our for loop
	//Where do we start aka init the var we will use
	//Where do we go, or where do we stop?
	//How will you get there? We are going to get there one step at a time, or one turn in this case at a time.

		for (int i = 0; i < 3; i++)
		{
			cout << "\nAgent you are on turn #" << i + 1 << " of 3. You got this!" << endl;
			enum fields { WORD, HINT, NUM_FIELDS };
			//Change this number to match our new number of word and hints!
			const int NUM_WORDS = 10;
			//List of 10 words.
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{
				{ "secret", "Classified stuff"},
				{ "computer", "Terminal for information"},
				{ "agent", "Coolest person on the planet! Like Archer"},
				{ "handler", "controls double agents"},
				{ "drop", "Package exchange"},
				{ "operation", "Work assignment"},
				{ "Mission", "Should you choose to accept this"},
				{ "Martini", "Shaken not stirred"},
				{ "Gun", "Target practice"},
				{ "Knife", "spreading butter"},
			};
			//Picking random words
			srand(static_cast<unsigned int>(time(0)));
			//Add Random for list of words
			int choice = (rand() % NUM_WORDS);
			string theWord = WORDS[choice][WORD];
			string theHint = WORDS[choice][HINT];
			//String word ties to theWord
			string wordScramble = theWord;
			//Length size of the word.
			int length = wordScramble.size();
			//For Loop where the words will be scrambled and you have to decrypt them.
			for (int j = 0; j < length; j++)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = wordScramble[index1];
				wordScramble[index1] = wordScramble[index2];
				wordScramble[index2] = temp;
			}
			//Shows the scrambled word.
			cout << "Here's your cryptic code: " << wordScramble;
			//This is where you type the word.
			string guess;
			cout <<"\n\nType in your guess: ";
			cin >> guess;
			//While loop to write out the word or pass to a another one.
			while ((guess != theWord) && (guess != "pass"))
			{
				//Hint
				if (guess == "hint")
				{
					cout << "\nYour Hint: " << theHint;
				}
				//Incorrect
				else
				{
					cout << "\nYour guess is incorrect.";
				}
				//Type your guess.
				cout << "\n\nType in your guess: ";
				cin >> guess;
			}
			//If the word is correct, you be congratulated.
			if (guess == theWord)
			{
				cout << "\n\nPerfect!!" << endl;
			}
		}
		//This is the choice on whether you want to play again or no.
		cout << "Would you like to r un the simulation again? (Y/N) ";
		char playerChoice;
		cin >> playerChoice;
		//Yes
		if (playerChoice == 'y' || playerChoice == 'Y')
		{
			playAgain = true;
		}
		//No
		else
		{
			//Allow simulation to finish
			playAgain = false;
		}
	} while (playAgain == true);
	//Simulation Summary
	cout << "\nThanks for playing.\n";
	system("pause");
}