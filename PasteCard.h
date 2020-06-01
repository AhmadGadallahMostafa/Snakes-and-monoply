#pragma once
#include "Action.h"
#include"Card.h"
class PasteCard :public Action
{
	CellPosition newCellPoisition;
public :
	PasteCard(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~PasteCard();

};

