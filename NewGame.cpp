#include "NewGame.h"

#include "Grid.h"
#include "Player.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

NewGame::NewGame(ApplicationManager* pApp) :Action(pApp)
{}

void NewGame::ReadActionParameters()
{
//Gadallah:no actions to be read from the user
}

void NewGame::Execute()
{
//Gadallah:reseting all players info x
	
	Grid* g = pManager->GetGrid();
	Output* pOut = g->GetOutput();
	g->UpdateInterface();
	CellPosition start;
	start.SetVCell(8);
	start.SetHCell(0);
	for (int i = 0; i < 4; i++)
	{
		Player* p = g->GetCurrentPlayer();
		p->SetWallet(100);
		p->setTurnCount(0);
		g->AdvanceCurrentPlayer();
		g->UpdatePlayerCell(p, start);

	}
	CardTen::pOwner = NULL;
	CardEleven::pOwner = NULL;
	CardTwelve::pOwner = NULL;
	CardThirteen::pOwner = NULL;
	CardFourteen::pOwner = NULL;
	g->resetCurr();
	g->SetEndGame(false);
}

NewGame::~NewGame()
{

}