#include "CardSix.h"

CardSix::~CardSix() {



}


CardSix::CardSix(const CellPosition& pos) : Card(pos)
{

	cardNumber = 6;

}

void CardSix::ReadCardParameters(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("New CardSix");


	pOut->ClearStatusBar();

	
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer) {


	Card::Apply(pGrid, pPlayer);

	Cell* x;

	x = pPlayer->GetCell(); // returns pointer to the cell of pPlayer

	CellPosition y;

	y = x->GetCellPosition(); // retrun cellposition of pPlayer

	int w = y.GetCellNum(); // return cell number of pPlayer

	int d = pPlayer->GetJustRolledDiceNumber(); // return just dice number of the pPlayer;

	int cellnumber = w - d; // the cell number the player should move to after the effect of the card

	y = y.GetCellPositionFromNum(cellnumber); // returns the new cell position of the pPlayer

	pGrid->UpdatePlayerCell(pPlayer, y); // the effect of card Six

}


void CardSix::Save(ofstream& outFile, int num)
{
	if (num == 3)
	{
		outFile << "6" << " " << position.GetCellNumFromPosition(position) << endl;

	}
	return;

}

void CardSix::Load(ifstream& InFile, Grid* pGrid)
{
	int cellnumber;
	InFile >> cellnumber;

	CellPosition CellN(cellnumber);

	CardSix* PC6 = new CardSix(CellN);
	pGrid->AddObjectToCell(PC6);
}