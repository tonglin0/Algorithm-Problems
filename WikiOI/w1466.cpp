#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n;
  scanf("%d",&n);
  if (n%400==0) 
    printf("%d",366);
  else if (n%100==0)
    printf("%d",365);
  else if (n%4==0)
    printf("%d",366);
  else 
    printf("365");
  printf("\n");
  return 0;
} 
