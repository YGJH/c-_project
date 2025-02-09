#include <iostream>
#include <string>
#include <functional> // std::hash
#include <unordered_set> // For unordered containers

struct Person {
    std::string name;
    int age;

    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

// 为自定义类型特化 std::hash
namespace std {
    template <>
    struct hash<Person> {
        std::size_t operator()(const Person& p) const {
            std::hash<std::string> string_hash;
            std::hash<int> int_hash;

            // 组合哈希值
            return string_hash(p.name) ^ (int_hash(p.age) << 1);
        }
    };
}

int main() {
    Person p1 = {"Alice", 30};
    Person p2 = {"Bob", 25};

    std::unordered_set<Person> people = {p1, p2};

    for (const auto& person : people) {
        std::cout << person.name << ", " << person.age << std::endl;
    }

    return 0;
}