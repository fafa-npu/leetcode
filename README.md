此项目用于记录本人leetcode刷题的代码

# 26. remove duplicates from sorted array.
* 最便捷的方法:使用stl的unique函数和vector的erase，两行即可得到结果，可是效率不高。
* 效率高的方法:使用两个指针。
由于给点数组是拍好序的，所以可以遍历数组，当当前遍历的值大于unique的最大数值时，将当前值复制到unique的数组中，并将返回值+1. 
 详见代码。

# 28. Implement strStr()
* c++ 比较字符串（string） 
    - 使用strcmp(const char * str1, const char * str2), 此方法比较char * 类型的字符串
    - 使用string::compare(const string & str), 此方法比较string类型的字符串
    
* c++ string获取子字符串 substr(long p1, long length), 从p1开始，长度为length的子串

# 36. Valid Sudoku
* 使用HashTable
* c++ 中 stl的hashmap为 unordered_map
    - 自带迭代器
    - key 为 (*it).first
    - value 为 (*it).second
    - 查找是否存在key    unordered_map::find(T key), 返回所在位置的迭代器，没有对应的key时返回end();
* vector 的初始化指定大小的数组 *vector<T> a(n);*

# 38. Count and Say
* 很简单的题目，详见代码
* 问题： 
    - 执行效率低
    - 思维混乱，表现在代码中就是逻辑不清晰
    - 用先想清楚或在纸上画清楚流程再开始写代码
    
# 48. Rotate Image
* 注意点：
    - 每个点与其对应旋转的其它三个点之间的旋转关系
    - 循环的方式与次数
        * 从最外层依次向里直至最中心，共需旋转的层数为n/2
        * 每一层中要旋转的次数为 n - i - 1 (i为所在层数)
        * 详见代码