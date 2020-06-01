#pragma once
#pragma once
#include "Action.h"
#include<string>
#include<fstream>
	class OpenGridAction :public Action
	{

	private:
		string fileName;

	public:

		OpenGridAction(ApplicationManager* pApp); // A Constructor

		virtual void ReadActionParameters();
		virtual void Execute();

		virtual ~OpenGridAction();

	};

