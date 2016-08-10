#include<stdio.h>
#include<stdlib.h>
#define max 2147483647
char x[301],y[301];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out2.txt","w",stdout);
 double a,b;
 char ch;
 while(scanf("%s %c %s",x,&ch,y)==3)
 {
  printf("%s %c %s\n",x,ch,y);
  a=atof(x);
  b=atof(y);
  if(a>max)printf("first number too big\n");
  if(b>max)printf("second number too big\n");
  if(ch=='+' && a+b >max)printf("result too big\n");
  if(ch=='*' && a*b >max)printf("result too big\n");
 }
    return 0;
}