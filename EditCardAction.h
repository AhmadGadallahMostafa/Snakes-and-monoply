#pragma once

#include "Action.h"
#include "GameObject.h"

class EditCardAction : public Action
{
	// [Action Parameters]
	CellPosition pos;
	Card* editCard;
	int cardNumber;

	// Note: These parameters should be read in ReadActionParameters()

public:
	EditCardAction(ApplicationManager *pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads EditCardAction action parameters

	virtual void Execute(); //Edits the card value

	virtual ~EditCardAction(); // A Virtual Destructor
};

