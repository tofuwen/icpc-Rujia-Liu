#include <iostream>

using namespace std;

int main()
{
    long right = 0, j = 0;
    for (long house = 2, pairs = 0; pairs < 10; house++) {
        long left = (house * house - house) / 2;
        if (right > 0) {
            right -= house;
        } else {
            j = house + 1;
        }
        while (right <= left) {
            right += j;
            if (right == left) {
                pairs++;
                cout.width(10);
                cout << house;
                cout.width(10);
                cout << j << endl;
            }
            j++;
        }
    }
    return 0;
}
