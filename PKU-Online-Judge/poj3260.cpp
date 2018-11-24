#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int v[105],num[104];
int f[24405];
int f1[24405];
int A[24405],B[24406];
int ff,r;

void insert(int x,int y)
{
  while(r>=ff&&B[r]>=y)
    r--;
  B[++r]=y;
  A[r]=x;
}

int main()
{
  freopen("3260.in","r",stdin);
  freopen("3260.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    scanf("%d",&v[i]);
  for (i=1;i<=n;i++)
    scanf("%d",&num[i]);
  int MN=m+14401;
  for (i=1;i<=MN;i++)
    f1[i]=(int)1e9;
  f1[0]=0;
  for (i=1;i<=n;i++)
    for (j=v[i];j<=MN;j++)
      f1[j]=min(f1[j],f1[j-v[i]]+1);
  for (i=1;i<=MN;i++)
    f[i]=(int)1e9;
  f[0]=0;
  for (i=1;i<=n;i++)
  {
    if (num[i]*v[i]>MN)
      num[i]=MN/v[i];
	for (int d=0;d<v[i];d++)
    {
      ff=1;r=0;
      for (j=0;j<=(MN-d)/v[i];j++)
      {
        insert(j,f[j*v[i]+d]-j);
        while(A[ff]<j-num[i])
          ff++;
        f[j*v[i]+d]=B[ff]+j;
	  }
	}
  }
  int ans=(int)1e9;
  int x1,x2;
  for (i=m;i<=MN;i++)
    ans=min(ans,f[i]+f1[i-m]);
  if (ans==(int)1e9)
    printf("-1\n");
  else
    printf("%d\n",ans);
  return 0;
}
