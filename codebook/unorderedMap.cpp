// 在 C++ 中，如果想要在 unordered_map 中使用自定義的 struct 或 class 作為 key（鍵），需要滿足兩個條件：

// 定義比較相等的運算符：必須為你的自定義類型定義 operator==（或者提供自定義的相等判斷函數），以便在查找時能正確判斷兩個鍵是否相等。

// 定義 hash 函數：unordered_map 需要一個 hash 函數來計算鍵的 hash 值。你可以通過兩種方式來實現：

// 為你的自定義類型提供一個特化的 std::hash<T> 模板；
// 或者在建立 unordered_map 時傳入一個自定義的 hash 函數對象。
// 下面給出一個完整的示例，假設有一個自定義結構體 Point，我們希望用它作為 unordered_map 的

#include <iostream>
#include <unordered_map>
using namespace std;

// 自定義結構體
struct Point {
    int x;
    int y;

    // 定義 operator==，用於比較兩個 Point 是否相等
    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }
};

// 方法1：提供 std::hash 的特化版本
namespace std {
    template<>
    struct hash<Point> {
        size_t operator()(const Point &p) const {
            // 常用的 hash 合併技巧：使用 std::hash<int>
            size_t h1 = std::hash<int>()(p.x);
            size_t h2 = std::hash<int>()(p.y);
            // 可以採用 XOR 和位移來合併兩個 hash 值
            return h1 ^ (h2 << 1);
        }
    };
}

int main() {
    // 現在可以直接使用 unordered_map，鍵為 Point，值為 string
    unordered_map<Point, string> pointMap;
    
    // 插入數據
    pointMap[{1, 2}] = "Point (1,2)";
    pointMap[{3, 4}] = "Point (3,4)";
    
    // 查找和輸出
    Point p = {1, 2};
    if(pointMap.find(p) != pointMap.end()){
        cout << "Found: " << pointMap[p] << "\n";
    } else {
        cout << "Not found.\n";
    }
    
    return 0;
}


// 方法2：自定義 hash 函數對象
// 如果不想修改 std 命名空間，也可以自定義一個 hash 函數對象，並在定義 unordered_map 時指定。例如：

struct PointHash {
    size_t operator()(const Point &p) const {
        size_t h1 = std::hash<int>()(p.x);
        size_t h2 = std::hash<int>()(p.y);
        return h1 ^ (h2 << 1);
    }
};

int main() {
    unordered_map<Point, string, PointHash> pointMap;
    // 與前面示例相同的操作……
}