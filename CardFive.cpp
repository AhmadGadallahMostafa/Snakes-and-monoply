#include "CardFive.h"
#include "Ladder.h"
#include "Snake.h"

CardFive::~CardFive() {



}


CardFive::CardFive(const CellPosition& pos) : Card(pos)
{

	cardNumber = 5;

}

void CardFive::ReadCardParameters(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("New CardFive");


	pOut->ClearStatusBar();


}

void CardFive::Apply(Grid* pGrid, Player* pPlayer) {


	Card::Apply(pGrid, pPlayer);

	Cell* x;

	x = pPlayer->GetCell(); // returns pointer to the cell of pPlayer

	CellPosition y;

	y = x->GetCellPosition(); // retrun cellposition of pPlayer

	int w = y.GetCellNum(); // return cell number of pPlayer

	int d = pPlayer->GetJustRolledDiceNumber(); // return just dice number of the pPlayer;

	int cellnumber = w + d; // the cell number the player should move to after the effect of the card

	y = y.GetCellPositionFromNum(cellnumber); // returns the new cell position of the pPlayer

	pGrid->UpdatePlayerCell(pPlayer, y); // the effect of card five

	Cell* p = pPlayer->GetCell();

	if (p->HasLadder()) {


		(p->HasLadder())->Apply(pGrid, pPlayer);

	}
	if (p->HasSnake()) {


		(p->HasSnake())->Apply(pGrid, pPlayer);


	}
	if (p->HasCard()) {

		(p->HasCard())->Apply(pGrid, pPlayer);

	}


}


void CardFive::Save(ofstream& outFile, int num)
{
	if (num == 3)
	{
		outFile << "5" << " " << position.GetCellNumFromPosition(position) << endl;

	}
	return;

}

void CardFive::Load(ifstream& InFile, Grid* pGrid)
{
	int cellnumber;
	InFile >> cellnumber;

	CellPosition CellN(cellnumber);

	CardFive* PC5 = new CardFive(CellN);
	pGrid->AddObjectToCell(PC5);
}
