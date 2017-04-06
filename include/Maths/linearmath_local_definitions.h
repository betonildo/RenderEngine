#ifndef DEFINITIONS_H
#define DEFINITIONS_H

//#define USE_SSE 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstddef>
#include <iostream>
#include <math.h>
#include "SSEs.h"
#define LF "\n"
#define PI 3.1415

// Converts degrees to radians.
#define ToRadians(angleDegrees) ((angleDegrees) * PI / 180.0)

// Converts radians to degrees.
#define ToDegrees(angleRadians) ((angleRadians) * 180.0 / PI)

#define PRECISION 0.000001
typedef unsigned char byte;
#endif /*DEFINITIONS_H*/