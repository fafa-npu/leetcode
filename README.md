此项目用于记录本人leetcode刷题的代码

# 2. Median of Two Sorted Arrays
* Star
* 暴力解法， apparently won't be accepted.
* 二分查找

    ----------------------------------------------------
            left    |    right
        A[0]...A[i] | A[i+1]...A[m-1]
        B[0]...B[j] | B[j+1]...B[n-1]
    ----------------------------------------------------
    - 其实本题只是找出 序列A 和 序列B 整体的中位数，并不需要对A+B重新排序。
    - 如上图所示，只需找到满足条件的 i 和 j, 使
        1. 
        ----------------------------------------------------
            left.size == right.size 
            即 i - 0 + j - 0 == m - 1 - i - 1 + n - 1 - j - 1 
            即 i + j == m + n - i - j - 4
        ---------------------------------------------------- 
        2. 
        ----------------------------------------------------
            A[i] <= B[j + 1]
            &&
            B[j] <= A[i + 1]
        ----------------------------------------------------
       为满足如上所述的条件，同时满足*log(m+n)*的时间复杂度要求，需要使用二分法查找*i,j* 
       

# 5. Longest Palindromic Substring
* Dynamic Programming
    - p[i][j] = 
        - true, if S<sub>i</sub>...S<sub>j</sub> is palindrome.
        - false
    - p[i][j] = p[i+1][j-1] && S<sub>i</sub> == S<sub>j</sub>
    - p[i,i] = true
    - p[i, i+1] = S<sub>i</sub> == S<sub>i+1</sub>
    将所有的p[i,i]和p[i, i+1]初始化，然后生成所有的三个字符的回文，依次往下
* 遍历string中可以作为中心的2n-1个位置，取以每个位置作为中心的最大回文。
* 注意：
    size_t 是 unsigned 类型的，所以用来作为string的index且做--操作时，不可以用>=0为临界条件。
    
# 10. Regular Expression Matching
* Dynamic Programming
    - s 为待匹配字符串， p为re表达式
    - f[i][j] 代表s[0, i-1]与p[0, j-1]匹配。
    - 首先考虑s为空时的情况，p是否能够匹配;
    - 当p[j-1] != '*' 时, f[i][j] = f[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')
    - 当p[j-1] == '*' 时, f[i][j] = 
        - 令 x = p[j-2]
        - x重复0次, f[i][j-2] 
        - x重复1次或多次, (s[i-1] == p[j-1] || p[j-1] == '.') && f[i-1][j]
        
# 11. Container With Most Water
* 穷举
* 双指针法
    1. 取指针front，back分别指向数组的前后
    2. 计算front与back的两个数所能组成的area
    3. 若front所指的值小于back所指的值，则front后移，反之back前移
    4. 重复2，直到front == back
    ![双指针法图解](https://leetcode.com/media/original_images/11_Container_Water.gif)
* 注意， 使用stl的max/min算法时要注意，输入的两个参数必须类型一致，size_t和int就无法比较。

# 15. 3Sum
* 先将数组排序，顺序遍历数组作为第一个数字
* 寻找第2、3个数字时采用类似二分查找的方法，从两边向中间找。
* 题目中的note要注意，由于规定只准保留不重复的结果，所以可以在出现一个结果时要跳过重复的数字。
* 注意：
    - map的迭代器无法进行加法或减法操作，只能自增或自减
    - set中元素的排列是顺序的
    - multiset相对于set，元素可以重复
    
# 16. 3Sum Closest
使用双指针法，先对数组进行排序，然后从两边向中间逼近。

# 22. Generate Parentheses
* 方法：
    - n = 1时，结果为 "()"
    - 假设n = i时，结果集合为R<sub>i</sub> = {a,b,c....xxx}, 则n = i+1时的结果集合R<sub>i+1</sub>的求法为：
        - 取R<sub>i</sub>中的string，对每个string中的每个位置都插入一个"()"得到tmpStr, 如果R<sub>i+1</sub>中不存在tmpStr，则将tmpStr加入R<sub>i+1</sub>中
        - R<sub>i+1</sub>即为 n = i+1时的结果
* 注意：
    - vector中没有find
    - 将set复制到vector中的方法
        - *std::copy(input.begin(), input.end(), std::back_inserter(output));*
        - *std::vector<double> output(input.size());*  
          *std::copy(input.begin(), input.end(), output.begin());*
        - 不可以直接使用*std::copy(input.begin(), input.end(), output.begin());*

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

# 34. Search for Range
* 先二分查找到target，然后再根据查找到的位置向左向右扩张

# 35. Search Insert Position
* 二分查找
* 注意
    - 使用二分查找时，循环的判断条件为 <=
    - *front = mid + 1*
    - *back = mid - 1*
    
# 36. Valid Sudoku
* 使用HashTable
* c++ 中 stl的hashmap为 unordered_map
    - 自带迭代器
    - key 为 (*it).first
    - value 为 (*it).second
    - 查找是否存在key    unordered_map::find(T key), 返回所在位置的迭代器，没有对应的key时返回end();
* vector 的初始化指定大小的数组 *vector<T> a(n);*

# 37. Solve Sudoku
* 回溯法
* 在回溯中判断当前棋盘是否valid时，
    - 使用36的方法重新遍历会非常耗时间。
    - 正确的做法是，只判断当前加入的数字是否valid就可以.

# 38. Count and Say
* 很简单的题目，详见代码
* 问题： 
    - 执行效率低
    - 思维混乱，表现在代码中就是逻辑不清晰
    - 用先想清楚或在纸上画清楚流程再开始写代码
    
# 39. Combination Sum
* 递归
* 回溯
* 注意：
    - vector中的元素翻转
        --
            vector::reverse(size_t size);
            std::reverse(vec.begin(), vec.end();
    - 

# 40. Combination Sum II
* 相对与39，解集合中每个给定的数字只能出现一次，但给定的数字中可能会用重复，所以要有去重操作。

# 42. Trapping Rain Water
* 1. 计算最底层的容量，然后各高度减1，递归计算最底层容量，知道所有高度减完。（TLE）
* 2. 使用双指针法，从两边向中间走，每次走值小的那边;左右各记录一个最大值,遇见比最大值小的计算容量，遇见比最大值大的，把现在的值设为最大值。 
    
# 46. Permutations
* 采用递归的方法
* 动态规划(待续)？
* 回溯法

# 48. Rotate Image
* 注意点：
    - 每个点与其对应旋转的其它三个点之间的旋转关系
    - 循环的方式与次数
        * 从最外层依次向里直至最中心，共需旋转的层数为n/2
        * 每一层中要旋转的次数为 n - i - 1 (i为所在层数)
        * 详见代码
        
# 66. Plus One
* 迭代器返向遍历
    --
        for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); it++) {
* 方法一：
    - 从最低位开始加一，依次进位，直到最高位。
* 方法二:
    - 从最低位开始加一，依次进位，直到进位值为0.
    - 具体地：
        - 若当前位为9， 则置当前位为0
        - 若当前位不是9， 则当前位+1， 返回当前数组。
