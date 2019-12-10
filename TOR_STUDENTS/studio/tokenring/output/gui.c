#include "gui.h"
#include "rendering_functions.h"
#include "widgetstyles.h"
#include "resources_manager.h"

GHandle ghPageContainerAddressSelectDisplay;
GHandle ghPageContainerConfigDisplay;
GHandle ghPageContainerMainDisplay;
GHandle ghPageContainerStartup;
GHandle btnSelect;
GHandle ghRadiobutton_15;
GHandle ghRadiobutton_14;
GHandle ghRadiobutton_13;
GHandle ghRadiobutton_12;
GHandle ghRadiobutton_11;
GHandle ghRadiobutton_10;
GHandle ghRadiobutton_9;
GHandle ghRadiobutton_8;
GHandle ghRadiobutton_7;
GHandle ghRadiobutton_6;
GHandle ghRadiobutton_5;
GHandle ghRadiobutton_4;
GHandle ghRadiobutton_3;
GHandle ghRadiobutton_2;
GHandle ghRadiobutton_1;
GHandle ghRadiobutton;
GHandle ghLabel_11;
GHandle btnBack;
GHandle btnADDRESSPlus;
GHandle btnSAPIPlus;
GHandle lblADDR;
GHandle lblSAPI;
GHandle btnADDRESSMinus;
GHandle btnSAPIMinus;
GHandle lblDebug;
GHandle lblAddress;
GHandle btnSendDebug;
GHandle cbSendCRCError;
GHandle cbRecCRCError;
GHandle cbDebugConnected;
GHandle cbAutoToken;
GHandle cbBroadcastTime;
GHandle cbConnectoed;
GHandle ghLabel_6;
GHandle ghLabel_7;
GHandle ghLabel_8;
GHandle ghLabel_5;
GHandle btnConfiguration;
GHandle lblTime;
GHandle btnDestination;
GHandle ghLabel_3;
GHandle ghLabel_2;
GHandle ghLabel_4;
GHandle cnslSend;
GHandle cnslReceive;
GHandle ghImagebox;
GHandle btnStart;
GHandle btnToken;
GHandle ghLabel;
GHandle ghLabel_1;

