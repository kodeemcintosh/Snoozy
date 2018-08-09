
#include "AsusAuraSDK.h"


const DWORD g_mbCtrlCount;
const DWORD g_gpuCtrlCount;
const DWORD g_dramCtrlCount;

MbLightControl* g_mbLightCtrl;
GPULightControl* g_gpuLightCtrl;
DramLightControl* g_dramLightCtrl;

struct LED { BYTE r, g, b };

AsusAuraSDK::AsusAuraSDK()
{
}

AsusAuraSDK::~AsusAuraSDK()
{
	delete[] g_mbLightCtrl;
	delete[] g_gpuLightCtrl;
	delete[] g_dramLightCtrl;
}

void AsusAuraSDK::Initialize()
{

	hLib = LoadLibraryA(ASUSAURASDKDLL);

	if (hLib)
	{
		dllLoaded = TRUE;

		// points each local function to their counterpart in the ASUS_AURA.DLL
		(FARPROC&)EnumerateMb = GetProcAddress(hLib, "EnumerateMbController");
		(FARPROC&)SetMbMode = GetProcAddress(hLib, "SetMbMode");
		(FARPROC&)SetMbColor = GetProcAddress(hLib, "SetMbColor");
		(FARPROC&)GetMbLedCount = GetProcAddress(hLib, "GetMbLedCount");

		(FARPROC&)EnumerateGPU = GetProcAddress(hLib, "EnumerateGPU");
		(FARPROC&)SetGPUMode = GetProcAddress(hLib, "SetGPUMode");
		(FARPROC&)SetGPUColor = GetProcAddress(hLib, "SetGPUColor");
		(FARPROC&)GetGPULedCount = GetProcAddress(hLib, "GetGPULedCount");

		(FARPROC&)EnumerateDram = GetProcAddress(hLib, "EnumerateDram");
		(FARPROC&)SetDramMode = GetProcAddress(hLib, "SetDramMode");
		(FARPROC&)SetDramColor = GetProcAddress(hLib, "SetDramColor");
		(FARPROC&)GetDramLedCount = GetProcAddress(hLib, "GetDramLedCount");


		// creates blank addresses on the disk where the Light controls will be stored
		DWORD mb_count = EnumerateMb(NULL, 0);
		DWORD gpu_count = EnumerateGPU(NULL, 0);
		DWORD dram_count = EnumerateDram(NULL, 0);

		// passes the previously declared variables' addresses to the light control pointers
		g_mbLightCtrl = new MbLightControl[mb_count];
		g_gpuLightCtrl = new GPULightControl[gpu_count];
		g_dramLightCtrl = new DramLightControl[dram_count];

		// counts the LEDs in each of the rgb components below and sets the values of the light control pointers
		EnumerateMb(g_mbLightCtrl, g_mbCtrlCount);
		EnumerateGPU(g_gpuLightCtrl, g_gpuCtrlCount);
		EnumerateDram(g_dramLightCtrl, g_dramCtrlCount);

	}
	else
	{
		dllLoaded = FALSE;
	}
}

void AsusAuraSDK::LightsOut()
{
	SetMbMode();
	SetGPUMode();
	SetDramMode();

}