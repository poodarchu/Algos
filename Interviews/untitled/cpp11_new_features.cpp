//
// Created by Poodar Chu on 9/15/17.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main4(int argc, char* argv[]) {
    int x = 1;
    int& y = x;
    cout << y << endl;
    cout << &y << endl;
}

class foo {

};

template <typename Product, typename Creator>
void processProduct(const Creator& creator) {
    Product* val = creator.makeObject();
    // do something with val.
};

template <typename Creator>
void processProduct(const Creator& creator) {
    auto val = creator.makeObject();
}

template <typename Creator>
auto processProduct(const Creator& creator) -> decltype(creator.makeObject()) {
    auto val = creator.makeObject();
    // do something with val.
}

void F(int a) {
    cout << a << endl;
}

void F(int *p) {
//    assert (p != NULL);
    cout << p << endl;
}


int main2(int argc, char* argv[]) {
    auto a = 0x01;

    auto i = 1;
    auto d = 1.0;
    auto str = "hello world.";
    auto ch = 'C';
    auto func = less<int>();

    vector<int> iv;
    auto ite = iv.begin();
    auto p = new foo();

    int x = 3;
    decltype(x) y = 4;
    cout << y << endl;

    int *r = nullptr;
    int *q = NULL;
    bool equal = (r == q);
    cout << equal << endl;

//    int ax = nullptr;
    F(0);
    F(nullptr);

    map<string, int> m{
            {"a", 1},
            {"b", 2},
            {"c", 3}
    };

    for (auto p : m) {
        cout << p.first << " : " << p.second << endl;
    }

    // Lambda 表达式 类似 JavaScript 的闭包，用于创建并定义匿名的函数对象
    // 【函数对象参数】（操作符重载函数参数）-》 返回值类型 {函数体}
    vector<int> iv2{5, 4, 3, 2, 1};

    int a2 = 2;
    int b2 = 1;

    // [] 内的参数指的是 lambda 表达式可以取得的全局变量。
    // 如果在 [] 内传入 = 的话，即是可以取得所有的外部变量
    // () 内的参数是每次调用函数时传入的参数
    // -> 后加上的是lambda表达式返回值的类型
//   for_each(iv.begin(), iv.end(), [b2](int &x) {cout << (x+b2) << endl;});
//   for_each(iv.begin(), iv.end(), [=](int &x) {x *= (a2+b2);});
//   for_each(iv.begin(), iv.end(), [=](int &x) -> int {return x*(a2+b2);});

    auto pair1 = make_pair(1, "C++ 11");
    cout << pair1.first << pair1.second << endl;

    // C++ 11 中引入了可变长参数模板，所以发明了 tuple，它是一个 N 元组，可以传入 1 个，2 个甚至多个不同的数据类型
    auto t1 = make_tuple(1, 2.0, "C++ 11");
//    auto t2 = make_tuple(1, 2.0, "C++ 11", {1, 0, 2});

    int arr[3] = {1, 2, 3};
    vector<int> v(arr, arr+3);

    int arr2[3]{1, 3, 4};
    vector<int> iv3{1, 3, 5};
    vector<int> iv4(arr2, arr2+3);
    map<int, string> map2{{1, "a"}, {2, "b"}};
    string str2{"Hello world"};

    return 0;
}