#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  char a[105];
  int i,l;
  scanf("%s",a);
  l=strlen(a);
  for (i=0;i<=l-1;i++)
    printf("%c",a[i]);
  printf("\n");
  //printf("%s\n",a);
  //system("pause");
  return 0;
} 
