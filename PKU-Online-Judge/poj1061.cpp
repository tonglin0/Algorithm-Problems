#include<cstdio>
#include<cstdlib>
#define LL long long
using namespace std;

void ex_gcd(LL a,LL b,LL &d,LL &x,LL &y)
{
  if (b==0){d=a;x=1;y=0;}
  else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int main()
{
  freopen("1061.in","r",stdin);
  freopen("1061.out","w",stdout);
  LL a,b,m,n,x,d,y,X,L,Y;
  scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&L);
  a=((m-n)%L+L)%L;
  b=L;
  LL c=((y-x)%L+L)%L;
  ex_gcd(a,b,d,X,Y);
  if (c%d)
    printf("Impossible\n");
  else
  {
    LL b2=b/d;
    LL ans=(X*c/d%b+b)%b;
    //LL ans=((X%b2+b2)%b2*c/d)%b;
    //LL ans=(X%b+b)%b*c/d;
    printf("%I64d\n",ans);
  }
  return 0;
}