static bool_t _createPageaddressSelectDisplay(void)
{
	GWidgetInit wi;

	gwinWidgetClearInit(&wi);

	// Page container
	wi.g.show = FALSE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 480;
	wi.g.height = 272;
	wi.g.parent = 0;
	wi.text = "Container";
	wi.customDraw = background_gray;
	wi.customParam = 0;
	wi.customStyle = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHPAGECONTAINERADDRESSSELECTDISPLAY_TAG;
	#endif
	ghPageContainerAddressSelectDisplay = gwinContainerCreate(0, &wi, GWIN_CONTAINER_BORDER);

	// btnSelect
	wi.g.show = TRUE;
	wi.g.x = 178;
	wi.g.y = 228;
	wi.g.width = 120;
	wi.g.height = 30;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Select";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = BTNSELECT_TAG;
	#endif
	wi.customStyle = 0;
	btnSelect = gwinButtonCreate(0, &wi);
	gwinSetFont(btnSelect, gstudioGetFont(arial__14));

	// ghRadiobutton_15
	wi.g.show = TRUE;
	wi.g.x = 340;
	wi.g.y = 163;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Broadcast";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_15_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_15 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_15, gstudioGetFont(arial_12));

	// ghRadiobutton_14
	wi.g.show = TRUE;
	wi.g.x = 340;
	wi.g.y = 133;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 15";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_14_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_14 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_14, gstudioGetFont(arial_12));

	// ghRadiobutton_13
	wi.g.show = TRUE;
	wi.g.x = 340;
	wi.g.y = 103;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 14";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_13_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_13 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_13, gstudioGetFont(arial_12));

	// ghRadiobutton_12
	wi.g.show = TRUE;
	wi.g.x = 340;
	wi.g.y = 73;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 13";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_12_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_12 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_12, gstudioGetFont(arial_12));

	// ghRadiobutton_11
	wi.g.show = TRUE;
	wi.g.x = 242;
	wi.g.y = 163;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 12";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_11_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_11 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_11, gstudioGetFont(arial_12));

	// ghRadiobutton_10
	wi.g.show = TRUE;
	wi.g.x = 242;
	wi.g.y = 133;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 11";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_10_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_10 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_10, gstudioGetFont(arial_12));

	// ghRadiobutton_9
	wi.g.show = TRUE;
	wi.g.x = 242;
	wi.g.y = 103;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 10";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_9_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_9 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_9, gstudioGetFont(arial_12));

	// ghRadiobutton_8
	wi.g.show = TRUE;
	wi.g.x = 242;
	wi.g.y = 73;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 9";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_8_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_8 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_8, gstudioGetFont(arial_12));

	// ghRadiobutton_7
	wi.g.show = TRUE;
	wi.g.x = 147;
	wi.g.y = 163;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 8";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_7_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_7 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_7, gstudioGetFont(arial_12));

	// ghRadiobutton_6
	wi.g.show = TRUE;
	wi.g.x = 147;
	wi.g.y = 133;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 7";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_6_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_6 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_6, gstudioGetFont(arial_12));

	// ghRadiobutton_5
	wi.g.show = TRUE;
	wi.g.x = 147;
	wi.g.y = 103;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 6";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_5_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_5 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_5, gstudioGetFont(arial_12));

	// ghRadiobutton_4
	wi.g.show = TRUE;
	wi.g.x = 147;
	wi.g.y = 73;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 5";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_4_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_4 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_4, gstudioGetFont(arial_12));

	// ghRadiobutton_3
	wi.g.show = TRUE;
	wi.g.x = 52;
	wi.g.y = 163;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 4";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_3_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_3 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_3, gstudioGetFont(arial_12));

	// ghRadiobutton_2
	wi.g.show = TRUE;
	wi.g.x = 52;
	wi.g.y = 133;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 3";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_2_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_2 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_2, gstudioGetFont(arial_12));

	// ghRadiobutton_1
	wi.g.show = TRUE;
	wi.g.x = 52;
	wi.g.y = 103;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 2";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_1_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton_1 = gwinRadioCreate(0, &wi, 0);
	gwinSetFont(ghRadiobutton_1, gstudioGetFont(arial_12));

	// ghRadiobutton
	wi.g.show = TRUE;
	wi.g.x = 52;
	wi.g.y = 73;
	wi.g.width = 90;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Station 1";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHRADIOBUTTON_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghRadiobutton = gwinRadioCreate(0, &wi, 0);
	gwinRadioPress(ghRadiobutton);
	gwinSetFont(ghRadiobutton, gstudioGetFont(arial_12));

	// ghLabel_11
	wi.g.show = TRUE;
	wi.g.x = 15;
	wi.g.y = 4;
	wi.g.width = 221;
	wi.g.height = 30;
	wi.g.parent = ghPageContainerAddressSelectDisplay;
	wi.text = "Select destination address:";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHLABEL_11_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghLabel_11 = gwinLabelCreate(0, &wi);
	gwinSetFont(ghLabel_11, gstudioGetFont(arial__14));

	return TRUE;
}

