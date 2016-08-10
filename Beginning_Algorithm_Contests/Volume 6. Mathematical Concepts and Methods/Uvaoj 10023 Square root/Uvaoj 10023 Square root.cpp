/*
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

BigInteger make(int num)
{
	string s = "1";
	for(int i=1;i<num;i++)
		s += "0";
	BigInteger h = s;
	return h;
}

BigInteger ans(BigInteger want, BigInteger low, BigInteger high)
{
	if(low*low==want)
		return low;
	BigInteger mid = (low+high)/2;
	//BigInteger hold = mid*mid;
	if(mid*mid==want)
		return mid;
	if(mid*mid>want)
		return ans(want,low,mid);
	return ans(want,mid,high);
}

int main()
{
	freopen("dataout.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for(int cc=0;cc<T;cc++)
	{
		string s;
		cin>>s;
		int l = s.length();
		BigInteger want = s;
		//cout<<want<<endl;
		BigInteger low = make((l+1)/2);
		//cout<<low<<endl;
		BigInteger high = low*10;
		//cout<<high<<endl;
		if(cc)
			cout<<endl;
		cout<<ans(want,low,high)<<endl;
	}
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

const int maxn = 1010;
//int ans[maxn];
int zero[10];
int other[maxn];
int counter;

void pre()
{
    zero[0] = 1;
    for(int i=1;i<9;i++)
        zero[i] = zero[i-1]*10;
}

/*
BigInteger make(int num, int f)//num-1 times of 0
{
    string s = "0";
    s[0] += f;
    for(int i=1;i<num;i++)
        s += "0";
    BigInteger h = s;
    return h;
}
*/

int length(BigInteger a)
{
    int many = a.s.size();
    int num = (many-1)*8;
    int h = a.s[many-1];
    while(h)
    {
        num++;
        h /= 10;
    }
    return num;
}

void makeOther(BigInteger a, int l)
{
    counter = 0;
    for(int i=0;i<l;i+=2)
    {
        int p1 = i/8;
        int p2 = i%8;
        int h1 = a.s[p1]%zero[p2+2];
        other[counter++] = h1/zero[p2];
    }
}

/*
int f(BigInteger a, int l)
{
    int mod = l%8;
    if(mod==0)
        mod = 8;
    int first = a.s[a.s.size()-1]/zero[mod-1];
    if(l%2==1)
        return first;
    else
    {
        int second;
        if(mod==1)
        {
            second = a.s[a.s.size()-2]/zero[7];
            return first*10+second;
        }
        else
        {
            int h = a.s[a.s.size()-1]%zero[mod-1];
            second = h/zero[mod-2];
            return first*10+second;
        }
    }
}
*/

BigInteger next_step(int degree, BigInteger remain, BigInteger current)
{
    remain = remain*100+other[degree];
    int nextDigit;
    BigInteger h1;
    for(nextDigit=9;nextDigit>=0;nextDigit--)
    {
        h1 = (current*20+nextDigit)*nextDigit;
        if(h1<=remain)
            break;
    }
    remain = remain-h1;
    current = current*10+nextDigit;
    degree--;
    if(degree<0)
        return current;
    return next_step(degree,remain,current);
}

BigInteger solve(BigInteger want, int l)
{
   // int l = length(want);
  //  int now = f(want,l);
    makeOther(want,l);
    int now = other[counter-1];
    int position = (l+1)/2;
    int nn = floor(sqrt(now+0.5));
   // ans[position-1] = nn;
   // BigInteger h = want;
   // BigInteger zs = make(position,nn);
    BigInteger hold1 = now-nn*nn;
    BigInteger hold2 = nn;
    if(counter==1)
        return hold2;
    return next_step(counter-2,hold1,hold2);
}

int main()
{
    //freopen("dataout.txt","r",stdin);
    pre();
    int T;
    scanf("%d",&T);
    for(int cc=0;cc<T;cc++)
    {
        string s;
        cin>>s;
        int l = s.length();
      //  int ansl = (l+1)/2;
        BigInteger want = s;
       // memset(ans,0,sizeof(ans));
       // solve(want);
        //makeOther(want,length(want));
       // for(int i=0;i<counter;i++)
        //    printf("m:%d\n",other[i]);
        //printf("qian:%d\n",f(want,length(want)));
         if(cc)
             cout<<endl;
         cout<<solve(want,l)<<endl;
    }
    return 0;
}