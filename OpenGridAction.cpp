#include "OpenGridAction.h"
#include "Ladder.h"
#include"Snake.h"
#include"Card.h"
OpenGridAction::OpenGridAction(ApplicationManager* pApp) :Action(pApp)
{
}

void OpenGridAction::ReadActionParameters()
{


	Grid* pG = pManager->GetGrid();
	Output* pO = pG->GetOutput();
	Input* pIn = pG->GetInput();
	pO->ClearGridArea();
	pO->PrintMessage("OPEN GRID: Enter name of file");
	fileName = pIn->GetSrting(pO);



}

void OpenGridAction::Execute()
{
	Grid* pG = pManager->GetGrid();
	Output* pO = pG->GetOutput();

	ReadActionParameters();

	ifstream inputFromFile;

	inputFromFile.open(fileName + ".txt", ios::in);//open file with name entered 
	
	
	if (!inputFromFile.is_open())// checks first if the file can be opened i.e (if it exists or not)
	{

		pO->PrintMessage("Error: '" + fileName + "' file name is wrong");
		return;

	}
	pG->ResetGrid();
	GameObject* pObj = NULL;
	GameObject::ReadFile(inputFromFile, pObj, pManager->GetGrid());


}
OpenGridAction::~OpenGridAction()
{
}
