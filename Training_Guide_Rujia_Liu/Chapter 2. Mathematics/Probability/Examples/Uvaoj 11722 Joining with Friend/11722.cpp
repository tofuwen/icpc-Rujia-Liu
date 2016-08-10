#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iostream>
using namespace std;

double t1, t2, s1, s2, w;

bool above_low(double t, double s) {
	return s > t - w;
}

bool above_high(double t, double s) {
	return s > t + w;
}

// 确定一个长边，枚举 y=x+w 以及 y=x-w的位置
double solve() {
	double area = (s2-s1)*(t2-t1);
	if(!above_low(t1, s2) || above_high(t2, s1)){
		// cout << 1 << endl;
		return 0.0;
	}
	if(above_high(t2, s2)) {
		if(above_low(t2, s1)) { 
			// cout << 2 << endl;
			return 0.5*(t2+w-s1)*(t2-s1+w);
		}
		else {
			// cout << 3 << endl;
			return 0.5*(t2+w-s1)*(t2-s1+w) - 0.5*(t2-w-s1)*(t2-s1-w);
		}
	}
	else {
		if(above_high(t1, s1)) {
			if(above_low(t2, s1)) {
				// cout << 4 << endl;
				return 0.5*(2*t2+2*w-s2-s1)*(s2-s1);
			}
			else {
				if(above_low(t2, s2)) {
					// cout << 5 << endl;
					return 0.5*(2*t2+2*w-s2-s1)*(s2-s1) - 0.5*(t2-w-s1)*(t2-s1-w);
				}
				else {
					// cout << 6 << endl;
					// cout << s1 << t1 << endl;
					return 2*w*(s2-s1);
				}
			}
		}
		else {
			if(above_high(t1, s2)) {
				if(above_low(t2, s1))
					return area - 0.5*(s2-w-t1)*(s2-w-t1);
				else {
					if(above_low(t2, s2)) {
						return area - 0.5*(s2-w-t1)*(s2-w-t1) - 0.5*(t2-w-s1)*(t2-s1-w);
					}
					else {
						if(above_low(t1, s1))
							return area - 0.5*(s2-w-t1)*(s2-w-t1) - 0.5*(s2-s1)*(2*t2-2*w-s1-s2);
						else
							return 0.5*(s2+w-t1)*(s2+w-t1) - 0.5*(s2-w-t1)*(s2-w-t1);
					}
				}
			}
			else {
				if(above_low(t2, s1))
					return area;
				else {
					if(above_low(t2, s2))
						return area - 0.5*(t2-w-s1)*(t2-s1-w);
					else {
						if(above_low(t1, s1))
							return area - 0.5*(s2-s1)*(2*t2-2*w-s1-s2);
						else {
							return 0.5*(s2+w-t1)*(s2+w-t1);
						}
					}
				}
			}
		}
	}
	return 1.0;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for(int cc=1;cc<=T;cc++) {
		scanf("%lf%lf%lf%lf%lf", &t1, &t2, &s1, &s2, &w);
		if(t2 - t1 < s2 - s1) {
			swap(t1, s1);
			swap(t2, s2);
		}
		double ans = solve() / (t2-t1) / (s2-s1);
		printf("Case #%d: %.8f\n", cc, fabs(ans));
	}
	return 0;
}