## 注意事项
- 不要为 std::hash 添加偏特化： 标准库允许全特化（如上例），但不允许偏特化。例如，以下代码是不合法的：
```example.cpp
template <typename T>
struct std::hash<MyTemplate<T>>; // 不允许
```
- 组合哈希值时防止冲突： 简单的异或运算可能导致冲突，建议采用更复杂的组合方式，例如：
```example2.cpp
size_t hash_combine(size_t seed, size_t value) {
    return seed ^ (value + 0x9e3779b9 + (seed << 6) + (seed >> 2));
}
```