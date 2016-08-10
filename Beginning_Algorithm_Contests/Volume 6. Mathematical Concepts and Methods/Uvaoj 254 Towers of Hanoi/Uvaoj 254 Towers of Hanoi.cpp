#include <algorithm> // max  
#include <cassert>   // assert  
#include <cstdio>    // printf,sprintf  
#include <cstring>   // strlen  
#include <iostream>  // cin,cout  
#include <string>    // string类  
#include <vector>    // vector类  
using namespace std;  
  
struct BigInteger {  
    typedef unsigned long long LL;  
  
    static const int BASE = 100000000;  
    static const int WIDTH = 8;  
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
        sprintf(buf, "%08d", x.s[i]);  
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

int pegs[5];

BigInteger power(int a, int n)
{
	BigInteger ans;
	if(n==0)
	{
		ans = 1;
		return ans;
	}
	if(n==1)
	{
		ans = a;
		return ans;
	}
	if(n%2==1)
		return power(a,n/2)*power(a,n/2)*a;
	return power(a,n/2)*power(a,n/2);
}

int plusPeg(int curPeg, int increment)
{
	return (curPeg+increment)%3;
}

void solve(BigInteger m, int current, int curPeg)
{
	if(current==0)
		return;
	BigInteger hold = power(2,current-1);
	if(m>=hold)
	{
		if(current%2==1)
		{
			pegs[plusPeg(curPeg,1)]++;
			solve(m-hold,current-1,plusPeg(curPeg,2));
		}
		else
		{
			pegs[plusPeg(curPeg,2)]++;
			solve(m-hold,current-1,plusPeg(curPeg,1));
		}
	}
	else
	{
		pegs[curPeg]++;
		solve(m,current-1,curPeg);
	}
}

int main()
{
	//freopen("data.txt","r",stdin);
	int n,m;
	while(scanf("%d",&n))
	{
		BigInteger m;
		cin>>m;
		if(n==0&&m==0)
			break;
		memset(pegs,0,sizeof(pegs));
		solve(m,n,0);
		for(int i=0;i<3;i++)
		{
			printf("%d",pegs[i]);
			if(i==2)
				printf("\n");
			else
				printf(" ");
		}	
	}		
	return 0;
}