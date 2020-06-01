#pragma once
#include "Card.h"


class CardTwo : public Card
{
	
	int walletAmount; 

public:
	CardTwo(const CellPosition& pos);

    void ReadCardParameters(Grid* pGrid); 

    void Apply(Grid* pGrid, Player* pPlayer); 

	
	virtual ~CardTwo(); 

	virtual void Save(ofstream& OutFile, int num);
	void Load(ifstream& InFile, Grid* pGrid);

	void EditCardParameters(Grid*);
};
