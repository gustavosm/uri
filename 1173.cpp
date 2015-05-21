#include <stdio.h>
 
int main()
{
    int v[10];
     
    scanf("%d", &v[0]);
     
    printf("N[0] = %d\n", v[0]);
     
    for (int i = 1; i < 10; i++)
    {
        v[i] = v[i - 1] * 2;
         
        printf("N[%d] = %d\n", i, v[i]);
    }
}
