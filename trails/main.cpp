#include <iostream>
#include "engine.h"
#include "userinterface.h"
#include "travelprobabillity.h"

//extern void showstats(wagon &mywagon);
//extern void move_landmark(wagon &mywagon, int landmark);

int main(int argc, const char * * argv)
{
    wagon mywagon;
    initdata(mywagon);
    mywagon.speed = 30;
    mywagon.landmark = 0;
    int pathnum = 0;
    while (mywagon.landmark < 2000)
    {
        showstats(mywagon);
        printf("Location: %d\n", mywagon.landmark);
        paths a = find_path(mywagon);
        pathnum = determine_path(a);
        move_landmark(mywagon, routes[pathnum].b);
        if (check_fort(mywagon.landmark))
        {
            char buy = 0;
            printf("You are at a fort, would you like to buy things?");
            scanf("%d", (int *)&buy);
            if (buy == 1)
                fort_shop(mywagon);
        }
        if (check_hunt(mywagon.landmark))
        {
            char hunt = 0;
            printf("You are at a hunting zone, would you like to hunt?");
            scanf("%d", (int *)&hunt);
            if (hunt == 1)
                hunt_food(mywagon);
        }
        if (check_river(mywagon.landmark))
        {
            char river = 0;
            bool done = false;
            bool sank = false;
            while (!done)
            {
                printf("You are at a river crossing, which would you like to do?\n"
                       "1. Try to go across the river\n"
                       "2. Try to float across the river\n"
                       "3. Pay $5.00 for the ferry\n");
                scanf("%d", (int *)&river);
                if (river < 1 || river > 3)
                    continue;
                if (river == 1)
                    done = true;
                if (river == 2)
                {
                    sink_wagon(mywagon);
                    done = true;
                }
                if (river == 3)
                {
                    if (mywagon.inventory.money < 5)
                        printf("Not enough money\n");
                    else
                    {
                        mywagon.inventory.money -= 5;
                        done = true;
                    }
                }
            }
        }
    }
    printf("You have reached the goal!\n");
}

