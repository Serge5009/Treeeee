#pragma once

class Treeeee	//	Class for all treeeee objects
{
public:

	Treeeee();	//	Constructor that applies starting values

	int Size;
	int Day;
	int WoodCost;
	/*
	Different buffs and debuffs and variables for them
	*/

	bool PlantTree();
	int CutTree();

private:

	int Calculate();

};