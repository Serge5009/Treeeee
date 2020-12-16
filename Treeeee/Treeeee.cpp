#include "TreeeeeClass.h"

Treeeee::Treeeee()	//	Constructor
{
	Size = 0;
	Day = 1;
	WoodCost = 1;
}

	//	Public functions	//

bool Treeeee::PlantTree()
{
	bool isPlanted = false;
	return isPlanted;
}

int Treeeee::CutTree()
{
	int Revenue = Calculate();

	Size = 0;

	return Revenue;
}

	//	Private functions	//

int Treeeee::Calculate()
{
	int Result;
	Result = Size * WoodCost;
	return Result;
}