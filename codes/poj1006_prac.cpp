#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int mi[]={0,23,28,33};
int a[5];

void ex_gcd(int a,int b,int &d,int &x,int &y)
{
  if (b==0){d=a;x=1;y=0;}
  else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int main()
{
  freopen("1006.in","r",stdin);
  freopen("1006.out","w",stdout);
  int d,n,i,j,k,t,x,y,b,m,M,ii=0;
  for (i=1;i<=3;i++)
    scanf("%d",&a[i]);
  scanf("%d",&t);
  while(t>=0)
  {
    M=1;
    int ans=0;
    for (i=1;i<=3;i++)
      M*=mi[i];
    for (i=1;i<=3;i++)
    {
      int w=M/mi[i];
      ex_gcd(w,mi[i],d,x,y);
      ans=(ans+w*x*a[i]+M)%M;
    }
    ans=(ans-t+M)%M;
    if (ans==0) ans=21252;
    for (i=1;i<=3;i++)
      scanf("%d",&a[i]);
    scanf("%d",&t);
    printf("Case %d: the next triple peak occurs in %d days.\n",++ii,ans);
  }
  return 0;
}
