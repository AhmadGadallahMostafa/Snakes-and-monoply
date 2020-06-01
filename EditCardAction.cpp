#include "EditCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "cell.h"

EditCardAction::EditCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

EditCardAction::~EditCardAction()
{
}

 void EditCardAction::ReadActionParameters()
{
	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Input *pIn = pGrid->GetInput();
	Output *pOut = pGrid->GetOutput();
	// 2- Read the "cell" parameter (the cell position) and check if it contains a card
	pOut->PrintMessage("click on the source to edit");
	pos = pIn->GetCellClicked();
	editCard=pGrid->getCard(pos);
	if (editCard == NULL)
	{
		pOut->PrintMessage("Cell has no card");
		return;
	}
	cardNumber=editCard->GetCardNumber();
	if (cardNumber != 1 && cardNumber != 2 && cardNumber != 9 && cardNumber != 10 && cardNumber != 11 && cardNumber != 12 && cardNumber != 13 && cardNumber != 14)
	{
		pOut->PrintMessage("Card can't be edited");
		return;
	}
}

void EditCardAction::Execute()
{
	EditCardAction::ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input *pIn = pGrid->GetInput();
	Output *pOut = pGrid->GetOutput();
	if (editCard != NULL)
	{
		editCard->EditCardParameters(pGrid);
	}
}