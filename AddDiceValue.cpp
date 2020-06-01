#include "AddDiceValue.h"
#include"Action.h"
#include "Grid.h"
#include "Player.h"
AddDiceValue::AddDiceValue(ApplicationManager* pApp) :Action(pApp)
{};

void AddDiceValue::ReadActionParameters()
{



}

void AddDiceValue::Execute()
{


	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	//Gadallah:checking if the game has ended
	if (pManager->GetGrid()->GetEndGame())
	{
		
		//Gadallah:if the condtion is found out to be true restart the game ;
		pOut->PrintMessage("Congrats you have won,a new game will be started ");
		CellPosition start;
		start.SetVCell(8);
		start.SetHCell(0);
		for (int i = 0; i < 4; i++)
		{
			Player* p = pGrid->GetCurrentPlayer();
			p->SetWallet(100);
			p->setTurnCount(0);
			pGrid->AdvanceCurrentPlayer();
			pGrid->UpdatePlayerCell(p, start);

		}
		CardTen::pOwner = NULL;
		CardEleven::pOwner = NULL;
		CardTwelve::pOwner = NULL;
		CardThirteen::pOwner = NULL;
		CardFourteen::pOwner = NULL;
		pGrid->resetCurr();
		pGrid->SetEndGame(false);
		return;
	}


	pOut->PrintMessage("Enter dice value between 1-6");
	int diceValue = pIn->GetInteger(pOut);
	//all of the upcming is done to valdiate the input of dice value 
	Player* p = pGrid->GetCurrentPlayer(); //pointer to player :gadallah
	Cell *c = p->GetCell();
	CellPosition cp = c->GetCellPosition();
	int cellNumber = cp.GetCellNumFromPosition(cp);


	while (diceValue + cellNumber > 99) //gadallah:For valdiation of dice value input
	{
		pOut->PrintMessage("Error ! Invalid dice value , Reenter dice value");
		 diceValue = pIn->GetInteger(pOut);
	}
	while (diceValue > 6 || diceValue < 1) //Gadallah:the second valdiation of input
	{
		pOut->PrintMessage("Error ! Invalid dice value , Reenter dice value");
		diceValue = pIn->GetInteger(pOut);
	}
	
		p->Move(pGrid, diceValue);
		pGrid->AdvanceCurrentPlayer();
	

}

AddDiceValue::~AddDiceValue()
{}