#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

int m[]={0,23,28,33};
int a[5];

void ex_gcd(int a,int b,int &d,int &x,int &y)
{
  if (b==0){d=a;x=1;y=0;}
  else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int main()
{
  freopen("756.in","r",stdin);
  freopen("756.out","w",stdout);
  int d,M,n,i,j,k,x,y,cur,ii=0;
  while(scanf("%d%d%d%d",&a[1],&a[2],&a[3],&cur)==4)
  {
    if (cur==-1)
      break;
	M=1;
    for (i=1;i<=3;i++)
      M*=m[i];
    int ans=0;
    for (i=1;i<=3;i++)
    {
      int mi=M/m[i];
      ex_gcd(mi,m[i],d,x,y);
      x*=a[i];
      x=(x%m[i]+m[i])%m[i];
      ans=(ans+x*mi%M)%M;
	}
	ans=(ans-cur+M)%M;
	if (ans==0)
	  printf("Case %d: the next triple peak occurs in %d days.\n",++ii,M);
	else
	  printf("Case %d: the next triple peak occurs in %d days.\n",++ii,ans);
  }
  return 0;
}
