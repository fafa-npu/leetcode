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

# ZigZag Conversion
        
        /*n=numRows
        Δ=2n-2    1                           2n-1                         4n-3
        Δ=        2                     2n-2  2n                    4n-4   4n-2
        Δ=        3               2n-3        2n+1              4n-5       .
        Δ=        .           .               .               .            .
        Δ=        .       n+2                 .           3n               .
        Δ=        n-1 n+1                     3n-3    3n-1                 5n-5
        Δ=2n-2    n                           3n-2                         5n-4
        */
   
   1. 观察上图，可以发现，每一行的排布是由规律的,从第一个数字开始，经过distance1后为第二个数字，再经过Distance2后为下一个数字，以此循环往复
   
          Distance1 = 2n - 2 - (2row - 1) = 2n - 2row
          Distance2 = 2(row - 1)
   2. 注意，第一行的Distance2为0， 最后一行的Distance1为0
   
    
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

# 17. Letter Combinations of a Phone Number
* 回溯

# 18. 4Sum
在3Sum的基础上再加一层循环，使4Sum问题降维到3Sum问题，最终降维到2Sum问题。

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
        
# 23. Merge k Sorted Lists
* 1. 每两个做一次merge操作，直到剩余一个list

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

# 31. Next Permutation
--
    1. 寻找最大的i，使得nums[i] < nums[i + 1];
    2. 若无法找到，则返回反转后的数组
    3. 寻找最大的k，使得nums[i] < nums[k]
    4. swap(nums[i], nums[k]}
    5. 反转nums(i + 1, nums.end)
    6. nums即为所求解
    
# 32. Longest Valid Parentheses
* DP
        
        令 longest[i]为s[0]到s[i]中最长的合法圆括号的数目
        则
            1. longest[0] = 0
            2. if s[i] == '('
                    longest[i] = 0 
               else           // s[i] == ')'
                    if s[i - 1] == '('
                        longest[i] = longest[i - 2] + 2;
                    else      // s[i - 1] == ')' 
                        if (s[i - longest[i - 1] - 1] == '(')
                            longest[i] = 2 + longest[i - 1] + longest[ i - longest[i - 1] - 2]
* Stack
        
        1. 创建一个stack
        2. 创建一个数组cnt, cnt[i]代表在stack的第i层归并的括号数
        3. 遍历s中的括号，将其添加到stack中
            a. 如果当前元素为'('， 将其添加到栈顶，且index++
            b. 如果当前元素为')' && 栈顶元素为'(', 
                index-- 
                cnt[index] += cnt[index + 1] + 2 
            c. 如果当前元素为')' && (栈顶元素为')' || 栈为空), 
                将其添加到栈顶， index++
        4. 返回cnt中最大的值
* 注意：
    c++ 中， string::size() 和string::length()是同义的。
    获取vector中最大的元素的*迭代器* std::max_element(vector::begin(), vector::end())
                            
# 33. Search in Rotated Sorted Array
* 先用二分查找找出rotate的位置，再用二分查找寻找当前数字的位置。
* 一直rotate开始的位置后，用二分查找查相应地数字时，要把mid和realMid区分开来。

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

# 43. Multiply String
* 要求：
    1. 给定的两个数字可能任意大且非负
    2. 不能使用string 转 int
    3. 不能使用类似BigInteger的内部库
* 解题方法，使用最原始的乘法手算法。
    
            a b c
          × d e f
          -------

* 注意：
    1. 每个循环最后一位的进位
    2. 要将结果中最开始的0去除掉，同时应注意结果为0 的情况
    
# 45. Jump Game II
* 广度优先搜索 + 贪心

        令 step 为当前所需要走的步数， start为当前可到达的范围的起始位，end为当前可到达的范围的终止位。
        则：
            start = end = 0
            step = 0
            while(maxEnd < length - 1) 
                step++
                for (int i = start; i <= end; i++)
                    maxEnd = end + 1
                    if (i + nums[i] >= length - 1)
                        return step
                    maxEnd = max(maxEnd , i + nums[i])
                start = end + 1
                end = maxEnd
            return step
                
    
# 46. Permutations
* 动态规划(待续)？
* 回溯法
    - swap

