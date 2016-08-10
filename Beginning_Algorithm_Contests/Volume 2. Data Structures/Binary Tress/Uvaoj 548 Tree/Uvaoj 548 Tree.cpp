
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn = 10010;
const int INF = 1<<30;

int inorder[maxn];
int postorder[maxn];
char s[100100];
//int dp[maxn];
int n1;
int n2;
int n;
int minimum;
int xx;

struct tree
{
    int value;
    int lch;
    int rch;
};

tree b[maxn];

int findInorder(int value, int is, int ie)
{
    for(int i=is;i<=ie;i++)
        if(inorder[i]==value)
            return i;
    cout<<"wrong"<<endl;
    return -1;
}

int makeTree(int ps,int pe, int is, int ie)
{
    //printf("ps: %d\npe: %d\nis: %d\nie: %d\nvalue: %d\n",ps,pe,is,ie,postorder[pe]);
  //  cout<<postorder[21]<<endl;
    b[pe].value = postorder[pe];
    if(ps==pe)
    {
        b[pe].lch = -1;
        b[pe].rch = -1;
        return pe;
    }
    int index = findInorder(postorder[pe],is,ie);
    if(index>is)
        b[pe].lch = makeTree(ps,ps+index-is-1,is,index-1);
    else
        b[pe].lch = -1;
    if(ie>index)
        b[pe].rch = makeTree(ps+index-is,pe-1,index+1,ie);
    else
        b[pe].rch = -1;
    return pe;
}

int numberOfDigits(int x)
{
    if(x==0)
        return 1;
    int ans = 0;
    while(x>0)
    {
        ans++;
        x /= 10;
    }
    return ans;
}

void operate(bool flag)
{
    char* h = s;
  //  int hh = 0;
    int d = strlen(s);
    if(flag)
    {
        while(h-s<d)
        {
            sscanf(h,"%d",&inorder[n1]);
            //cout<<"char: "<<h[0]<<endl;
         //   hh += (numberOfDigits(inorder[n1])+1);
            h += (numberOfDigits(inorder[n1])+1);
            n1++;
        }
    }
    else
    {
        while(h-s<d)
        {
            sscanf(h,"%d",&postorder[n2]);
         //   hh += (numberOfDigits(postorder[n2])+1);
            h += (numberOfDigits(postorder[n2])+1);
            n2++;
        }
    }
    //cout<<postorder[21]<<endl;
}

void sum(int index, int ssum)
{
    if(b[index].rch==-1&&b[index].lch==-1)
    {
        if(ssum+b[index].value<minimum)
        {
            minimum = ssum+b[index].value;
            xx = b[index].value;
            //cout<<"xx: "<<xx<<endl;
            //cout<<b[index].value<<endl;
        }
        return;
    }
    if(b[index].lch==-1)
    {
        if(ssum+b[index].value<minimum)
            sum(b[index].rch, ssum+b[index].value);
        return;
    }
    if(b[index].rch==-1)
    {
        if(ssum+b[index].value<minimum)
            sum(b[index].lch, ssum+b[index].value);
        return;
    }
    if(ssum+b[index].value<minimum)
        sum(b[index].lch, ssum+b[index].value);
    if(ssum+b[index].value<minimum)
        sum(b[index].rch, ssum+b[index].value);
}

void solve()
{
    n = n1;
    //cout<<n-1<<endl;
    makeTree(0,n-1,0,n-1);
    //cout<<n1<<endl;
    sum(n-1,0);
    printf("%d\n",xx);
   // for(int i=0;i<n;i++)
  //      printf("number: %d\nvalue: %d\n lch: %d\n rch: %d\n\n",i,b[i].value,b[i].lch,b[i].rch);
 //for(int i=0;i<n;i++)
    //    cout<<inorder[i]<<' ';
   // cout<<endl;
  //  for(int i=0;i<n;i++)
  //      cout<<postorder[i]<<' ';
 //   cout<<endl;
}

