//
// Created by fa－apple on 2016/11/26.
//

#include <climits>
#include <stack>
#include <queue>
#include <ctime>
#include <sstream>
#include "Solution.h"

/**
 * 计算最长公共前缀
 * @param strs 要计算的各string组成的vector
 * @return 公共前缀，如果没有公共前缀时返回 ""
 */
string Solution::longestCommonPrefix(vector<string>& strs) {
    string prefix = "";

    if (strs.size() == 0) {
        return prefix;
    }
    vector<string>::iterator it = strs.begin();
    size_t strLength = it->length();
    char tmpChar;
    for (size_t index = 0; index < strLength; index++){
        it = strs.begin();
        for (; it != strs.end(); it++) {
            if (it->length() <= index) {
                return prefix;
            }
            if (it == strs.begin()) {
                tmpChar = it->at(index);
            }
            if (tmpChar != it->at(index)) {
                return prefix;
            }
        }
        prefix.push_back(tmpChar);
    }
    return prefix;
}

/**
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * 从小到大排列
 * @param l1 sorted linked list
 * @param l2 sorted linked list
 * @return merged list
 */
ListNode * Solution::mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode * mergedList = NULL;
    ListNode * currentNode = NULL;
    ListNode * tmpNode = NULL;
    ListNode * tmpNode1 = l1, *tmpNode2 = l2;
    for (; tmpNode1 != NULL && tmpNode2 != NULL; ) {
        if (tmpNode1->val < tmpNode2->val) {
            tmpNode = tmpNode1;
            tmpNode1 = tmpNode1->next;
        } else {
            tmpNode = tmpNode2;
            tmpNode2 = tmpNode2->next;
        }

        if (mergedList == NULL) {
            mergedList = tmpNode;
            currentNode = tmpNode;
        } else {
            currentNode->next = tmpNode;
            currentNode = tmpNode;
        }
    }
    tmpNode = tmpNode1 == NULL ? tmpNode2 : tmpNode1;
    if (mergedList == NULL) {
        mergedList = tmpNode;
    }else {
        currentNode -> next = tmpNode;
    }

    return mergedList;
}

/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 * 可以用string代替vector
 * @param s
 * @return
 */
