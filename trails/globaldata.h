#ifndef trails_globaldata_h
#define trails_globaldata_h

#define NUM_ROUTES 83
#define NUM_FORTS  16
#define NUM_RIVERS 5
#define NUM_HUNTS  5

namespace weather
{
    const static char CLEAR = 0;
    const static char RAINY = 1;
    const static char SNOWY = 2;
    const static char BLIZZ = 3;
    const static char DRY   = 4;
    const static char DROUT = 5;
    const static char FLOOD = 6;
}

namespace condition
{
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
    
    const static char GOODHEALTH  = 7;
    const static char FAIRHEALTH  = 4;
    const static char POORHEALTH  = 2;
    const static char VERYPOORHL  = 0;
}

namespace occupations
{
    const static char BANKER     = 1;
    const static char DOCTOR     = 2;
    const static char BLACKSMITH = 3;
    const static char HATTER     = 4;
    const static char FARMER     = 5;
    const static char TEACHER    = 7;
    const static char PEASANT    = 9;
}

typedef struct _person
{
    int condition;
    int occupation;
} person;

typedef struct _line
{
    int a, b;
} line;

typedef struct _paths
{
    int num_paths;
    int pathnums[5];
} paths;

typedef struct _pack
{
    int oxen;
    int clothes;
    int food;
    int bullets;
    float money;
} pack;

typedef struct _date
{
    int month;
    int day;
} datetime;

typedef struct _price
{
    float ox;      //1 ox
    float food;    //1 lb of food
    float bullets; //20 bullets/box
    float clothes; //1 set of clothes
} price;

struct wagon
{
    int currentpath;    //path number
    int position;       //position in miles
    int landmark;       //mi marker of next stop
    int prevmark;       //mi marker of last stop
    int speed;          //miles/day
    int food;           //food consumed inlb/person/day
    int weather;        //weather conditions
    int totalcondition; //condition of all people in wagon
    person party[6];    //collection of your travellers
    pack inventory;     //contents of your wagon
    datetime date;      //current date (affects weather)
};

const static line routes[NUM_ROUTES] = {
    { 0,    90   },
    { 90,   200  },
    { 200,  350  },
    { 350,  550  },
    { 550,  700  },
    { 700,  900  },
    { 900,  1300 },
    { 1300, 1500 },
    { 1500, 1600 },
    { 1600, 1750 },
    { 1750, 1900 },
    { 1900, 2000 },
    { 90,   300  },
    { 300,  500  },
    { 500,  600  },
    { 600,  800  },
    { 800,  1000 },
    { 1000, 1200 },
    { 1200, 1400 },
    { 1400, 1500 },
    { 1500, 1650 },
    { 1650, 1700 },
    { 1700, 1800 },
    { 1800, 1950 },
    { 1950, 2000 },
    { 90,   190  },
    { 190,  345  },
    { 345,  600  },
    { 550,  800  },
    { 900,  1200 },
    { 1900, 1950 },
    { 2000, 2400 },
    { 2000, 2350 },
    { 2000, 2300 },
    { 2000, 2090 },
    { 2400, 2590 },
    { 2400, 2500 },
    { 2350, 2470 },
    { 2350, 2420 },
    { 2300, 2470 },
    { 2300, 2410 },
    { 2300, 2420 },
    { 2420, 2600 },
    { 2420, 2470 },
    { 2590, 2690 },
    { 2590, 2800 },
    { 2690, 2950 },
    { 2690, 3000 },
    { 2630, 2690 },
    { 2630, 3000 },
    { 2630, 2700 },
    { 2630, 2970 },
    { 2900, 2970 },
    { 2900, 2960 },
    { 2950, 3000 },
    { 2950, 3100 },
    { 2970, 3000 },
    { 2970, 3075 },
    { 3075, 3300 },
    { 3075, 3330 },
    { 3075, 3320 },
    { 3075, 3200 },
    { 3300, 3325 },
    { 3300, 3350 },
    { 3300, 4000 },
    { 2700, 2900 },
    { 2600, 2670 },
    { 2670, 2750 },
    { 2750, 2900 },
    { 2960, 3075 },
    { 3300, 3310 },
    { 3310, 3320 },
    { 3320, 3330 },
    { 3330, 4000 },
    { 3000, 3300 },
    { 2800, 2950 },
    { 2470, 2630 },
    { 2410, 2600 },
    { 2500, 2630 },
    { 2090, 2420 },
    { 3100, 3300 },
    { 3325, 3370 },
    { 3350, 3370 }
};

const static
int  forts[NUM_FORTS] = {
    90, 345, 350, 1000, 1100, 1500, 1200, 1950,
    2090, 2500, 2600, 2630, 2970, 3000, 3300, 3330
};

const static int  rivers[NUM_RIVERS] = {
    300, 800, 1400, 1750, 1900
};

const static int  hunts[NUM_HUNTS] = {
    550, 600, 1200, 1300, 1600
};

const static price  prices[NUM_FORTS + 1] = {
    { 10.00, 00.15, 00.20, 01.00 },
    { 12.00, 01.15, 00.25, 03.00 },
    { 20.00, 03.15, 00.30, 05.00 },
    { 25.00, 04.50, 00.40, 07.00 },
    { 27.40, 10.75, 00.50, 09.00 },
    { 30.10, 11.00, 01.00, 11.00 },
    { 30.40, 12.00, 15.00, 13.00 },
    { 50.00, 15.00, 30.00, 15.00 },
    
    { 10.00, 00.15, 00.20, 01.00 },
    { 12.00, 01.15, 00.25, 03.00 },
    { 20.00, 03.15, 00.30, 05.00 },
    { 25.00, 04.50, 00.40, 07.00 },
    { 27.40, 10.75, 00.50, 09.00 },
    { 30.10, 11.00, 01.00, 11.00 },
    { 30.40, 12.00, 15.00, 13.00 },
    { 50.00, 15.00, 30.00, 15.00 },
    
    { 09.00, 00.11, 00.18, 00.89 }
};

static const int startmoney[10] = {
    20000,
    15000,
    10000,
    05000,
    03000,
    00000,
    00500,
    00000,
    00300
};

#endif

extern void initdata(wagon &t);
