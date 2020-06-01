#pragma  once
#include "Card.h"

class CardTwelve : public Card
{
private:
	static int price;
	static int fees;

public:
	static Player* pOwner;
	CardTwelve(const CellPosition &pos);

	virtual void ReadCardParameters(Grid *pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	void CardTwelve::EditCardParameters(Grid *pGrid);

	virtual void Save(ofstream& OutFile, int num);
	virtual void Load(ifstream& inFromFile, Grid* pG);

	virtual ~CardTwelve();
};