bool Solution::isValid(string s) {
    vector<char> tmpVec;
    set<char> pre = {'(', '{', '['};
    set<char> post = {')', '}', ']'};
    size_t strLength = s.length();
    char tmpC;
    for (size_t index = 0; index < strLength; index ++) {
        if (tmpVec.size() == 0) {
            tmpC = s.at(index);
            tmpVec.insert(tmpVec.begin(), tmpC);
        }else if (pre.find(s.at(index)) != pre.end()){
            tmpC = s.at(index);
            tmpVec.insert(tmpVec.begin(), tmpC);
        }else if (post.find(s.at(index)) != post.end()) {
            vector<char>::iterator it = tmpVec.begin();
            char currentChar = *it;
            switch( s.at(index) ) {
                case ')':
                    if (currentChar == '(') {
                        tmpVec.erase(it);
                    }else {
                        tmpC = s.at(index);
                        tmpVec.insert(tmpVec.begin(), tmpC);
                    }
                    break;
                case '}':
                    if (currentChar == '{') {
                        tmpVec.erase(it);
                    }else {
                        tmpC = s.at(index);
                        tmpVec.insert(tmpVec.begin(), tmpC);
                    }
                    break;
                case ']':
                    if (currentChar == '[') {
                        tmpVec.erase(it);
                    }else {
                        tmpC = s.at(index);
                        tmpVec.insert(tmpVec.begin(), tmpC);
                    }
                    break;
            }
        }
    }

    if (tmpVec.size() == 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * Given a linked list, swap every two adjacent nodes and return its head.
 * For example,Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 */
ListNode * Solution::swapPairs(ListNode * head) {
    ListNode * currentNode = head , * preNode = head;
    ListNode * tmpNode = NULL;
    size_t cnt = 0;
    while (currentNode != NULL && currentNode->next != NULL) {
        cnt ++;
        if (cnt == 1) {
            if (head != NULL && head->next != NULL) {
                currentNode = head -> next;
                head -> next = currentNode -> next;
                currentNode -> next = head;
                head = currentNode;
                currentNode = head->next->next;
                preNode = head -> next;
            }
        } else {

            tmpNode = currentNode->next;
            preNode -> next = tmpNode;
            currentNode->next = tmpNode->next;
            tmpNode->next = currentNode;
            currentNode = currentNode->next;
            preNode = tmpNode -> next;
        }
    }

    return head;
}

ListNode* Solution::reverseKGroup(ListNode* head, int k) {
    vector<ListNode *> listVector;
    size_t cnt = 0;
    ListNode * currentNode = head;
    ListNode * preNode = NULL;
    bool isFirstRound = true;
    while (currentNode != NULL) {
        cnt ++;

        if (cnt <= k) {
            listVector.push_back(currentNode);
            currentNode = currentNode -> next;
            if (cnt == k) {
                cnt = 0;
                listVector[0] -> next = currentNode;

                for (size_t index = k-1; index > 0; index --) {
                    listVector[index] -> next = listVector[index - 1];
                }

                if (isFirstRound) {
                    head = listVector[k - 1];
                    isFirstRound = false;
                } else {
                    preNode->next = listVector[k-1];
                }
                preNode = listVector[0];
                listVector.clear();
            }
        }

    }
    return head;
}

/**
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 * Your function should return length = 2, with the first two elements of nums being 2.
 */
int Solution::removeElement(vector<int> & nums, int val) {
    nums.erase(remove(nums.begin(),nums.end(),val),nums.end());
    return nums.size();
}

/**
 * Determine whether an integer is a palindrome. Do this without extra space.
 * @param x
 * @return
 */
bool Solution::isPalindrome(int x) {
    int originInt = x;
    int reversedInt = 0;
    if (x < 0) {
        return false;
    }
    while (x != 0) {
        reversedInt = reversedInt * 10 + x % 10;
        x /= 10;
    }

    if (reversedInt == originInt) {
        return true;
    } else {
        return false;
    }
}


int Solution::reverse(int x) {
    int reversedNum = 0;

    while (x != 0) {
        if (reversedNum * 10 / 10  != reversedNum) {
            return 0;
        }
        reversedNum = (x % 10) + reversedNum * 10;
        x = x / 10;
    }
    return reversedNum;
}

int Solution::myAtoi(string str) {
    int result = 0;
    int lengthOfStr = str.length();
    int index = 0;
    bool atBegin = true;
    bool pOrN = true;
    for (index = 0; index < lengthOfStr; index++){
        char c = str[index];
        if (atBegin && c == ' ') {
            // 去除空格
            continue;
        }
        if (atBegin) {
            atBegin = false;
            // 判断正负符号
            if (c == '+') {
                if (str[index + 1] < '0' || str[index + 1] > '9') {
                    // 避免正负号后面跟其他字符
                    break;
                }
                pOrN = true;
            }else if (c == '-') {
                if (str[index + 1] < '0' || str[index + 1] > '9') {
                    // 避免正负号后面跟其他字符
                    break;
                }
                pOrN = false;
            }else if (c <= '9' && c >= '0') {
                // 第一位为数字
                result = (c - '0');
                continue;
            }else {
                // 若第一位为其他符号，则结束循环（返回值为0）
                break;
            }
        } else {
            if (!(c >= '0' && c <= '9')) {
                //判断是否为数字,若不是数字则跳出循环
                break;
            }
            if (result * 10 / 10 != result || (result * 10 + (c - '0')) >> 31 != result >> 31 ) {
                // 溢出
                // 当输入 INT_MIN 时也会执行到这里
                if (pOrN) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            result = result * 10 + c - '0';
        }
    }
    if (!pOrN) { // 正负处理
        result = -result;
    }
    return result;
}

/**
 *
 */
size_t Solution::lengthOfLongestSubstring(string s) {
    size_t length = 0;
    size_t lengthOfOriginString = s.length();
    std::set<int> setCharSlidingWindow;
    for (size_t i = 0, j = 0;
         i < lengthOfOriginString && j < lengthOfOriginString;
            ) {
        if (setCharSlidingWindow.find(s[j]) != setCharSlidingWindow.end()) {
            setCharSlidingWindow.erase(setCharSlidingWindow.find(s[i]));
            i++;
            continue;
        } else {
            int c = s[j];
            setCharSlidingWindow.insert(c);
            j++;
            length = std::max(length, j - i);
        }
    }

    return length;
}

/**
 *
 * @param l1
 * @param l2
 * @return
 */
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    unsigned long firstNum = 0;
    unsigned long secondNum = 0;
    unsigned long sum = 0;
    size_t cnt = 0;
    ListNode * lSum = NULL;
    ListNode * endNode = NULL;
    ListNode * tmp1 = NULL;
    ListNode * tmp2 = NULL;
    char unit = 0;
    bool carry = false;
    for (tmp1 = l1,tmp2 = l2;
         tmp1 != NULL || tmp2 != NULL;
         tmp1 = tmp1 == NULL ? NULL : tmp1->next, tmp2 = tmp2 == NULL ? NULL : tmp2->next){
        unsigned int num1;
        unsigned int num2;
        if (tmp1 == NULL) {
            num1 = 0;
        } else {
            num1 = tmp1->val;
        }
        if (tmp2 == NULL) {
            num2 = 0;
        } else {
            num2 = tmp2->val;
        }
        unit = ( num1 + num2 + carry) % 10;
        ListNode * tmpNode = (ListNode *)malloc(sizeof(ListNode));
        tmpNode->val = unit;
        tmpNode->next = NULL;
        if (lSum == NULL) {
            lSum = endNode = tmpNode;
        }else {
            endNode->next = tmpNode;
            endNode = tmpNode;
        }
        carry = ( num1 + num2 + carry) / 10 == 1;

    }
    if (carry) {
        ListNode * lastNode = new ListNode(carry);
        endNode->next = lastNode;
    }

    return lSum;

}

int Solution::removeDuloicates(vector<int> & nums){
    // excellent resolution.
    int i = 0;
    for (int n : nums)
        if (!i || n > nums[i-1])
            nums[i++] = n;
    return i;
//    nums.erase(unique(nums.begin(), nums.end()), nums.end());
//    return nums.size();
}

int Solution::strStr(string haystack, string needle) {
    size_t haystackLength = haystack.length();
    size_t needleLength = needle.length();
    if (needleLength > haystackLength) {
        return -1;
    }
    for (int index = 0; index < haystackLength - needleLength + 1; index ++) {
        string tmpStr =  haystack.substr(index, needleLength);
        if (tmpStr.compare(needle) == 0) {
            return index;
        }
    }
    return -1;
}

bool Solution::isValidSudoku(vector<vector<char>> & board) {
    vector< unordered_map<char, bool>> sudoku(27);
    for (size_t wIndex = 0; wIndex < 9; wIndex ++) {
        for (size_t hIndex = 0; hIndex < 9; hIndex ++) {
            char currentChar = board[wIndex][hIndex];
            if (currentChar != '.') {
                if (sudoku[wIndex].find(currentChar) == sudoku[wIndex].end()
                        && sudoku[9 + hIndex].find(currentChar) == sudoku[8 + hIndex].end()
                        && sudoku[18 + wIndex/3 * 3 + hIndex / 3].find(currentChar) == sudoku[18 + wIndex/3 * 3 + hIndex / 3].end()) {
                    sudoku[wIndex][currentChar] = true;
                    sudoku[9 + hIndex][currentChar] = true;
                    sudoku[18 + wIndex/3 * 3 + hIndex / 3][currentChar] = true;
                }else {
                    return false;
                }
            }
        }
    }
    return true;
}

string Solution::countAndSay(int n) {
    size_t roundIndex = 1, charIndex = 0;
    size_t seqLength = 0;
    string seq = "1";
    string tmpSeq;
    char currentChar;
    size_t currentCharCnt = 0;
    while (roundIndex < n) {
        tmpSeq = "";
        seqLength = seq.length();
        charIndex = 0;
        while (charIndex < seqLength) {
            currentChar = seq.at(charIndex++);
            currentCharCnt = 1;
            while (charIndex < seqLength && seq.at(charIndex) == currentChar) {
                currentCharCnt ++;
                charIndex ++;
            }
            tmpSeq.push_back(currentCharCnt + '0');
            tmpSeq.push_back(currentChar);
        }
        seq = tmpSeq;
        roundIndex ++;
    }
    return seq;
}

void Solution::rotate(vector<vector<int>> &matrix) {
    int tmp;
    int n = matrix.size();
    for (size_t i = 0; i < n / 2; i++) {
        for (size_t j = i; j < n - i - 1; j ++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = tmp;
        }
    }
}

vector<string> Solution::generateParenthesis(int n) {
    set<string> result, tmpParenthesis;
    for (size_t i = 0; i < n; i++) {
        tmpParenthesis.clear();
        if (i == 0) {
            tmpParenthesis.insert("()");
        } else {
            for (string str : result) {
                for (size_t indexOfStr = 0; indexOfStr < str.length(); indexOfStr++) {
                    string tmpStr = str.substr(0, indexOfStr) + "()" + str.substr(indexOfStr, str.length()-indexOfStr);
                    if (tmpParenthesis.find(tmpStr) == tmpParenthesis.end()) {
                        tmpParenthesis.insert(tmpStr);
                    }
                }
            }
        }
        result = tmpParenthesis;
    }
    vector<string> resultVec(result.size());
    copy(result.begin(), result.end(), resultVec.begin());
    return resultVec;
}

vector<vector<int>> Solution::threeSum(vector<int> &nums) {
    vector<vector<int>> resultVec;
    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); i++) {
        int target = -nums[i];
        size_t front = i + 1;
        size_t back = nums.size() - 1;
        while (front < back) {
            if (nums[front] + nums[back] == target) {
                resultVec.push_back({nums[i], nums[front], nums[back]});
                front ++;
                back --;
                while (nums[front] == nums[front - 1] && front < back) {
                    front ++;
                }
                while (nums[back] == nums[back + 1] && front < back) {
                    back --;
                }
            } else if (nums[front] + nums[back] > target) {
                back --;
            } else if (nums[front] + nums[back] < target) {
                front ++;
            }
        }
        while (i + 1 != nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
    }

    return resultVec;
}

bool Solution::isMatch(string s, string p) {
    /*
     * 递归解法
    if (p.empty()) {
        return s.empty();
    }

    if ('*' == p[1]) {
        return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p) );
    } else {
        return (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)) );
    }
     */

    //  dp解法
    size_t m = s.length();
    size_t n = p.length();
    vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
    f[0][0] = true;
    for (size_t j = 1; j <= n; j++) {
        f[0][j] = j > 1 && '*' == p[j-1] && f[0][j-2];
    }
    for (size_t i = 1; i<= m; i++) {
        for (size_t j = 1; j <= n; j ++) {
            if (p[j - 1] == '*') {
                f[i][j] = f[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.') && f[i-1][j];
            } else {
                f[i][j] = f[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
            }
        }
    }
    return f[m][n];
}

int Solution::maxArea(vector<int> &height) {
    /* time limit exceeded.
    // 穷举法
    size_t i = 0, j = 0;
    int maxArea = 0;
    for (i = 0; i < height.size() - 1; i++) {
        for (j = i+1; j < height.size(); j++) {
            int h1 = height[i];
            int h2 = height[j];
            int area = 0;
            if (h1 < h2) {
               area = h1 * (j - i);
            }else {
                area = h2 * (j - i);
            }
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }
    return maxArea;
     */
    int front = 0, back = height.size() - 1;
    int maxArea = 0;
    while (front < back) {
        if (height[front] < height[back]){
            maxArea = std::max(maxArea,height[front] * (back - front));
            front ++;
        }else {
            maxArea = std::max(maxArea,height[back] * (back - front));
            back --;
        }
    }
    return maxArea;
}

string Solution::longestPalindrome(string s) {
    /* dp，TLE...
    size_t length = s.length();
    bool hasPalindrome = false;
    string longestPalindrome;
    vector<vector<bool>> p(length, vector<bool>(length, false));
    for (size_t index = 0; index < length - 1; index++) {
        p[index][index] = true;
        p[index][index+1] = s.at(index) == s.at(index+1);
        if (p[index][index+1]) {
            hasPalindrome = true;
            longestPalindrome = s.substr(index, 2);
        }
    }
    if (!hasPalindrome) {
        longestPalindrome = s.substr(0,1);
    }

    p[length-1][length-1] = true;
    for (size_t pCnt = 2; pCnt < length; pCnt++) {
        for (size_t index = 0; index < length - pCnt; index ++) {
            p[index][index + pCnt] = p[index + 1][index+pCnt -1] && s.at(index) == s.at(index + pCnt);
            if (p[index][index+pCnt]) {
                longestPalindrome = s.substr(index, pCnt+1);
            }
        }
    }
    return longestPalindrome;
     */
    int length = s.length();
    int longestLen = 0;
    int front = 0, back = 0;
    int longestFront, longestBack;
    for (int index = 0; index < length; index ++) {
        front = back = index;
        while (front >= 0 && back < length) {
            if (s.at(front) == s.at(back)) {
                front --;
                back ++;
            } else {
                break;
            }
        }
        if (longestLen < back - front - 1) {
            longestLen = back - front - 1;
            longestFront = front + 1;
            longestBack = back - 1;
        }
        front = index;
        back = index + 1;
        while (front >= 0 && back < length) {
            if (s.at(front) == s.at(back)) {
                front --;
                back ++;
            } else {
                break;
            }
        }
        if (longestLen < back - front - 1) {
            longestLen = back - front - 1;
            longestFront = front + 1;
            longestBack = back - 1;
        }
    }
    return s.substr(longestFront, longestBack - longestFront + 1);
}

int Solution::threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    size_t front = 0, middle = 1, back = nums.size() - 1;
    int sum = nums[front] + nums[middle] + nums[back];
    int closestSum = sum;
    int minDiff = abs(target - sum);
    while (front < back - 1) {
        middle = front + 1;
        while (middle < back) {
            sum = nums[front] + nums[middle] + nums[back];
            if (target - sum == 0) {
                return target;
            }
            if (minDiff > abs(target - sum)) {
                minDiff = abs(target - sum);
                closestSum = sum;
            }
            if (target - sum > 0) {
                middle ++;
            } else {
                back --;
            }
        }
        front ++;
        back = nums.size() - 1;
    }
    return closestSum;
}

int Solution::searchInsert(vector<int> &nums, int target) {
    int front = 0, back = nums.size() - 1;
    while (front <= back) {
        int mid = front + (back - front) / 2;
        if (nums[mid] < target) {
            front = mid + 1;
        } else if (nums[mid] > target){
            back = mid - 1;
        } else {
            return mid;
        }
    }
    return front + (back - front) / 2;
}

int Solution::binarySearch(vector<int> &nums, int target) {
    int front = 0, back = nums.size() - 1;
    while (front <= back) {
        int mid = front + (back - front) / 2;
        if (nums[mid] < target) {
            front = mid + 1;
        } else if (nums[mid] > target){
            back = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

vector<int> Solution::searchRange(vector<int> &nums, int target) {
    int front = 0, back = nums.size() - 1;
    int start = 0, end = 0;
    vector<int> result{-1, -1};
    while (front <= back) {
        int mid = front + (back - front) / 2;
        if (nums[mid] > target) {
            back = mid - 1;
        } else if (nums[mid] < target) {
            front = mid + 1;
        } else {
            start = end = mid;
            while (start - 1 >= 0 && nums[start - 1] == nums[mid]) {
                start --;
            }
            while (end + 1 < nums.size() && nums[end + 1] == nums[mid]) {
                end ++;
            }
            result.clear();
            result.push_back(start);
            result.push_back(end);
            break;
        }
    }
    return result;
}

double Solution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    size_t m = nums1.size(), n = nums2.size();
    if (m < n) {
        swap(nums1, nums2);
        swap(m, n);
    }
    int front = 0, back = n * 2;
    while (front <= back)  {
        int mid2 = (front + back) / 2;
        int mid1 = m + n - mid2;

        double l1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
        double l2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
        double r1 = mid1 == 2 * m ? INT_MAX : nums1[mid1 / 2];
        double r2 = mid2 == 2 * n ? INT_MAX : nums2[mid2 / 2];

        if (l1 > r2) {
            front = mid2 + 1;
        } else if (l2 > r1) {
            back = mid2 - 1;
        } else {
            return ( (max(l1, l2) + min(r1, r2)) / 2);
        }
    }
    return -1;
}

vector<vector<int>> Solution::permute(vector<int> &nums) {
    if (nums.size() == 1) {
        return vector<vector<int>>{{nums[0]}};
    }
    vector<vector<int>> result;
    for (int n: nums) {
        vector<int> tmpNums(nums);
        tmpNums.erase(remove(tmpNums.begin(), tmpNums.end(), n), tmpNums.end());
        for (vector<int> row : permute(tmpNums)) {
            row.insert(row.begin(), n);
            result.push_back(row);
        }
    }

    return result;
}

vector<vector<int>> Solution::combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination;
    result = combinationSum(candidates, target, combination, 0);
    return result;
}

vector<vector<int>> Solution::combinationSum(vector<int> &candidates, int target, vector<int> & combiantion, int begin ) {
    vector<vector<int>> result;
    if (target == 0) {
        return vector<vector<int>>{combiantion};
    }
    for (size_t index = begin; index < candidates.size(); index ++) {
        combiantion.push_back(candidates[index]);
        if (target >= candidates[index]) {
            for (vector<int> row : combinationSum(candidates, target - candidates[index], combiantion, index)) {
                result.push_back(row);
            }
        }
        combiantion.pop_back();
    }
    return result;
}

vector<vector<int>> Solution::combinationSum2(vector<int> &candidates, int target) {

    vector<int> combination;
    sort(candidates.begin(), candidates.end());
    return combinationSum2(candidates, target, combination, 0);
}

vector<vector<int>> Solution::combinationSum2(vector<int> &candidates, int target, vector<int> &combination,
                                              int begin) {
    vector<vector<int>> result;
    if (target == 0) {
        result.push_back(combination);
        return result;
    }
    for (int index = begin; index < candidates.size(); index ++) {
        if (index != 0 && index != begin && candidates[index] == candidates[index - 1]) { // 去除重复
            continue;
        }
        if (candidates[index] <= target) {
            combination.push_back(candidates[index]);
            for (vector<int> row : combinationSum2(candidates, target - candidates[index], combination, index + 1)) {
                result.push_back(row);
            }
            combination.pop_back();
        }
    }
    return result;
}

int Solution::trap(vector<int> &height) {

    /** 这种方法太暴力
    int cap = 0;
    vector<int> stack;
    bool isAllZero = true;
    for (int index = 0; index < height.size(); index++) {

            if (height[index] > 0) {
                if (stack.size() != 0) {
                    cap += (index - stack.back() - 1);
                    stack.pop_back();
                }
                stack.push_back(index);
                height[index] -- ;
                isAllZero = false;
            }
    }
    if (isAllZero) {
        return 0;
    }
    return cap + trap(height);
     */
    int left = 0, right = height.size() - 1;
    int cap = 0;
    int maxLeft = 0, maxRight = 0;
    while (left <= right) {
        if (height[left] <= height[right]) {
            if (maxLeft <= height[left]) {
                maxLeft = height[left];
            } else {
                cap += maxLeft - height[left];
            }
            left ++;
        } else {
            if (maxRight <= height[right]) {
                maxRight = height[right];
            } else {
                cap += maxRight - height[right];
            }
            right -- ;
        }
    }
    return cap;
}

void Solution::solveSudoku(vector<vector<char>> &board) {
    solveSudoku(board, 0,0);
}

bool Solution::solveSudoku(vector<vector<char>> &board, int i, int j) {
    if (i == 9) return true;
    if (j == 9) return solveSudoku(board, i + 1, 0);
    if (board[i][j] != '.') return solveSudoku(board, i, j+1);
    for (char c = '1'; c <= '9'; c++) {
        if (isValidSudoku(board, i, j, c)) {
            board[i][j] = c;
            if (solveSudoku(board, i, j+1)) return true;
            board[i][j] = '.';
        }
    }
    return false;
}

bool Solution::isValidSudoku(vector<vector<char>> &board, int i, int j, char c) {
    for (int x = 0; x < 9; x++) {
        if (board[i][x] == c || board[x][j] == c) {
            return false;
        }
    }
    for (int x = i / 3 * 3; x < i/3*3 + 3; x++) {
        for (int y = j/3*3; y < j/3*3 + 3; y ++) {
            if (board[x][y] == c) {
                return false;
            }
        }
    }
    return true;
}

vector<int> Solution::plusOne(vector<int> &digits) {
    for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); it++) {
        if (*it == 9) {
            *it = 0;
        } else {
            *it += 1;
            return digits;
        }
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

vector<vector<string>> Solution::groupAnagrams(vector<string> & strs){
    unordered_map<string, vector<string>> mapAnagrams;
    for (string str : strs) {
        string strSorted = str;
        sort(strSorted.begin(), strSorted.end());
        mapAnagrams[strSorted].push_back(str);
    }
    vector<vector<string>> group;
    for (unordered_map<string, vector<string>>::iterator it = mapAnagrams.begin(); it != mapAnagrams.end(); it++) {
        group.push_back(it->second);
    }
    return group;
}

vector<string> Solution::letterCombinations(string digits) {
    unordered_map<char, string> digitsMap {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
    vector<string> result;
    if (digits.size() == 0) {
        return result;
    }
    if (digits.size() == 1) {
        for (auto c : digitsMap[digits[0]]) {
            string str;
            str.push_back(c);
            result.push_back(str);
        }
        return result;
    }
    string tmpStr = digits;
    tmpStr.erase(tmpStr.begin());

    for (string str : letterCombinations(tmpStr)) {
        for (int i = 0; i < digitsMap[digits[0]].length(); i++) {
            string s = str;
            s.insert(s.begin(),digitsMap[digits[0]][i]);
            result.push_back(s);
        }
    }
    return result;
}

int Solution::search(vector<int> & nums, int target){
    int front = 0, back = nums.size() - 1;
    int middle;
    int minIndex = 0;

    while (front <= back) {
        middle = front + (back - front) / 2;
        if (middle != 0) {
            if (nums[middle] < nums[middle - 1]){
                minIndex = middle;
                break;
            }
        }
        if (nums[middle] >= nums[back]) {
            front = middle + 1 ;
        } else {
            back = middle - 1;
        }

    }
    front = 0;
    back = nums.size() - 1;
    while (front <= back ) {
        int mid = (back + front) / 2;
        middle = (mid + minIndex) % nums.size();
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] > target) {
            back = mid - 1;
        } else {
            front = mid + 1;
        }
    }
    return -1;
}

vector<vector<int>> Solution::permuteUnique(vector<int> &nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());  // 为什么要排序？？
    result =  permuteUnique(nums, 0);
    return result;
}
vector<vector<int>> Solution::permuteUnique(vector<int> nums, int begin) {
    vector<vector<int>> result;
    if (begin == nums.size() - 1) {
        result.push_back(vector<int>{nums[begin]});
        return result;
    }

    for (int i = begin; i < nums.size(); i ++) {
        if (i != begin && nums[i] == nums[begin]) continue;
        swap(nums[begin], nums[i]);
        for (vector<int> row: permuteUnique(nums, begin + 1)) {
            row.insert(row.begin(), nums[begin]);
            result.push_back(row);
        }
//        swap(nums[begin], nums[i]);  // 为什么这里不能恢复？？？
    }
    return result;
}

void Solution::nextPermutation(vector<int> &nums) {
    int i = 0, k = 0;
    bool isMax = true;
    for (int index = 0; index < nums.size() - 1; index++) {
         if (nums[index] < nums[index + 1]) {
             if (index > i)
             i = index;
             isMax = false;
         }
        if (nums[index + 1] > nums[i]) {
            k = index + 1;
        }
    }
    if (isMax) {
        std::reverse(nums.begin(), nums.end());
        return;
    }
    swap(nums[i], nums[k]);
    vector<int>::iterator it = nums.begin() + i + 1;
    std::reverse(it, nums.end());
    return;
}

ListNode * Solution::mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) return NULL;
    while (lists.size() > 1 ) {
        lists[1] = mergeTwoLists(lists[0], lists[1]);
        lists.erase(lists.begin());
    }
    return lists[0];
}

