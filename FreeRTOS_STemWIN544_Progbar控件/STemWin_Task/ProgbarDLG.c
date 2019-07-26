/*********************************************************************
*                                                                    *
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                                                                    *
**********************************************************************
*                                                                    *
* C-file generated by:                                               *
*                                                                    *
*        GUI_Builder for emWin version 5.44                          *
*        Compiled Nov 10 2017, 08:53:57                              *
*        (c) 2017 Segger Microcontroller GmbH & Co. KG               *
*                                                                    *
**********************************************************************
*                                                                    *
*        Internet: www.segger.com  Support: support@segger.com       *
*                                                                    *
**********************************************************************
*/
#include "ProgbarDLG.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0     (GUI_ID_USER + 0x00)
#define ID_PROGBAR_0     (GUI_ID_USER + 0x02)
#define ID_PROGBAR_1     (GUI_ID_USER + 0x03)
#define ID_BUTTON_0     (GUI_ID_USER + 0x04)
#define ID_BUTTON_1     (GUI_ID_USER + 0x05)

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 800, 480, 0, 0x64, 0 },
  { PROGBAR_CreateIndirect, "Progbar", ID_PROGBAR_0, 65, 40, 320, 40, 0, 0x0, 0 },
  { PROGBAR_CreateIndirect, "Progbar", ID_PROGBAR_1, 540, 45, 40, 320, 1, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_0, 610, 225, 50, 50, 0, 0x0, 0 },
  { BUTTON_CreateIndirect, "Button", ID_BUTTON_1, 610, 315, 50, 50, 0, 0x0, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/**
  * @brief 对话框回调函数
  * @note 无
  * @param pMsg：消息指针
  * @retval 无
  */
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;
	static U16 temp = 0, progbar_value = 0;

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    /* 初始化Framewin控件 */
    hItem = pMsg->hWin;
    FRAMEWIN_SetTitleHeight(hItem, 32);
    FRAMEWIN_SetText(hItem, "STemWIN@EmbeddedFire STM32F429");
    FRAMEWIN_SetFont(hItem, GUI_FONT_32_ASCII);
    /* 初始化Progbar0 */
    hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_0);
    PROGBAR_SetFont(hItem, GUI_FONT_COMIC24B_ASCII);
		PROGBAR_SetMinMax(hItem, 0, 100);
    /* 初始化Progbar1 */
    hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_1);
		PROGBAR_SetSkinClassic(hItem);
		PROGBAR_SetBarColor(hItem, 1, GUI_GRAY_E7);
		PROGBAR_SetBarColor(hItem, 0, GUI_GREEN);
    PROGBAR_SetFont(hItem, GUI_FONT_6X8);
		PROGBAR_SetMinMax(hItem, 0, 100);
    /* 初始化Button0 */
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_0);
    BUTTON_SetText(hItem, "+");
    BUTTON_SetFont(hItem, GUI_FONT_32B_ASCII);
    /* 初始化Button1 */
    hItem = WM_GetDialogItem(pMsg->hWin, ID_BUTTON_1);
    BUTTON_SetText(hItem, "-");
    BUTTON_SetFont(hItem, GUI_FONT_32B_ASCII);
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_BUTTON_0: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
				temp += 10;
				hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_1);
				PROGBAR_SetValue(hItem, temp);
			
        break;
      }
      break;
    case ID_BUTTON_1: // Notifications sent by 'Button'
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
				if(temp == 0)
				{break;}
				temp -= 10;
				hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_1);
				PROGBAR_SetValue(hItem, temp);
        break;
      }
      break;
    }
    break;
	case WM_PAINT:
		hItem = WM_GetDialogItem(pMsg->hWin, ID_PROGBAR_0);
		progbar_value = PROGBAR_GetValue(hItem);
		if(progbar_value == 100)
			PROGBAR_SetValue(hItem, 0);
		else
			PROGBAR_SetValue(hItem, progbar_value+1);
		break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
 /**
  * @brief 资源表方式间接创建对话框
  * @note 无
  * @param 无
  * @retval hWin：资源表中第一个控件的句柄
  */
WM_HWIN CreateFramewin(void);
WM_HWIN CreateFramewin(void) {
  WM_HWIN hWin;

  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

/**
  * @brief GUI主任务
  * @note 无
  * @param 无
  * @retval 无
  */
void MainTask(void)
{
	WM_HWIN hWin;
	
	hWin = CreateFramewin();
	
	while(1)
	{
		GUI_Delay(10);
		WM_InvalidateWindow(hWin);
	}
}

/*************************** End of file ****************************/
