#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node
{
  int pr;
  bool me;
  node* next;
};

bool find(node *head)
{
  node *p;
  p=head->next;
  if (p==NULL) return false;
  int t=head->pr;
  while(p!=NULL)
  {
    if (p->pr>t)
      return true;
    p=p->next;
  }
  return false;
}

int main()
{
  freopen("3125.in","r",stdin);
  freopen("3125.out","w",stdout);
  int T,i,j,k,m,n;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&m);
    node *p;
    p=new node;
    node *head,*r;
    scanf("%d",&p->pr);
    if (m==0) p->me=true;else p->me=false;
    p->next=NULL;
    head=p;
    r=p;
    for (i=1;i<n;i++)
    {
      p=new node;
      scanf("%d",&p->pr);
      if (i==m) p->me=true;else p->me=false;
      p->next=NULL;
      r->next=p;
      r=p;
    }
    int ans=0;
    while(true)
    {
      if (!find(head))
      {
        if (head->me) break;
        head=head->next;
        ans++;
      }
      else
      {
        r->next=head;
        head=head->next;
        r=r->next;
        r->next=NULL;
      }
    }
    printf("%d\n",ans+1);
  }
  return 0;
}
