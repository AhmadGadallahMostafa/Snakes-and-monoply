#include "SaveGrid.h"
#include"Grid.h"
#include"Output.h"
#include"Input.h"
SaveGrid::SaveGrid(ApplicationManager* pApp) :Action(pApp)
{}

void SaveGrid::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("saving the grid");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
}


void SaveGrid::Execute()
{
	ReadActionParameters(); //Gadallah:reading the file name 

	ofstream outFile;

	outFile.open("grid.txt");

	Grid* pGrid = pManager->GetGrid();


	pGrid->SaveAll(outFile, 1);///Gadallah:for the ladders

	pGrid->SaveAll(outFile, 2);//for the snakes

	pGrid->SaveAll(outFile, 3);//for the cards

	outFile.close();
}
