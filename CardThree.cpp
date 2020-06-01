
#include "CardThree.h"
#include"Ladder.h"

CardThree::CardThree(const CellPosition& pos) :Card(pos) {



	cardNumber = 3; // sets the card number 


}
void CardThree::Apply(Grid* pGrid, Player* pPlayer) {



	Card::Apply(pGrid, pPlayer);

	Cell* x;
	x = pPlayer->GetCell(); // return the cell of pPlayer

	CellPosition y;
	y = x->GetCellPosition(); //return the cell position of pPlayer

	if (pGrid->GetNextLadder(y)) {



		pGrid->UpdatePlayerCell(pPlayer, ((pGrid->GetNextLadder(y))->GetPosition())); // The Action of cardThree

		(pGrid->GetNextLadder(y))->Apply(pGrid, pPlayer);
	}





}


CardThree::~CardThree() {

}

void CardThree::ReadCardParameters(Grid* pGrid) {

	Output* pOut = pGrid->GetOutput();


	pOut->PrintMessage("New CardThree");

	pOut->ClearStatusBar();

}
 void CardThree::Save(ofstream& outFile, int num)
 {
	 if (num == 3)
	 {
		 outFile << "3" << " " << position.GetCellNumFromPosition(position) << endl;

	 }
	 return;

 }
 void CardThree::Load(ifstream& InFile, Grid* pGrid)
 {
	 int cellnumber;
	 InFile >> cellnumber;

	 CellPosition CellN(cellnumber);

	 CardThree* PC3 = new CardThree(CellN);
	 pGrid->AddObjectToCell(PC3);
 }