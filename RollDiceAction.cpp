#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager *pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
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
	// -- If not ended, do the following --:
	
	// 2- Generate a random number from 1 to 6 --> This step is done for you
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
	string s = to_string(diceNumber);
	pOut->PrintMessage("Dice value is "+s);
	// 3- Get the "current" player from pGrid
	Player *p =pGrid->GetCurrentPlayer();
	Cell* flag = p->GetCell();
	CellPosition c= flag->GetCellPosition();  //Gadallah valdiating if the player reached cell 99
	// 4- Move the currentPlayer using function Move of class player
	
	p->Move(pGrid, diceNumber);
	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

RollDiceAction::~RollDiceAction()
{
}
