#pragma  once
#include "Card.h"

class CardFourteen : public Card
{
private:
	static int price;
	static int fees;
public:
	static Player* pOwner;
	CardFourteen(const CellPosition &pos);

	virtual void ReadCardParameters(Grid *pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	void CardFourteen::EditCardParameters(Grid *pGrid);

	virtual void Save(ofstream& OutFile, int num);
	virtual void Load(ifstream& inFromFile, Grid* pG);

	virtual ~CardFourteen();
};