#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n,m;
  printf("Enter the speed limit: ");
  scanf("%d",&n);
  printf("Enter the recorded speed of the car: ");
  scanf("%d",&m);
  m-=n;
  if (m<=0)
  {
    printf("Congratulations, you are within the speed limit");
    return 0;
  }
  else
  {
    printf("You are speeding and your fine is $ ");
    if (m<=20)
    {
      printf("%d\n",100);
      return 0;
    }
    else if (m<=30)
    {
      printf("%d\n",270);
      return 0;
    }
    else printf("%d\n",500);
  }
  return 0;
} 
