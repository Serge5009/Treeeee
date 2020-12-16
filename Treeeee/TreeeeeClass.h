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

	void PlantTree(int& Money);
	void CutTree(int& Money);

private:

	int Calculate();

};