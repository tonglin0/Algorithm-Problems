#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
  char a[100000];
  char ch;
  int n;
  n='C'-'J';
  while(scanf("%s",a)==1)
  {
    int i;
    for (i=0;i<=strlen(a)-1;i++)
      printf("%c",a[i]+n);
    printf("\n");
  }
  //system("pause");
  return 0;
} 
