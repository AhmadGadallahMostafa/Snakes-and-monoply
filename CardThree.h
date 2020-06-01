#pragma once

# include"Card.h"

class CardThree: public Card {


	

public:

	CardThree(const CellPosition&);

	void Apply(Grid* , Player* );

	virtual ~CardThree();

	virtual void Save(ofstream& OutFile, int num);
	void Load(ifstream& InFile, Grid* pGrid);

	void ReadCardParameters(Grid*);
};