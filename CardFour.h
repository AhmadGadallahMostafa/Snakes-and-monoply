#pragma once


# include"Card.h"

class CardFour : public Card {




public:

	CardFour(const CellPosition&);

	void Apply(Grid*, Player*);

	virtual ~CardFour();
	
	virtual void Save(ofstream& OutFile, int num);
	void Load(ifstream& InFile, Grid* pGrid);

	void ReadCardParameters(Grid*);
};