double Solution::myPow(double x, int n) {
    if (n == 0) return 1;
    if (n > 0) {
        if (n % 2) {  // is odd
            return (x * myPow(x*x, n/2));
        } else {
            return myPow(x*x , n/2);
        }
    } else {
        if (n == INT_MIN) return (1/x * myPow(x, n+1));
        else return myPow(1/x, -n);
    }
}

int Solution::lengthOfLastWord(string s) {
    int length = 0;
    int back = s.size() - 1;
    while (back >= 0 && s[back] == ' ' ) {
        back --;
    }
    if (back < 0) return 0;
    while (back >= 0 && s[back] != ' ') {
        length ++;
        back --;
    }
    return length;
}

string Solution::addBinary(string a, string b) {
    string result;
    int carry = 0;
    int currentBit;
    int aLength = a.size();
    int bLength = b.size();
    if (aLength > bLength) { // 使a变为短的一方
        swap(a, b);
        swap(aLength, bLength);
    }
    for (int i = 1; i <= aLength; i++) {
        int intA = a[aLength - i] - '0';
        int intB = b[bLength - i] - '0';
        currentBit = (intA + intB + carry) % 2;
        carry = (intA && intB || intA && carry || intB && carry);
        result.insert(result.begin(), currentBit + '0');
    }
    for (int i = bLength - aLength - 1; i >= 0; i--) {
        currentBit = (b[i] - '0' + carry) % 2;
        carry = (b[i] - '0') * carry;
        result.insert(result.begin(), currentBit + '0');
    }
    if (carry) {
        result.insert(result.begin(), carry + '0');
    }
    return result;
}

