#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


int main() {
    int K, N;
    cin >> K >> N;

    int arr[K][N];

    for(int i = 0; i < K; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    int ptr[10000];

    int i,minval,maxval,minrange,minel,maxel,flag,minind;

    for(i = 0;i <= K;i++)
        ptr[i] = 0;

    minrange = INT_MAX;

    while(true) {
        minind = -1;
        minval = INT_MAX;
        maxval = INT_MIN;
        flag = 0;

        for(i = 0;i < K;i++) {
            if(ptr[i] == N) {
                flag = 1;
                break;
            }
            if(ptr[i] < N && arr[i][ptr[i]] < minval) {
                minind=i;  // update the index of the list
                minval=arr[i][ptr[i]];
            }
            if(ptr[i] < N && arr[i][ptr[i]] > maxval)
                maxval = arr[i][ptr[i]];
        }

        if(flag)
            break;

        ptr[minind]++;

        if((maxval-minval) < minrange) {
            minel = minval;
            maxel = maxval;
            minrange = maxel - minel;
        }
    }

    printf("%d %d", minel, maxel);

    return 0;
}
