#pragma once


#include"Grid.h"

#include"Card.h"

class CardSix : public Card {


public:

	CardSix(const CellPosition&);

	 void ReadCardParameters(Grid* pGrid);
	 void Apply(Grid*, Player*);
	
	 virtual ~CardSix();
	
	 virtual void Save(ofstream& OutFile, int num);
	 void Load(ifstream& InFile, Grid* pGrid);
	

};