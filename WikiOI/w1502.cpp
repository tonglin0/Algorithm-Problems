#include<stdio.h>
#include<stdlib.h>

int main()
{
  int r=0,n,m;
  scanf("%d%d",&n,&m);
  if (n%400==0)
    r=1;
  else if (n%100==0)
    r=0;
  else if (n%4==0)
    r=1;
  switch(m)
  {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:printf("31");break;
    case 4:
    case 6:
    case 9:
    case 11:printf("30");break;
    default: 
      if (r)
        printf("29");
      else 
        printf("28");
  }
  return 0;
} 
