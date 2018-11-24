#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

int dp[12][109][109];
int ten[12];
int k;
bool vis[12][109][109];

int find(int a,int m1,int m2)
{
  if (vis[a][m1][m2])
    return dp[a][m1][m2];
  vis[a][m1][m2]=true;
  if (a==0)
  {
    if (m1==0&&m2==0)
      dp[a][m1][m2]=1;
    else
      dp[a][m1][m2]=0;
    return dp[a][m1][m2];
  }
  for (int i=0;i<=9;i++)
    dp[a][m1][m2]+=find(a-1,((m1-i)%k+k)%k,((m2-i*ten[a-1])%k+k)%k);
  return dp[a][m1][m2];
}

int fsum(int n)
{
  char s[14];
  sprintf(s,"%d",n);
  int len=strlen(s);
  int ans=0,d=0,ds=0;
  for (int i=0;i<len;i++)
  {
  	int da=len-i-1;
    for (int j=0;j<s[i]-'0';j++)
      ans+=find(da,(((-d-j))%k+k)%k,((-ds-ten[da]*j)%k+k)%k);
    d+=s[i]-'0';
    ds+=(s[i]-'0')*ten[da];
  }
  return ans;
}

int main()
{
  freopen("11361.in","r",stdin);
  freopen("11361.out","w",stdout);
  int a,b,T,i,j,m,n;
  ten[0]=1;
  for (i=1;i<=9;i++)
    ten[i]=10*ten[i-1];
  scanf("%d",&T);
  while(T--)
  {
  	memset(vis,0,sizeof(vis));
  	memset(dp,0,sizeof(dp));
    scanf("%d%d%d",&a,&b,&k);
    if (k>90)
      printf("0\n");
    else
      printf("%d\n",fsum(b+1)-fsum(a));
  }
  //printf("%.6lf\n",clock()/(double)CLOCKS_PER_SEC);
  return 0;
}
