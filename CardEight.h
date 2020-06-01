#pragma once


#include"Card.h"

class CardEight : public Card {


public:

	CardEight(const CellPosition&);

	void ReadCardParameters(Grid* pGrid);

	virtual ~CardEight();

	void Apply(Grid*, Player*);

	virtual void Save(ofstream& OutFile, int num);
	void Load(ifstream& InFile, Grid* pGrid);

};
