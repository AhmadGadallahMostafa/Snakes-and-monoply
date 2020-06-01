#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) 
{
	cardNumber = 2; 
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{

	Input* pIn=pGrid->GetInput();   Output* pOut=pGrid->GetOutput();

	pOut->PrintMessage("New CardTwo : Enter its wallet amount : ");
	walletAmount = pIn->GetInteger(pOut);
	
	while (walletAmount < 0) {


		pOut->PrintMessage("Please enter Positive value : ");

		walletAmount = pIn->GetInteger(pOut);

	}


	pOut->ClearStatusBar();

	
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount); // increment the pPlayer wallet with walletamount

}

void CardTwo::EditCardParameters(Grid* pGrid) {

	Input* pIn = pGrid->GetInput(); Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Enter the new wallet amount : ");
	walletAmount = pIn->GetInteger(pOut);

	while (walletAmount < 0) {


		pOut->PrintMessage("Please enter Positive value : ");

		walletAmount = pIn->GetInteger(pOut);


	}

	pOut->ClearStatusBar();
}

void CardTwo::Save(ofstream& outFile, int num)
{
	if (num == 3)
	{
		outFile << "2" << " " << position.GetCellNumFromPosition(position) << " " << walletAmount << endl;

	}
	return;

}
void CardTwo::Load(ifstream& InFile, Grid* pGrid)
{
	int cellnumber, incrementValue;
	InFile >> cellnumber;
	InFile >> incrementValue;

	CellPosition CellN(cellnumber);

	CardTwo* PC2 = new CardTwo(CellN);
	PC2->walletAmount = incrementValue;
	pGrid->AddObjectToCell(PC2);
}