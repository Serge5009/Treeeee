#include "TreeeeeClass.h"

Treeeee::Treeeee()	//	Constructor
{
	Size = 0;		//	All trees are created as soon as game starts
	Day = 0;		//	But they have size of 0
	WoodCost = 1;	//	So they exist and don't exist at the same time
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
	Result = Size * WoodCost;
	return Result;
}