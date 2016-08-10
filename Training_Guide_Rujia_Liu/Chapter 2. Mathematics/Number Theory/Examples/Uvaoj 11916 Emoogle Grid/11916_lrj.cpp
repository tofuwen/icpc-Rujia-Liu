// UVa11916 Emoogle Grid
// Rujia Liu
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
using namespace std;

const int MOD = 100000007;
const int maxb = 500 + 10;
int n, m, k, b, r, x[maxb], y[maxb];
set<pair<int, int> > bset;

int pow_mod(int a, long long p) {
  if(p == 0) return 1;
  int ans = pow_mod(a, p/2);
  ans = (long long)ans * ans % MOD;
  if(p%2) ans = (long long)ans * a % MOD;
  return ans;
}

int mul_mod(int a, int b) {
  return (long long)a * b % MOD;
}

int inv(int a) {
  return pow_mod(a, MOD-2);
}

int log_mod(int a, int b) {
  int m, v, e = 1, i;
  m = (int)sqrt(MOD);
  v = inv(pow_mod(a, m));
  map <int,int> x;
  x[1] = 0;
  for(i = 1; i < m; i++){ e = mul_mod(e, a); if (!x.count(e)) x[e] = i; }
  for(i = 0; i < m; i++){
    if(x.count(b)) return i*m + x[b];
    b = mul_mod(b, v);
  }
  return -1;
}

// ¼ÆËã¿É±ä²¿·ÖµÄ·½°¸Êý
int count() {
  int c = 0; // ÓÐkÖÖÍ¿·¨µÄ¸ñ×ÓÊý
  for(int i = 0; i < b; i++) {
    if(x[i] != m && !bset.count(make_pair(x[i]+1, y[i]))) c++; // ²»¿ÉÍ¿É«¸ñÏÂÃæµÄ¿ÉÍ¿É«¸ñ
  }
  c += n; // µÚÒ»ÐÐËùÓÐ¿Õ¸ñ¶¼ÓÐkÖÖÍ¿·¨
  for(int i = 0; i < b; i++)
    if(x[i] == 1) c--; // ¿Û³ýÄÇÐ©²»ÄÜÍ¿É«µÄ¸ñ×Ó

  // ans = k^c * (k-1)^(mn - b - c)
  return mul_mod(pow_mod(k, c), pow_mod(k-1, (long long)m*n - b - c));
}

int doit() {
  int cnt = count();
  if(cnt == r) return m; // ²»±ä²¿·ÖÎª¿Õ

  int c = 0;
  for(int i = 0; i < b; i++)
    if(x[i] == m) c++; // ¿É±ä²¿·ÖµÚÒ»ÐÐÖÐÓÐkÖÖÍ¿·¨µÄ¸ñ×ÓÊý
  m++; // ¶àÁËÒ»ÐÐ£¨¿É±ä²¿·ÖµÄµÚÒ»ÐÐ£©
  cnt = mul_mod(cnt, pow_mod(k, c));
  cnt = mul_mod(cnt, pow_mod(k-1, n - c));
  if(cnt == r) return m; // ´ËÊ±cntÎª²»±ä²¿·ÖºÍ¿É±ä²¿·ÖµÚÒ»ÐÐµÄ·½°¸×ÜÊý

  return log_mod(pow_mod(k-1,n), mul_mod(r, inv(cnt))) + m;
}

int main() {
  freopen("data.txt", "r", stdin);
  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; t++) {
    scanf("%d%d%d%d", &n, &k, &b, &r);
    bset.clear();
    m = 1;
    for(int i = 0; i < b; i++) {
      scanf("%d%d", &x[i], &y[i]);
      if(x[i] > m) m = x[i]; // ¸üÐÂ²»±ä²¿·ÖµÄÐÐÊý
      bset.insert(make_pair(x[i], y[i]));
    }
    printf("Case %d: %d\n", t, doit());
  }
}
