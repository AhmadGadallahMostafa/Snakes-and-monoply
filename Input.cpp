#include "Input.h"

#include "Output.h"
using namespace std;
#include <iostream>
//======================================================================================//
//								General Functions									    //
//======================================================================================//

Input::Input(window* pW) 
{
	pWind = pW; // point to the passed window
}

////////////////////////////////////////////////////////////////////////////////////////// 

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y); // Note: x and y of WaitMouseClick are sent by reference
}

////////////////////////////////////////////////////////////////////////////////////////// 

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	// ESCAPE key is pressed
			return "";	// returns nothing as user has cancelled label
		if(Key == 13 )	// ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	// BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

////////////////////////////////////////////////////////////////////////////////////////// 

int Input::GetInteger(Output *pO) const 
{

	///TODO: implement the GetInteger function as described in Input.h file 
	//       using function GetString() defined above and function stoi()
	
	int s = stoi(GetSrting(pO));


	return s;



	// Note: stoi(s) converts string s into its equivalent integer (for example, "55" is converted to 55)

	return 0; // this line should be changed with your implementation
}

//======================================================================================//
//								Game  Functions									        //
//======================================================================================//

ActionType Input::GetUserAction() const
{	
	int x = -1, y = -1;
	GetPointClicked(x, y); 

	//  ============ GUI in the Design mode ============
	if ( UI.InterfaceMode == MODE_DESIGN )	
	{
		// [1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			// Check which Menu item was clicked
			// ==> This assumes that menu items are lined up horizontally <==

			int ClickedItemOrder = (x / UI.MenuItemWidth);

			// Divide x coord of the point clicked by the menu item width (integer division)
			// If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_ADD_LADDER: return ADD_LADDER;
			case ITM_ADD_SNAKE: return ADD_SNAKE;
			case ITM_ADD_CARD: return ADD_CARD;
			case ITM_DELETE_OBJECT:return DELETE_OBJECT;
			case ITM_COPY_CARD: return COPY_CARD;
			case ITM_CUT_CARD: return CUT_CARD;
			case ITM_PASTE_CARD: return PASTE_CARD;
			case ITM_EDIT_CARD: return EDIT_CARD;
			case ITM_SAVE_GRID: return SAVE_GRID;
			case ITM_OPEN_GRID: return OPEN_GRID;
			case ITM_EXIT: return EXIT;
			case ITM_SWITCH_TO_PLAY_MODE: return TO_PLAY_MODE;			

				///TODO: Add cases for the other items of Design Mode




			default: return EMPTY;	// A click on empty place in toolbar
			}
		}

		// [2] User clicks on the grid area
		if ( (y >= UI.ToolBarHeight) && (y < UI.height - UI.StatusBarHeight))
		{
			return GRID_AREA;	
		}

		// [3] User clicks on the status bar
		return STATUS;
	}

	// ============ GUI in the Play mode ============
	else	
	{
	

		///TODO:
		// perform checks similar to Design mode checks above for the Play Mode
		// and return the corresponding ActionType
		if (UI.InterfaceMode == MODE_PLAY) //Gadallah:nafs el hagat zay ely fo2 bzbt bss el maerady h4t8l 3la el enums ely fe el play mode b2a msh el design ely homa l7d dlo2ty roll dice w returnb to design mode bss l7d ama n4of hn3ml add l eh

		{
			if (y >= 0 && y < UI.ToolBarHeight)
			{
				int ClickedItemOrder = (x / UI.MenuItemWidth); //Gadallah:lw be 0 yb2a hwa e5tar awl item fe el tool bar w hakza , kol el items leha nafs el width ely mt3rf fe el output.cpp

				switch (ClickedItemOrder)
				{
				case ITM_ROLL_DICE: return ROLL_DICE;
				case ITM_ADD_DICE_VALUE:return ADD_DICE_VALUE;
				case ITM_EXIT2: return EXIT2;
				case ITM_NEW_GAME: return NEW_GAME;
				case ITM_SWITCH_TO_DESIGN_MODE: return TO_DESIGN_MODE;
					
                ////Gadallahg :lsa el mafrood n add hagat hna w nafs el klam fe el design mode ;


				default: return EMPTY;;
				}

			}
			// [2] User clicks on the grid area
			if ((y >= UI.ToolBarHeight) && (y < UI.height - UI.StatusBarHeight))
			{
				return GRID_AREA;
			}

			// [3] User clicks on the status bar
			return STATUS;
		}
		return TO_DESIGN_MODE;	// just for now ==> This should be updated




	}	

}

////////////////////////////////////////////////////////////////////////////////////////// 

CellPosition Input::GetCellClicked() const
{
	int x,y;
	pWind->WaitMouseClick(x, y);	// Get the coordinates of the user click

	CellPosition cellPos;

	if ( UI.InterfaceMode == MODE_DESIGN )	
	{
		if ( y >= UI.ToolBarHeight && y <= (UI.height - UI.StatusBarHeight))
		{
			///TODO: SetHCell and SetVCell of the object cellPost appropriately
			//       using the coordinates x, y and the appropriate variables of the UI_Info Object (UI)
			////Gaadllah:3aks ely kan mawgoud fe el output class .
			cellPos.SetHCell(x / UI.CellWidth);
			cellPos.SetVCell((y / UI.CellHeight) - 1);
		}
	}

	return cellPos;
}

////////////////////////////////////////////////////////////////////////////////////////// 
