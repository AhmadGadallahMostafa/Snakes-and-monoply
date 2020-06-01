#include "CardFourteen.h"
#include <fstream>
CardFourteen::CardFourteen(CellPosition const &pos) : Card(pos)
{
	cardNumber = 14;
}

int CardFourteen::price = 0;
int CardFourteen::fees = 0;
Player* CardFourteen::pOwner = NULL;

void CardFourteen::ReadCardParameters(Grid *pGrid)
{
	Input *pIn = pGrid->GetInput();
	Output *pOut = pGrid->GetOutput();
	if (price == 0 && fees == 0)
	{
		pOut->PrintMessage("New CardFourteen: Please enter price of station");
		int test = pIn->GetInteger(pOut);
		while (test < 0)
		{
			pOut->PrintMessage("Please enter a positive number for price");
			test = pIn->GetInteger(pOut);
		}
		price = test;
		pOut->PrintMessage("Please enter fees to for players to pay");
		test = pIn->GetInteger(pOut);
		while (test < 0)
		{
			pOut->PrintMessage("Please enter a positive number for fees");
			test = pIn->GetInteger(pOut);
		}
		fees = test;
		pOut->ClearStatusBar();
	}
}
void CardFourteen::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Input *pIn = pGrid->GetInput();
	Output *pOut = pGrid->GetOutput();
	if (pOwner == NULL)
	{
		if (pPlayer->GetWallet() < price)
		{
			pOut->PrintMessage("Insufficient funds can't buy card");
			return;
		}
		pOut->PrintMessage("you have reached a station. Do you want to buy it? y/n?");
		string answer = pIn->GetSrting(pOut);
		if (answer == "y")
		{

			pPlayer->SetWallet(pPlayer->GetWallet() - price);
			pOwner = pPlayer;
			return;
		}
		if (answer == "n")
		{
			return;
		}
	}
	if (pPlayer == pOwner)
	{
		pOut->PrintMessage("Player is owner of card. Click to continue");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	else
	{
		pOut->PrintMessage("you have reached a bought station. Click to continue?");
		int x, y;
		pIn->GetPointClicked(x, y);									//mesh 3aref lesa sa7 wala la2 to wait for click
		if (fees <= pPlayer->GetWallet()) {

			if (pPlayer->getRestrictions() == true)
			{

				pPlayer->SetWallet(pPlayer->GetWallet() - fees);
				pOwner->SetWallet(pOwner->GetWallet() + fees);



				int diceNumber = 1 + rand() % 6;


				pPlayer->setRestrictions(false);
				pPlayer->Move(pGrid, diceNumber);
			}

			else 
			{

				pPlayer->SetWallet(pPlayer->GetWallet() - fees);
				pOwner->SetWallet(pOwner->GetWallet() + fees);
				pPlayer->setRestrictions(false);

			}



		}
		else 
		{

			pPlayer->setRestrictions(true);


		}
		pOut->ClearStatusBar();
	}
}

void CardFourteen::EditCardParameters(Grid *pGrid)
{
	Input *pIn = pGrid->GetInput();
	Output *pOut = pGrid->GetOutput();
	pOut->PrintMessage("Please enter new card price");
	int test = pIn->GetInteger(pOut);
	while (test < 0)
	{
		pOut->PrintMessage("Please enter a positive number for price");
		test = pIn->GetInteger(pOut);
	}
	price = test;
	pOut->PrintMessage("Please enter fees to for players to pay");
	test = pIn->GetInteger(pOut);
	while (test < 0)
	{
		pOut->PrintMessage("Please enter a positive number for fees");
		test = pIn->GetInteger(pOut);
	}
	fees = test;
	pOut->ClearStatusBar();
}

void CardFourteen::Save(ofstream& outFile, int num)
{
	if (num == 3)
	{
		outFile << "14" << " " << position.GetCellNumFromPosition(position) << " " << price << " " << fees << endl;

	}
	return;

}

void CardFourteen::Load(ifstream& InFile, Grid* pGrid)
{
	int cellnumber, price, fees;
	InFile >> cellnumber >> price >> fees;

	CellPosition CellN(cellnumber);

	CardFourteen* PC14 = new CardFourteen(CellN);
	PC14->price = price; PC14->fees = fees;
	pGrid->AddObjectToCell(PC14);
}


CardFourteen::~CardFourteen()
{

}