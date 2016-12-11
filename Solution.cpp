//
// Created by fa－apple on 2016/11/26.
//

#include <climits>
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
    for (size_t index = 0; index < strLength; index ++) {
        if (tmpVec.size() == 0) {
            tmpVec.insert(tmpVec.begin(), s.at(index));
        }else if (pre.find(s.at(index)) != pre.end()){
             tmpVec.insert(tmpVec.begin(), s.at(index));
        }else if (post.find(s.at(index)) != post.end()) {
            vector<char>::iterator it = tmpVec.begin();
            char currentChar = *it;
            switch( s.at(index) ) {
                case ')':
                    if (currentChar == '(') {
                        tmpVec.erase(it);
                    }else {
                        tmpVec.insert(tmpVec.begin(), s.at(index));
                    }
                    break;
                case '}':
                    if (currentChar == '{') {
                        tmpVec.erase(it);
                    }else {
                        tmpVec.insert(tmpVec.begin(), s.at(index));
                    }
                    break;
                case ']':
                    if (currentChar == '[') {
                        tmpVec.erase(it);
                    }else {
                        tmpVec.insert(tmpVec.begin(), s.at(index));
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
            setCharSlidingWindow.insert(s[j]);
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
}