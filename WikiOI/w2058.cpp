#include<cstdio>
#include<cstdlib>
#include<stack>
#include<cstring>
#define mn int(2*1e6+2)
using namespace std;

char a[10]={' ','(','[','{','<',')',']','}','>'};
int find(char ch)
{
  int i;
  for (i=1;i<=8;i++)
    if (a[i]==ch) return i;
}
stack<int> s;
int main()
{
  bool flag;
  int n,i,j;
  char ch;
  char c[mn];
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%s",c);
    flag=1;
    s.clear();
    //while (!s.empty())
      //s.pop();
    for (j=0;j<=strlen(c)-1;j++)
    {
      int k=find(c[j]);
      if (k<=4)
        s.push(k);
       else if ((k>4&&s.empty())||k>4&&s.top()!=(k-4))
       {
         flag=0;
         break;
       }
       else s.pop();
    }
    if (!s.empty()) flag=false; 
    if (flag) printf("TRUE\n");else printf("FALSE\n");
  }
  //system("pause");
  return 0;
} 
