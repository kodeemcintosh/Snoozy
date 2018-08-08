
#include "stdafx.h"


EnumerateMbControllerFunc EnumerateMb;
SetMbModeFunc SetMbMode;
SetMbColorFunc SetMbColor;
GetMbLedCountFunc GetMbLedCount;

EnumerateGPUFunc EnumerateGPU;
SetGPUModeFunc SetGPUMode;
SetGPUColorFunc SetGPUColor;
GetGPULedCountFunc GetGPULedCount;

EnumerateDramFunc EnumerateDram;
SetDramModeFunc SetDramMode;
SetDramColorFunc SetDramColor;
GetDramLedCountFunc GetDramLedCount;

const DWORD mbControllerCount = EnumerateMb(NULL, 0);
const DWORD gpuControllerCount = EnumerateGPU(NULL, 0);
const DWORD dramControllerCount = EnumerateDram(NULL, 0);

MbLightControl* g_mbLightCtrl = new MbLightControl();
GPULightControl* g_gpuLightCtrl = new GPULightControl();
DramLightControl* g_dramLightCtrl = new DramLightControl();

void init()
{
	// intialize the mouse lighting
	bool LedInitialized = LogiLedInit();
	if (!LedInitialized)
	{
		std::cout << "LogiLedInit() failed";
		exit(EXIT_FAILURE);
	}
}

int time_check(int duration, int off)
{
	Sleep(duration * 1000);

	// GNU & UNIX implementation
	// time_t t;
	// struct tm *tm = localtime( &t );
	// if(tm.tm_hour >= 21)
	// {
	//   return 0;
	// }
	// else
	// {
	//   return 1;
	// }

	// Windows implementation
	SYSTEMTIME t;
	GetLocalTime( &t );

	if (t.wHour >= off)
	{
		return 0;
	}
	else
	{
		return 1;
	}

	delete &t;
}

// lights off for ASUS mobo, phanteks led strips, phanteks case, and G.SKILL trident RGB ram
void set_aura(int status)
{



	if (status == 0)
	{

	}

	if (status == 1)
	{

	}
}

// lights for with G203 mouse
void set_logitech(int status)
{

	if (status == 0)
	{
		bool ok = LogiLedSaveCurrentLighting();
		if (!ok)
		{
			std::cout << "SaveCurrentLighting() failed";
			exit(EXIT_FAILURE);
		}
		LogiLedSetLighting(0, 0, 0);
	}

	if (status == 1)
	{
		bool ok = LogiLedRestoreLighting();
		if (!ok)
		{
			std::cout << "LogiLedRestoreLighting() failed";
			exit(EXIT_FAILURE);
		}
	}
}

// this one may be a little more involved
// I may have to read serial ports and stuff
// lights for with NZXT X62 CPU watercooler head
void set_hueplus(int status)
{

	if (status == 0)
	{

	}

	if (status == 1)
	{

	}
}

// this one will also probably get pretty involved
// lights for with Nvidia GTX 1080ti
void set_nvidia(int status)
{

	if (status == 0)
	{

	}

	if (status == 1)
	{

	}
}


