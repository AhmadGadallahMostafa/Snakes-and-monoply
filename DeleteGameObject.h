#pragma once
#include "Action.h"
class DeleteGameObject :public Action
{
private :
	CellPosition deletedCellPosition;
public:
	DeleteGameObject(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~DeleteGameObject();
};

