#include<cstdio>
#include<cstdlib>
#include<cstring>
#define LL long long
using namespace std;

void ex_gcd(LL a,LL b,LL &d,LL &x,LL &y)
{
  if (b==0){d=a;x=1;y=0;}
  else {ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int main()
{
  freopen("2115.in","r",stdin);
  freopen("2115.out","w",stdout);
  LL a,b,c,i,j,n,m,k,p,A,B,C,X,Y,d;
  scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&k);
  while(a!=0||b!=0||c!=0||k!=0)
  {
    p=(LL)1<<k;
    A=c;B=p;C=b-a;
    ex_gcd(A,B,d,X,Y);
    if (C%d)
      printf("FOREVER\n");
    else
    {
      LL b2=B/d;
      LL ans=((X%b2+b2)%b2*C/d%b2+b2)%b2;
      printf("%I64d\n",ans);
    }
    scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&k);
  }
  return 0;
}
