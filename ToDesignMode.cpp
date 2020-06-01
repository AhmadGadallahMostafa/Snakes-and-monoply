#include "ToDesignMode.h"
#include"Grid.h"
#include"Player.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

ToDesignMode::ToDesignMode(ApplicationManager* pApp) :Action(pApp)
{}

void ToDesignMode::ReadActionParameters()
{
	//Gadallah:no actions to be read from the user
}

void ToDesignMode::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();

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
}

ToDesignMode::~ToDesignMode() {}