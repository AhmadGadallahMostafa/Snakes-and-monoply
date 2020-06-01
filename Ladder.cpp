#include "Ladder.h"
#include<fstream>
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if (!(startCellPos.HCell() != endCellPos.HCell() || startCellPos.VCell() <= endCellPos.VCell()))
	{
		this->endCellPos = endCellPos;
	}
	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	
	Output* pOut=NULL;
	pOut = pGrid->GetOutput();
	Input* pIn = NULL;
	pIn = pGrid->GetInput();
	int x, y;

	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pIn->GetPointClicked(x,y);
	pGrid->UpdatePlayerCell(pPlayer,endCellPos);
}

bool Ladder::IsOverLapping(GameObject* newObj) const
{
	Ladder* newladder = dynamic_cast <Ladder*> (newObj);
	if (newladder && (GetPosition()).HCell() == (newladder->GetEndPosition()).HCell())
	{
		if ((newladder->GetPosition()).VCell() <= GetPosition().VCell() && (newladder->GetPosition()).VCell() >= (GetEndPosition()).VCell())
			return true;//return true if the start of new ladder is between the start and end of old ladder
		else if ((newladder->GetEndPosition()).VCell() <= GetPosition().VCell() && (newladder->GetEndPosition()).VCell() >= (GetEndPosition()).VCell())
			return true;//return true if the end of new ladder is between the start and end of old ladder
		else if (GetPosition().VCell() <= (newladder->GetPosition()).VCell() && GetPosition().VCell() >= (newladder->GetEndPosition()).VCell())
			return true;//return true if he start/end (doesn`t matter) of old ladder is between start and end of new ladder
	}
	return false;//return false if the ladder does not overlaps with the new ladder
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save(ofstream& outFile, int num)
{
	if (num == 1)
	{
		outFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
	}
	else
		return;
}

void Ladder::Load(ifstream& InFile, Grid* pGrid)
{
	int startcellnum, endcellnum;
	InFile >> startcellnum, InFile >> endcellnum;
	CellPosition startCell(startcellnum), endCell(endcellnum);
	Ladder* pLadder = new Ladder(startCell,endCell);
	pGrid->AddObjectToCell(pLadder);
}

Ladder::~Ladder()
{
}
