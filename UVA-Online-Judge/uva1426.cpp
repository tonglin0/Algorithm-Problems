#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
#include<cmath>
#define lint long long
using namespace std;

lint X,R,N;
set<lint> anss;

void ex_gcd(lint a,lint b,lint &d,lint &x,lint &y)
{
  if (b==0){d=a;x=1;y=0;}
  else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

void work(lint a,lint c,lint b)
{
  lint d,x,y;
  ex_gcd(a,b,d,x,y);
  if (c%d)
    return ;
  lint b2=b/d;
  x=x*(c/d);
  x=(x%b2+b2)%b2;
  lint lcm=a/d*b;
  for (lint i=0;a*(x+i*b2)-R<=N;i++)
  {
    lint t=x+i*b2;
    lint ans=a*t-R;
    if (ans>=0&&ans<N&&ans*ans%N==X)
      anss.insert(ans);
  }
  /*x=a*x-R;
  for (;x<N;x+=lcm)
    if (x>=0&&x<N&&x*x%N==X)
      anss.insert(x);*/                               //注释部分是另一种写法，也是正确的。 
}

int main()
{
  freopen("1426.in","r",stdin);
  freopen("1426.out","w",stdout);
  lint ii=0,n,i,j,k,m;
  while(scanf("%lld%lld%lld",&X,&N,&R)==3&&(X+N+R))
  {
    printf("Case %lld:",++ii);
    anss.clear();
    m=(lint)sqrt(N+0.5);
    for (i=1;i<=m;i++)
      if (N%i==0)
	  {
        work(N/i,2*R,i);
        work(i,2*R,N/i);
	  }
	anss.insert(R);
	set<lint>::iterator it;
	for (it=anss.begin();it!=anss.end();it++)
	  printf(" %lld",*it);
    printf("\n");
  }
  return 0;
}
