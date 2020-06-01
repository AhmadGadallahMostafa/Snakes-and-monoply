#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "CardOne.h"
#include "cardtwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"

GameObject::GameObject(const CellPosition & pos)
{
	position = pos; // Sets Position
}

CellPosition GameObject::GetPosition() const
{
	return position;
}
void GameObject::setPosition(CellPosition& pos)
{
	position = pos;
}

bool GameObject::IsOverLapping(GameObject* newObj) const
{
	return false;
}

void GameObject::ReadFile(ifstream& InFile, GameObject* GameObj, Grid* pGrid)
{
	int numOfLadderObj = 0;

	InFile >> numOfLadderObj;
	CellPosition startCell, Endcell;

	for (int i = 0; i < numOfLadderObj; i++)
	{
		Ladder* pLadder = new Ladder(startCell, Endcell);
		pLadder->Load(InFile, pGrid);
		delete pLadder;
	}

	int numOfSnakeObj = 0;
	InFile >> numOfSnakeObj;

	for (int i = 0; i < numOfSnakeObj; i++)
	{
		Snake* pSnake = new Snake(startCell, Endcell);
		pSnake->Load(InFile, pGrid);
		delete pSnake;
	}

	int numOfCardobj;
	InFile >> numOfCardobj;

	for (int i = 0; i < numOfCardobj; i++)
	{
		int cardnumber;
		InFile >> cardnumber;
		Card* pCard;
		if (cardnumber == 1)
		{
			pCard = new CardOne(0);
			pCard->Load(InFile, pGrid);
			delete pCard;
		}
		else if (cardnumber == 2)
		{
			pCard = new CardTwo(0);
			pCard->Load(InFile, pGrid);
			delete pCard;
		}
		else if (cardnumber == 3)
		{
			pCard = new CardThree(0);
			pCard->Load(InFile, pGrid);
			delete pCard;
		}
		else if (cardnumber == 4)
		{
			pCard = new CardFour(0);
			pCard->Load(InFile, pGrid);
			delete pCard;
		}
		else if (cardnumber == 5)
		{
			pCard = new CardFive(0);
			pCard->Load(InFile, pGrid);
			delete pCard;
		}
		else if (cardnumber == 6)
		{
			pCard = new CardSix(0);
			pCard->Load(InFile, pGrid);
			delete pCard;
		}
		else if (cardnumber == 7)
		{
			pCard = new CardSeven(0);
			pCard->Load(InFile, pGrid);
			delete pCard;
		}
		else if (cardnumber == 8)
		{
			pCard = new CardEight(0);
			pCard->Load(InFile, pGrid);
			delete pCard;
		}
		else if (cardnumber == 9)
		{
			pCard = new CardNine(0);
			pCard->Load(InFile, pGrid);
			delete pCard;
		}
		else if (cardnumber == 10)
		{
			pCard = new CardTen(0);
			pCard->Load(InFile, pGrid);
			delete pCard;
		}
		else if (cardnumber == 11)
		{
			pCard = new CardEleven(0);
			pCard->Load(InFile, pGrid);
			delete pCard;
		}
		else if (cardnumber == 12)
		{
			pCard = new CardTwelve(0);
			pCard->Load(InFile, pGrid);
			delete pCard;
		}
		else if (cardnumber == 13)
		{
			pCard = new CardThirteen(0);
			pCard->Load(InFile, pGrid);
			delete pCard;
		}
		else if (cardnumber == 14)
		{
			pCard = new CardFourteen(0);
			pCard->Load(InFile, pGrid);
			delete pCard;
		}

	}

}

GameObject::~GameObject()
{
}