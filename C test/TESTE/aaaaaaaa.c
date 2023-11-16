#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 4

int main()
{
    srand(time(NULL));
    printf("start");
    int m[max][max], count = 0;

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            m[i][j] = rand()% 4;
            if (m[i][j] >= 10)
            {
                count++;
            }
        }
    }
    printf("%daaaaaa", count);
    return 0;
}