# 47. Permutations II
* 回溯法
* 与46相比，给定的集合中可能会有重复的数字，因此要有去重操作。
* 在swap前判断要swap的两个数是否相同，如果相同，则不交换。

# 48. Rotate Image
* 注意点：
    - 每个点与其对应旋转的其它三个点之间的旋转关系
    - 循环的方式与次数
        * 从最外层依次向里直至最中心，共需旋转的层数为n/2
        * 每一层中要旋转的次数为 n - i - 1 (i为所在层数)
        * 详见代码

# 49. Group Anagrams
* 将给定字符串排序，以排序后的string做hash table.

# 50. Pow(x, n)
* 递归调用，二分查找

# 51. N-Queens
* 回溯法
* n-queens合法的条件为
        
        令 (row, col)为当前放置皇后的坐标
        1. for(int i = 0; i < n; i++) queens[i][col] != 'Q'
        2. for(int j = 0; j < n; j++) queens[row][j] != 'Q';
        3. for(int i = 0; i < n; i++) 
                queens[x-i][y-i] != 'Q'
              &amp;&amp; queens[x+i][y+i] != 'Q'
              &amp;&amp; queens[x-i][y+i] != 'Q'
              &amp;&amp; queens[x+i][y-i] != 'Q'
 *或 
 
        设置三个flag数组，其中
            flag1[] 代表相应列是否有queen 
            flag2[] 代表45°直线是否有queen
            flag3[] 代表135°直线是否有queen
             | | |                / / /             \ \ \
             O O O               O O O               O O O
             | | |              / / / /             \ \ \ \
             O O O               O O O               O O O
             | | |              / / / /             \ \ \ \ 
             O O O               O O O               O O O
             | | |              / / /                 \ \ \
            3 columns        5 45° diagonals     5 135° diagonals    (when n is 3)
 
 # 52. N-Queens II
 * 不需要返回整个board，所以不需要维护board
 
 # 53. Maximum Subarray
 * 动态规划法 O(n)
        
        ans = nums[0]
        sum = 0 
        for i = 0 : n - 1 
            sum += nums[i]
            ans = max(sum, ans)
            sum = max(sum,0)
 
 # 54. Spiral Matrix
 * 从外向内循环，每层按如下方式遍历
        
        ---- |
        |    |
        |-----
        具体的：
            设置 u,b, l, r 四个边界，每个边界中的元素遍历完后都执行一次 ++ 或 -- 操作
            
# 55. Jump Games
* 方法一
    * 0是可能会造成无法到达的关键因素。
    * 对nums中出现的每一个0，假设其所在的位置为index，若对于[0,index-1]内的所有i，不存在nums[i]使得nums[i] - (index - i) > 0， 则返回false
* 方法二
    * 贪心
    * 遍历整个数组，计算所能到达的最大的位置
    * Here is a brilliant method:
            
            for (int i = 0, reach = 0; i < n && i <= reach) 
                reach = max(i+A[i], reach)
            return i == n
            
# 56. Merge Intervals
* 先对所有的范围对按照第一个数字的大小进行排序
* 对排序后的结果，如果当前范围对的后一个数字小于等于下一个范围对的前一个数字，则合并。
* 排序：
        
        sort(myVector.begin(), myVector.end(), myFunction);
        
* merge:
        
        1. 将intervals[0]添加到result
        2. 顺序遍历intervals中剩余的元素
            if (result.back.end < intervals[i].start)
                result.push_back(intervals[i])
            else 
                result.back.end = max(result.back.end, intervals[i].end)
                
# 57. Insert Interval
* 先排序
* 对intervals内的start从小到大遍历

        1. if (newInterval.end < intervals[i].start)
                遍历终止，将剩余的interval添加到result
        2. if (newInterval.start < intervals[i].end)
                newInterval = { min(newInterval.start, intervals[i].start), max(newIntervals.end, intervals[i].end) }
        3. if (newInterval.end > intervals[i].start)
                result.push_back(it)
                
# 58. Length of Last Word
* 从后往前数
* 注意最后是空格时的状况
        
# 59. Spiral Matrix II
* 螺旋矩阵
* 从外向内，一层一层遍历。共有(n+1) / 2 层

# 60. Permutation Sequence
1. 使用next_permutation
    TLE...
