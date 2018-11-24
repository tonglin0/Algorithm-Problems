#include<cstdio>
#include<cstring>
using namespace std;

struct node{
	char s[402];
	int stp;
};
node q1[40002],q2[40002];
int h1=1,r1=0,h2=1,r2=0;
char s1[8][22],s2[8][22];
int n=0;

bool add1(int st,int k)
{
	++r1;
	q1[r1].stp=q1[h1].stp+1;
	for (int i=0;i<st;i++)
		q1[r1].s[i]=q1[h1].s[i];
	int len2=strlen(s2[k]),len1=strlen(s1[k]);
	for (int i=0;i<len2;i++)
		q1[r1].s[i+st]=s2[k][i];
	int i=st+len1,j=st+len2;
	for (i=st+len1;i<=strlen(q1[h1].s);i++,j++)
		q1[r1].s[j]=q1[h1].s[i];
	for (i=h2;i<=r2;i++)
		if (strcmp(q1[r1].s,q2[i].s)==0)
		{
			printf("%d\n",q1[r1].stp+q2[i].stp);
			return true;
		}
	return false;
}

bool add2(int st,int k)
{
	++r2;
	q2[r2].stp=q2[h2].stp+1;
	for (int i=0;i<st;i++)
		q2[r2].s[i]=q2[h2].s[i];
	int len2=strlen(s2[k]),len1=strlen(s1[k]);
	for (int i=0;i<len1;i++)
		q2[r2].s[i+st]=s1[k][i];
	int i=st+len2,j=st+len1;
	for (i=st+len2;i<=strlen(q2[h2].s);i++,j++)
		q2[r2].s[j]=q2[h2].s[i];
	for (i=h1;i<=r1;i++)
		if (strcmp(q2[r2].s,q1[i].s)==0)
		{
			printf("%d\n",q2[r2].stp+q1[i].stp);
			return true;
		}
	return false;
}

bool solve()
{
	while(h1<=r1&&h2<=r2&&q1[h1].stp+q2[h2].stp<10)
	{
		if (r1-h1<r2-h2)
		{
			int tmpstp=q1[h1].stp;
			while(q1[h1].stp==tmpstp)
			{
				for (int i=1;i<=n;i++)
					for (int j=0;j<strlen(q1[h1].s);j++)
					{
						if (strncmp(s1[i],&q1[h1].s[j],strlen(s1[i]))==0)
							if (add1(j,i))
								return true;
					}
				h1++;
			}
		}
		else
		{
			int tmpstp=q2[h2].stp;
			while(q2[h2].stp==tmpstp)
			{
				for (int i=1;i<=n;i++)
					for (int j=0;j<strlen(q2[h2].s);j++)
					{
						if (strncmp(s2[i],&q2[h2].s[j],strlen(s2[i]))==0)
							if (add2(j,i))
								return true;
					}
				h2++;
			}
		}
	}
	return false;
}

int main()
{
	freopen("1032.in","r",stdin);
	int i;
	scanf("%s",q1[++r1].s);
	q1[r1].stp=0;
	scanf("%s",q2[++r2].s);
	q2[r2].stp=0;
	while(scanf("%s%s",s1[n+1],s2[n+1])==2)
		n++;
	if (!solve())
		printf("NO ANSWER!\n");
	return 0;
}
