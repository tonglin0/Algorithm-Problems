#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 200009
using namespace std;

int next[MN];

void getfail(char *s,int l1,int l2)
{
  int len=strlen(s);
  next[0]=next[1]=0;
  for (int i=1;i<len;i++)
  {
    int j=next[i];
    while(j&&s[i]!=s[j])
      j=next[j];
    next[i+1]=(s[i]==s[j])?j+1:0;
  }
}

int main()
{
  freopen("1867.in","r",stdin);
  freopen("1867.out","w",stdout);
  int n,i,j,k,m;
  char s1[MN],s2[MN];
  while(scanf("%s%s",s1,s2)==2)
  {
    int l1=strlen(s1),l2=strlen(s2);
    char ans1[MN],ans2[MN];
    char ts[MN];
	for (i=0;i<l1;i++)
      ts[i]=s1[i];
    for (i=0;i<l2;i++)
      ts[i+l1]=s2[i];
    ts[l1+l2]='\0';
	getfail(ts,l1,l2);
	if (next[l1+l2]>min(l1,l2))
	  next[l1+l2]=min(l1,l2);
	int tmpn=next[l1+l2];
	for (i=0;i<l2;i++)
	  ans1[i]=ts[l1+i];
	for (i=next[l1+l2];i<l1;i++)
	  ans1[l2+i-next[l1+l2]]=ts[i];
	ans1[max(max(l1,l2),l2+l1-next[l1+l2])]='\0';
	int len1=max(l1,max(l2,l1+l2-next[l1+l2]));
      for (i=0;i<l1;i++)
        ts[i]=s1[i];
      for (i=0;i<l2;i++)
        s1[i]=s2[i];
      for (i=0;i<l1;i++)
        s2[i]=ts[i];
      s1[l2]='\0';
      s2[l1]='\0';
	  swap(l1,l2);
	for (i=0;i<l1;i++)
	  ts[i]=s1[i];
    for (i=0;i<l2;i++)
      ts[i+l1]=s2[i];
    ts[l1+l2]='\0';
    getfail(ts,l1,l2);
    if (next[l1+l2]>min(l1,l2))
      next[l1+l2]=min(l1,l2);
    for (i=0;i<l2;i++)
      ans2[i]=ts[l1+i];
    for (i=next[l1+l2];i<l1;i++)
      ans2[i-next[l1+l2]+l2]=ts[i];
    ans2[max(l1,max(l1+l2-next[l1+l2],l2))]='\0';
      for (i=0;i<l1;i++)
        ts[i]=s1[i];
      for (i=0;i<l2;i++)
        s1[i]=s2[i];
      for (i=0;i<l1;i++)
        s2[i]=ts[i];
      s1[l2]='\0';
      s2[l1]='\0';
	  swap(l1,l2);
	int len2=max(max(l1,l2),l1+l2-next[l1+l2]);
    if (len1<len2)
    {
      printf("%s",s2);
      for (i=tmpn;i<l1;i++)
        printf("%c",s1[i]);
      printf("\n");
	}
    else if (len1>len2)
    {
      printf("%s",s1);
      for (i=next[l1+l2];i<l2;i++)
        printf("%c",s2[i]);
      printf("\n");
	}
	else
	{
	  if (strcmp(ans1,ans2)>0)
	    printf("%s\n",ans2);
	  else
	    printf("%s\n",ans1);
	}
  }
  return 0;
}
