#pragma  once
#include "Card.h"

class CardTen : public Card
{
private:
	static int price;
	static int fees;
protected:

public:
	static Player* pOwner;
	CardTen(const CellPosition &pos);
	
	virtual void ReadCardParameters(Grid *pGrid);
	
	virtual void Apply(Grid* pGrid, Player* pPlayer);

	void CardTen::EditCardParameters(Grid *pGrid);

	virtual void Save(ofstream& OutFile, int num);
	virtual void Load(ifstream& inFromFile, Grid* pG);

	virtual ~CardTen();
};