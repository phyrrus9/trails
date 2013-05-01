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
#ifdef _WIN32
        Sleep(1000);
#else
        sleep(1);
#endif
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
                mywagon.inventory.clothes -= losses;
                break;
            case 13:
            case 12:
                losses = rand() % 100;
                losses = losses > mywagon.inventory.bullets ? mywagon.inventory.bullets : losses;
                printf("You lost %d bullets\n", losses);
                mywagon.inventory.bullets -= losses;
            case 11:
            case 10:
                losses = rand() % 100;
                losses = losses > mywagon.inventory.food ? mywagon.inventory.food : losses;
                printf("You lost %d pounds of food\n", losses);
                mywagon.inventory.food -= losses;
            default:
                break;
        }
    }
}

void eat_food(wagon &mywagon)
{
    int num_alive = 0;
    for (int i = 0; i < 6; i++)
        if (mywagon.party[i].condition > condition::DEAD)
            num_alive++;
    mywagon.inventory.food -= mywagon.food * num_alive; //sub foot_contents, food_speed
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
        got += rand() % 100;
    }
    carried = got > 5 ? rand() % got : got;
    printf("You killed %d pounds of food, and carried %d back\n", got, carried);
    mywagon.inventory.food    += carried;
    mywagon.inventory.bullets -= bullets;
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
    else if (test < 35)
    {
        if (mywagon.party[seed].condition > condition::DEAD &&
            mywagon.party[seed].condition < condition::GOOD)
        {
            mywagon.party[seed].condition++;
            printf("Member %d got better\n", seed);
        }
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
    return NUM_FORTS;
}

void fort_shop(wagon &mywagon)
{
    int fort = select_fort(mywagon.landmark);
    int selection = 1<<16;
    int buy[4] = { 0, 0, 0, 0 };
    float buy_total = 0.0;
    while (selection > 0 || buy_total > mywagon.inventory.money)
    {
        buy_total =
        (buy[0]       *   prices[fort].ox     ) +
        (buy[1]       *   prices[fort].food   ) +
        (buy[2]       *   prices[fort].bullets) +
        (buy[3]       *   prices[fort].clothes);
        printf("Price listing:\n"
               "1. 1 Ox                     : $%-2.2f : %-3d  2. 1 pound of food : $%-2.2f : %-3d\n"
               "3. 1 box of bullets (20/box): $%-2.2f : %-3d  4. 1 set of clothes: $%-2.2f : %-3d\n",
               prices[fort].ox,      buy[0],
               prices[fort].food,    buy[1],
               prices[fort].bullets, buy[2],
               prices[fort].clothes, buy[3]);
        printf("You have $%2.2f\n", mywagon.inventory.money);
        printf("Total used in buy: $%2.2f\n", buy_total);
        scanf("%d", &selection);
        if (selection > 0 && selection < 5)
        {
            printf("Quantity? ");
            scanf("%d", (int *)&buy[selection - 1]);
        }
    }
    mywagon.inventory.money   -= buy_total;
    mywagon.inventory.oxen    += buy[0];
    mywagon.inventory.food    += buy[1];
    mywagon.inventory.bullets += buy[2] * 20;
    mywagon.inventory.clothes += buy[3];
}
