#include "PasteCard.h"
#include"Grid.h"
#include"Card.h"
#include"Snake.h"
#include"Ladder.h"
#include"CopyCard.h"

PasteCard::PasteCard(ApplicationManager* pApp):Action(pApp){}
void PasteCard::ReadActionParameters()
{
	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->PrintMessage("click on the cell you want to paste the card to please");
	newCellPoisition = pIn->GetCellClicked();

	while (!newCellPoisition.IsValidCell())//Gadallah: checking if the cell is in the range of the grid
	{
		pOut->PrintMessage("ERROR,Choose a valid cell");
		newCellPoisition = pIn->GetCellClicked();
	}

	Ladder* lFlag = dynamic_cast<Ladder*>(pGrid->getGameObject(newCellPoisition));
	Snake* sFlag = dynamic_cast<Snake*>(pGrid->getGameObject(newCellPoisition));


	while (lFlag != NULL || sFlag != NULL)
	{
		pOut->PrintMessage("invalid card cell,please enter a new cell ");
		newCellPoisition = pIn->GetCellClicked();
		lFlag = dynamic_cast<Ladder*>(pGrid->getGameObject(newCellPoisition));
		sFlag = dynamic_cast<Snake*>(pGrid->getGameObject(newCellPoisition));
	}

}


void PasteCard::Execute()
{
	ReadActionParameters();
	/*Gadallah:defined a setter for position tos the set the position of the newCardPostion which will be taken from the user and 
	then calling addobject to cell of the grid*/
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Card* pCard = pGrid->GetClipboard();
	pCard->setPosition(newCellPoisition);
	pGrid->AddObjectToCell(pCard);

}





PasteCard:: ~PasteCard(){}