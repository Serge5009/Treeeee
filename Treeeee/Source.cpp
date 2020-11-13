#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>

//Serhii Marchenko (AKA Serge5009)
//2020.11.13
//	Thanks to Muhammet Ahmet Polat for participation!

using namespace std;

bool start();
void Game();
void Stats(int Planted, int Biggest, int Cut, int Lost, int N, int M);

int main()
{
	srand(time(0));
	bool isPlaying = start();	//"Do you wanna play" screen
	system("CLS");
	if (isPlaying)				//If yes		
	{
		Game();					//Starting game
	}
	else						//If no, why do you touch the game icon?! %$&@(
	{
		cout << "Ok, see you next time!\n\n";
	}
	return 0;
}

bool start()
{
	char UserInputStart = 'A';
	while (UserInputStart != 'Y' && UserInputStart != 'y' && UserInputStart != 'N' && UserInputStart != 'n')
	{
		system("CLS");
		cout << "\n\n\n\n\n\t\t\tWellcome to\n\n\t\t\t  \033[32mTREEEEE\033[37m\n\n\n\n\n\n";
		cout << "Type \033[32mY\033[37m to start, type \033[31mN\033[37m to exit...  \033[33m";
		cin >> UserInputStart;
		cout << "\033[37m";
		if (UserInputStart == 'Y' || UserInputStart == 'y')
		{
			return true;
		}
		else if (UserInputStart == 'N' || UserInputStart == 'n')
		{
			return false;
		}
	}
}
void Game()				//Main game loop
{
	int Day = 1;					//Day count
	int Money = 10;					//Money amount
	bool isGamePlyed = true;		//Main loop condition
	bool isTreePlanted = false;		//Do we have a tree now
	int TreeSize = 0;				//Size of a current tree
	char UserInput1 = 0;			//Variable for user's action
	int FailureChance = 0;			//Progressive failure chance

	//Variables for stats
	int TreesPlanted = 0;
	int BiggestTree = 0;
	int TreesCut = 0;
	int TreesLost = 0;

	const int TREECOST = 3;
	while (isGamePlyed) //One day cycle
	{
		FailureChance = 100 * pow(1.07, TreeSize) - 100;		//Formula for failure chance
		if (FailureChance >= 80)						//Limiting failure chance
		{
			FailureChance = 80;
		}

		system("CLS");
		cout << "\t\033[32mTREEEEE\033[37m - the game by Serge5009" << endl;
		cout << "\t\033[46m\033[30mDay: " << Day << "                                   Money: " << Money << " $        \033[37m\033[40m\n" << endl;
		cout << "\t" << endl;
		cout << "\tYour \033[32mTreeeee\033[37m:" << endl;
		if (isTreePlanted)
		{
			cout << "\033[102m\t|";
			for (int TreeBarSize = TreeSize; TreeBarSize > 0; TreeBarSize--)
			{
				cout << " |";
			}
			cout << "\033[40m" << endl;
			cout << "\t Size: " << TreeSize << endl;
			cout << "\t Chance of failure: " << FailureChance << "%" << endl;
		}
		else
		{
			cout << "\033[101m";
			cout << "\t Your Treeeee is not planted yet\033[40m" << endl;
			cout << "\t" << endl;
			cout << "\t" << endl;
		}
		cout << "\t" << endl;
		cout << "\t" << endl;

		cout << "\tNEWS:" << endl;
		cout << "\tTo be added" << endl;

		cout << "\t" << endl;
		cout << "\t" << endl;

		cout << "\tPossible actions:" << endl;

		if (isTreePlanted)
		{
			cout << "\t1. Cut the \033[32mTreeeee\033[37m." << endl;
		}
		else
		{
			cout << "\t1. Plant the \033[32mTreeeee\033[37m." << endl;
		}

		cout << "\t2. Wait till the next day..." << endl;
		cout << "\t3. Shop.  //To be added " << endl;

		cout << "\t";
		cin >> UserInput1;
		UserInput1 = (int)UserInput1;

		if (UserInput1 == '1') //Action for cutting or planting the treeeee
		{
			if (isTreePlanted) //If we already hava a treeeee,
			{				   //We we will cut it.
				Money += TreeSize;		//Sell the wood
				isTreePlanted = false;	//Tree is no more
				TreeSize = 0;			//So it's size is 0 now
				Day += 1;				//Cutting a treeeee takes a full day
			}
			else
			{
				if (Money >= TREECOST)	//If we don't have a treeeee yet
				{
					Money -= TREECOST;		//We will buy a seedling
					isTreePlanted = true;	//Plant the tree
					TreeSize = 1;			//It's small but exists
					Day += 1;				//It also takes a full day
					TreesPlanted += 1;		//We add 1 more tree to stats
				}
				else
				{

				}
			}
		}
		else if (UserInput1 == '2')
		{
			if (isTreePlanted)
			{



				int RandNum = rand() % 100 + 1;

				if (RandNum <= FailureChance)
				{
					TreeSize = -1;
					isTreePlanted = false;
				}

				TreeSize += 1;
				Day += 1;

			}
			else
			{
				Day += 1;
			}
		}
		else if (UserInput1 == '3')
		{

		}
		else
		{

		}

		if (Money < 3 && isTreePlanted == false)
		{
			isGamePlyed = false;
			Stats(TreesPlanted, BiggestTree, TreesCut, TreesLost, Day, Money);
		}

	}
}

void Stats(int Planted, int Biggest, int Cut, int Lost, int N, int M)
{
	system("CLS");
	cout << "Your stats:" << endl;
	cout << "Coming soon!" << endl;
}