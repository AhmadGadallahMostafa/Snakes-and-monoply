#include "ApplicationManager.h"
#include "AddLadderAction.h"
#include "AddSnakeAction.h"
#include "Grid.h"
#include "RollDiceAction.h"
#include "AddDiceValue.h"
#include"NewGame.h"
#include"AddCardAction.h"
#include"EditCardAction.h"
#include"DeleteGameObject.h"
#include"CopyCard.h"
#include"PasteCard.h"
#include"CutCard.h"
#include"ToPlayMode.h"
#include"ToDesignMode.h"
#include"SaveGrid.h"
#include"OpenGridAction.h"
///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;

	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;

	case DELETE_OBJECT:
		pAct = new DeleteGameObject(this);
		break;
	case ADD_CARD:
		pAct = new AddCardAction(this);
		break; // create an object of AddCardAction here
	case COPY_CARD:
		pAct = new CopyCard(this);
		break;
	case CUT_CARD:
		pAct = new CutCard(this);
		break;
	case PASTE_CARD:
		pAct = new PasteCard(this);
		break;
	case EDIT_CARD:
		pAct = new EditCardAction(this);
		break;
	case SAVE_GRID:
		pAct = new SaveGrid(this);
		break;
	case OPEN_GRID:
		pAct = new OpenGridAction(this);
	case EXIT:
		break;

	case TO_PLAY_MODE:
		pAct=new ToPlayMode(this); // temporary till you made its action class (CHANGE THIS LATTER)//Changed
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case ADD_DICE_VALUE:
		pAct = new AddDiceValue(this);
		break;
	case NEW_GAME:
		pAct = new NewGame(this);
		break;
	case EXIT2:
		break;
	case TO_DESIGN_MODE:
		pAct = new ToDesignMode(this);// temporary till you make its action class (CHANGE THIS LATTER)//chagned
		break;

	

		///TODO: Add a case for EACH Action type in the Design mode or Play mode



	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
