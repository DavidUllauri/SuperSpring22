#pragma once

#include "TDEApp.h"

#define TDE_APPLICATION_START(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}