#ifndef _GUI_H
#define _GUI_H

#include "gfx.h"

typedef enum guiPage {
	ADDRESSSELECTDISPLAY,
	CONFIGDISPLAY,
	MAINDISPLAY,
	STARTUP,
} guiPage;

// Widget tags
#define GHPAGECONTAINERADDRESSSELECTDISPLAY_TAG 0
#define GHPAGECONTAINERCONFIGDISPLAY_TAG 0
#define GHPAGECONTAINERMAINDISPLAY_TAG 0
#define GHPAGECONTAINERSTARTUP_TAG 0
#define BTNSELECT_TAG 0
#define GHRADIOBUTTON_15_TAG 15
#define GHRADIOBUTTON_14_TAG 14
#define GHRADIOBUTTON_13_TAG 13
#define GHRADIOBUTTON_12_TAG 12
#define GHRADIOBUTTON_11_TAG 11
#define GHRADIOBUTTON_10_TAG 10
#define GHRADIOBUTTON_9_TAG 9
#define GHRADIOBUTTON_8_TAG 8
#define GHRADIOBUTTON_7_TAG 7
#define GHRADIOBUTTON_6_TAG 6
#define GHRADIOBUTTON_5_TAG 5
#define GHRADIOBUTTON_4_TAG 4
#define GHRADIOBUTTON_3_TAG 3
#define GHRADIOBUTTON_2_TAG 2
#define GHRADIOBUTTON_1_TAG 1
#define GHRADIOBUTTON_TAG 0
#define GHLABEL_11_TAG 0
#define BTNBACK_TAG 0
#define BTNADDRESSPLUS_TAG 0
#define BTNSAPIPLUS_TAG 0
#define LBLADDR_TAG 0
#define LBLSAPI_TAG 0
#define BTNADDRESSMINUS_TAG 0
#define BTNSAPIMINUS_TAG 0
#define LBLDEBUG_TAG 0
#define LBLADDRESS_TAG 0
#define BTNSENDDEBUG_TAG 0
#define CBSENDCRCERROR_TAG 0
#define CBRECCRCERROR_TAG 0
#define CBDEBUGCONNECTED_TAG 0
#define CBAUTOTOKEN_TAG 0
#define CBBROADCASTTIME_TAG 0
#define CBCONNECTOED_TAG 0
#define GHLABEL_6_TAG 0
#define GHLABEL_7_TAG 0
#define GHLABEL_8_TAG 0
#define GHLABEL_5_TAG 0
#define BTNCONFIGURATION_TAG 0
#define LBLTIME_TAG 0
#define BTNDESTINATION_TAG 0
#define GHLABEL_3_TAG 0
#define GHLABEL_2_TAG 0
#define GHLABEL_4_TAG 0
#define GHIMAGEBOX_TAG 0
#define BTNSTART_TAG 0
#define BTNTOKEN_TAG 0
#define GHLABEL_TAG 0
#define GHLABEL_1_TAG 0

// Widget handles
extern GHandle ghPageContainerAddressSelectDisplay;
extern GHandle ghPageContainerConfigDisplay;
extern GHandle ghPageContainerMainDisplay;
extern GHandle ghPageContainerStartup;
extern GHandle btnSelect;
extern GHandle ghRadiobutton_15;
extern GHandle ghRadiobutton_14;
extern GHandle ghRadiobutton_13;
extern GHandle ghRadiobutton_12;
extern GHandle ghRadiobutton_11;
extern GHandle ghRadiobutton_10;
extern GHandle ghRadiobutton_9;
extern GHandle ghRadiobutton_8;
extern GHandle ghRadiobutton_7;
extern GHandle ghRadiobutton_6;
extern GHandle ghRadiobutton_5;
extern GHandle ghRadiobutton_4;
extern GHandle ghRadiobutton_3;
extern GHandle ghRadiobutton_2;
extern GHandle ghRadiobutton_1;
extern GHandle ghRadiobutton;
extern GHandle ghLabel_11;
extern GHandle btnBack;
extern GHandle btnADDRESSPlus;
extern GHandle btnSAPIPlus;
extern GHandle lblADDR;
extern GHandle lblSAPI;
extern GHandle btnADDRESSMinus;
extern GHandle btnSAPIMinus;
extern GHandle lblDebug;
extern GHandle lblAddress;
extern GHandle btnSendDebug;
extern GHandle cbSendCRCError;
extern GHandle cbRecCRCError;
extern GHandle cbDebugConnected;
extern GHandle cbAutoToken;
extern GHandle cbBroadcastTime;
extern GHandle cbConnectoed;
extern GHandle ghLabel_6;
extern GHandle ghLabel_7;
extern GHandle ghLabel_8;
extern GHandle ghLabel_5;
extern GHandle btnConfiguration;
extern GHandle lblTime;
extern GHandle btnDestination;
extern GHandle ghLabel_3;
extern GHandle ghLabel_2;
extern GHandle ghLabel_4;
extern GHandle cnslSend;
extern GHandle cnslReceive;
extern GHandle ghImagebox;
extern GHandle btnStart;
extern GHandle btnToken;
extern GHandle ghLabel;
extern GHandle ghLabel_1;

#ifdef __cplusplus
extern "C" {
#endif

	bool_t guiInit(void);
	void guiShowPage(guiPage page);

#ifdef __cplusplus
}
#endif

#endif // _GUI_H
