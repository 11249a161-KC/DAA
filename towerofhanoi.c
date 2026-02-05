#include<stdio.h>
void th(int, char, char, char);
void th(int k, char x, char y, char z)
{
    if(k==1)
    {
        printf("%c to %c\n", x,y);
    }
    else
    {
        th(k-1,x,z,y);
        printf("%c to %c\n",x,z);
        th(k-1,z,y,x);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    th(n,'A','B','C');
    
    return 0;
}