#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<string, string> courses;

int main(int argc, char* argv[]) {
    int numCourses;
    cin >> numCourses;

    map<string, string>::iterator iter;

    while(numCourses--) {
        char date, time;
        string cid;
        cin >> date >> time >> cid;
        string tmp = string(1,date)+string(1,time);

        iter = courses.find(tmp);
        if(iter == courses.end()) {
            courses[tmp] = cid;
        }
        else {
            string i = courses[tmp];
            i += " " + cid;
            courses[tmp] = i;
        }
    }

    for(map<string, string>::iterator iter = courses.begin(); iter != courses.end(); iter++) {
        if(iter->second.size() > 6)
            cout << iter->first << " " << iter->second << endl;
    }




    return 0;
}