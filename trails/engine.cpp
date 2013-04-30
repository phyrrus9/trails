#include "engine.h"
#include <stdio.h>
#include <stdlib.h>

paths find_path(wagon &t)
{
    paths tmp;
    //int possible[5]; //max of 5
    int pos = t.landmark;
    tmp.num_paths = 0;
    if (t.landmark == 2000)
    {
        tmp.num_paths = -1;
        return tmp;
    }
    for (int i = 0, x = 0; i < NUM_ROUTES; i++)
    {
        if (routes[i].a == pos)
        {
            tmp.num_paths++;
            tmp.pathnums[x++] = i;
        }
    }
    return tmp;
}

int determine_path(paths &t)
{
    int pathnum = -1;
    if (t.num_paths == -1)
        return -1;
    if (t.num_paths == 1 || routes[t.pathnums[0]].a == 0)
        return t.pathnums[0];
    while (pathnum < 0)
    {
        printf("You are at a trail crossing, you may take "
               "the following paths\n");
        for (int i = 0; i < t.num_paths; i++)
        {
            printf("%d %d->%d\n", i + 1, routes[t.pathnums[i]].a, routes[t.pathnums[i]].b);
        }
        scanf("%d", &pathnum);
        if (pathnum < 1 || pathnum > t.num_paths)
            pathnum = -1;
        else
            pathnum = t.pathnums[pathnum - 1];
    }
    return pathnum;
}

bool check_fort(int position)
{
    for (int i = 0; i < NUM_FORTS; i++)
        if (position == forts[i])
            return true;
    return false;
}

bool check_river(int position)
{
    for (int i = 0; i < NUM_RIVERS; i++)
        if (position == rivers[i])
            return true;
    return false;
}

bool check_hunt(int position)
{
    for (int i = 0; i < NUM_HUNTS; i++)
        if (position == hunts[i])
            return true;
    return false;
}
