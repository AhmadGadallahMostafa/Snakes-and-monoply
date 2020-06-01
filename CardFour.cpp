#include "CardFour.h"
#include"Snake.h"
CardFour::CardFour(const CellPosition& pos) :Card(pos) {



	cardNumber = 4; // sets the card number 


}
void CardFour::Apply(Grid* pGrid, Player* pPlayer) {



	Card::Apply(pGrid, pPlayer);

	Cell* x;
	x = pPlayer->GetCell(); // return the cell of pPlayer

	CellPosition y;
	y = x->GetCellPosition(); //return the cell position of pPlayer

	if (pGrid->GetNextSnake(y)) {



		pGrid->UpdatePlayerCell(pPlayer, ((pGrid->GetNextSnake(y))->GetPosition())); // The Action of Card Four
		(pGrid->GetNextSnake(y))->Apply(pGrid, pPlayer);
	}
}


CardFour::~CardFour() {

}

void CardFour::ReadCardParameters(Grid* pGrid) {

	Output* pOut = pGrid->GetOutput();


	pOut->PrintMessage("New CardFour");

	pOut->ClearStatusBar();

}

void CardFour::Save(ofstream& outFile, int num)
{
	if (num == 3)
	{
		outFile << "4" << " " << position.GetCellNumFromPosition(position) << endl;

	}
	return;

}

void CardFour::Load(ifstream& InFile, Grid* pGrid)
{
	int cellnumber;
	InFile >> cellnumber;

	CellPosition CellN(cellnumber);

	CardFour* PC4 = new CardFour(CellN);
	pGrid->AddObjectToCell(PC4);
}