int Solution::climbStairs(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    vector<int> stairs(n + 1, 0);
    stairs[0] = 1;
    stairs[1] = 1;
    for (int i = 2; i <= n; i++) {
        stairs[i] = stairs[i - 1] + stairs[i - 2];
    }
    return stairs[n];
}

bool Solution::isValidQueens(vector<string> queens, int i, int j) {
    int row = i, col = j;
    int n = queens.size();
    for (int index = 0; index < n; index ++ ) {
        if (index != col && queens[row].at(index) == 'Q' || index != row && queens[index].at(col) == 'Q'){
            return false;
        }
        if (index != 0) {
            if (i - index >= 0 && j - index >= 0 && queens[i - index][j - index] == 'Q'
                || i + index < n && j + index < n && queens[i + index][j + index] == 'Q'
                || i + index < n && j - index >= 0 && queens[i + index][j - index] == 'Q'
                || i - index >= 0 && j + index < n && queens[i - index][j + index] == 'Q'
                    ) {
                return false;
            }
        }
    }
    return true;
}

vector<vector<string>> Solution::solveNQueens(int n) {
    vector<string> initQueens(n, string(n,'.'));
    vector<vector<string>> result =  solveNQueens(initQueens,n, 0);
    return result;
}
vector<vector<string>> Solution::solveNQueens(vector<string> _queens, int n, int row) {
    vector<vector<string> > result;
    if (row == n){
        result.push_back(_queens);
        return result;
    }
    for (int i = 0; i < n; i++) {
        _queens[row][i] = 'Q';
        if (isValidQueens(_queens, row, i)) {
            for (vector<string> queens : solveNQueens(_queens, n, row + 1)) {
                result.push_back(queens);
            }
        }
        _queens[row][i] = '.';
    }
    return result;
}

int Solution::totalNQueens(int n) {
    vector<bool> flag(5*n - 2, true);
    int num = 0;
    totalNQueens(flag, n, 0, num);
    return num;
}

void Solution::totalNQueens(vector<bool> &flag, int n, int row, int &num) {
    if (row == n) {
        num ++;
        return;
    }
    for (int col = 0; col < n; col ++) {
        if (flag[col] && flag[n + row + col] && flag[3*n -1 + row - col + n]) {
            flag[col] = flag[n + row + col] = flag[ 4 * n + row - col - 1] = false;
            totalNQueens(flag, n, row + 1, num);
            flag[col] = flag[n + row + col] = flag[ 4 * n + row - col - 1] = true;
        }
    }
}

int Solution::maxSubArray(vector<int> &nums) {
    int length = nums.size();
    if (length == 0) return 0;
    int ans = nums[0], sum = 0;

    for (int i = 0; i < length; i++) {
        sum += nums[i];
        ans = max(ans, sum);
        sum = max(sum, 0);
    }
    return ans;
}


vector<vector<int>> Solution::generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    int step, num = 0;
    int i = 0, j = 0;
    for (int loop = 0; loop < (n + 1)/ 2; loop ++) {    // totally (n + 1) / 2 loops.
        step = n - 2 * loop - 1;
        if (step == 0) {
            result[i][j] = ++num;
            break;
        }
        i = j = loop;
        while (step > 0) {            // 1. left to right
            result[i][j++] = ++num;
            step -- ;
        }
        step = n - 2 * loop - 1;
        while (step > 0) {            // 2. top to bottom
            result[i++][j] = ++num;
            step --;
        }
        step = n - 2 * loop - 1;
        while (step > 0) {            // 3. right to left
            result[i][j--] = ++num;
            step --;
        }
        step = n - 2 * loop - 1;
        while (step > 0) {            // 4. bottom to top
            result[i--][j] = ++num;
            step --;
        }
        i ++;
        j ++;
    }
    return result;
}

int Solution::uniquePaths(int m, int n) {
    vector<vector<int>> paths(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        paths[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        paths[0][j] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            paths[i][j] = paths[i - 1][j] + paths[i][j-1];
        }
    }
    return paths[m-1][n-1];
}

int Solution::uniquePathsWithObstacles(vector<vector<int>> obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> paths(m, vector<int> (n)) ;
    paths[0][0] = obstacleGrid[0][0] ? 0 : 1;
    for (int i = 1; i < m; i++) {
        if (obstacleGrid[i][0] == 0) {
            paths[i][0] = paths[i - 1][0];
        }
    }
    for (int j = 1; j < n; j++) {
        if (obstacleGrid[0][j] == 0) {
            paths[0][j] = paths[0][j - 1];
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 0) {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            } else {
                paths[i][j] = 0;
            }
        }
    }
    return paths[m - 1][n - 1];
}

int Solution::minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
//    vector<vector<int>> sum(m, vector<int>(n, 0));
//    sum[0][0] = grid[0][0];
//    for (int i = 1; i < m; i++) {
//        sum[i][0] = sum[i - 1][0] + grid[i][0];
//    }
//    for (int j = 1; j < n; j++) {
//        sum[0][j] = sum[0][j - 1] + grid[0][j];
//    }
//    for (int i = 1; i < m; i++) {
//        for (int j = 1; j < n; j++) {
//            sum[i][j] = grid[i][j] + min(sum[i - 1][j], sum[i][j - 1]);
//        }
//    }
//    return sum[m - 1][n - 1];
    vector<int> cur(m);
    cur[0] = grid[0][0];
    for (int i = 1; i < m; i++) {
        cur[i] = cur[i - 1] + grid[i][0];
    }
    for (int j = 1; j < n; j++) {
        cur[0] += grid[0][j];
        for (int i = 1; i < m; i++) {
            cur[i] = min(cur[i], cur[i - 1]) + grid[i][j];
        }
    }
    return cur[m - 1];
}

void Solution::setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<bool> record(m + n, false);
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                record[i] = true;
                record[j + m] = true;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (record[i]) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int j = 0; j < n; j++) {
        if (record[j + m]) {
            for (int i = 0; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}

bool Solution::searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    int front = 0, back = m * n - 1;
    while (front <= back) {
        int mid = front + (back - front) / 2;
        int row = mid / n;
        int col = mid % n;
        if (matrix[row][col] == target) {
            return true;
        }
        if (matrix[row][col] > target) {
            back = mid - 1;
        } else {
            front = mid + 1;
        }
    }
    return false;
}

int Solution::sqrt(int x) {
    if (x == 0) return 0;
    int front = 1, back = x;
    while (front <= back) {
        int mid = front + (back - front) / 2;
        if (mid == x / mid){
            return mid;
        }
        if (mid < x / mid) {
            if (mid + 1 > x / (mid + 1))
                return mid;
            front = mid + 1;
        } else {
            back = mid - 1;
        }
    }
    return -1;
}

vector<int> Solution::spiralOrder(vector<vector<int>> & matrix) {
    int rows = matrix.size();
    if (rows == 0) return {};
    int cols = matrix[0].size();
    vector<int> result(rows * cols);
    int u = 0, b = rows - 1, l = 0, r = cols - 1;
    int index = 0;
    while (true)  {
        for (int col = l; col <= r; col ++) {
            result[index++] = matrix[u][col];
        }
        if (++u > b) break;
        for (int row = u; row <= b; row ++) {
            result[index++] = matrix[row][r];
        }
        if (--r < l) break;
        for (int col = r; col >= l; col --) {
            result[index++] = matrix[b][col];
        }
        if (--b < u) break;
        for (int row = b; row >= u; row --) {
            result[index++] = matrix[row][l];
        }
        if (++l > r) break;
    }
    return result;
}

void Solution::sortColors(vector<int> &nums) {
    int length = nums.size();
    if (length == 1) return;
    int flag0 = 0, flag2 = length - 1;
    int index = 1;
    while (index <= flag2) {
        if (nums[index] == 0) {
            swap(nums[flag0], nums[index]);
            flag0 ++;
            index ++;
        } else if (nums[index] == 2) {
            swap(nums[flag2], nums[index]);
            flag2 --;
        } else {
            index ++;
        }
    }
}

bool Solution::canJump(vector<int> &nums) {
    if (nums.size() == 1) return true;
    for (int index = 0; index < nums.size() - 1; index ++) {
        if (nums[index] == 0) {
            bool canReach = false;
            for (int tmpIndex = 0; tmpIndex < index; tmpIndex++) {
                if (nums[tmpIndex] - (index - tmpIndex) > 0) {
                    canReach = true;
                    break;
                }
            }
            if (! canReach) return false;
        }
    }
    return true;
}

bool sortIntervalFunction(Interval i1, Interval i2) {
    return i1.start < i2.start;
}
vector<Interval> Solution::merge(vector<Interval> &intervals) {
    if (intervals.size() == 0) return {};
    std::sort(intervals.begin(), intervals.end(), sortIntervalFunction);
    vector<Interval> result;
    result.push_back(intervals[0]);
    for (int i = 1, rIndex = 0; i < intervals.size(); i++) {
        if (result.back().end < intervals[i].start) {
            result.push_back(intervals[i]);
        }else {
            result.back().end = max(result.back().end, intervals[i].end);
        }
    }
    return result;
}

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int length = intervals.size();
    vector<Interval> result;
    if (length == 0) return {newInterval};
    sort(intervals.begin(), intervals.end(), sortIntervalFunction);
    vector<Interval>::iterator it = intervals.begin();
    while (it != intervals.end()) {
        if (it->start > newInterval.end) {
            break;
        }
        if (newInterval.start > it->end) {
            result.push_back(*it);
        }else {
            newInterval = {min(newInterval.start, it->start), max(newInterval.end, it->end)};
        }
        it ++;
    }
    result.push_back(newInterval);
    while (it != intervals.end()) {
        result.push_back(*it);
        it++;
    }
    return result;
}

