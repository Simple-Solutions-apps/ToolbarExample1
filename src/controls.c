/*-------------------------------------------
  Copyright Simple Solutions, 2022
  Revised: 2022/06/12 22:21
-------------------------------------------*/

//standard includes
#include <windows.h>
#include <commctrl.h>

//custom includes
#include "..\include\controls.h"

int CreateControls(HWND sHdlWinMain)
{
	//declarations
	TBBUTTON sbButtonsToAdd[TOOLBAR_BTN_COUNT]; //Container for three buttons
	TBADDBITMAP sBitMap;
	HWND sToolBar;
	HMODULE vModInstHandle;

	//attempt to create this module instance handle
	vModInstHandle = GetModuleHandle(NULL);

	//Check if module instance handle was created correctly if not exit
	if(vModInstHandle == NULL)
	{
		MessageBox(sHdlWinMain, "Could not create module instance handle.", "Error", MB_OK | MB_ICONERROR);
		return;
	}

	//attempt to create toolbar 
	sToolBar = CreateWindowEx(0, "ToolbarWindow32", NULL,
	CCS_ADJUSTABLE | WS_BORDER | WS_CHILD | WS_VISIBLE | TBSTYLE_FLAT,
	0, 0, 0, 0, sHdlWinMain, (HMENU) IDC_MAIN_TOOLBAR, vModInstHandle, NULL);

	//Check if toolbar was created correctly if not exit
	if(sToolBar == NULL)
	{
		MessageBox(sHdlWinMain, "Could not create toolbar.", "Error", MB_OK | MB_ICONERROR);
		return __LINE__;
	}
	
	//define the bitmap to use
	sBitMap.hInst = HINST_COMMCTRL; //system standard common controls
	sBitMap.nID = IDB_STD_LARGE_COLOR; //IDB_STD_SMALL_COLOR for small buttons	
	
	//define functionality for buttons
	ZeroMemory(sbButtonsToAdd, sizeof(sbButtonsToAdd));
    sbButtonsToAdd[0].iBitmap = STD_FILENEW;
    sbButtonsToAdd[0].fsState = TBSTATE_ENABLED;
    sbButtonsToAdd[0].fsStyle = TBSTYLE_BUTTON;
    sbButtonsToAdd[0].idCommand = IDC_MAIN_TOOLBAR_FILE_NEW;
	sbButtonsToAdd[0].iString = "New File";

    sbButtonsToAdd[1].iBitmap = STD_FILEOPEN;
    sbButtonsToAdd[1].fsState = TBSTATE_ENABLED;
    sbButtonsToAdd[1].fsStyle = TBSTYLE_BUTTON;
    sbButtonsToAdd[1].idCommand = IDC_MAIN_TOOLBAR_FILE_OPEN;
	sbButtonsToAdd[1].iString = "Open File";

    sbButtonsToAdd[2].iBitmap = STD_FILESAVE;
    sbButtonsToAdd[2].fsState = TBSTATE_ENABLED;
    sbButtonsToAdd[2].fsStyle = TBSTYLE_BUTTON;
    sbButtonsToAdd[2].idCommand = IDC_MAIN_TOOLBAR_FILE_SAVEAS;
	sbButtonsToAdd[2].iString = "Save File";

	//send messages to toolbar (apply definitions)
	SendMessage(sToolBar, TB_BUTTONSTRUCTSIZE, (WPARAM)sizeof(TBBUTTON), 0); //Send the TB_BUTTONSTRUCTSIZE message (for backward compatibility)
	SendMessage(sToolBar, TB_ADDBITMAP, 0, (LPARAM) &sBitMap); //add bitmap to toolbar
	SendMessage(sToolBar, TB_ADDBUTTONS, sizeof(sbButtonsToAdd)/sizeof(TBBUTTON), (LPARAM) &sbButtonsToAdd); //add buttons to toolbar
	SendMessage(sToolBar, TB_AUTOSIZE, 0, 0); //resize buttons on toolbar

	//show toolbar
	ShowWindow(sToolBar, TRUE);
}