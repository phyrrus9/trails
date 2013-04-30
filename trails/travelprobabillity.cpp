#include <stdlib.h>
#include <time.h>
#include "travelprobabillity.h"

extern char * getcondition(int condition, bool total = false, wagon *mywagon = NULL);

void move_landmark(wagon &mywagon, int landmark)
{
    int speed = mywagon.speed;
    int miles = landmark - mywagon.landmark; //distance in miles
    int hurt_rand = 0;
    for ( ; miles > 0 ; hurt_rand = rand() % 25 )
    {
        miles -= speed;
        //mywagon.date++
        eat_food(mywagon);
        if (hurt_rand < 5)
            hurt_ai(mywagon);
        sleep(1);
        if (miles > 0)
            printf("%d miles until next landmark\n", miles);
    }
    mywagon.landmark = landmark;
}

void sink_wagon(wagon &mywagon)
{
    srand((int)time(0));
    int result = rand() % 10;
    if (result < 6)
    {
        printf("Your wagon sank..\n");
        result = rand() % 16;
        int losses = 0;
        switch (result)
        {
            case 15: //clothes
            case 14:
                losses = rand() % 4;
                losses = losses > mywagon.inventory.clothes ? mywagon.inventory.clothes : losses;
                printf("You lost %d sets of clothes\n", losses);
                break;
            default:
                break;
        }
    }
}

void eat_food(wagon &mywagon)
{
    mywagon.inventory.food -= mywagon.food; //sub foot_contents, food_speed
}

void hunt_food(wagon &mywagon)
{
    if (mywagon.inventory.bullets <= 0)
    {
        printf("You cannot hunt without bullets\n");
        return;
    }
    srand((int)time(0));
    int got = 0, carried = 0, bullets = 0, i;
    do
    {
        printf("How many bullets would you like to use? (you have %d)\n", mywagon.inventory.bullets);
        scanf("%d", &bullets);
    } while (bullets > mywagon.inventory.bullets);
    for (i = 0; i < bullets; i++)
    {
        carried += rand() % 100;
    }
    carried = got > 5 ? rand() % got : got;
    printf("You killed %d pounds of food, and carried %d back\n", got, carried);
    mywagon.inventory.food += carried;
}

void hurt_ai(wagon &mywagon)
{
    srand((int)time(0));
    int seed = rand() % 5;
    int damage = rand() % 2;
    int test = rand() % 50;
    if (test < 25)
    {
        if (mywagon.party[seed].condition - damage > condition::DEAD)
        {
            mywagon.party[seed].condition -= damage;
        }
        printf("Member %d got sick\n", seed);
    }
}

void steal_things(wagon &mywagon)
{
    
}

int select_fort(int landmark)
{
    for (int i = 0; i < NUM_FORTS; i++)
    {
        if (forts[i] == landmark)
            return i;
    }
    return -1;
}

void fort_shop(wagon &mywagon)
{
    int fort = select_fort(mywagon.landmark);
    printf("Price listing:\n"
           "1 Ox                     : $%2.2f  1 pound of food : $%2.2f\n"
           "1 box of bullets (20/box): $%2.2f  1 set of clothes: $%2.2f\n",
           prices[fort].ox, prices[fort].food, prices[fort].bullets, prices[fort].clothes);
    printf("You have $%2.2f\n", mywagon.inventory.money);
    scanf("%d", &fort);
}
