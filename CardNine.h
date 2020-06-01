#pragma once



#include"Card.h"

class CardNine : public Card {

	int cellnumber;

public:

	CardNine(const CellPosition&);

	void ReadCardParameters(Grid* pGrid);

	virtual ~CardNine();

	void Apply(Grid*, Player*);

	virtual void Save(ofstream& OutFile, int num);
	void Load(ifstream& InFile, Grid* pGrid);
	
	void EditCardParameters(Grid*);
};
