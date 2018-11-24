#include<stdio.h>
#include<stdlib.h>

int main()
{
  unsigned int a,b,c;
  scanf("%u%u%u",&a,&b,&c);
  if (a+b>c&&b+c>a&&a+c>b)
    printf("Yes");
  else printf("No");
  //system("pause");
  return 0;
} 
