#pragma once


#include"Card.h"

class CardFive : public Card {


public:

	CardFive(const CellPosition&);

	void ReadCardParameters(Grid* pGrid);

	virtual ~CardFive();

	virtual void Save(ofstream& OutFile, int num);
	void Load(ifstream& InFile, Grid* pGrid);

	void Apply(Grid* , Player* );

};