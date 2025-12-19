#include<stdio.h>
int main()
{
    int r;
    float PI=3.142,area;


   printf("Enter the radius");
   scanf("%d",&r);


area=4*PI*r*r;
   printf("surface area=%.2f\n", area);

return 0;
}
