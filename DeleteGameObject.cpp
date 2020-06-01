#include "DeleteGameObject.h"
#include "Grid.h"
#include"ladder.h"
#include"Card.h"
#include"Snake.h"
DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) :Action(pApp)
{}

void DeleteGameObject::ReadActionParameters()
	{
	//gadallah:will read the click from the user to delete the game object in the excuete function
	Grid* g = pManager->GetGrid();
	Input* pIn = g->GetInput();
	Output* pOut = g->GetOutput();
	
	pOut->PrintMessage("Delete object :Click on the cell");
	deletedCellPosition = pIn->GetCellClicked();

	//Gadallah:clearing the status bar
	pOut->ClearStatusBar();
	}

void DeleteGameObject::Execute()
{
	ReadActionParameters();
	Cell* c = new Cell(deletedCellPosition);
	Grid* pGrid = pManager->GetGrid();
	Output* o = pGrid->GetOutput();
	CellPosition available = c->GetCellPosition();
	if (!c->GetGameObject())  //Gadallah:checking if there is a game object
	{
		pGrid->RemoveObjectFromCell(c->GetCellPosition());
	}
	else
		o->PrintMessage("There is no object at the selceted cell");
}


DeleteGameObject::~DeleteGameObject()
{}