string Solution::getPermutation(int n, int k) {
    if (n == 0 || k == 0) return "";
    string result("");
    vector<int> factorial(n, 0);
    string numSet("123456789");
    factorial[0] = 1;
    vector<int> X(n, 0);
    for (int i = 1; i < n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
    for (int i = n; i > 0; i --) {
        for (int x = i - 1 ; x >= 0; x--) {
            if (x * factorial[i - 1] <= k - 1) {
                result.push_back(numSet[x]);
                numSet.erase(numSet.begin()+x);
                k -= x * factorial[i - 1];
                break;
            }
        }
    }
    return result;
}

ListNode * Solution::rotateList(ListNode *head, int k) {
    if (head == NULL) return NULL;
    vector<ListNode *> list;
    ListNode * node(head);
    while (node != NULL) {
        list.push_back(node);
        node = node->next;
    }
    k = k % list.size();
    if (k == 0) return head;
    vector<ListNode *>::iterator it = list.end() - k;
    (*(it-1))->next = NULL;
    list.back()->next = list[0];
    return *it;
}

int Solution::minDistance(string word1, string word2) {
    int length1 = word1.length();
    int length2 = word2.length();
    if ( !(length1 && length2)) {
        // lenght1 == 0 || length2 == 0
        return length1 + length2;
    }
    vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
    for (int i = 1; i <= length1; i++) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= length2; i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= length1; i++) {
        for (int j = 1; j <= length2; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int minDp = std::min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1);
                dp[i][j] = std::min(minDp, dp[i][j - 1] + 1);
            }
        }
    }
    return dp[length1][length2];

}

string Solution::convert(string s, int numRows) {
    if (numRows == 1) return s;
    int length = s.length();
    string result;
    for (int row = 1; row <= numRows; row++) {
        if (row - 1 < length) {
            result.push_back(s[row - 1]);
        } else {
            break;
        }
        int cur = row - 1;
        while (true) {
            cur += (2 * numRows - 2 * row);
            if (cur < length) {
                if (row != numRows) {
                    result.push_back(s[cur]);
                }
            } else {
                break;
            }
            cur += (2 * (row - 1));
            if (cur < length) {
                if (row - 1 != 0) {
                    result.push_back(s[cur]);
                }
            }else {
                break;
            }
        }
    }
    return result;
}

int Solution::jump(vector<int> & nums) {
    int step = 0, start = 0, end = 0, maxEnd = 0;
    int length = nums.size();
    while (maxEnd < length - 1) {
        step ++;
        for (int index = start; index <= end; index++) {
            if (index + nums[index] >= length - 1) {
                return step;
            }
            maxEnd = max(maxEnd, index + nums[index]);
        }
        start = end + 1;
        end = maxEnd;
    }
    return step;
}

vector<vector<int>> Solution::fourSum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    int length = nums.size();
    if (length < 4) return result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < length - 3; i++) {
        for (int j = i + 1; j < length - 2; j++) {
            int front = j + 1;
            int back = length - 1;
            int tmpTarget = target - nums[i] - nums[j];
            while (front < back) {
                int sum = nums[front] + nums[back];
                if (sum < tmpTarget) {
                    front ++;
                } else if (sum > tmpTarget){
                    back --;
                } else {
                    int numFront = nums[front];
                    int numBack = nums[back];
                    result.push_back({nums[i], nums[j], numFront, numBack});
                    while (front + 1 < back && nums[front] == nums[front + 1]) front++;
                    front ++;
                    while (back - 1 > front && nums[back] == nums[back - 1]) back --;
                    back --;
                }
            }
            while (j + 1 < length - 2 && nums[j] == nums[j + 1]) j++;
        }
        while (i + 1 < length - 3 && nums[i] == nums[i + 1]) i++;
    }
    return result;
}

string Solution::multiply(string num1, string num2) {
    int length1 = num1.length();
    int length2 = num2.length();
    string result(length1 + length2 , '0');
    int carry = 0;

    for (int i = length1; i > 0; i-- ) {
        carry = 0;
        for (int j = length2; j > 0; j--) {
            int num = (result[i + j - 1] - '0' + (num1[i - 1] - '0') * (num2[j - 1] - '0')) + carry;
            carry = num / 10;
            result[i + j - 1] = num % 10 + '0';
        }
        int cnt = i - 1;
        while (carry != 0 && cnt >= 0) {
            int num = carry + result[cnt] - '0';
            carry = num / 10;
            result[cnt] = num % 10 + '0';
        }
    }
    while (result[0] == '0' && result.length() > 1) {
        result.erase(result.begin());
    }
    return result;
}

int Solution::longestValidParentheses(string s) {
    int length = s.length();
    if (length <= 1) return 0;
    vector<int> longest(length, 0);
    if (s[0] == '(' && s[1] == ')') longest[1] = 2;
    int maxLongest = longest[1];
    for (int index = 2; index < length; index++) {
        if (s[index] == '(') {
            longest[index] = 0;
        } else {
            if (s[index - 1] == '(') {
                longest[index] = longest[index - 2] + 2;
            } else {
                if (index - longest[index - 1] - 1 >= 0 && s[index - longest[index - 1] - 1] == '(') {
                    longest[index] = longest[index - 1] + 2 + (index - longest[index - 1] - 2 >= 0 ? longest[index - longest[index - 1] - 2] : 0);
                }
            }
        }
        maxLongest = max(maxLongest, longest[index]);
    }
    return maxLongest;
}

int Solution::longestValidParenthesesStack(string s) {
    if (s.size() == 0) return 0;
    vector<char> stack;
    vector<int> cnt(s.size(), 0);
    int index = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stack.push_back(s[i]);
            index ++;
        } else {
            if (stack.size() > 0 && stack.back() == '(') {
                stack.pop_back();
                index --;
                cnt[index] += cnt[index + 1] + 2;
                cnt[index + 1] = 0;
            } else {
                stack.push_back(s[i]);
                index ++;
            }
        }
    }
    return *max_element(cnt.begin(), cnt.end());
}

string Solution::simplifyPath(string path) {

    vector<string> stackPath;
    string s;
    for (int i = 0; i < path.length(); i++) {
        while (path[i] == '/' && i < path.length()) {
            i++;
        }
        while (path[i] != '/' && i < path.length()) {
            s += path[i];
            i++;
        }
        if (s == "..") {
            if (stackPath.size() > 0) {
                stackPath.pop_back();
            }
        }else if ( s != "." && s.size() > 0) {
            stackPath.push_back(s);
        }
        s.clear();
    }
    if (stackPath.size() == 0) {
        return "/";
    }
    string result;
    while (stackPath.size() != 0) {
        result += "/";
        result += stackPath.front();
        stackPath.erase(stackPath.begin());
    }
    return result;
}

vector<vector<int>> Solution::combine(int n, int k) {
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
    }
    return combine(nums,0, k);
}
vector<vector<int>> Solution::combine( vector<int> nums, int index, int k) {
    vector<vector<int>> result;
    vector<int> com;
    if (k == 1) {
        for (int i = index; i < nums.size(); i++) {
            com.push_back(nums[i]);
            result.push_back(com);
            com.clear();
        }
        return result;
    }
    int cur = nums.back();
    for (int i = index; i < nums.size() - k + 1; i++ ) {
        for (auto com : combine(nums, i + 1, k - 1)) {
            com.push_back(nums[i]);
            result.push_back(com);
        }
    }
    return result;
}

vector<vector<int>> Solution::subsets(vector<int> &nums) {
    if (nums.size() == 0) return {{}};
        int curNum = nums.front();
        vector<int> tmpNums(nums.begin() + 1, nums.end());
        vector<vector<int>> preResult = subsets(tmpNums);
        vector<vector<int>> result(preResult);
        for (auto line : preResult) {
            line.push_back(curNum);
            result.push_back(line);
        }
        return result;
}

int Solution::removeDuplicatesII(vector<int> &nums) {
    if (nums.empty()) return 0;
    int cnt = 0, n = nums.size();
    for (int i = 2; i < n; i++) {
        if (nums[i] == nums[i - 2 - cnt]) cnt ++;
        else nums[i - cnt] = nums[i];
    }
    return n - cnt;
}

bool Solution::isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false; // either p or q but not both is NULL.
    if (p->val != q->val) return false;
    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

ListNode * Solution::deleteDuplicates(ListNode *head) {
    ListNode * curNode = head;
    while (curNode != NULL) {
        while (curNode->next != NULL && curNode->val == curNode->next->val) {
            curNode->next = curNode->next->next;
        }
        curNode = curNode->next;
    }
    return head;
}

ListNode * Solution::deleteDuplicatesII(ListNode *head) {
    ListNode * curNode = head;
    ListNode * preNode = NULL;
    ListNode * newHead = NULL;
    while (curNode != NULL) {
        bool isDuplicate = false;
        while (curNode -> next != NULL && curNode->val == curNode->next->val) {
            isDuplicate = true;
            curNode = curNode->next;
        }
        if (isDuplicate){
            curNode = curNode->next;
            continue;
        } else {
            if (newHead == NULL) {
                newHead = curNode;
                preNode = newHead;
            } else {
                preNode->next = curNode;
                preNode = curNode;
            }
            curNode = curNode->next;
        }
    }
    if (preNode != NULL) {
        preNode->next = curNode;
    }
    return newHead;
}

vector<int> Solution::inorderTraversal(TreeNode *root) {
    vector<int> inorderTraversal;
    if (!root) return inorderTraversal;
    stack<TreeNode *> stackNode;
    unordered_map<TreeNode *, bool> mapNode;
    stackNode.push(root);
    while (!stackNode.empty()) {
        TreeNode * curNode = stackNode.top();
        if (curNode->left && !mapNode[curNode]) {
            stackNode.push(curNode->left);
            mapNode[curNode] = true;
        } else {
            inorderTraversal.push_back(curNode->val);
            stackNode.pop();
            if (curNode->right) {
                stackNode.push(curNode->right);
            }
        }
    }
    return inorderTraversal;
}

void Solution::merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int p1 = m, p2 = n;
    while (p1 != 0 && p2 != 0) {
        if (nums1[p1 - 1] > nums2[p2 - 1]) {
            nums1[p1 + p2 - 1] = nums1[p1 - 1];
            p1 --;
        } else {
            nums1[p1 + p2 - 1] = nums2[p2 - 1];
            p2 --;
        }
    }
    if (p1 == 0) {
        for (int i = 0; i < p2; i++) {
            nums1[i] = nums2[i];
        }
    }
}

