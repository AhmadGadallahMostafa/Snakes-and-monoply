#include "CardOne.h"
#include <time.h>

CardOne::CardOne(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	Input* pIn = pGrid->GetInput();   Output* pOut = pGrid->GetOutput();

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	pOut->PrintMessage("New CardOne : Enter its wallet amount : ");
	walletAmount = pIn->GetInteger(pOut);

	while (walletAmount < 0) {


		pOut->PrintMessage("Please enter Positive value : ");

		walletAmount = pIn->GetInteger(pOut);


	}
	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar();


}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne

	Card::Apply(pGrid, pPlayer);

	if (walletAmount <= pPlayer->GetWallet()) {

		if (pPlayer->getRestrictions() == true) {

			pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);



			int diceNumber = 1 + rand() % 6;


			pPlayer->setRestrictions(false);
			pPlayer->Move(pGrid, diceNumber);
		}

		else {

			pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);
			pPlayer->setRestrictions(false);

		}



	}
	else {

		pPlayer->setRestrictions(true);


	}
}

void CardOne::EditCardParameters(Grid* pGrid) {



	Input* pIn = pGrid->GetInput(); Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("Enter the new wallet amount : ");
	walletAmount = pIn->GetInteger(pOut);

	while (walletAmount < 0) {


		pOut->PrintMessage("Please enter Positive value : ");

		walletAmount = pIn->GetInteger(pOut);


	}

	pOut->ClearStatusBar();
}

void CardOne::Save(ofstream& outFile, int num)
{
	if (num == 3)
	{
		outFile << "1" << " " << position.GetCellNumFromPosition(position) << " " << walletAmount << endl;

	}
	return;

}
void CardOne::Load(ifstream& InFile, Grid* pGrid)
{
	int cellnumber,decrementValue;
	InFile >> cellnumber;
	InFile >> decrementValue;

	CellPosition CellN(cellnumber);
	
	CardOne* PC1 = new CardOne(CellN);
	PC1->walletAmount = decrementValue;
	pGrid->AddObjectToCell(PC1);
}