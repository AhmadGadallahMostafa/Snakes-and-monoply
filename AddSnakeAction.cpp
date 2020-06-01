#include "AddSnakeAction.h"
#include "Ladder.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
	valid = 1;//to validate if the ladder can be drawn
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces


	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
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
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
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

	if (startPos.VCell() > endPos.VCell())//checking if the start.v is after end.h the end (ex:start.v=3,end.v=0)
	{
		pOut->PrintMessage("ERROR,start cell can not be after end cell");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		valid = 0;
		return;
	}

	if (startPos.VCell() == endPos.VCell())//checking if the snake is horizontal() or in the same cell
	{
		pOut->PrintMessage("ERROR,the snake can not be horizontal(or in the same cell)");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		valid = 0;
		return;
	}

	if (startPos.HCell() != endPos.HCell())//checking if the snake is vertical
	{
		pOut->PrintMessage("ERROR,the Snake is not vertical");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		valid = 0;
		return;

	}
	if (startPos.GetCellNumFromPosition(startPos) == 99)//checking if the snake can not be in the last cell
	{
		pOut->PrintMessage("ERROR,the snake can not be in the last cell");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		valid = 0;
		return;
	}
	Snake* pSnake = new Snake(startPos, endPos);
	if (pGrid->IsOverLapping(pSnake))//checking if the snake is overlapping with other snakes
	{
		pOut->PrintMessage("Error overlapping Snake");
		pIn->GetCellClicked();
		pOut->ClearStatusBar();
		valid = 0;
		return;
	}
	for (int i = 0; i < 9; i++)//checking if the end/start of snake is the start/end of another ladder 
	{                        //looping in the same column to check the ladder that has start and end cell in this column doesn`t interfer with snake
		CellPosition check(i, startPos.HCell());
		Ladder* lFlag = dynamic_cast<Ladder*>(pGrid->getGameObject(check));
		if (lFlag)
		{
			if ((lFlag->GetEndPosition()).VCell() == startPos.VCell() || (lFlag->GetPosition()).VCell() == endPos.VCell())
			{
				pOut->PrintMessage("ERROR,The end of snake can not be the start of another ladder and vice versa");
				pIn->GetCellClicked();
				pOut->ClearStatusBar();
				valid = 0;
				return;
			}
		}
	}


	///TODO: Make the needed validations on the read parameters



	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	if (!valid)
		return;

	// Create a snake object with the parameters read from the user
	Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	bool added = pGrid->AddObjectToCell(pSnake);
	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}


}
