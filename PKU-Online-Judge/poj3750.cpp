#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{char s[20];node *next,*pre;};

int main()
{
  freopen("3750.in","r",stdin);
  freopen("3750.out","w",stdout);
  int n,i,j,k,m,t;
  scanf("%d",&n);
  node *head,*r;
  node *p;
  p=new node;
  scanf("%s",p->s);
  p->next=NULL;p->pre=NULL;
  head=p;
  r=p;
  for (i=2;i<=n;i++)
  {
    p=new node;
    scanf("%s",p->s);
    p->next=NULL;p->pre=r;
    r->next=p;
    r=p;
  }
  r->next=head;
  head->pre=r;
  p=head;
  scanf("%d,%d",&m,&k);
  for (i=1;i<=m-1;i++)
    p=p->next;
  for (i=1;i<=n;i++)
  {
    for (j=1;j<k;j++)
      p=p->next;
    printf("%s\n",p->s);
    p->pre->next=p->next;
    p->next->pre=p->pre;
    p=p->next;
  }
  return 0;
}
