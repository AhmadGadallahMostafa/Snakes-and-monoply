#pragma once
#include "Action.h"
class ToPlayMode :public Action
{
public :
	ToPlayMode(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~ToPlayMode();
};

