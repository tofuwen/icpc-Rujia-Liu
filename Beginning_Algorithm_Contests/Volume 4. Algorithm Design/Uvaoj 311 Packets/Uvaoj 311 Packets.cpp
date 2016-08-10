#include <cstdio>
using namespace std;

int num[10];

int main()
{
	//freopen("data.txt","r",stdin);
	while(1){
		int sum = 0;
		for(int i=0;i<6;i++){
			scanf("%d",&num[i]);
			sum += num[i];
		}
		if(sum == 0)
			break;
		int ans = 0;
		for(int i=5;i>=0;i--){
			switch(i){
				case 5:{
					ans += num[i];
					break;
				}
				case 4:{
					ans += num[i];
					num[0] -= 11*num[i];
					break;
				}
				case 3:{
					ans += num[i];
					if(num[1] >= num[i]*5)
						num[1] -= num[i]*5;
					else{
						int remain = 5*num[i] - num[1];
						num[1] = 0;
						num[0] -= remain*4;
					}
					break;
				}
				case 2:{
					int k = num[i] / 4;
					int remain = num[i] - 4*k;
					ans += k;
					if(remain > 0){
						ans++;
						switch(remain){
							case 3:{
								if(num[1] > 0){
									num[1]--;
									num[0] -= 5;
								}
								else
									num[0] -= 9;
								break;
							}
							case 2:{
								if(num[1] >= 3){
									num[1] -= 3;
									num[0] -= 6;
								}
								else{
									int r = 18 - 4*num[1];
									num[1] = 0;
									num[0] -= r;
								}
								break;
							}
							case 1:{
								if(num[1] >= 5){
									num[1] -= 5;
									num[0] -= 7;
								}
								else{
									int r = 27 - 4*num[1];
									num[1] = 0;
									num[0] -= r;
								}
								break;
							}
							default: break;
						}
					}
					break;
				}
				case 1:{
					int k = num[i] / 9;
					ans += k;
					int remain = num[i] - 9*k;
					if(remain > 0){
						ans++;
						int r = 36 - remain*4;
						num[0] -= r; 
					}
					break;
				}
				case 0:{
					if(num[i] > 0){
						int k = num[i] / 36;
						ans += k;
						int remain = num[i] - k*36;
						if(remain > 0)
							ans++;
					}
					break;
				}
				default: break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}