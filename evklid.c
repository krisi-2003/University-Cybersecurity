#include <stdio.h>
#include <stdlib.h>

int NOD(int a,int b)
{
    while(a != b)
    {
        if(a > b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    return a;
}
int main()
{
    int a=0,b=0;
    printf("Добавете a: ");
    scanf("%d",&a);
    printf("Добавете b: ");
    scanf("%d",&b);
    int res=NOD(a,b);
    printf("%d - %d = NOD(%d)\n",a,b,res);

    return EXIT_SUCCESS;
}