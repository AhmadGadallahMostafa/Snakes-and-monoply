#pragma  once
#include "Card.h"

class CardThirteen : public Card
{
private:
	static int price;
	static int fees;
public:
	static Player* pOwner;
	CardThirteen(const CellPosition &pos);

	virtual void ReadCardParameters(Grid *pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	void CardThirteen::EditCardParameters(Grid *pGrid);

	virtual void Save(ofstream& OutFile, int num);
	virtual void Load(ifstream& inFromFile, Grid* pG);

	virtual ~CardThirteen();
};