2. 什么算法？？？ 看不懂啊

# 61. Rotate List
* 使用一个vector临时存储List，可以实现只遍历一次就rotate的目标。


# 62. Unique Paths
* 动态规划

        p[i][j]为到达(i,j)所需的步数。
        p[i][j] = p[i-j][j] + p[i][j-1]
* 使用的DP数组的大小可以设置为(m + 1) * (n + 1), 这样就不用单独处理第一行和第一列了。

# 63. Unique Paths II
* 同上， 动态规划
* 若当前位置为1， 则paths count = 0
* 注意当（0，0）位置为1时。

# 64. Minimum Path Sum
* 动态规划
       
       sum[i][j] 保存到达当前位置最小的sum
       则，
       sum[i][j] = currentNum + min(sum[i - 1][j], sum[i][j - 1]
* 注意， 由于当前位置的sum仅与左和上方的sum有关系，因此，可以使用两个vector代替sum
  进而，可以使用一个vector代替sum，只保存当前位置上方的sum和当前位置左下方的sum, 详见[dicuss](https://discuss.leetcode.com/topic/15269/10-lines-28ms-o-n-space-dp-solution-in-c-with-explanations)

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

# 67. Add Binary
* 从后往前加
* 注意进位

# 69. Sqrt(x)
* binary search
* 注意： 边界值
* target找到的条件
    
        nums == target / nums;

# 70. Climbing Stairs
* 等同于斐波那契数列
* 动态规划
 
        1. stairs[i]为攀登i层可能的方法
        2. stairs[0] = 0
           stairs[1] = 1
           stairs[2] = 2
        3. stairs[i] = stairs[i-1] + stairs[i-2]

# 72. Edit Distance
* 动态规划

        令 dp[i, j] 为 word1[0, i-1], word2[0, i-2]的minDistance
        则：
            dp[i][0] = i                   if word2 is ""
            dp[0][j] = j                   if word1 is ""
            dp[i][j] = 
                dp[i-1][j-1] ,             if word1[i] == word2[j]
                min (
                    dp[i - 1][j - 1] + 1,  if replace
                    dp[i - 1][j] + 1,      if delete a character from word1
                    dp[i][j - 1] + 1,      if insert a character into word1
                ) 
* 由于dp[i][j]只与dp[i-1][j-1], dp[i-1][j], dp[i][j-1]有关，因此可以将dp由m*n 简化为m + 1或n + 1(逐行或逐列)          

# 73. Set Matrix Zeroes
* O(m + n) space
            
            需要一个额外的空间存储哪一行哪一列置0.
    
* O(1) space
        
            令
            第一行的所有数字作为其所在列是否存在0的指示位，
            第一列的所有数字作为其所在行是否存在0的指示位。 
            遍历整个矩阵，如果当前数字为0，则置当前行和当前列的第一个数字为0
            注意，nums[0][0]位置的数字是row0与col0的重合，所以应设置另外一个变量单独记录row0或col0
          
# 74. Search a 2D Matrix 
* binary search
        
        length = m * n;
        for (i : length) 
            row = i / n;
            col = i * n;
            
# 75. Sort Colors
* 设置两个标志位a, b 分别代表正在排序的0和2的下一个位置。

        具体地：
        flag0 = 0
        flag2 = nums.size()- 1
        index = 0
        while (index <= flag2)
            if (nums[index] == 0) 
                swap(nums[index],nums[flag0]
                index++
                flag0++
            else if (nums[index] == 2)
                swap(nums[index], nums[flag2])
                flag2--
            else 
                index ++
* 为什么 在nums[index] == 0 的时候index++ ，而nums[index] == 2的时候不能index++，可否将0中的index++移到2中去？
    - 不可以
    1. 当nums[index] == 2时，swap之后，index所指向的元素是一个新的元素，此时如果执行index++操作，会把swap过来的元素忽略，所以在2中不能进行index++操作。
    2. 当nums[index] == 0时，flag0 <= index始终成立，所以flag0所指的位置必定为1，故不需要重新判断，可以执行自增操作。
    3. 若0中不进行自增操作，可能会造成flag0 > index的情况，比如nums为 (0,0,1)时，此时flag0越界，因此0中必须执行自增操作。