vector<int> Solution::grayCode(int n) {
    int cnt = 1 << n;
    vector<int> gray;
    for (int i = 0; i < cnt; i++) {
        gray.push_back((i / 2) ^ i);
    }
    return gray;
}

bool Solution::exist(vector<vector<char>> &board, string word) {
    if (word.size() == 0) return false;
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<bool>> visitBoard(rows, vector<bool>(cols, false));

    for (int row = 0; row < rows; row ++) {
        for (int col = 0; col < cols; col++) {
            if (exist(board, row, col, word, 0, visitBoard)) {
                return true;
            }
        }
    }
    return false;
}
bool Solution::exist(vector<vector<char>> &board, int row, int col, string word, int index, vector<vector<bool>> &visitBoard) {
        if (board[row][col] != word[index]) return false;
    if (index == word.size() - 1) return true;
    int rows = board.size();
    int cols = board[0].size();
    visitBoard[row][col] = true;
    if (row + 1 < rows && !visitBoard[row + 1][col] && exist(board, row+1, col, word, index + 1, visitBoard))
        return true;
    if (row - 1 >=0 && !visitBoard[row - 1][col] && exist(board, row-1, col, word, index + 1, visitBoard))
        return true;
    if (col + 1 < cols && !visitBoard[row][col + 1] && exist(board, row, col + 1, word, index + 1, visitBoard))
        return true;
    if (col - 1 >= 0 && !visitBoard[row][col - 1] && exist(board, row, col - 1, word, index + 1, visitBoard))
        return true;
    visitBoard[row][col] = false;
    return false;
}

int Solution::numTrees(int n) {
    vector<int> g(n+1, 0);
    g[0] = g[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            g[i] += g[j - 1] * g[i - j];
        }
    }
    return g[n];
}

vector<TreeNode *> genTrees(int start, int end) {
    vector<TreeNode *> result;
    if (start == end) {
        result.push_back(new TreeNode(start));
        return result;
    }
    if (start > end) {          // 边界情况：当下述循环的index为start或end时，其lnode/rnode即为NULL
        result.push_back(NULL);
        return result;
    }
    for (int index = start; index <= end; index++) {
        for (auto lTree : genTrees(start, index - 1)) {
            for (auto rTree : genTrees(index + 1, end)) {
                TreeNode * root = new TreeNode(index);
                root->left = lTree;
                root->right = rTree;
                result.push_back(root);
            }
        }
    }
    return result;
}

vector<TreeNode *> Solution::generateTreesRecursive(int n) {
    if (n == 0) return vector<TreeNode *>();
    return genTrees(1,n);
}

vector<TreeNode * > Solution::generateTrees(int n) {

}

vector<vector<int>> Solution::subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> result = {{}};
    if (nums.empty()) return result;
    int numLength = nums.size();
    std::sort(nums.begin(), nums.end());
    for (int index = 0; index < numLength; index ++) {
        int cnt = 1;
        while (index + 1 < numLength && nums[index] == nums[index + 1]) {
            index ++;
            cnt++;
        }
        vector<vector<int>> resultCopy(result);
        for (auto line : resultCopy) {
            for (int tmpCnt = 0; tmpCnt < cnt; tmpCnt++) {
                line.push_back(nums[index]);
                result.push_back(line);
            }
        }
    }
    return result;
}

ListNode * Solution::partition(ListNode *head, int x) {
    if (head == NULL) return head;
    ListNode * pre = NULL;
    ListNode * cur = head;
    if (head->val < x) {
        pre = head;
    }
    while (cur->next != NULL) {
        if (cur->next->val < x ) {
            if (cur != pre) {
                if (pre == NULL) {
                    pre = cur->next;
                    cur->next = cur->next->next;
                    pre->next = head;
                    head = pre;
//                    pre = pre->next;
                } else {
                    ListNode *tmpNode = cur->next;
                    cur->next = cur->next->next;
                    tmpNode->next = pre->next;
                    pre->next = tmpNode;
                    pre = pre->next;
                }
            } else {
                cur = cur->next;
                pre = pre->next;
            }
        }else {
            cur = cur->next;
        }
    }
    return head;
}

ListNode * Solution::reverseBetween(ListNode *head, int m, int n) {
    if (m == n) return head;
    vector<ListNode *> nodeVector;
    nodeVector.push_back(NULL);
    ListNode * curNode = head;
    while (curNode != NULL) {
        nodeVector.push_back(curNode);
        curNode = curNode->next;
    }
    nodeVector.push_back(NULL);
    if (m == 1) {
        head = nodeVector[n];
    } else {
        nodeVector[m - 1] -> next = nodeVector[n];
    }
    nodeVector[m] -> next = nodeVector[n + 1];
    for (int index = m + 1 ; index <= n; index ++) {
       nodeVector[index] -> next = nodeVector[index - 1];
    }
    return head;
}

bool Solution::isScramble(string s1, string s2) {
    if (s1.compare(s2) == 0) return true;
    unordered_map<char, int> cmap;
    for (auto c : s1) {
        cmap[c] += 1;
    }
    for (auto c : s2) {
        cmap[c] -= 1;
    }
    for (auto ele : cmap) {
        if (ele.second != 0) return false;
    }
    int length = s1.size();
    for (int index  = 1; index < length; index ++) {
        if (isScramble(s1.substr(0, index), s2.substr(0, index)) && isScramble(s1.substr(index), s2.substr(index))) return true;
        if (isScramble(s1.substr(0, index), s2.substr(length - index)) && isScramble(s1.substr(index), s2.substr(0, length - index))) return true;
    }
    return false;
}

