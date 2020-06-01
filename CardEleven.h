#pragma  once
#include "Card.h"

class CardEleven : public Card
{
private:
	static int price;
	static int fees;
public:
	static Player* pOwner;
	CardEleven(const CellPosition &pos);

	virtual void ReadCardParameters(Grid *pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	void CardEleven::EditCardParameters(Grid *pGrid);

	virtual void Save(ofstream& OutFile, int num);
	virtual void Load(ifstream& inFromFile, Grid* pG);

	virtual ~CardEleven();
};