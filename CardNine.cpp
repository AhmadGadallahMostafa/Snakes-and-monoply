#include "CardNine.h"
#include"Ladder.h"
#include"Snake.h"


CardNine::~CardNine() {



}


CardNine::CardNine(const CellPosition& pos) : Card(pos)
{

	cardNumber = 9;

}

void CardNine::ReadCardParameters(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();  Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New CardNine : Enter cell number :");

	cellnumber = pIn->GetInteger(pOut);

	while (cellnumber < 1 || cellnumber > 99) {

		pOut->PrintMessage("Please enter cell number between 1 and 99 (inclusive) : ");

		cellnumber = pIn->GetInteger(pOut);

	}

	pOut->ClearStatusBar();


}

void CardNine::Apply(Grid* pGrid, Player* pPlayer) {

	Card::Apply(pGrid, pPlayer);

	CellPosition x;

	x = x.GetCellPositionFromNum(cellnumber); // Get the cell position of cell number entered in design mode


	pGrid->UpdatePlayerCell(pPlayer, x); // Action of CardNine

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

void CardNine::EditCardParameters(Grid* pGrid) {

	Input* pIn = pGrid->GetInput(); Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Enter the new cell number : ");
	cellnumber = pIn->GetInteger(pOut);

	while (cellnumber < 1 || cellnumber > 99) {

		pOut->PrintMessage("Please enter cell number between 1 and 99 (inclusive) : ");

		cellnumber = pIn->GetInteger(pOut);

	}

	pOut->ClearStatusBar();

}

void CardNine::Save(ofstream& outFile, int num)
{
	if (num == 3)
	{
		outFile << "9" << " " << position.GetCellNumFromPosition(position) << " " << cellnumber << endl;

	}
	return;

}

void CardNine::Load(ifstream& InFile, Grid* pGrid)
{
	int cellnumber,Tocellnumber;
	InFile >> cellnumber >> Tocellnumber;

	CellPosition CellN(cellnumber);

	CardNine* PC9 = new CardNine(CellN);
	PC9->cellnumber = Tocellnumber;
	pGrid->AddObjectToCell(PC9);
}