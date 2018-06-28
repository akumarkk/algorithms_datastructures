#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void
target_sum(int *a, int n, int target)
{
    int map[10000];
    int diff;

    for(int i=0; i<n; i++)
    {
        diff = target - a[i];
        if(map[diff])
        {
            printf("(%d, %d) = %d\n", a[i], diff, target);
        }

        map[a[i]] = true;
    }
}

int
main()
{
    int a[100], n, target;

    printf("# of elements   :   ");
    scanf("%d", &n);

    printf("Array elements  :   ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Target Value    :   ");
    scanf("%d", &target);

    target_sum(a, n, target);

    return 0;
}
