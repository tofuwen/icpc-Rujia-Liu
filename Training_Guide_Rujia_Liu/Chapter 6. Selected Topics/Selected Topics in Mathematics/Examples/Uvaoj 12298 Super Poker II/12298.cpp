#include <complex>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 50010;

int composite[maxn];

void pre() {
  memset(composite, 0, sizeof(composite));
  for(int i=2;i<maxn;i++) {
    if(composite[i] == 0) {
      for(int j=2*i;j<maxn;j+=i)
        composite[j] = 1;
    }
  }
}

const long double PI = acos(0.0) * 2.0;

typedef complex<double> CD;

// Cooley-Tukey的FFT算法，迭代实现。inverse = false时计算逆FFT
inline void FFT(vector<CD> &a, bool inverse) {
  int n = a.size();
  // 原地快速bit reversal
  for(int i = 0, j = 0; i < n; i++) {
    if(j > i) swap(a[i], a[j]);
    int k = n;
    while(j & (k >>= 1)) j &= ~k;
    j |= k;
  }

  double pi = inverse ? -PI : PI;
  for(int step = 1; step < n; step <<= 1) {
    // 把每相邻两个“step点DFT”通过一系列蝴蝶操作合并为一个“2*step点DFT”
    double alpha = pi / step;
    // 为求高效，我们并不是依次执行各个完整的DFT合并，而是枚举下标k
    // 对于一个下标k，执行所有DFT合并中该下标对应的蝴蝶操作，即通过E[k]和O[k]计算X[k]
    // 蝴蝶操作参考：http://en.wikipedia.org/wiki/Butterfly_diagram
    for(int k = 0; k < step; k++) {
      // 计算omega^k. 这个方法效率低，但如果用每次乘omega的方法递推会有精度问题。
      // 有更快更精确的递推方法，为了清晰起见这里略去
      CD omegak = exp(CD(0, alpha*k)); 
      for(int Ek = k; Ek < n; Ek += step << 1) { // Ek是某次DFT合并中E[k]在原始序列中的下标
        int Ok = Ek + step; // Ok是该DFT合并中O[k]在原始序列中的下标
        CD t = omegak * a[Ok]; // 蝴蝶操作：x1 * omega^k
        a[Ok] = a[Ek] - t;  // 蝴蝶操作：y1 = x0 - t
        a[Ek] += t;         // 蝴蝶操作：y0 = x0 + t
      }
    }
  }

  if(inverse)
    for(int i = 0; i < n; i++) a[i] /= n;
}

// 用FFT实现的快速多项式乘法
inline vector<double> operator * (const vector<double>& v1, const vector<double>& v2) {
  int s1 = v1.size(), s2 = v2.size(), S = 2;
  while(S < s1 + s2) S <<= 1;
  vector<CD> a(S,0), b(S,0); // 把FFT的输入长度补成2的幂，不小于v1和v2的长度之和
  for(int i = 0; i < s1; i++) a[i] = v1[i];
  FFT(a, false);
  for(int i = 0; i < s2; i++) b[i] = v2[i];
  FFT(b, false);
  for(int i = 0; i < S; i++) a[i] *= b[i];
  FFT(a, true);
  vector<double> res(s1 + s2 - 1);
  for(int i = 0; i < s1 + s2 - 1; i++) res[i] = a[i].real(); // 虚部均为0
  return res;
}

void make(vector<double> & v, int * x, int b) {
  v.reserve(b);
  for(int i=0;i<b;i++)
    if(x[i])
      v.push_back(1.0);
    else
      v.push_back(0.0);
}

int main()
{
  // freopen("data.txt", "r", stdin);
  pre();
  int a, b, c;
  while(scanf("%d%d%d", &a, &b, &c) && a) {
    char s[1000];
    int S[maxn], H[maxn], D[maxn], C[maxn];
    memcpy(S, composite, maxn * sizeof(int));
    memcpy(H, composite, maxn * sizeof(int));
    memcpy(D, composite, maxn * sizeof(int));
    memcpy(C, composite, maxn * sizeof(int));
    for(int i=0;i<c;i++) {
      scanf("%s", s);
      int l = strlen(s);
      char cur = s[l-1];
      s[l-1] = 0;
      int data;
      sscanf(s, "%d", &data);
      switch(cur) {
        case 'S': S[data] = 0; break;
        case 'H': H[data] = 0; break;
        case 'D': D[data] = 0; break;
        default: C[data] = 0; break;
      }
    }
    vector<double> ss, hh, dd, cc;
    make(ss, S, b+5);
    make(hh, H, b+5);
    make(dd, D, b+5);
    make(cc, C, b+5);
    ss = ss * hh;
    ss = ss * dd;
    ss = ss * cc;
    for(int i=a;i<=b;i++)
      printf("%lld\n", (long long)(ss[i]+0.5));
      // printf("%.0f\n", fabs(ss[i]));
    printf("\n");
  }
  return 0;
}