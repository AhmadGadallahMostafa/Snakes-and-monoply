#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"
#include"Snake.h"
#include"cell.h"
#include"Card.h"

//testing branching 

AddLadderAction::AddLadderAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer

	valid = 1;//to validate if the ladder can be drawn
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces


	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	if (!startPos.IsValidCell())//checking if the start cell is in the range of the grid
	{
		pOut->PrintMessage("ERROR,Choose a valid cell");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		valid = 0;
		return;
	}


	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	//valdiating the cells clicked
	if (!endPos.IsValidCell())//checking if the end cell is in the range of the grid
	{
		pOut->PrintMessage("ERROR,End cell is not a valid cell");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		valid = 0;
		return;
	}

	if (startPos.VCell() < endPos.VCell())//checking if the start.v is before.h the end (ex:start.v=2,end.v=5)
	{
		pOut->PrintMessage("ERROR,start cell can not be before end cell");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		valid = 0;
		return;
	}
	if (startPos.VCell() == endPos.VCell())//checking if the ladder is horizontal() or in the same cell
	{
		pOut->PrintMessage("ERROR,the ladder can not be horizontal(or in the same cell)");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		valid = 0;
		return;
	}
	if (startPos.HCell() != endPos.HCell())//checking if the ladder is vertical
	{
		pOut->PrintMessage("ERROR,the ladder is not vertical");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		valid = 0;
		return;

	}
	if (startPos.GetCellNumFromPosition(startPos) == 1)//checking if the ladder can not be in the first cell
	{
		pOut->PrintMessage("ERROR,the ladder can not be in first cell");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		valid = 0;
		return;
	}
	Ladder* pLadder = new Ladder(startPos, endPos);
	if (pGrid->IsOverLapping(pLadder))//checking if the ladder is overlapping with other ladders
	{
		pOut->PrintMessage("Error overlapping ladder");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		valid = 0;
		return;
	}
	for (int i = 0; i < 9; i++)//checking if the end/start of ladder is the start/end of another snake
	{
		CellPosition check(i, startPos.HCell());
		Snake* lFlag = dynamic_cast<Snake*>(pGrid->getGameObject(check));
		if (lFlag)
		{
			if ((lFlag->GetPosition()).VCell() == endPos.VCell() || (lFlag->GetEndPosition()).VCell() == startPos.VCell())
			{
				pOut->PrintMessage("ERROR,the end of the ladder can not be the start of the snake or vice versa");
				pIn->GetCellClicked();
				pOut->ClearStatusBar();
				valid = 0;
				return;
			}
		}
	}
	Ladder newladder(startPos, endPos);
	GameObject* newgame = &newladder;



	///TODO: Make the needed validations on the read parameters



	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	if (!valid)
		return;


	// Create a Ladder object with the parameters read from the user
	Ladder* pLadder = new Ladder(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Add the ladder object to the GameObject of its Cell:

	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
