#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>

#include "TreeeeeClass.h"

//Serhii Marchenko
//16.12.2020

using namespace std;

int DrawMenu(int NUM_TR, Treeeee TreeToPass[]);
void DrawTopLine();
void DrawTreeeees(int NUM, Treeeee tree[]);
int DrawDialogue();
void DrawTree(int N, int TREE_COST, Treeeee tree[]);
void TreeShop();
void NextDay(Treeeee tree[]);

	// Global Variables	//

int gMoney = 10;	//	Amount of money
int gDay = 1;	//	Day # 

const int TREEEEE_AMOUNT = 10;	//	Defines how many treeeees will be in the game
const float FAIL_CHANCE = 1;	//	Game difficulty (0 - creative mode, 1 - normal, more - hard)
const int TREE_COST = 3;		//	Cost of planting a tree (3 is recomended)


	//	MAIN	//

int main()
{
	
	Treeeee Tree[TREEEEE_AMOUNT];	//	Creating out treeeees, but their size is 0

	Tree[0].Size = 5;	// DEBUG AND TEST LINE


	while (true)
	{
		int PlayerAnswer = DrawMenu(TREEEEE_AMOUNT, Tree);
		if (PlayerAnswer == -1)
		{	//	QUIT
			break;
		}
		else if (PlayerAnswer == 0)
		{
			NextDay(Tree);
		}
		else if (PlayerAnswer > TREEEEE_AMOUNT)
		{	//	Wrong value, doing nothing

		}
		else
		{	//	Interracting with a tree
			DrawTree(PlayerAnswer, TREE_COST, Tree);
		}
	}


	return 0;
}

int DrawMenu(int NUM_TR, Treeeee TreeToPass[])	//	Draws main menu
{
	system("cls");	//	Clear console
	DrawTopLine();
	DrawTreeeees(NUM_TR, TreeToPass);
	return DrawDialogue();
}

void DrawTopLine()	//	Draws line with some info
{
	cout << "\033[46m";	//	Changing BG color to Cyan
	cout << "Treeeee                      Money: " << gMoney << "                         Day " << gDay;
	cout << "\033[40m" << endl;	//	Changing BG color to Black
}

void DrawTreeeees(int NUM, Treeeee tree[])	//	Draws all trees in a short form (Num + Size)
{
	for (int n = 0; n < NUM; n++)	//	Loops through all trees in the array 
	{
		cout << "\tTreeeee " << n+1 << ":" << endl;
			
		if (tree[n].Size > 0)
		{
			cout << "\033[42m|";	//	Starting symbol of the bar + color
			for (int N = 0; N < tree[n].Size; N++)
			{
				cout << " |";
			}
			cout << "\033[40m" << endl;	//	Ending the line + removing color
		}
		else
		{
			cout << "[NO TREE HERE]" << endl;
		}
	}
}

int DrawDialogue()
{
	int Decition = -1;
	cout << endl << endl << endl;
	cout << "\tType \"-1\" to quit, \"0\" to skip the day or" << endl;
	cout << "\tType N of Treeeee to intrerract with: ";
	cin >> Decition;
	return Decition;
}

void DrawTree(int N, int TREE_COST, Treeeee tree[])
{
	int n = N - 1;
	bool isLoopGoing = true;
	int UserInput;
	while (isLoopGoing)
	{
		system("cls");
		DrawTopLine();
		//	Drawing the same stuff as in main menu
		cout << "\tTreeeee " << n + 1 << ":" << endl;

		if (tree[n].Size > 0)	//	If tree is already planted
		{
			cout << "\033[42m|";	//	Starting symbol of the bar + color
			for (int N = 0; N < tree[n].Size; N++)
			{
				cout << " |";
			}
			cout << "\033[40m" << endl;	//	Ending the line + removing color
		}
		else	//	If tree is not planted yet
		{
			cout << "[NO TREE HERE]" << endl;
		}

		cout << "\tTreeeee size is " << tree[n].Size << endl;
		cout << "\tIt exist for " << tree[n].Day << " Days" << endl << endl;

		cout << "\tPossible actions: " << endl << endl;
		if (tree[n].Size < 1)	
		{
			cout << "\t1.\tPlant a new Treeeee" << endl;
		}
		else
		{
			cout << "\t1.\tCut the Treeeee." << endl;
		}
		cout << "\t2.\tBuy Treeeee upgrades" << endl;
		cout << "\t3.\tBack" << endl << "\t";
		cin >> UserInput;

		if (UserInput < 1 || UserInput > 3)
		{
			isLoopGoing = true;
		}
		else
		{
			isLoopGoing = false;
		}
	}
	if (UserInput == 1)	//	Cut or Plant tree
	{	
		if (tree[n].Size < 1)	//	If tree is not planted yet
		{	
			if (gMoney >= TREE_COST)	//	And if we have enough money
			{
				tree[n].PlantTree(gMoney);	//	Plant a tree
			}
		}
		else	//	if tree exists
		{
			tree[n].CutTree(gMoney);	//	Cut it
		}

	}
	if (UserInput == 2)	//	Shop
	{	//	Opening shop
		TreeShop();	//	TBA
	}
	if (UserInput == 3)	//	Quit
	{	//	Just letting to finish the function
		
	}
}

void TreeShop()
{
	int UserInput;
	cin >> UserInput;
}

void NextDay(Treeeee tree[])
{
	gDay++;
	for (int n = 0; n < TREEEEE_AMOUNT; n++)
	{
		tree[n].Grow();
	}
}

