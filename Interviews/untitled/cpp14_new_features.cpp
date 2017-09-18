//
// Created by Poodar Chu on 9/15/17.
//

#include <iostream>
#include <vector>
#include <string>
#include <numeric>

[[deprecated]]struct record {
    std::string name;
    int id;
//    GUID id;
};

// replace below 'int' with auto
auto find_id(const std::vector<record> &people, const std::string &name) {
    auto match_name = [&name](const record& r) -> bool {
        return r.name == name;
    };
//    auto ii = std::find_if(people.begin(), people.end(), match_name);
//    if(ii == people.end()) {
//        return -1;
//    } else
//        return ii->id;
}

template <typename Container>
struct finder {
    static decltype(Container::find) finder1 = Container::find;
    static decltype(auto) finder2 = Container::find;
};


int main3() {
    std::vector<record> roster = {
            {"mark", 1},
            {"bill", 2},
            {"ted", 3}
    };
//    std::cout << find_id(roster, "bill") << std::endl;
//    std::cout << find_id(roster, "ron") << std::endl;

    std::vector<int> ivec = {1, 2, 3, 4};
    std::vector<std::string> svec = {"red", "green", "blue"};
    auto adder = [](auto op1, auto op2){return op1+op2;};
    std::cout << "int result: " << std::accumulate(ivec.begin(), ivec.end(), 0, adder);
    std::cout << "string result: " << std::accumulate(svec.begin(), svec.end(), std::string(""), adder);

    return 0;
}
