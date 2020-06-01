#include "CopyCard.h"
#include"Grid.h"
#include"Card.h"
#include"Cell.h"

CopyCard::CopyCard(ApplicationManager* pApp) :Action(pApp)
{}

void CopyCard::ReadActionParameters()
{
	//Gadallah:reading the start position elly hwa el makan ely feah el card elly ana 3ayzo 
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on a Cell that has a card please ");
	orginal = pIn->GetCellClicked();
	


	while (!orginal.IsValidCell())//Gadallah: checking if the cell is in the range of the grid
	{
		pOut->PrintMessage("ERROR,Choose a valid cell");
		orginal = pIn->GetCellClicked();
	}

	copiedCard = dynamic_cast<Card*>(pGrid->getGameObject(orginal));

	if (copiedCard == NULL)
	{
		pOut->PrintMessage("Error enter a cell that contains a card");
		CellPosition dummy = pIn->GetCellClicked();
		pOut->ClearStatusBar();
		return;
			
		
	}
	
	pOut->PrintMessage("Card copied to clipboard");

}

void CopyCard::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();

	pGrid->SetClipboard(copiedCard);

}

CopyCard::~CopyCard(){}