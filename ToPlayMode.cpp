#include "ToPlayMode.h"
#include"Grid.h"
#include"Player.h"
ToPlayMode::ToPlayMode(ApplicationManager* pApp) :Action(pApp)
{}

void ToPlayMode::ReadActionParameters()
{
	//Gadallah:no actions to be read from the user
}

void ToPlayMode::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreatePlayModeToolBar();
	
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
	pGrid->resetCurr();
	pGrid->SetEndGame(false);
}


ToPlayMode::~ToPlayMode() {}