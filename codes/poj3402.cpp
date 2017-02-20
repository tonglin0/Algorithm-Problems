#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cctype>
#define MN 28
using namespace std;

bool ori[MN][MN],a[MN][MN],b[MN][MN];

int main()
{
  freopen("3402.in","r",stdin);
  freopen("3402.out","w",stdout);
  int n,i,j,k,m,s;
  scanf("%d%d%d",&n,&m,&k);
  memset(a,0,sizeof(a));
  memset(ori,0,sizeof(ori));
  memset(b,0,sizeof(b));
  for (i=1;i<=k;i++)
  {
    char ch;
    int u;
    scanf("%c",&ch);
    while(!isalpha(ch)) scanf("%c",&ch);
    scanf("%d",&u);
    int v=ch-'a'+1;
    ori[v][u]=true;
    for (int x=1;x<=n;x++)
      a[x][u]=true;
    for (int y=1;y<=m;y++)
      a[v][y]=true;
    int w=v-u;
    for (int x=1;x<=n;x++)
    {
      int y=x-w;
      if (y>=1&&y<=m)
        a[x][y]=true;
    }
    w=v+u;
    for (int x=1;x<=n;x++)
    {
      int y=w-x;
      if (y>=1&&y<=m)
        a[x][y]=true;
    }
  }
  int dx,dy,ans=-1;
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
      if (ori[i][j]) continue;
      memcpy(b,a,sizeof(a));
      for (int x=1;x<=n;x++)
        b[x][j]=true;
      for (int y=1;y<=m;y++)
        b[i][y]=true;
      int w=i-j;
      for (int x=1;x<=n;x++)
      {
        int y=x-w;
        if (y>=1&&y<=m)
          b[x][y]=true;
      }
      w=i+j;
      for (int x=1;x<=n;x++)
      {
        int y=w-x;
        if (y>=1&&y<=m)
          b[x][y]=true;
      }
      int s=0;
      for (int x=1;x<=n;x++)
        for (int y=1;y<=m;y++)
          if (!b[x][y])
            s++;
      if (s>ans)
      {
        ans=s;
        dx=i;
        dy=j;
      }
      else if (s==ans)
      {
        if (i==dx)
        {
          char s1[100],s2[100];
          memset(s1,0,sizeof(s1));
          memset(s2,0,sizeof(s2));
          sprintf(s1,"%d",dy);
          sprintf(s2,"%d",j);
          if (strcmp(s1,s2)>0)
            dy=j;
        } 
      }
    }
  printf("%c%d\n",dx+'a'-1,dy);
  printf("%d\n",ans);
  return 0;
}
