#include "CardEight.h"



CardEight::~CardEight() {



}


CardEight::CardEight(const CellPosition& pos) : Card(pos)
{

	cardNumber = 8;

}

void CardEight::ReadCardParameters(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("New CardEight");


	pOut->ClearStatusBar();


}

void CardEight::Apply(Grid* pGrid, Player* pPlayer) {

	Card::Apply(pGrid, pPlayer);


	pPlayer->setIsPrevented(true);//prevent the player from playing



}
void CardEight::Save(ofstream& outFile, int num)
{
	if (num == 3)
	{
		outFile << "8" << " " << position.GetCellNumFromPosition(position) << endl;

	}
	return;

}

void CardEight::Load(ifstream& InFile, Grid* pGrid)
{
	int cellnumber;
	InFile >> cellnumber;

	CellPosition CellN(cellnumber);

	CardEight* PC8 = new CardEight(CellN);
	pGrid->AddObjectToCell(PC8);
}