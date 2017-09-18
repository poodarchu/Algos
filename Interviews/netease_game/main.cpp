#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

void split(const string& s, char delim, vector<string>& v) {
    auto i = 0;
    auto pos = s.find(delim);
    while (pos != string::npos) {
        v.push_back(s.substr(i, pos-i));
        i = ++pos;
        pos = s.find(delim, pos);

        if (pos == string::npos)
            v.push_back(s.substr(i, s.length()));
    }
}

bool isValidTime(int hr, int min, int sec) {
    return (((hr >= 0) && (hr < 24)) && ((min >= 0) && (min < 60)) && ((sec >= 0) && (sec < 60)));
}

int main2(int argc, char* argv[]) {
    int T;
    cin >> T;

    vector<vector<string>> lst;

    while(T--) {
        string timestamp;
        vector<string> v;
        int HH, MM, SS;

        cin >> timestamp;
        split(timestamp, ':', v);

        HH = atoi(v[0].c_str()), MM = atoi(v[1].c_str()), SS = atoi(v[2].c_str());

        if(isValidTime(HH, MM, SS)) {
//            cout << v[0] << ":" << v[1] << ":" << v[2];
            lst.push_back(v);
        } else {
            if(HH >= 24 && HH < 30)
                v[0][1] = '0';
            else if(HH >= 30)
                v[0][0] = '0';

            if(MM >= 60)
                v[1][0] = '0';

            if(SS >= 60) {
                v[2][0] = '0';
            }
//            cout << v[0] << ":" << v[1] << ":" << v[2];
            lst.push_back(v);
        }

//        if(T > 1)
//            cout << endl;
    }

    for(int i = 0; i < lst.size(); i++) {
        cout << lst[i][0] << ":" << lst[i][1] << ":" << lst[i][2];
        if(i < lst.size()-1)
            cout << endl;
    }


    return 0;
}