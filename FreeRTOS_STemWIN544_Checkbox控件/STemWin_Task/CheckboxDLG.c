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

#include "GUI.h"
#include "DIALOG.h"
#include "./led/bsp_led.h"

/*********************************************************************
*
*       Defines
*
**********************************************************************
*/
#define ID_FRAMEWIN_0   (GUI_ID_USER + 0x00)
#define ID_CHECKBOX_0   (GUI_ID_USER + 0x02)
#define ID_CHECKBOX_1   (GUI_ID_USER + 0x03)
#define ID_CHECKBOX_2   (GUI_ID_USER + 0x04)
#define ID_CHECKBOX_3   (GUI_ID_USER + 0x05)

/*********************************************************************
*
*       Static data
*
**********************************************************************
*/
extern GUI_CONST_STORAGE GUI_BITMAP bmcheckbox_true;

/*********************************************************************
*
*       _aDialogCreate
*/
static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { FRAMEWIN_CreateIndirect, "Framewin", ID_FRAMEWIN_0, 0, 0, 800, 480, 0, 0x64, 0 },
  { CHECKBOX_CreateIndirect, "Checkbox1", ID_CHECKBOX_0, 30, 30, 130, 35, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Checkbox2", ID_CHECKBOX_1, 30, 100, 130, 35, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Checkbox3", ID_CHECKBOX_2, 30, 170, 130, 35, 0, 0x0, 0 },
  { CHECKBOX_CreateIndirect, "Checkbox4", ID_CHECKBOX_3, 30, 240, 130, 35, 0, 0x0, 0 },
};

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/**
  * @brief 对话框回调函数
  * @note pMsg：消息指针
  * @param 无
  * @retval 无
  */
static void _cbDialog(WM_MESSAGE * pMsg) {
  WM_HWIN hItem;
  int     NCode;
  int     Id;

  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
    /* 初始化Framewin控件 */
    hItem = pMsg->hWin;
    FRAMEWIN_SetFont(hItem, GUI_FONT_32_ASCII);
    FRAMEWIN_SetTitleHeight(hItem, 32);
    FRAMEWIN_SetText(hItem, "STemWIN@EmbeddedFire STM32F429");
    /* 初始化Checkbox1 */
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_0);
    CHECKBOX_SetText(hItem, "Checkbox1");
    CHECKBOX_SetFont(hItem, GUI_FONT_20_ASCII);
	  /* 初始化Checkbox2 */
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_1);
    CHECKBOX_SetText(hItem, "Checkbox2");
    CHECKBOX_SetFont(hItem, GUI_FONT_20_ASCII);
	  /* 初始化Checkbox3 */
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_2);
    CHECKBOX_SetText(hItem, "Checkbox3");
    CHECKBOX_SetFont(hItem, GUI_FONT_20_ASCII);
		CHECKBOX_SetTextColor(hItem, GUI_LIGHTGRAY);
		CHECKBOX_SetBoxBkColor(hItem, GUI_LIGHTGRAY, CHECKBOX_CI_DISABLED);
		CHECKBOX_SetState(hItem, 1);
		WM_DisableWindow(hItem);
    /* 初始化Checkbox4 */
    hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_3);
    CHECKBOX_SetText(hItem, "Checkbox4");
    CHECKBOX_SetFont(hItem, GUI_FONT_20_ASCII);
		CHECKBOX_SetSkinClassic(hItem);
    CHECKBOX_SetImage(hItem, &bmcheckbox_true, CHECKBOX_BI_ACTIV_CHECKED);
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch(Id) {
    case ID_CHECKBOX_0: // Notifications sent by 'Checkbox1'
			hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_0);
		  switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        if(CHECKBOX_IsChecked(hItem))
				{LED2_ON;}
				else
				{LED2_OFF;}
        break;
      case WM_NOTIFICATION_RELEASED:
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        break;
      }
      break;
    case ID_CHECKBOX_1: // Notifications sent by 'Checkbox2'
      hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_1);
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        if(CHECKBOX_IsChecked(hItem))
					CHECKBOX_SetTextColor(hItem, GUI_RED);
				else
					CHECKBOX_SetTextColor(hItem, GUI_BLACK);
        break;
      case WM_NOTIFICATION_RELEASED:
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        break;
      }
      break;
    case ID_CHECKBOX_2: // Notifications sent by 'Checkbox3'
			hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_2);
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        break;
      case WM_NOTIFICATION_RELEASED:
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        break;
      }
      break;
    case ID_CHECKBOX_3: // Notifications sent by 'Checkbox4'
			hItem = WM_GetDialogItem(pMsg->hWin, ID_CHECKBOX_3);
      switch(NCode) {
      case WM_NOTIFICATION_CLICKED:
        if(CHECKBOX_IsChecked(hItem))
					CHECKBOX_SetImage(hItem, &bmcheckbox_true, CHECKBOX_BI_ACTIV_CHECKED);
        break;
      case WM_NOTIFICATION_RELEASED:
        break;
      case WM_NOTIFICATION_VALUE_CHANGED:
        break;
      }
      break;
    }
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
	/* 创建对话框 */
	CreateFramewin();
  
	while(1)
	{
		GUI_Delay(200);
	}
}

/*************************** End of file ****************************/
