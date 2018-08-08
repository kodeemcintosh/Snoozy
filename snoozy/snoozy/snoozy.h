#pragma once

//#include "stdafx.h"


// place for any code that needs to be run on service initialization
void init(void);

// where the sleep and clock check functionality is located
int time_check(int = 10, int = 21);


// LIGHTING
// sets the Aura sync lights
void set_aura(int = 0);
// sets the hueplus lights
void set_hueplus(int = 0);
// sets the logitech peripheral lights
void set_logitech(int = 0);
// sets the nvidia gpu lights
void set_nvidia(int = 0);