static bool_t _createPageconfigDisplay(void)
{
	GWidgetInit wi;

	gwinWidgetClearInit(&wi);

	// Page container
	wi.g.show = FALSE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 480;
	wi.g.height = 272;
	wi.g.parent = 0;
	wi.text = "Container";
	wi.customDraw = background_gray;
	wi.customParam = 0;
	wi.customStyle = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHPAGECONTAINERCONFIGDISPLAY_TAG;
	#endif
	ghPageContainerConfigDisplay = gwinContainerCreate(0, &wi, GWIN_CONTAINER_BORDER);

	// btnBack
	wi.g.show = TRUE;
	wi.g.x = 394;
	wi.g.y = 243;
	wi.g.width = 80;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "Back";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = BTNBACK_TAG;
	#endif
	wi.customStyle = 0;
	btnBack = gwinButtonCreate(0, &wi);
	gwinSetFont(btnBack, gstudioGetFont(arial__14));

	// btnADDRESSPlus
	wi.g.show = TRUE;
	wi.g.x = 395;
	wi.g.y = 183;
	wi.g.width = 25;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "+";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = BTNADDRESSPLUS_TAG;
	#endif
	wi.customStyle = 0;
	btnADDRESSPlus = gwinButtonCreate(0, &wi);
	gwinSetFont(btnADDRESSPlus, gstudioGetFont(arial__14));

	// btnSAPIPlus
	wi.g.show = TRUE;
	wi.g.x = 395;
	wi.g.y = 148;
	wi.g.width = 25;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "+";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = BTNSAPIPLUS_TAG;
	#endif
	wi.customStyle = 0;
	btnSAPIPlus = gwinButtonCreate(0, &wi);
	gwinSetFont(btnSAPIPlus, gstudioGetFont(arial__14));

	// lblADDR
	wi.g.show = TRUE;
	wi.g.x = 354;
	wi.g.y = 183;
	wi.g.width = 25;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "  7";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = LBLADDR_TAG;
	#endif
	wi.customStyle = 0;
	lblADDR = gwinLabelCreate(0, &wi);
	gwinSetFont(lblADDR, gstudioGetFont(arial__14));

	// lblSAPI
	wi.g.show = TRUE;
	wi.g.x = 354;
	wi.g.y = 147;
	wi.g.width = 25;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "  1";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = LBLSAPI_TAG;
	#endif
	wi.customStyle = &red_green;
	lblSAPI = gwinLabelCreate(0, &wi);
	gwinSetFont(lblSAPI, gstudioGetFont(arial__14));

	// btnADDRESSMinus
	wi.g.show = TRUE;
	wi.g.x = 314;
	wi.g.y = 183;
	wi.g.width = 25;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "-";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = BTNADDRESSMINUS_TAG;
	#endif
	wi.customStyle = 0;
	btnADDRESSMinus = gwinButtonCreate(0, &wi);
	gwinSetFont(btnADDRESSMinus, gstudioGetFont(arial__14));

	// btnSAPIMinus
	wi.g.show = TRUE;
	wi.g.x = 314;
	wi.g.y = 147;
	wi.g.width = 25;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "-";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = BTNSAPIMINUS_TAG;
	#endif
	wi.customStyle = 0;
	btnSAPIMinus = gwinButtonCreate(0, &wi);
	gwinSetFont(btnSAPIMinus, gstudioGetFont(arial__14));

	// lblDebug
	wi.g.show = TRUE;
	wi.g.x = 7;
	wi.g.y = 183;
	wi.g.width = 132;
	wi.g.height = 30;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "Debug mode is: ON";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = LBLDEBUG_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	lblDebug = gwinLabelCreate(0, &wi);
	gwinSetFont(lblDebug, gstudioGetFont(arial_12));

	// lblAddress
	wi.g.show = TRUE;
	wi.g.x = 7;
	wi.g.y = 151;
	wi.g.width = 120;
	wi.g.height = 30;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "Local address is: 2";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = LBLADDRESS_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	lblAddress = gwinLabelCreate(0, &wi);
	gwinSetFont(lblAddress, gstudioGetFont(arial_12));

	// btnSendDebug
	wi.g.show = TRUE;
	wi.g.x = 197;
	wi.g.y = 111;
	wi.g.width = 160;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "Send debug message";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = BTNSENDDEBUG_TAG;
	#endif
	wi.customStyle = 0;
	btnSendDebug = gwinButtonCreate(0, &wi);
	gwinSetFont(btnSendDebug, gstudioGetFont(arial__14));

	// cbSendCRCError
	wi.g.show = TRUE;
	wi.g.x = 197;
	wi.g.y = 86;
	wi.g.width = 160;
	wi.g.height = 20;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "Send a bad CRC";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = CBSENDCRCERROR_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	cbSendCRCError = gwinCheckboxCreate(0, &wi);
	gwinCheckboxCheck(cbSendCRCError, FALSE);
	gwinSetFont(cbSendCRCError, gstudioGetFont(arial_12));

	// cbRecCRCError
	wi.g.show = TRUE;
	wi.g.x = 197;
	wi.g.y = 61;
	wi.g.width = 160;
	wi.g.height = 20;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "Receive CRC error";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = CBRECCRCERROR_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	cbRecCRCError = gwinCheckboxCreate(0, &wi);
	gwinCheckboxCheck(cbRecCRCError, FALSE);
	gwinSetFont(cbRecCRCError, gstudioGetFont(arial_12));

	// cbDebugConnected
	wi.g.show = TRUE;
	wi.g.x = 197;
	wi.g.y = 36;
	wi.g.width = 212;
	wi.g.height = 20;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "Debug station connected";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = CBDEBUGCONNECTED_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	cbDebugConnected = gwinCheckboxCreate(0, &wi);
	gwinCheckboxCheck(cbDebugConnected, TRUE);
	gwinSetFont(cbDebugConnected, gstudioGetFont(arial_12));

	// cbAutoToken
	wi.g.show = TRUE;
	wi.g.x = 7;
	wi.g.y = 86;
	wi.g.width = 160;
	wi.g.height = 20;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "Auto token (caution)";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = CBAUTOTOKEN_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	cbAutoToken = gwinCheckboxCreate(0, &wi);
	gwinCheckboxCheck(cbAutoToken, FALSE);
	gwinSetFont(cbAutoToken, gstudioGetFont(arial_12));

	// cbBroadcastTime
	wi.g.show = TRUE;
	wi.g.x = 7;
	wi.g.y = 61;
	wi.g.width = 120;
	wi.g.height = 20;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "Broadcast time";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = CBBROADCASTTIME_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	cbBroadcastTime = gwinCheckboxCreate(0, &wi);
	gwinCheckboxCheck(cbBroadcastTime, FALSE);
	gwinSetFont(cbBroadcastTime, gstudioGetFont(arial_12));

	// cbConnectoed
	wi.g.show = TRUE;
	wi.g.x = 7;
	wi.g.y = 36;
	wi.g.width = 156;
	wi.g.height = 19;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "Station connected";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = CBCONNECTOED_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	cbConnectoed = gwinCheckboxCreate(0, &wi);
	gwinCheckboxCheck(cbConnectoed, TRUE);
	gwinSetFont(cbConnectoed, gstudioGetFont(arial_12));

	// ghLabel_6
	wi.g.show = TRUE;
	wi.g.x = 197;
	wi.g.y = 4;
	wi.g.width = 120;
	wi.g.height = 30;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "Debug control:";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHLABEL_6_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghLabel_6 = gwinLabelCreate(0, &wi);
	gwinSetFont(ghLabel_6, gstudioGetFont(arial__14));

	// ghLabel_7
	wi.g.show = TRUE;
	wi.g.x = 197;
	wi.g.y = 151;
	wi.g.width = 80;
	wi.g.height = 20;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "Debug SAPI";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHLABEL_7_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghLabel_7 = gwinLabelCreate(0, &wi);
	gwinSetFont(ghLabel_7, gstudioGetFont(arial_12));

	// ghLabel_8
	wi.g.show = TRUE;
	wi.g.x = 197;
	wi.g.y = 183;
	wi.g.width = 100;
	wi.g.height = 30;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "Debug address";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHLABEL_8_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghLabel_8 = gwinLabelCreate(0, &wi);
	gwinSetFont(ghLabel_8, gstudioGetFont(arial_12));

	// ghLabel_5
	wi.g.show = TRUE;
	wi.g.x = 7;
	wi.g.y = 4;
	wi.g.width = 136;
	wi.g.height = 30;
	wi.g.parent = ghPageContainerConfigDisplay;
	wi.text = "Station control:";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHLABEL_5_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghLabel_5 = gwinLabelCreate(0, &wi);
	gwinSetFont(ghLabel_5, gstudioGetFont(arial__14));

	return TRUE;
}

