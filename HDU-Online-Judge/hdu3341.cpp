#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
#include<string>
#include<vector>
#include<map>
#define eps 1e-8
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
using namespace std;

int tot;
int ch[504][5];
int f[121*121+2][502];
int last[504],next[504];
char st[45];
int sz[504];
map<char,int> tras;

void insert(char *s)
{
  int u=0,len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=tras[s[i]];
    if (!ch[u][c])
    {
      ch[u][c]=++tot;
      memset(ch[tot],0,sizeof(ch[tot]));
      sz[tot]=0;
	}
	u=ch[u][c];
  }
  sz[u]++;
}

void acgetfail()
{
  queue<int> q;
  next[0]=last[0]=0;
  for (int i=0;i<4;i++)
    if (ch[0][i])
    {
      int u=ch[0][i];
      q.push(u);
      last[u]=next[u]=0;
	}
  while(!q.empty())
  {
    int r=q.front();q.pop();
    for (int i=0;i<4;i++)
    {
      int u=ch[r][i];
      if (!u)
      {
        ch[r][i]=ch[next[r]][i];
        continue;
	  }
	  q.push(u);
	  int v=next[r];
	  next[u]=ch[v][i];
	  sz[u]+=sz[next[u]];
	  //last[u]=sz[next[u]]?next[u]:last[next[u]];
	  //sz[u]+=sz[last[u]];
	}
  }
}

void PRINT(int j,int &t)
{
  if (j)
  {
    t+=sz[j];
    if (last[j])
      PRINT(last[j],t);
  }
}

int main()
{
  freopen("3341.in","r",stdin);
  freopen("3341.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  tras['A']=0;tras['C']=1;tras['G']=2;tras['T']=3;
  while(scanf("%d",&n)==1)
  {
    if (n==0)
      break;
    memset(ch[0],0,sizeof(ch[0]));
    sz[0]=0;
    tot=0;
    for (i=1;i<=n;i++)
    {
      scanf("%s",st);
      insert(st);
	}
	scanf("%s",st);
	int n1=1,n2=1,n3=1,n4=1;
	int len=strlen(st);
	for (i=0;i<len;i++)
	  if (st[i]=='A')
	    n1++;
	  else if (st[i]=='C')
	    n2++;
	  else if (st[i]=='G')
	    n3++;
	  else
	    n4++;
	acgetfail();
	for (i=0;i<=n1*n2*n3*n4;i++)
	  for (j=0;j<=tot;j++)
	    f[i][j]=-INF;
	f[0][0]=0;
	int cnt=(n1-1)*n2*n3*n4+(n2-1)*n3*n4+(n3-1)*n4+n4-1;
    int tmp1=n2*n3*n4,tmp2=n3*n4,tmp3=n4;
	for (i=0;i<=cnt;i++)
	{
	  for (j=0;j<=tot;j++)
	  if (f[i][j]<0)
	    continue;
	  else
	  {
		for (k=0;k<4;k++)
        {
		  if (k==0)
          {
		    int t1=i/tmp1;
		    if (t1>=n1-1)
		      continue;
			f[i+tmp1][ch[j][k]]=max(f[i+tmp1][ch[j][k]],f[i][j]+sz[ch[j][k]]);
          }
		  else if (k==1)
		  {
            int t2=i%tmp1/tmp2;
            if (t2>=n2-1)
              continue;
			f[i+tmp2][ch[j][k]]=max(f[i+tmp2][ch[j][k]],f[i][j]+sz[ch[j][k]]);
          }
		  else if (k==2)
		  {
		  	int t3=i%tmp2/tmp3;
		  	if (t3>=n3-1)
		  	  continue;
            f[i+tmp3][ch[j][k]]=max(f[i+tmp3][ch[j][k]],f[i][j]+sz[ch[j][k]]);
          }
		  else
          {
          	int t4=i%tmp3;
          	if (t4>=n4-1)
          	  continue;
			f[i+1][ch[j][k]]=max(f[i+1][ch[j][k]],f[i][j]+sz[ch[j][k]]);
          }
		}
	  }
	}
	int ans=0;
	for (j=0;j<=tot;j++)
	  ans=max(ans,f[cnt][j]);
	printf("Case %d: %d\n",++ii,ans);
  }
  return 0;
}