int Solution::maxDepth(TreeNode *root) {
    if (root == NULL) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

TreeNode * Solution::sortedArrayToBST(const vector<int> &nums, int start, int end) {
    if (end < start) {
        return NULL;
    }
    TreeNode * root;
    if (start == end){
        root = new TreeNode(nums[start]);
        return root;
    }
    int rootIndex = (start + (end - start + 1) / 2);
    root = new TreeNode(nums[rootIndex]);
    TreeNode * left = sortedArrayToBST(nums, start, rootIndex - 1);
    TreeNode * right = sortedArrayToBST(nums, rootIndex + 1, end);
    root->left = left;
    root->right = right;
    return root;
}
TreeNode * Solution::sortedArrayToBST(vector<int> &nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

int Solution::maxProfit(vector<int> &prices) {
    if (prices.empty()) return 0;
    int size = prices.size();
    int maxProfit = 0;
    int lowestPrice = prices[0];
    for (int index = 1; index < size; index++) {
        maxProfit = max(maxProfit, prices[index] - lowestPrice);
        lowestPrice = min(lowestPrice, prices[index]);
    }
    return maxProfit;
}

int Solution::maxProfitII(vector<int> &prices) {
    int maxProfit = 0;
    int size = prices.size();
    for (int index = 0; index < size - 1; index++) {
        if (prices[index + 1] > prices[index]) {
            maxProfit += (prices[index + 1] - prices[index]);
        }
    }
    return maxProfit;
}

int Solution::maxProfitIII(vector<int> &prices) {
    return 0;
}

bool Solution::isSymmetric(TreeNode *root) {
    if (root == NULL) return true;
    queue<TreeNode *> tl, tr;
    tl.push(root->left);
    tr.push(root->right);
    while (!tl.empty() && !tr.empty()) {
        TreeNode * left = tl.front();
        tl.pop();
        TreeNode * right = tr.front();
        tr.pop();
        if (left == NULL && right == NULL) continue;
        if (left == NULL || right == NULL) return false;
        if (left->val != right->val) return false;
        tl.push(left->left);
        tl.push(left->right);
        tr.push(right->right);
        tr.push(right->left);
    }
    return true;
}

vector<vector<int>> Solution::levelOrder(TreeNode *root) {
    vector<TreeNode *> levelNode;
    vector<TreeNode *> nextLevelNode;
    vector<int> singleLevelOrder;
    vector<vector<int>> result;
    if (root == NULL) return result;
    levelNode.push_back(root);
    while (!levelNode.empty() ) {

        TreeNode * curNode = levelNode.front();
        levelNode.erase(levelNode.begin());
        singleLevelOrder.push_back(curNode->val);
        if (curNode->left != NULL) {
            nextLevelNode.push_back(curNode->left);
        }
        if (curNode->right != NULL) {
            nextLevelNode.push_back(curNode->right);
        }
        if (levelNode.empty()) {
            result.push_back(singleLevelOrder);
            singleLevelOrder.clear();
            levelNode = nextLevelNode;
            nextLevelNode.clear();
        }
    }
    return result;
}

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode *root) {

    vector<TreeNode *> levelNode;
    vector<TreeNode *> nextLevelNode;
    vector<int> singleLevelOrder;
    vector<vector<int>> result;
    if (root == NULL) return result;
    levelNode.push_back(root);
    bool shouldReverse = false;
    while (!levelNode.empty() ) {

        TreeNode * curNode = levelNode.front();
        levelNode.erase(levelNode.begin());
        singleLevelOrder.push_back(curNode->val);
        if (curNode->left != NULL) {
            nextLevelNode.push_back(curNode->left);
        }
        if (curNode->right != NULL) {
            nextLevelNode.push_back(curNode->right);
        }
        if (levelNode.empty()) {
            if (shouldReverse) {
                std::reverse(singleLevelOrder.begin(), singleLevelOrder.end());
            }
            shouldReverse = !shouldReverse;
            result.push_back(singleLevelOrder);
            singleLevelOrder.clear();
            levelNode = nextLevelNode;
            nextLevelNode.clear();
        }
    }
    return result;
}

vector<vector<int>> Solution::levelOrderBottom(TreeNode *root) {
    vector<TreeNode * > curLevelNode;
    vector<TreeNode *> nextLevelNode;
    stack<vector<TreeNode *>> stackLevels;
    vector<vector<int>> result;
    if (root == NULL) return result;
    curLevelNode.push_back(root);
    while (!curLevelNode.empty()) {
        stackLevels.push(curLevelNode);
        int size = curLevelNode.size();
        for (int index = 0; index < size; index++) {
            if (curLevelNode[index]->left != NULL) {
                nextLevelNode.push_back(curLevelNode[index]->left);
            }
            if (curLevelNode[index]->right != NULL) {
                nextLevelNode.push_back(curLevelNode[index]->right);
            }
        }
        curLevelNode = nextLevelNode;
        nextLevelNode.clear();
    }
    while (!stackLevels.empty()) {
        vector<TreeNode *> &curLevel = stackLevels.top();
        vector<int> level;
        for (TreeNode * node : curLevel) {
            level.push_back(node->val);
        }
        result.push_back(level);
        stackLevels.pop();
    }
    return result;
}

TreeNode * Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode * Solution::buildTree(vector<int> &preorder, vector<int> &inorder, int pStart, int pEnd, int iStart,
                               int iEnd) {
    if (pStart == pEnd) return new TreeNode(preorder[pStart]);
    if (pStart > pEnd) return NULL;
    int curVal = preorder[pStart];
    TreeNode * root = new TreeNode(curVal);
    int leftChildLength = std::find(inorder.begin(), inorder.end(), curVal) - inorder.begin() - iStart;
    root->left = buildTree(preorder, inorder, pStart + 1, pStart + leftChildLength , iStart, iStart + leftChildLength - 1);
    root->right = buildTree(preorder, inorder, pStart + leftChildLength + 1, pEnd, iStart + leftChildLength + 1, iEnd);
    return root;
}

TreeNode * Solution::buildTreeII(vector<int> &inorder, vector<int> &postorder) {
    return buildTreeII(inorder, postorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode * Solution::buildTreeII(vector<int> & inorder, vector<int> & postorder, int pStart, int pEnd, int iStart, int iEnd){
    if (pStart > pEnd) return NULL;
    if (pStart == pEnd) return new TreeNode(postorder[pStart]);
    int curVal = postorder[pEnd];
    TreeNode * root = new TreeNode(curVal);
    int leftChildLength = std::find(inorder.begin(), inorder.end(), curVal) - inorder.begin() - iStart;
    root->left = buildTreeII(inorder, postorder, pStart, pStart + leftChildLength - 1, iStart, iStart + leftChildLength - 1);
    root->right = buildTreeII(inorder, postorder, pStart + leftChildLength, pEnd - 1, iStart + leftChildLength + 1, iEnd);
    return root;
}

int Solution::getHeightOfTree(TreeNode *root) {
    if (root == NULL) return 0;
    else return 1 + std::max(getHeightOfTree(root->left), getHeightOfTree(root->right));
}
bool Solution::isBalanced(TreeNode *root) {
    if (root == NULL) return true;
    return (std::abs(getHeightOfTree(root->right) - getHeightOfTree(root->left)) <= 1 && isBalanced(root->right) && isBalanced(root->left));
}

TreeNode * Solution::sortedListToBST(ListNode *head) {
    vector<int> vecList;
    while (head != NULL) {
        vecList.push_back(head->val);
        head = head->next;
    }
    return sortedArrayToBST(vecList, 0, vecList.size());
}
TreeNode * Solution::sortedListToBSTII(ListNode *head) {
    if (head == NULL)
        return  NULL;
    ListNode * node = head;
    int length = 0;
    while (node != NULL) {
        length ++;
        node = node -> next;
    }
    return generateBST(length, head);
}
TreeNode * Solution::generateBST(int n, ListNode *&list) {
    if (n == 0) return NULL;
    TreeNode * leftChild = generateBST( n / 2, list);
    TreeNode * root = new TreeNode(list->val);
    list = list->next;
    TreeNode * rightChild = generateBST(n - n / 2 - 1, list);
    root->left = leftChild;
    root->right = rightChild;
    return  root;
}

int Solution::minDepth(TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);
    return 1 + std::min(minDepth(root->left), minDepth(root->right));
}

bool Solution::hasPathSum(TreeNode *root, int sum) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL && root->val == sum) return true;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

vector<vector<int>> Solution::pathSum(TreeNode *root, int sum) {
    vector<vector<int>> result;
    if (root == NULL) return result;
    if (root->left == NULL && root->right == NULL) {
        if (root->val == sum) {
            result.push_back({root->val});
        }
        return result;
    }
    vector<vector<int>> leftResult = pathSum(root->left, sum - root->val);
    if (! leftResult.empty()) {
        for (auto list : leftResult) {
            list.insert(list.begin(),root->val);
            result.push_back(list);
        }
    }
    vector<vector<int>> rightResult = pathSum(root->right, sum - root->val);
    if ( !rightResult.empty()) {
        for (auto list : rightResult) {
            list.insert(list.begin(),root->val);
            result.push_back(list);
        }
    }
    return result;
}

void Solution::flatten(TreeNode *root) {
    if (root == NULL)
        return;
    TreeNode * curNode = NULL, * preNode = NULL;
    std::stack<TreeNode *> rightNodeStack;
    rightNodeStack.push(root);
    while (!rightNodeStack.empty()) {
        curNode = rightNodeStack.top();
        rightNodeStack.pop();
        if (preNode != NULL) {
            preNode->right = curNode;
        }
        while (curNode != NULL) {
            preNode = curNode;
            TreeNode * leftNode = curNode->left;
            TreeNode * rightNode = curNode->right;
            if (rightNode != NULL) {
                rightNodeStack.push(rightNode);
            }
            curNode->right = leftNode;
            curNode->left = NULL;
            curNode = leftNode;
        }
    }
}

void traversal(TreeLinkNode * root, vector<vector<TreeLinkNode *>> & vecVecNode , int level) {
    if (root == NULL) return;
    if (level >= vecVecNode.size()) {
        std::vector<TreeLinkNode * > vec;
        vecVecNode.push_back(vec);
    }
    vecVecNode[level].push_back(root);
    traversal(root->left, vecVecNode, level + 1);
    traversal(root->right, vecVecNode, level + 1);
}
void Solution::connect(TreeLinkNode * root) {
    if (root == NULL) {
        return;
    }
    vector<vector<TreeLinkNode *>> vecVecNode;
    traversal(root, vecVecNode, 0);
    for (auto vecNode : vecVecNode) {
        for (int index = 0 ; index < vecNode.size() - 1; index++) {
            vecNode[index]->next = vecNode[index+1];
        }
        vecNode.back()->next = NULL;
    }
}

vector<vector<int>> Solution::generate(int numRows) {
    if (numRows == 0) return {};
    vector<vector<int>> pascal(numRows, vector<int>());
    pascal[0].push_back(1);
    int row = 1;
    while (row < numRows) {
        pascal[row].push_back(1);
        for (int col = 1; col < row; col ++) {
            pascal[row].push_back(pascal[row - 1][col - 1] + pascal[row - 1][col]);
        }
        pascal[row].push_back(1);
        row ++;
    }

    return pascal;
}

vector<int> Solution::getRow(int rowIndex) {
    vector<int> pascalRow(1,1);
    for (int row = 1; row <= rowIndex; row ++) {
        int pre = 1, cur = 1;
        for (int col = 1; col < row; col++) {
            pre = pascalRow[col];
            pascalRow[col] += cur  ;
            cur = pre;
        }
        pascalRow.push_back(1);
    }
    return pascalRow;
}


int Solution::minimumTotal(vector<vector<int>> &triangle) {
    vector<int> vecMin(triangle[triangle.size() - 1]);
    for (int layer = triangle.size() - 2; layer >= 0; layer --) {
        for (int index = 0; index < triangle[layer].size(); index ++) {
            vecMin[index] = triangle[layer][index] + std::min(vecMin[index], vecMin[index + 1]);
        }
    }
    return vecMin[0];
}

vector<int> Solution::preorderTraversal(TreeNode *root) {
    vector<int> result;
    if (root == NULL) return result;
    result.push_back(root->val);
    for (auto n : preorderTraversal(root->left)) {
        result.push_back(n);
    }
    for (auto n : preorderTraversal(root->right)) {
        result.push_back(n);

        return result;
    }
}

vector<int> Solution::preorderTraversalIte(TreeNode *root) {
    std::stack<TreeNode *> tmpStack;
    std::vector<int> result;
    if (root == NULL) return result;
    tmpStack.push(root);
    while (!tmpStack.empty()) {
        TreeNode *curNode = tmpStack.top();
        tmpStack.pop();
        result.push_back(curNode->val);
        if (curNode->right)
            tmpStack.push(curNode->right);
        if (curNode->left)
            tmpStack.push(curNode->left);
    }
    return result;
}


bool Solution::isPalindrome(string s) {
    int p1 = 0, p2 = s.size()-1;
    while (p1 < p2) {
        while ( p1 < p2 && !std::isalnum(s.at(p1))) {
            p1 ++;
        }
        while ( p2 > p1 && !std::isalnum(s.at(p2)) ){
            p2 --;
        }
        if (p1 < p2 && std::toupper(s.at(p1)) != std::toupper(s.at(p2))) {
            return false;
        } else {
            p1 ++;
            p2 --;
        }
    }
    return true;
}

int Solution::getIntFromStack(std::stack<int> nodeStack) {
    int times = 1;
    int result = 0;
    while (!nodeStack.empty()) {
        result += nodeStack.top() * times;
        times *= 10;
        nodeStack.pop();
    }
    return result;
}
void Solution::dfsTraversal(TreeNode * root, std::stack<int> nodeStack, std::vector<int> & nums) {
    nodeStack.push(root->val);
    if (root->left == NULL && root->right == NULL) {
        nums.push_back(getIntFromStack(nodeStack));
    } else {
        if (root->left != NULL) {
            dfsTraversal(root->left, nodeStack, nums);
        }
        if (root->right != NULL) {
            dfsTraversal(root->right, nodeStack, nums);
        }
    }
}
int Solution::sumNumbers(TreeNode *root) {
    std::stack<int> nodeStack;
    std::vector<int> nums;
    if (root == NULL) return 0;
    dfsTraversal(root, nodeStack, nums);
    int sum = 0;
    for (int n : nums) {
        sum += n;
    }
    return sum;
}

int Solution::singleNumber(vector<int> &nums) {
    int result = 0;
    for (int n : nums) {
        result ^= n;
    }
    return result;
}

vector<int> Solution::postorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> treeStack;
    TreeNode * curNode = root;
    TreeNode * lastVisit = NULL;
    while (curNode || !treeStack.empty()) {
        while (curNode) {
            treeStack.push(curNode);
            curNode = curNode->left;
        }
        curNode = treeStack.top();
        if (curNode->right == NULL || lastVisit == curNode->right) {
            result.push_back(curNode->val);
            treeStack.pop();
            lastVisit = curNode;
            curNode = NULL;
        } else {
            curNode = curNode->right;
        }
    }
    return result;
}

