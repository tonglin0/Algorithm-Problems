#include<cstdio>
#include<iostream>
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
#define MN 300009
using namespace std;

int pos[MN];
lint a[MN],b[MN];
int cnt,n,u,sz;
char ch;

void read(int &x)
{
  while(ch=getchar(),ch<'0'||ch>'9');
  x=ch-'0';
  while(ch=getchar(),ch<='9'&&ch>='0') x=x*10+ch-'0';
}

void reset(int x)
{
  int l=(x-1)*sz+1,r=min(n,x*sz);
  for (int i=l;i<=r;i++)
    b[i]=a[i];
  sort(b+l,b+r+1);
}

int find(int x,int v)
{
  int st=(x-1)*sz+1,r=min(n,x*sz);
  if (b[st]>=v)
    return 0;
  int l=st;
  while(l<r)
  {
    int mid=(l+r+1)>>1;
    if (b[mid]<v)
      l=mid;
    else
      r=mid-1;
  }
  return l-st+1;
}

int query(int l,int r,int v)
{
  int ans=0;
  if (pos[l]==pos[r])
  {
    for (int i=l;i<=r;i++)
      if (a[i]<v)
        ans++;
    return ans;
  }
  for (int i=l;i<=pos[l]*sz;i++)
    if (a[i]<v)
      ans++;
  for (int i=(pos[r]-1)*sz+1;i<=r;i++)
    if (a[i]<v)
      ans++;
  for (int i=pos[l]+1;i<pos[r];i++)
    //ans+=lower_bound(b+(i-1)*sz+1,b+i*sz+1,v)-(b+(i-1)*sz+1);     注释掉的也对 
	ans+=find(i,v);
  return ans;
}

int get(int l,int r,int v)
{
  while(l<=r)
  {
    int mid=l+r>>1;
    if (b[mid]==v)
      return mid;
    if (b[mid]<v)
      l=mid+1;
    else
      r=mid-1;
  }
}

void maintain(int p,int y)
{
  int l=(pos[p]-1)*sz+1,r=min(n,pos[p]*sz);
  int k=get(l,r,a[p]);
  /*int k;
  for (k=l;k<=r;k++)
    if (b[k]==a[p])
      break;*/      // 注释掉的也对 
  a[p]=y;
  b[k]=y;
  while(k<r&&b[k+1]<b[k])
  {
    swap(b[k+1],b[k]);
    k++;
  }
  while(k>l&&b[k]<b[k-1])
  {
    swap(b[k-1],b[k]);
    k--;
  }
}

int main()
{
  freopen("12003.in","r",stdin);
  freopen("12003.out","w",stdout);
  int ca,i,j,k,m,ii=0;
  int qus;
  read(n);read(qus);read(u);
  sz=(int)sqrt(n+0.01);
  if (n%sz)
    cnt=n/sz+1;
  else
    cnt=n/sz;
  for (i=1;i<=n;i++)
  {
    cin>>a[i];
    pos[i]=(i-1)/sz+1;
  }
  for (i=1;i<=cnt;i++)
    reset(i);
  while(qus--)
  {
    int l,r,v,p;
    read(l);read(r);read(v);read(p);
    lint s=query(l,r,v);
    maintain(p,(lint)u*s/(r-l+1));
  }
  for (i=1;i<=n;i++)
    cout<<a[i]<<endl;
  return 0;
}

