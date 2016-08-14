#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct component {
	long long price, quality;
	component(long long price, long long quality): price(price), quality(quality){}
};

// void prlong long(const vector<component> & v) {
// 	long long size = v.size();
// 	for(long long i=0;i<size;i++) {
// 		cout << v[i].price << " " << v[i].quality << endl;
// 	}
// }

long long choose(long long quality, const vector<component> & v) {
	long long ans = 1 << 30;
	for(long long i=0;i<v.size();i++) {
		if(v[i].quality >= quality)
			ans = min(ans, v[i].price);
	}
	return ans;
}

long long solve(const map<string, vector<component>> & Map, long long b) {
	long long low = 0, high = 1000000001;
	while(high-low > 1) {
		long long mid = (high+low)/2;
		long long total = 0;
		for(auto iter=Map.begin(); iter != Map.end(); iter++) {
			total += choose(mid, iter->second);
		}
		if(total > b)
			high = mid;
		else
			low = mid;
	}
	return low;
}

int main()
{
	// freopen("data.txt", "r", stdin);
	long long T;
	cin >> T;
	while(T--) {
		long long n, b;
		cin >> n >> b;
		map<string, vector<component>> Map;
		for(long long i=0;i<n;i++) {
			string type, name;
			long long price, quality;
			cin >> type >> name >> price >> quality;
			auto iter = Map.find(type);
			if (iter == Map.end()) {
				vector<component> v;
				v.push_back(component(price, quality));
				Map[type] = v;
			} else {
				iter->second.push_back(component(price, quality));
			}
		}
		// for (auto iter = Map.begin(); iter != Map.end(); iter++) {
		// 	cout << iter->first << endl;
		// 	prlong long(iter->second);
		// }
		cout << solve(Map, b) << endl;
	}
	return 0;
}