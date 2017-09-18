#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int checkContinuous(string str) {
    int begin = 0;
    int len = 1;

    while(begin < str.size()) {
        int i = 0;
        while(str[i]==str[i+1]) {
            i += 1;
            len += 1;
        }
        begin = i;
        len = 1;
    }
    return len;
}
int main2(int arg, char* argv[]) {
    string str;
    int swapNum;
    cin >> str >> swapNum;

    // if there're str.size() characters, then there're str.size()-1 types of swap.
    int maxLen = 0;

    for(int i = 0; i < swapNum; i++) {
        for(int j = 0; j < str.size()-1; j++) {
            string tmpStr = str;
            swap(tmpStr[j], tmpStr[j+1]);
            for(int k = 0; k < str.size()-1; k++) {
                string tmpStr2 = tmpStr;
                swap(tmpStr2[k], tmpStr2[k+1]);
                int localLen = checkContinuous(tmpStr2);
                if(maxLen < localLen)
                    maxLen = localLen;
            }
        }
    }

    cout << maxLen;

    return 0;
}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//typedef struct Pearl {
//    int num;
//    vector<int> arr;
//} ;
//
//int main(int argc, char* argv[]) {
//    int n, m, c; // n: 串珠数目，m: 任意连续 m 个串珠， c: 一共 c 种颜色
//
//    cin >> n >> m >> c;
//
//    vector<Pearl> bracelet;
//
//    int falseCnt = 0;
//
//    for(int i = 0; i < n; i++) {
//        Pearl p;
//        int num;
//        cin >> num;
//        p.num = num;
//        vector<int> arr;
//        int tmp;
//        while(num--) {
//            cin >> tmp;
//            arr.push_back(tmp);
//        }
//        p.arr = arr;
//        bracelet.push_back(p);
//    }
//
//    vector<int> cs(c+1);
//    vector<bool> falseColor(c+1);
//    for(int i = 0; i < c+1; i++)
//        falseColor[i] = true;
//
//    for(int i = 0; i < n; i++) {
//        Pearl tmp = bracelet[i];
//        for(int j = 0; j < m; j++) {
////            if(i + j >= bracelet.size() - 1)
////                break;
//            int idx = (i+j)%n;
//            for(int k = 0; k < bracelet[idx].num; k++) {
//                cs[bracelet[idx].arr[k]] += 1;
//            }
//        }
//        for(int i = 0; i < c+1; i++)
//            if (cs[i] > 1) {
//                falseColor[i] = false;
//            }
//
//        for(int i = 0; i < c+1; i++)
//            cs[i] = 0;
//
//    }
//
//    for(int i = 0; i < c+1; i++) {
//        if(falseColor[i] == false)
//            falseCnt += 1;
//    }
//
//    cout << falseCnt;
//
//    return 0;
//}