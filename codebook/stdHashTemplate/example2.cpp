#include <iostream>
#include <string>
#include <functional> // std::hash

// 内置支持的类型
// 标准库已经对以下类型特化了 std::hash：

// 整数类型（如 int, long, unsigned int, size_t 等）。
// 浮点类型（float, double 等）。
// 指针类型。
// 标准容器 std::string、std::wstring 等。
// 对这些类型，std::hash 已经实现了直接支持，无需用户自定义。例如：

int main() {
    std::hash<int> int_hash;
    std::hash<std::string> string_hash;

    int value = 42;
    std::string name = "ChatGPT";

    std::cout << "Hash of " << value << ": " << int_hash(value) << std::endl;
    std::cout << "Hash of \"" << name << "\": " << string_hash(name) << std::endl;

    return 0;
}