static bool_t _createPagemainDisplay(void)
{
	GWidgetInit wi;

	gwinWidgetClearInit(&wi);

	// Page container
	wi.g.show = FALSE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 480;
	wi.g.height = 272;
	wi.g.parent = 0;
	wi.text = "Container";
	wi.customDraw = background_gray;
	wi.customParam = 0;
	wi.customStyle = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHPAGECONTAINERMAINDISPLAY_TAG;
	#endif
	ghPageContainerMainDisplay = gwinContainerCreate(0, &wi, GWIN_CONTAINER_BORDER);

	// btnConfiguration
	wi.g.show = TRUE;
	wi.g.x = 374;
	wi.g.y = 243;
	wi.g.width = 102;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerMainDisplay;
	wi.text = "Config";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = BTNCONFIGURATION_TAG;
	#endif
	wi.customStyle = 0;
	btnConfiguration = gwinButtonCreate(0, &wi);
	gwinSetFont(btnConfiguration, gstudioGetFont(arial__14));

	// lblTime
	wi.g.show = TRUE;
	wi.g.x = 243;
	wi.g.y = 248;
	wi.g.width = 120;
	wi.g.height = 15;
	wi.g.parent = ghPageContainerMainDisplay;
	wi.text = "Time is: --:--:--";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = LBLTIME_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	lblTime = gwinLabelCreate(0, &wi);
	gwinSetFont(lblTime, gstudioGetFont(arial_12));

	// btnDestination
	wi.g.show = TRUE;
	wi.g.x = 110;
	wi.g.y = 243;
	wi.g.width = 110;
	wi.g.height = 25;
	wi.g.parent = ghPageContainerMainDisplay;
	wi.text = "4";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = BTNDESTINATION_TAG;
	#endif
	wi.customStyle = 0;
	btnDestination = gwinButtonCreate(0, &wi);
	gwinSetFont(btnDestination, gstudioGetFont(arial__14));

	// ghLabel_3
	wi.g.show = TRUE;
	wi.g.x = 3;
	wi.g.y = 247;
	wi.g.width = 104;
	wi.g.height = 16;
	wi.g.parent = ghPageContainerMainDisplay;
	wi.text = "Select destination:";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHLABEL_3_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghLabel_3 = gwinLabelCreate(0, &wi);
	gwinSetFont(ghLabel_3, gstudioGetFont(arial_12));

	// ghLabel_2
	wi.g.show = TRUE;
	wi.g.x = 3;
	wi.g.y = 3;
	wi.g.width = 120;
	wi.g.height = 20;
	wi.g.parent = ghPageContainerMainDisplay;
	wi.text = "Message to send:";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHLABEL_2_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghLabel_2 = gwinLabelCreate(0, &wi);
	gwinSetFont(ghLabel_2, gstudioGetFont(arial__14));

	// ghLabel_4
	wi.g.show = TRUE;
	wi.g.x = 243;
	wi.g.y = 3;
	wi.g.width = 128;
	wi.g.height = 20;
	wi.g.parent = ghPageContainerMainDisplay;
	wi.text = "Received message:";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHLABEL_4_TAG;
	#endif
	wi.customStyle = &white_on_gray;
	ghLabel_4 = gwinLabelCreate(0, &wi);
	gwinSetFont(ghLabel_4, gstudioGetFont(arial__14));

	// cnslSend
	wi.g.show = TRUE;
	wi.g.x = 6;
	wi.g.y = 23;
	wi.g.width = 220;
	wi.g.height = 214;
	wi.g.parent = ghPageContainerMainDisplay;
	cnslSend = gwinConsoleCreate(0, &wi.g);
	gwinSetFont(cnslSend, gstudioGetFont(arial_12));

	// cnslReceive
	wi.g.show = TRUE;
	wi.g.x = 243;
	wi.g.y = 23;
	wi.g.width = 220;
	wi.g.height = 214;
	wi.g.parent = ghPageContainerMainDisplay;
	cnslReceive = gwinConsoleCreate(0, &wi.g);

	return TRUE;
}