int main()
{
    //freopen("data2.txt","r",stdin);
    //freopen("data.out","w",stdout);
    bool flag = true;
    while(gets(s))
    {
        if(flag)
            n1 = n2 = 0;
        operate(flag);
        flag = !flag;
        if(flag)
        {
            minimum = INF;
          //  for(int i=0;i<maxn;i++)
          //      dp[i] = INF;
            //cout<<postorder[21]<<endl;
            solve();
            //cout<<"n"<<n<<endl;
         //   for(int i=0;i<n;i++)
          //      cout<<postorder[i]<<' ';
        }
    }
    return 0;
}


/*
#include <iostream>
#include <cstdlib>
#include <cstring>
#include<cstdio>

using namespace std ;

const int maxn = 10000 + 10 ;

struct Node { Node * left ; Node * right ; int data ; } ;

char str1[maxn*10] , str2[maxn*10] ;//字符串长度有可能很长（空格......）
int arr1[maxn] , arr2[maxn] ;
int mymin ; int ans ;
int count1 = 0 ;
int count2 = 0 ;

void init()//初始化
{
    memset( arr1 , 0 , sizeof( arr1 ) ) ;
    memset( arr2 , 0 , sizeof( arr2 ) ) ;
    count1 = 0 ; count2 = 0 ; mymin = 2147483647 ; ans = 0 ;
    return ;
}

void input()//读入数据
{
    int len1 = strlen( str1 ) ;
    int len2 = strlen( str2 ) ;
    for( int i = 0 ; i < len1 ;  )
    {
        if( isdigit( str1[i] ) )
        {
            int num = 0 ;
            while( isdigit( str1[i] ) )
            {
                num = num * 10 + str1[i] - '0' ;
                i++  ;
            }
            arr1[count1] = num ;
//            map[num] = count1++ ;
            count1++ ;
        }
        else i++ ;
    }
    for( int i = 0 ; i < len2 ;  )
    {
        if( isdigit( str2[i] ) )
        {
            int num = 0 ;
            while( isdigit( str2[i] ) )
            {
                num = num * 10 + str2[i] - '0' ;
                i++  ;
            }
            arr2[count2++] = num ;
        }
        else i++ ;
    }
    return ;
}

Node * creatNode( int a )//创建结点
{
    Node * node = new Node ;
    node -> data = a ;
    node -> left = NULL ;
    node -> right = NULL ;
    return node ;
}
//以下是该程序最重要的部分
Node * buildTree( Node * root , int a[] , int b[] , int ab , int ae , int bb , int be )
{
    if( bb <= be )
    {
        Node * node = creatNode( b[be] ) ;
        root = node ;
        int pos = 0 ;
        for( int i = ab ; i <= ae ; i++ )
        if( a[i] == b[be] )
        { pos = i ; break ; }
        //递归构造左子树，pos-ab-1为左子树在数组的长度.....
        root -> left = buildTree( root -> left , a , b , ab , pos - 1 , bb , bb + pos - ab - 1 ) ;
        root ->right = buildTree( root -> right , a , b , pos + 1 , ae , bb + pos - ab , be - 1 ) ;
        return root ;
    }
    else
    return NULL ;
}
//深度优先模拟先序遍历
void dfs( Node * u , int cur )
{
  if( u )//若结点不为空
  {
      cur += u -> data ;
      if( ! u -> left && ! u -> right )//若到到叶子结点
      {
          if( cur < mymin )//得到的和比当前最小的和还小，更新记录叶子数据的数值与当前最小值
          {
              mymin = cur ;
              ans = u -> data ;
          }
          return ;
      }
      if( u -> left ) dfs( u -> left , cur ) ;
      if( u -> right ) dfs( u -> right , cur ) ;
  }
  else return ;
}

int main()
{
    //freopen("data2.txt","r",stdin);
    while( gets( str1 ) )
    {
        gets( str2 ) ;
        init() ;
        input() ;
        Node * root = NULL ;
        root = buildTree( root , arr1 , arr2 , 0 , count1 - 1 , 0 , count2 - 1 ) ;
        dfs( root , 0 ) ;
        cout << ans << endl ;
    }
    return 0 ;
}
*/
