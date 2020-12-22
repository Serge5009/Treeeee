#include "TreeeeeClass.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

Treeeee::Treeeee()	//	Constructor
{
	Size = 0;		//	All trees are created as soon as game starts
	Day = 0;		//	But they have size of 0
					//	So they exist and don't exist at the same time

	WoodCost = 1;		//	The bigger the level the more money you get from cutting a tree
	Strength = 1;		//	Reduces the chance of loosing tree
	GrowthSpeed = 1;	//	Increases chance of growing twice faster;
}

	//	Public functions	//

void Treeeee::PlantTree(int& Money)
{
	Size = 1;	//	Tree starts with size of 1
	Day = 1;	//	It's its first day in this world
	Money -= 3;	//	Everything has a price
}

void Treeeee::CutTree(int& Money)
{
	int Revenue = Calculate();	//	Calculates revenue
	Money += Revenue;			//	Now you have some money
	Size = 0;					//	But treeeee is no more, it's sad(
}

	//	Private functions	//

int Treeeee::Calculate()
{
	int Result;
	Result = Size * (1 + 0.2 * WoodCost);
	return Result;
}

int Treeeee::FailChance()
{
	int Chance; 
	//	FailureChance = 80 * pow(1.07, TreeSize) - 100;		!!!OLD!!!
	Chance = 50 * pow(1.07, Size) - 70;	//	UNFINISHED	
	if (Chance < 10)
	{
		Chance = 10;
	}
	else if (Chance > 80)
	{
		Chance = 80;
	}
	return Chance;
}

void Treeeee::Grow()
{
	srand(time(0));
	if (Size > 0)
	{
		if (rand() % 100 + 1 - FailChance() < 0)
		{
			Size = 0;
			Day = 0;
		}
		else
		{
			Size++;
			Day++;
		}
	}
}