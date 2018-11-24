#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
	int sz,val;
	node *next[2];
};
char st[19];
node *head;

void insert(char *s)
{
  node *u=head;
  int len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=s[i]-'0';
    if (u->next[c]==NULL)
    {
      u->next[c]=new node;
      u->next[c]->val=u->next[c]->sz=0;
      u->next[c]->next[0]=u->next[c]->next[1]=0;
	}
	u=u->next[c];
	u->sz++;
  }
  u->val=1;
}

bool dfs(node *u)
{
  bool flag=true;
  if (u->val==1&&u->sz>=2)
    return false;
  if (u->next[0]!=NULL)
    flag=flag&&dfs(u->next[0]);
  if (u->next[1]!=NULL)
    flag=flag&&dfs(u->next[1]);
  return flag;
}

void release(node *u)
{
  for (int i=0;i<=1;i++)
    if (u->next[i]!=NULL)
      release(u->next[i]);
  delete u;
}

int main()
{
  freopen("1056.in","r",stdin);
  freopen("1056.out","w",stdout);
  int n,i,j,ii=0,k,m;
  node *p;
  while(scanf("%s",st)==1)
  {
    head=new node;
    head->sz=head->val=0;
    head->next[0]=head->next[1]=NULL;
    insert(st);
    while(scanf("%s",st)==1&&st[0]!='9')
      insert(st);
    bool flag=dfs(head);
    if (flag)
      printf("Set %d is immediately decodable\n",++ii);
    else
      printf("Set %d is not immediately decodable\n",++ii);
    release(head);
  }
  return 0;
}
