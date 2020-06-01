#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	if (!(startCellPos.HCell() != endCellPos.HCell() || startCellPos.VCell() >= endCellPos.VCell()))
	{
		this->endCellPos = endCellPos;
	}

	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

	Output* pOut = NULL;
	pOut = pGrid->GetOutput();
	Input* pIn = NULL;
	pIn = pGrid->GetInput();
	int x, y;
	pOut->PrintMessage("You have reached a snake ! Click to continue ...");
	pIn->GetPointClicked(x, y);
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}

bool Snake::IsOverLapping(GameObject* newObj) const
{
	Snake* newSnake = dynamic_cast <Snake*> (newObj);
	if (newSnake && (GetPosition()).HCell() == (newSnake->GetEndPosition()).HCell())
	{
		if ((newSnake->GetPosition()).VCell() >= GetPosition().VCell() && (newSnake->GetPosition()).VCell() <= (GetEndPosition()).VCell())
			return true;//return true if the start of new snake is between the start and end of old snake
		else if ((newSnake->GetEndPosition()).VCell() >= GetPosition().VCell() && (newSnake->GetEndPosition()).VCell() <= (GetEndPosition()).VCell())
			return true;//return true if the end of new snake is between the start and end of old snake
		else if (GetPosition().VCell() >= (newSnake->GetPosition()).VCell() && GetPosition().VCell() <= (newSnake->GetEndPosition()).VCell())
			return true;//return true if he start/end (doesn`t matter) of old snake is between start and end of new snake
	}
	return false;//return false if the ladder does not overlaps with the new ladder
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::Save(ofstream& OutFile, int num)
{
	if (num == 2)
	{
		OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;


	}
	else
		return;
}
void Snake::Load(ifstream& InFile, Grid* pGrid)
{
	int startcellnum, endcellnum;
	InFile >> startcellnum, InFile >> endcellnum;
	CellPosition startCell(startcellnum), endCell(endcellnum);
	Snake* pSnake = new Snake(startCell, endCell);
	pGrid->AddObjectToCell(pSnake);
}

Snake::~Snake()
{
}
