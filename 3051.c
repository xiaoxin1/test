#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long gcd(long long x,long long y)
{
  if (y==0) return x;
  return gcd(y,x%y);
}
long long m,h1,a1,x1,y1,h2,a2,x2,y2;
int main()
{
  long long i,t1,t2,t11,t22,judge1,judge2;
  scanf("%I64d",&m);
  scanf("%I64d%I64d",&h1,&a1);
  scanf("%I64d%I64d",&x1,&y1);
  scanf("%I64d%I64d",&h2,&a2);
  scanf("%I64d%I64d",&x2,&y2);
  t1=t2=t11=t22=-1; judge1=judge2=0;
  for (i=1;i<=2*m;i++)
  {
	h1=(h1*x1+y1)%m;
	if (h1==a1) 
	if (judge1==0){t1=i;judge1=1;}
	else {t11=i-t1;break;}
  }
  for (i=1;i<=2*m;i++)
  {
	h2=(h2*x2+y2)%m; 
	if (h2==a2) 
	if (judge2==0){t2=i;judge2=1;}
	else {t22=i-t2;break;}
  }
  if (t1==-1||t2==-1||t11==-1||t22==-1) printf("-1\n");
  else {
	if (t11<t22) {swap(t1,t2); swap(t11,t22);}
	for (i=0;i<=2*m;i++)
	  if ((i*t11+t1-t2)%t22==0&&(i*t11+t1-t2)>=0) {
		printf("%I64d\n",i*t11+t1); break;
	  }
	if (i>2*m) printf("-1\n");
  }
  return 0;
}
