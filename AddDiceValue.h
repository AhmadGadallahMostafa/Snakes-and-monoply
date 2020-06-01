#pragma once
#include "Action.h"
#include "Grid.h"
#include "Player.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
class AddDiceValue :public Action
{
public:
	AddDiceValue(ApplicationManager* pApp);
	virtual  void ReadActionParameters();
	virtual void Execute();
	virtual ~AddDiceValue();
};

