#include "userinterface.h"

char * getcondition(int condition, bool total = false, wagon *mywagon = NULL)
{
    using namespace condition;
    /*
     const static char DEAD        = 0;
     const static char TYPHOID     = 1;
     const static char DYSSENTARY  = 2;
     const static char MEASELS     = 3;
     const static char FEVER       = 4;
     const static char BROKENLEG   = 5;
     const static char BROKENARM   = 6;
     const static char SNAKEBITE   = 7;
     const static char HUNGRY      = 8;
     const static char GOOD        = 9;
     */
    if (total)
    {
        float totalcondition = 0;
        for (int i = 0; i < 5; i++)
            totalcondition += mywagon->party[i].condition;
        totalcondition /= 5;
        switch ((int)totalcondition)
        {
            case 0:
            case 1:
            case 2:
                return (char *)"very poor";
                break;
            case 3:
            case 4:
            case 5:
                return (char *)"poor";
                break;
            case 6:
            case 7:
            case 8:
                return (char *)"fair";
                break;
            case 9:
                return (char *)"good";
                break;
            default:
                return (char *)"unknown";
                break;
        }
    }
    switch (condition)
    {
        case DEAD:
            return (char *)"dead";
            break;
        case TYPHOID:
            return (char *)"typhoid fever";
            break;
        case DYSSENTARY:
            return (char *)"dyssentary";
            break;
        case MEASELS:
            return (char *)"measels";
            break;
        case FEVER:
            return (char *)"fever";
            break;
        case BROKENLEG:
            return (char *)"broken leg";
            break;
        case BROKENARM:
            return (char *)"broken arm";
            break;
        case SNAKEBITE:
            return (char *)"snake bite";
            break;
        case HUNGRY:
            return (char *)"hungry";
            break;
        case GOOD:
            return (char *)"good";
            break;
    }
    return (char *)"unknown";
}

void showstats(wagon &mywagon)
{
    printf("Stats page:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Member %d: condition: %-9s", i + 1, getcondition(mywagon.party[i].condition));
        if (i % 2 == 1)
            printf("\n");
        else
            printf("\t");
    }
    printf("You     : condition: %-9s\n", getcondition(mywagon.party[5].condition));
    printf("Food: %d   Total condition: %-9s Bullets: %d\n", mywagon.inventory.food,
           getcondition(0, true, &mywagon), mywagon.inventory.bullets);
    printf("Location: %d Clothes: %d Computed score: %d\n", mywagon.landmark, mywagon.inventory.clothes,
           compute_score(mywagon));
}
