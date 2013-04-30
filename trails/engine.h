#include "globaldata.h"
#include "travelprobabillity.h"
#include "userinterface.h"
#ifndef trails_engine_h
#define trails_engine_h

paths find_path      (wagon &t);        //find all possible paths from point.
int   determine_path (paths &t);        //pick a route to use
bool  check_fort     (int position);    //check if is a fort
bool  check_river    (int position);    //check for river crossing
bool  check_hunt     (int position);    //check if can hunt

#endif
