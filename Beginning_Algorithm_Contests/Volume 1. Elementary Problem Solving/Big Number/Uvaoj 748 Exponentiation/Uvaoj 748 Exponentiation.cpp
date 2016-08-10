/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int maxn = 1000;

struct bign
{
    int len;
    int s[maxn];
    //1234:s[0] = 4, s[1] = 3...
    bign()
    {
        memset(s,0,sizeof(s));
        len = 1;
    }
    bign operator = (const char* num)
    //支持 x = "123456" 的赋值方法
    {
        len = strlen(num);
        for(int i=0;i<len;i++)
            s[i] = num[len-i-1] - '0';
        return *this;
    }
    bign operator = (int num)
    {
        char s[maxn];
        sprintf(s,"%d",num);
        *this = s;//调用了上面的函数
        return *this;
    }
    bign(int num)
    {
        *this = num;
    }
    bign(const char* num)
    {
        *this = num;
    }
    string str() const
    {
        string res = "";
        for(int i=0;i<len;i++)
            res = (char)(s[i]+'0')+res;
        if(res=="")
            res = "0";
        return res;
    }
    bign operator + (const bign& b) const
    {
        bign c;
        c.len = 0;
        for(int i=0,g=0;g||i<max(len,b.len);i++)
        {
            int x = g;
            if(i<len) x += s[i];
            if(i<b.len) x += b.s[i];
            c.s[c.len++] = x%10;
            g = x/10;
        }
        return c;
    }
    bign operator += (const bign& b)
    {
        *this = *this + b;
        return *this;
    }
    bool operator < (const bign& b) const
    {
        if(len!=b.len) return len<b.len;
        for(int i=len-1;i>=0;i--)
            if(s[i]!=b.s[i])
                return s[i]<b.s[i];
        return false;
    }
    bool operator > (const bign& b) const
    {
        return b<*this;
    }
    bool operator <= (const bign& b) const
    {
        return !(b<*this);
    }
    bool operator >= (const bign& b) const
    {
        return !(*this<b);
    }
    bool operator != (const bign& b) const
    {
        return b<*this||*this<b;
    }
    bool operator == (const bign& b) const
    {
        return !(b<*this)&&!(*this<b);
    }
};

istream& operator >> (istream &in, bign& x)
{
    string s;
    in>>s;
    x = s.c_str();
    return in;
}

ostream& operator << (ostream &out, const bign& x)
{
    //支持 cout<<x 的方法打印
    out<<x.str();
    return out;
}


int main()
{
    return 0;
}
*/

#include <algorithm> // max
#include <cassert>   // assert
#include <cstdio>    // printf,sprintf
#include <cstring>   // strlen
#include <iostream>  // cin,cout
#include <string>    // string类
#include <vector>    // vector类
#include <cmath>
using namespace std;

struct BigInteger {
    typedef unsigned long long LL;

    static const int BASE = 10;
    static const int WIDTH = 1;
    vector<int> s;

