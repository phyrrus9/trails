#ifndef __trails__travelprobabillity__
#define __trails__travelprobabillity__
#include "engine.h"
#include <unistd.h>
#include <stdio.h>
#endif

void  move_landmark (wagon &mywagon, int landmark);
void  sink_wagon    (wagon &mywagon);
void  eat_food      (wagon &mywagon);
void  hunt_food     (wagon &mywagon);
void  hurt_ai       (wagon &mywagon);
void  steal_things  (wagon &mywagon);
void  fort_shop     (wagon &mywagon);