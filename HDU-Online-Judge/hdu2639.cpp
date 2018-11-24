#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int w[109],v[109];
int f[1009][33];
int A[33],B[33];

int main()
{
  freopen("2639.in","r",stdin);
  freopen("2639.out","w",stdout);
  int n,i,j,k,m,ca,K;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d%d%d",&n,&m,&K);
    for (i=1;i<=n;i++)
      scanf("%d",&w[i]);
    for (i=1;i<=n;i++)
      scanf("%d",&v[i]);
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
      for (j=m;j>=v[i];j--)
      {
        for (k=1;k<=K;k++)
        {
          A[k]=f[j][k];
          B[k]=f[j-v[i]][k]+w[i];
        }
        A[K+1]=B[K+1]=-1;
        int a=1,b=1,c=1;
        while(c<=K&&(A[a]!=-1||B[b]!=-1))
        {
          if (A[a]>B[b])
            f[j][c]=A[a++];
          else
            f[j][c]=B[b++];
          if (f[j][c]!=f[j][c-1])
            c++;
        }
      }
    printf("%d\n",f[m][K]);
  }
  return 0;
}
