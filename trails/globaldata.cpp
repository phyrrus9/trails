#include "globaldata.h"

void initdata(wagon &t)
{
    for (int i = 0; i < 6; i++)
    {
        t.party[i].condition = condition::GOOD;
        t.party[i].occupation = occupations::BANKER;
    }
    t.inventory.clothes = 0;
    t.inventory.food    = 0;
    t.inventory.money   = 0;
    t.inventory.oxen    = 0;
    t.inventory.bullets = 0;
    
    t.currentpath       = 0;
    t.food              = 0;
    t.landmark          = 0;
    t.prevmark          = 0;
    t.position          = 0;
    t.speed             = 0;
    t.totalcondition    = condition::GOODHEALTH;
    t.weather           = weather::CLEAR;
}