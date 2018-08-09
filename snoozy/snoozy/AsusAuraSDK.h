#pragma once

#include "AURALightingSDK.h"

#define ASUSAURASDKDLL "AURA_SDK.dll"

class AsusAuraSDK
{
public:

	AsusAuraSDK();
	~AsusAuraSDK();

	void Initialize();
	void LightsOut();


private:

	HMODULE hLib = NULL;

	bool dllLoaded = FALSE;

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
};


