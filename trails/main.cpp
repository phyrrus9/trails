#include <iostream>
#include "engine.h"
#include "userinterface.h"
#include "travelprobabillity.h"

int select_occupation(int occupation)
{
    switch (occupation)
    {
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 4;
        case 7:
            return 5;
        case 9:
            return 6;
    }
    return 6;
}

void get_occupation(wagon &mywagon)
{
    int selection = 0;
    do
    {
        printf("Please select your occupation:\n"
               "1. Banker    2. Doctor    3. Blacksmith\n"
               "4. Hatter    5. Farmer    7. Teacher\n"
               "9. Peasant\n");
        scanf("%d", &selection);
    } while (selection < 0 || selection > 9 || (selection == 6 || selection == 8));
    mywagon.party[6].occupation = selection - 1;
    mywagon.inventory.money = startmoney[selection - 1];
    fort_shop(mywagon);
}

int main(int argc, const char * * argv)
{
    wagon mywagon;
    initdata(mywagon);
    get_occupation(mywagon);
    mywagon.speed = 30;
    mywagon.food  = 01;
    mywagon.landmark = 0;
    int pathnum = 0;
    //if (argc > 1)
      //  mywagon.landmark = atoi(argv[1]);
    while (mywagon.landmark < 4000)
    {
        //printf("Location: %d\n", mywagon.landmark);
        paths a = find_path(mywagon);
        pathnum = determine_path(a);
        move_landmark(mywagon, routes[pathnum].b);
        showstats(mywagon);
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

