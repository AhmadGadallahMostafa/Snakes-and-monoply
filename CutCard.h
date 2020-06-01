#pragma once
#include "Action.h"
class CutCard :public Action
{
	CellPosition orginal;  //Gadallah:dol data members 34an a5od el mkan el asly we el kan ely h3ml feah copy
	Card* copiedCard;//to save the clipboard to it
public:
	CutCard(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~CutCard();

};

