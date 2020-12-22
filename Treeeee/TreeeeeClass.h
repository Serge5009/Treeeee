#pragma once

class Treeeee	//	Class for all treeeee objects
{
public:

	Treeeee();	//	Constructor that applies starting values

	int Size;
	int Day;
	
	/*
	Different buffs and debuffs and variables for them
	*/

	int WoodCost;
	int Strength;
	int GrowthSpeed;

	void PlantTree(int& Money);
	void CutTree(int& Money);
	void Grow(int Ran);

	int GetFailChance();
private:

	int Calculate();
	int FailChance();

};