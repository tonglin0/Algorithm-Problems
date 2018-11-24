#include<stdio.h>
#include<stdlib.h>

int gcd(int a,int b)
{
  if (b==0) return a;
  else return gcd(b,a%b);    
}
int main()
{
  int a,b,i;
  while (scanf("%d%d",&a,&b)!=EOF)
    printf("%d\n",gcd(a,b));
  //system("pause");
  return 0;
} 
