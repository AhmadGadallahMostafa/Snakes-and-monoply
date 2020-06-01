#pragma once
#include "Action.h"
#include"fstream"
#include<string>
class SaveGrid : public Action
{
	string nameFile;
public:

	SaveGrid(ApplicationManager* pApp);
	virtual void ReadActionParameters();//Gadallah:reading the file name
	virtual void Execute();
};

