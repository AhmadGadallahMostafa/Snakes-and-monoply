#pragma once


#include"Card.h"

class CardSeven : public Card {


public:

	CardSeven(const CellPosition&);

	void ReadCardParameters(Grid* pGrid);

	virtual ~CardSeven();

	void Apply(Grid*, Player*);

	virtual void Save(ofstream& OutFile, int num);
	void Load(ifstream& InFile, Grid* pGrid);

};
