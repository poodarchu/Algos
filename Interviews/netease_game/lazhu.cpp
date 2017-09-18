//
// Created by Poodar Chu on 9/16/17.
//

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    int num;
    cin >> num;

    while(num--) {
        vector<int> seq;

        int N, M;
        cin >> N >> M;

        int tmp;
        while(N--) {
            cin >> tmp;
            seq.push_back(tmp);
        }

        sort(seq.begin(), seq.end());

        for(int i = N-1; i >= 0, M-- > 0; i--) {
            int tmp = seq[i];

        }

//        int max = 0;
//
//        for(int i = seq.size()-1; i > 0; i--) {
//            int local = seq[i] - seq[i-1];
//            if(local > max)
//                max = local;
//        }
//
//        cout << max << endl;

    }

    return 0;
}