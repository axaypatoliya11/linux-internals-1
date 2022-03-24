#include <stdio.h>
int main()
{
    int N, count=0;

    printf("enter the value of N\n");
    scanf("%d", &N);

    // num = 2;
    for (int i = 2; i <=N; i++)
    {

        for (int j = 1; j <=i; j++)
        {
            // int rem = ;
            if (i % j == 0)
            {
                count++;
            }
        }
        if (count == 2)
        {
            printf("%d\n", i);
            // c++;
        }
        count=0;
        // num++;
    }
return 0;
}