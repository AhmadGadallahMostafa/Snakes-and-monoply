#include "CardSeven.h"
#include "Ladder.h"
#include"Snake.h"
#include<time.h>

CardSeven::~CardSeven() {



}


CardSeven::CardSeven(const CellPosition& pos) : Card(pos)
{

	cardNumber = 7;

}

void CardSeven::ReadCardParameters(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("New CardSeven");


	pOut->ClearStatusBar();


}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer) {

	Card::Apply(pGrid, pPlayer);

	Output* pOut = pGrid->GetOutput();
	srand((int)time(NULL));
	int diceNumber = 1 + rand() % 6;
	string s = to_string(diceNumber);
	pOut->PrintMessage("Dice value is " + s);
	pPlayer->Move(pGrid, diceNumber);

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

void CardSeven::Save(ofstream& outFile, int num)
{
	if (num == 3)
	{
		outFile << "7" << " " << position.GetCellNumFromPosition(position) << endl;

	}
	return;

}

void CardSeven::Load(ifstream& InFile, Grid* pGrid)
{
	int cellnumber;
	InFile >> cellnumber;

	CellPosition CellN(cellnumber);

	CardSeven* PC7 = new CardSeven(CellN);
	pGrid->AddObjectToCell(PC7);
}