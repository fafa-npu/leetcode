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