ListNode * Solution::insertionSortList(ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode * curNode = head;
    ListNode * newHead = NULL;
    ListNode * tmp = NULL;
    while (curNode != NULL) {
        if (newHead == NULL) {
            tmp = curNode->next;
            curNode->next = NULL;
            newHead = curNode;
        } else if (curNode->val <= newHead->val) {
            tmp = curNode->next;
            curNode->next = newHead;
            newHead = curNode;
        }else {
            ListNode * pointNode = newHead;
            while (pointNode->next != NULL && curNode->val > pointNode->next->val) {
                pointNode = pointNode->next;
            }
            tmp = curNode->next;
            curNode->next = pointNode->next;
            pointNode->next = curNode;
        }
        curNode = tmp;
    }
    return newHead;
}

ListNode * Solution::detectCycle(ListNode *head) {
    ListNode * sp = head;
    ListNode * fp = head;
    bool hasCycle = false;
    while (true) {
        if (sp && fp && fp->next) {
            sp = sp->next;
            fp = fp->next->next;
        } else {
            hasCycle = false;
            break;
        }
        if (sp != NULL && sp == fp) {
            hasCycle = true;
            break;
        }
    }
    if (hasCycle) {
        sp = head;
        while (sp != fp) {
            sp = sp->next;
            fp = fp->next;
        }
        return sp;
    } else {
        return NULL;
    }
}

vector<int> Solution::twoSum(vector<int> &numbers, int target) {
    int length = numbers.size();
    for (int index = 0; index <= length - 2; index ++) {
        int numToFind = target - numbers[index];
        int l = index + 1, r = length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (numbers[mid] == numToFind) {
                return {index + 1, mid + 1};
            } else if (numbers[mid] > numToFind) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    return {};
}

int Solution::majorityELement(vector<int> &nums) {
//    sort(nums.begin(), nums.end());
//    return nums[nums.size() >> 1];
    int length = nums.size();
    srand(time(NULL));
    while (true) {
        int index = rand() % length;
        int candidate = nums[index];
        int cnt = 0;
        for (int i = 0; i < length; i++) {
            if (nums[i] == candidate) {
                cnt ++;
            }
        }
        if (cnt > length / 2) {
            return candidate;
        }
    }
}

ListNode * Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode * p1 = headA;
    ListNode * p2 = headB;
    while (p1 != p2) {
        p1 = p1 ? p1->next : headB;
        p2 = p2 ? p2->next : headA;
    }
    return p1;
}

int Solution::findPeakElement(vector<int> &nums) {
    return findPeakElement(nums, 0, nums.size() - 1);
}

int Solution::findPeakElement(vector<int> &nums, int l, int r) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] > nums[mid + 1]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int Solution::hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n) {
        n = n & (n - 1);
        cnt ++;
    }
    return cnt;
}

int maxDeep(TreeNode * root) {
    if (root == NULL) {
        return 0;
    }
    return max(maxDeep(root->right), maxDeep(root->left)) + 1;
}
int maxEdges(TreeNode * root){
    if (root == NULL || root->right == NULL && root->left == NULL) {
        return 0;
    }
    return max(maxDeep(root->left) + maxDeep(root->right),
        max(maxEdges(root->right), maxEdges(root->left)));
}
int Solution::diameterOfBinaryTree(TreeNode *root) {
    return maxEdges(root);
}

TreeNode * Solution::convertBST(TreeNode *root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL) {
        return root;
    }
    if (root->right != NULL) {
        convertBST(root->right);
        TreeNode * mostLeftInRight = root->right;
        while (mostLeftInRight->left) {
            mostLeftInRight = mostLeftInRight->left;
        }
        root->val += mostLeftInRight->val;
    }
    if (root->left != NULL) {
        TreeNode * mostRightInLeft = root->left;
        while (mostRightInLeft->right) {
            mostRightInLeft = mostRightInLeft->right;
        }
        mostRightInLeft->val += root->val;
        convertBST(root->left);
    }
    return root;
}


bool neededUpdate(vector<vector<int>> & matrix, int rows, int cols, int row, int col) {

    if (matrix[row][col] == 0) {
        return false;
    }
    if (col - 1 >= 0 ) {
        if (matrix[row][col] > matrix[row][col - 1]){
            return false;
        }
    }
    if (col + 1 < cols) {
        if (matrix[row][col] > matrix[row][col + 1]){
            return false;
        }
    }
    if (row - 1 >= 0) {
        if (matrix[row][col] > matrix[row - 1][col]){
            return false;
        }
    }
    if (row + 1 < rows) {
        if (matrix[row][col] > matrix[row + 1][col]){
            return false;
        }
    }
    return true;
}
bool updateFinished(vector<vector<int>> & matrix, int rows, int cols) {
    for (int row = 0; row < rows; row ++) {
        for (int col = 0; col < cols; col ++) {
            if (neededUpdate(matrix, rows, cols, row, col)) {
                return false;
            }
        }
    }
    return true;
}
void Solution::updateMatrix(vector<vector<int>> & matrix, int rows, int cols) {
    for (int row = 0; row < rows; row ++) {
        for (int col = 0; col < cols; col ++){
            if (neededUpdate(matrix, rows, cols, row, col)) {
                matrix[row][col] += 1;
            }
        }
    }
}
vector<vector<int>> Solution::updateMatrix(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    if (rows == 0) {
        return {{}};
    }
    int cols = matrix[0].size();
    if (cols == 0) {
        return {{}};
    }
    while (!updateFinished(matrix, rows, cols)) {
        updateMatrix(matrix, rows, cols);
    }
    return matrix;
}

bool Solution::checkPerfectNumber(int num) {
}

void getRV(const string & s, int & r, int & v) {
    string::size_type pos = s.find('+');
    int num = 0;
    for (size_t i = 0; i < pos; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + s[i] - '0';
        }
    }
    if (s[0] == '-') {
        num = -num;
    }
    r = num;
    num = 0;
    for (size_t i = pos + 1; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9'){
            num = num * 10 + s[i] - '0';
        }
    }
    if (s[pos + 1] == '-'){
        num = -num;
    }
    v = num;
    num = 0;
}
string getComplexString(int r, int v) {

    string s;
    stringstream ss;
    ss << r;
    s = ss.str();
    s += "+";
    stringstream sss;
    sss << v;
    s += sss.str();
    s += "i";
    return s;
}
string Solution::complexNumberMultiply(string a, string b) {
    int r1 = 0, r2 = 0, v1 = 0, v2 = 0;
    getRV(a, r1, v1);
    getRV(b, r2, v2);
    int r = r1 * r2 - v1 * v2;
    int v = r1 * v2 + r2 * v1;
    return getComplexString(r, v);
}
bool isLeaf(TreeNode * node) {
    if (node->left == NULL && node->right == NULL) {
        return true;
    }else {
        return false;
    }
}
int getDepth(TreeNode * root) {
    if (root == NULL) {
        return 0;
    }
    return max(getDepth(root->left), getDepth(root->right)) + 1;
}
void getBottomBound(TreeNode * root, vector<TreeNode *> & bottomBount) {
    if (root == NULL) {
        return ;
    }
    if (isLeaf(root)) {
        bottomBount.push_back(root);
        return ;
    }
    getBottomBound(root->left, bottomBount);
    getBottomBound(root->right, bottomBount);
}
vector<int> Solution::boundaryOfBinaryTree(TreeNode *root) {    vector<int> boundary;
    if (root==NULL){
        return boundary;
    }
    if (isLeaf(root)){
        boundary.push_back(root->val);
        return boundary;
    }
    int deep = getDepth(root);
    // bottom bound
    vector<TreeNode *> bottomBound;
    getBottomBound(root, bottomBound);
    TreeNode * node;

    // leftBoundary
    vector<TreeNode *> leftBoundary;
    bool hasMostLeft = false;
    leftBoundary.reserve(deep);
    node = root->left;
    while (node) {
        hasMostLeft = true;
        leftBoundary.push_back(node);
        if (node->left){
            node = node->left;
        }else if(node->right){
            node = node->right;
        }else {
            // leafNode
            break;
        }
    }
    // rightBoundary
    bool hasMostRight = false;
    vector<TreeNode *> rightBoundary;
    rightBoundary.reserve(deep);
    node = root->right;
    while (node){
        hasMostRight = true;
        rightBoundary.push_back(node);
        if (node->right){
            node = node->right;
        }else if(node->left){
            node = node->left;
        }else {
            // leaf node
            break;
        }
    }

    // merge
    boundary.push_back(root->val);
    vector<TreeNode *> boundNode(leftBoundary);
    if (!bottomBound.empty()) {
        if (hasMostLeft){
            copy(bottomBound.begin() + 1, bottomBound.end(), back_inserter(boundNode));
        }else {
            copy(bottomBound.begin(), bottomBound.end(), back_inserter(boundNode));
        }
    }
    if (!rightBoundary.empty()) {
        reverse(rightBoundary.begin(), rightBoundary.end());
        if (hasMostRight) {
            copy(rightBoundary.begin() + 1, rightBoundary.end(), back_inserter(boundNode));
        }else {
            copy(rightBoundary.begin() , rightBoundary.end(), back_inserter(boundNode));

        }
    }
    for (auto node : boundNode) {
        boundary.push_back(node->val);
    }

    return boundary;
}