static bool_t _createPagestartup(void)
{
	GWidgetInit wi;

	gwinWidgetClearInit(&wi);

	// Page container
	wi.g.show = FALSE;
	wi.g.x = 0;
	wi.g.y = 0;
	wi.g.width = 480;
	wi.g.height = 272;
	wi.g.parent = 0;
	wi.text = "Container";
	wi.customDraw = background_Display_Background;
	wi.customParam = 0;
	wi.customStyle = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHPAGECONTAINERSTARTUP_TAG;
	#endif
	ghPageContainerStartup = gwinContainerCreate(0, &wi, GWIN_CONTAINER_BORDER);

	// ghImagebox
	wi.g.show = TRUE;
	wi.g.x = 10;
	wi.g.y = 19;
	wi.g.width = 300;
	wi.g.height = 205;
	wi.g.parent = ghPageContainerStartup;
	wi.text = "";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHIMAGEBOX_TAG;
	#endif
	wi.customStyle = 0;
	ghImagebox = gwinImageCreate(0, &wi.g);
	gwinImageOpenFile(ghImagebox, gstudioGetImageFilePath(token_w));

	// btnStart
	wi.g.show = TRUE;
	wi.g.x = 347;
	wi.g.y = 35;
	wi.g.width = 120;
	wi.g.height = 36;
	wi.g.parent = ghPageContainerStartup;
	wi.text = "Start system without token";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = BTNSTART_TAG;
	#endif
	wi.customStyle = 0;
	btnStart = gwinButtonCreate(0, &wi);
	gwinSetFont(btnStart, gstudioGetFont(arial_12));

	// btnToken
	wi.g.show = TRUE;
	wi.g.x = 347;
	wi.g.y = 99;
	wi.g.width = 120;
	wi.g.height = 36;
	wi.g.parent = ghPageContainerStartup;
	wi.text = "Start system with one token send";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = BTNTOKEN_TAG;
	#endif
	wi.customStyle = &red_green;
	btnToken = gwinButtonCreate(0, &wi);
	gwinSetFont(btnToken, gstudioGetFont(arial_12));

	// ghLabel
	wi.g.show = TRUE;
	wi.g.x = 365;
	wi.g.y = 250;
	wi.g.width = 113;
	wi.g.height = 21;
	wi.g.parent = ghPageContainerStartup;
	wi.text = "(sap) PTR - 2018";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHLABEL_TAG;
	#endif
	wi.customStyle = 0;
	ghLabel = gwinLabelCreate(0, &wi);
	gwinSetFont(ghLabel, gstudioGetFont(arial_12));

	// ghLabel_1
	wi.g.show = TRUE;
	wi.g.x = 365;
	wi.g.y = 236;
	wi.g.width = 78;
	wi.g.height = 17;
	wi.g.parent = ghPageContainerStartup;
	wi.text = "Rev 1.0a";
	wi.customDraw = 0;
	wi.customParam = 0;
	#if GWIN_WIDGET_TAGS
		wi.tag = GHLABEL_1_TAG;
	#endif
	wi.customStyle = 0;
	ghLabel_1 = gwinLabelCreate(0, &wi);
	gwinSetFont(ghLabel_1, gstudioGetFont(arial_12));

	return TRUE;
}

void guiShowPage(guiPage page)
{
	// Hide all pages
	gwinHide(ghPageContainerAddressSelectDisplay);
	gwinHide(ghPageContainerConfigDisplay);
	gwinHide(ghPageContainerMainDisplay);
	gwinHide(ghPageContainerStartup);

	// Show the selected page
	switch (page) {
		case ADDRESSSELECTDISPLAY:
			gwinShow(ghPageContainerAddressSelectDisplay);
			break;

		case CONFIGDISPLAY:
			gwinShow(ghPageContainerConfigDisplay);
			break;

		case MAINDISPLAY:
			gwinShow(ghPageContainerMainDisplay);
			break;

		case STARTUP:
			gwinShow(ghPageContainerStartup);
			break;

		default:
			break;
	}
}

bool_t guiInit(void)
{
	// Initialize resources
	if (!guiResourcesManagerInit()) {
		return FALSE;
	}

	// Set GWIN default values
	gwinSetDefaultStyle(&WhiteWidgetStyle, FALSE);

	// Create display pages
	_createPageaddressSelectDisplay();
	_createPageconfigDisplay();
	_createPagemainDisplay();
	_createPagestartup();

	return TRUE;
}