    BigInteger& clean(){while(!s.back()&&s.size()>1)s.pop_back(); return *this;}
    BigInteger(LL num = 0) {*this = num;}
    BigInteger(string s) {*this = s;}
    BigInteger& operator = (long long num) {
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        } while (num > 0);
        return *this;
    }
    BigInteger& operator = (const string& str) {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for (int i = 0; i < len; i++) {
            int end = str.length() - i*WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start,end-start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return (*this).clean();
    }

    BigInteger operator + (const BigInteger& b) const {
        BigInteger c; c.s.clear();
        for (int i = 0, g = 0; ; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = g;
            if (i < s.size()) x += s[i];
            if (i < b.s.size()) x += b.s[i];
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c;
    }
    BigInteger operator - (const BigInteger& b) const {
        assert(b <= *this); // 减数不能大于被减数
        BigInteger c; c.s.clear();
        for (int i = 0, g = 0; ; i++) {
            if (g == 0 && i >= s.size() && i >= b.s.size()) break;
            int x = s[i] + g;
            if (i < b.s.size()) x -= b.s[i];
            if (x < 0) {g = -1; x += BASE;} else g = 0;
            c.s.push_back(x);
        }
        return c.clean();
    }
    BigInteger operator * (const BigInteger& b) const {
        int i, j; LL g;
        vector<LL> v(s.size()+b.s.size(), 0);
        BigInteger c; c.s.clear();
        for(i=0;i<s.size();i++) for(j=0;j<b.s.size();j++) v[i+j]+=LL(s[i])*b.s[j];
        for (i = 0, g = 0; ; i++) {
            if (g ==0 && i >= v.size()) break;
            LL x = v[i] + g;
            c.s.push_back(x % BASE);
            g = x / BASE;
        }
        return c.clean();
    }
    BigInteger operator / (const BigInteger& b) const {
        assert(b > 0);  // 除数必须大于0
        BigInteger c = *this;       // 商:主要是让c.s和(*this).s的vector一样大
        BigInteger m;               // 余数:初始化为0
        for (int i = s.size()-1; i >= 0; i--) {
            m = m*BASE + s[i];
            c.s[i] = bsearch(b, m);
            m -= b*c.s[i];
        }
        return c.clean();
    }
    BigInteger operator % (const BigInteger& b) const { //方法与除法相同
        BigInteger c = *this;
        BigInteger m;
        for (int i = s.size()-1; i >= 0; i--) {
            m = m*BASE + s[i];
            c.s[i] = bsearch(b, m);
            m -= b*c.s[i];
        }
        return m;
    }
    // 二分法找出满足bx<=m的最大的x
    int bsearch(const BigInteger& b, const BigInteger& m) const{
        int L = 0, R = BASE-1, x;
        while (1) {
            x = (L+R)>>1;
            if (b*x<=m) {if (b*(x+1)>m) return x; else L = x;}
            else R = x;
        }
    }
    BigInteger& operator += (const BigInteger& b) {*this = *this + b; return *this;}
    BigInteger& operator -= (const BigInteger& b) {*this = *this - b; return *this;}
    BigInteger& operator *= (const BigInteger& b) {*this = *this * b; return *this;}
    BigInteger& operator /= (const BigInteger& b) {*this = *this / b; return *this;}
    BigInteger& operator %= (const BigInteger& b) {*this = *this % b; return *this;}

    bool operator < (const BigInteger& b) const {
        if (s.size() != b.s.size()) return s.size() < b.s.size();
        for (int i = s.size()-1; i >= 0; i--)
            if (s[i] != b.s[i]) return s[i] < b.s[i];
        return false;
    }
    bool operator >(const BigInteger& b) const{return b < *this;}
    bool operator<=(const BigInteger& b) const{return !(b < *this);}
    bool operator>=(const BigInteger& b) const{return !(*this < b);}
    bool operator!=(const BigInteger& b) const{return b < *this || *this < b;}
    bool operator==(const BigInteger& b) const{return !(b < *this) && !(b > *this);}
};

ostream& operator << (ostream& out, const BigInteger& x) {
    out << x.s.back();
    for (int i = x.s.size()-2; i >= 0; i--) {
        char buf[20];
        sprintf(buf, "%01d", x.s[i]);
        for (int j = 0; j < strlen(buf); j++) out << buf[j];
    }
    return out;
}

istream& operator >> (istream& in, BigInteger& x) {
    string s;
    if (!(in >> s)) return in;
    x = s;
    return in;
}

BigInteger cal(BigInteger x, int mi)
{
    BigInteger ans;
    BigInteger hold;
    if(mi==0)
    {
        ans = 1;
        return ans;
    }
    if(mi==1)
        return x;
    int mid = mi/2;
    hold = cal(x,mid);
   // cout<<mid<<" "<<hold<<endl;
    if(mi%2==0)
    {
        ans = hold*hold;
        //cout<<ans<<endl;
        return ans;
    }
    else
    {
        ans = hold*hold;
        ans *= x;
        return ans;
    }
}

int main()
{
   // freopen("data.txt","r",stdin);
    double x;
    int mi;
    BigInteger ans;
    BigInteger a;
    while(scanf("%lf%d",&x,&mi)!=EOF)
    {
       // cout<<x<<' '<<mi<<endl;
        long long a0 = floor(x*10000+0.5);
        a = a0;
      //  cout<<a<<endl;
        ans = cal(a,mi);
      //  cout<<ans<<endl;
        int zeros = mi*4;
        int l = ans.s.size();
        for(int i=l-1;i>=zeros;i--)
            cout<<ans.s[i];
        putchar('.');
        for(int i=0;i<zeros-l;i++)
            putchar('0');
        int j;
        for(j=0;j<l;j++)
            if(ans.s[j]!=0)
                break;
        for(int i=min(l,zeros)-1;i>=j;i--)
            cout<<ans.s[i];
        cout<<endl;
    }
    return 0;
}






















