/*-------------------------------------------
  Copyright Simple Solutions, 2022
  Revised: 2022/06/12 22:47
-------------------------------------------*/

//conditional header guard wrapper to avoid processing more than once
#ifndef CONTROLLS_H
	#define CONTROLLS_H

	//Controls
	
	//tool bar
	#define IDC_MAIN_TOOLBAR 1100
	#define TOOLBAR_BTN_COUNT 3

	//Command IDs for tool bar
	#define IDC_MAIN_TOOLBAR_FILE_NEW 1101
	#define IDC_MAIN_TOOLBAR_FILE_OPEN 1102
	#define IDC_MAIN_TOOLBAR_FILE_SAVEAS 1103

	//prototypes
	int CreateControls(HWND sHdlWinMain);

//end of wrapper
#endif