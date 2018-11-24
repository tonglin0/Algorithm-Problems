#include<stdio.h>
#include<stdlib.h>

int area(int x,int y)
{
  return x*y;   
}
int main()
{
  int a,b,c,d,e,f,ans=0;
  scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
  ans=area(a,b)-area(c,d)-area(e,f);
  printf("%d\n",ans);
  //system("pause");
  return 0;
} 
