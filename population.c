/*
########################################################################
Determine how long it takes for a population to reach a particular size.
########################################################################

$ ./population
Start size: 100
End size: 200
Years: 9

## Background ##########################################################
Say we have a population of n llamas. Each year, n / 3 new llamas are born, and n / 4 llamas pass away.

For example, if we were to start with n = 1200 llamas, then in the first year, 1200 / 3 = 400 new llamas would be born
and 1200 / 4 = 300 llamas would pass away. At the end of that year, we would have 1200 + 400 - 300 = 1300 llamas.

To try another example, if we were to start with n = 1000 llamas, at the end of the year, we would have 1000 / 3 = 333.33 new llamas.
We can’t have a decimal portion of a llama, though, so we’ll truncate the decimal to get 333 new llamas born. 1000 / 4 = 250 llamas will pass away,
so we’ll end up with a total of 1000 + 333 - 250 = 1083 llamas at the end of the year.
*/
#include <stdio.h>

int read_input(int *target)
{
    int population = 0;

    while (1)
    {
        printf("Start size: ");
        scanf("%i", &population);
        if (population > 9)
            break;
        printf("invalid size\n");
    }

    while (1)
    {
        printf("End size: ");
        scanf("%i", target);
        if (*target > population)
            break;
        printf("invalid size\n");
    }

    return population;
}

int main(void)
{
    int population;
    int target;
    int year;

    year = 0;
    population = read_input(&target);

    while (population < target)
    {
        population += (population / 3) - (population / 4);
        year++;
    }

    printf("Years: %d\n", year);
    return 0;
}