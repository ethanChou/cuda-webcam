#pragma once

#include "cudaCommon.h"

void deviceInvertLaunch(
	float *d_Image,
	int width,
	int height
	);