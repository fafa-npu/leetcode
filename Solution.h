//
// Created by fa－apple on 2016/11/26.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H
#include <string>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

/**
 * Definitation of TreeLink Node.
 */
/**
* Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode * left;
     TreeNode * right;
     TreeNode(int x):val(x),left(NULL), right(NULL){}
 };

struct Interval {
    int start;
    int end;
    Interval():start(0),end(0){}
    Interval(int s, int e):start(s),end(e){}
};

/**
 * Definition for a point.
 */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


class Solution {
public :
    /**
     * 输出链表
     * @param list
     */
    void printList(ListNode * list){
        while(list != NULL){
            cout << list->val << " ";
            list = list->next;
        }
    }

    /**
     * 使用迭代的方法进行深度优先遍历
     * @param root
     */
    vector<int> iterateDfs(TreeNode * root) {
        vector<int> result;
        if (root == NULL)
            return result;
        std::stack<TreeNode * > treeStack;
        treeStack.push(root);
        while (!treeStack.empty()) {
            auto node = treeStack.top();
            treeStack.pop();
            result.push_back(node->val);
            std::cout << node->val << " ";
            if (node->right != NULL) {
                treeStack.push(node->right);
            }

            if (node->left != NULL) {
                treeStack.push(node->left);
            }
        }
        return result;
    }

    /**
     * 二分查找
     * @param nums
     * @param target
     * @return
     */
    int binarySearch(vector<int> & nums, int target);

    /**
     * 2. Add Two Numbers
     * You are given two linked lists representing two non-negative numbers.
     * The digits are stored in reverse order and each of their nodes contain a single digit.
     * Add the two numbers and return it as a linked list.
     * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
     * Output: 7 -> 0 -> 8
     * @param l1
     * @param l2
     * @return
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

    /** 3. Longest Substring Without Repeating Characters
     * Given a string, find the length of the longest substring without repeating characters.
     * Examples:
     * Given "abcabcbb", the answer is "abc", which the length is 3.
     * Given "bbbbb", the answer is "b", with the length of 1.
     * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
     * @param s
     * @return
     */
    size_t lengthOfLongestSubstring(string s);

    /** 4. Median of Two Sorted Arrays
     * There are two sorted arrays nums1 and nums2 of size m and n respectively.
        Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
        Example 1:
            nums1 = [1, 3]
            nums2 = [2]
            The median is 2.0
        Example 2:
            nums1 = [1, 2]
            nums2 = [3, 4]
            The median is (2 + 3)/2 = 2.5
     * @param nums1
     * @param nums2
     * @return
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

    /** 5. Longest Palindromic Substring
     * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
        Example:
            Input: "babad"
            Output: "bab"
            Note: "aba" is also a valid answer.
        Example:
            Input: "cbbd"
            Output: "bb"
     * @param s
     * @return
     */
    string longestPalindrome(string s);

    /**
     * 6. ZigZag Conversion
        The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

        P   A   H   N
        A P L S I I G
        Y   I   R
        And then read line by line: "PAHNAPLSIIGYIR"
        Write the code that will take a string and make this conversion given a number of rows:

        string convert(string text, int nRows);
        convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

     * @param s
     * @param numRows
     * @return
     */
    string convert(string s, int numRows);

    /**
     * 7. Reverse Integer
     * author : zhaohua
     * created on : 2016/11/19
     * discription:
     *     Reverse digits of an integer.
     *
     *     Example1: x = 123, return 321
     *     Example2: x = -123, return -321
     */
    int reverse(int x);

    /**
     * 8. String to Integer(atoi)
     * Implement atoi to convert a string to an integer.
     *
     * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
     *
     * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
     * @param str
     * @return
     */
    int myAtoi(string str);

    /**
     * 9. Palindrome Number
     * Determine whether an integer is a palindrome. Do this without extra space.
     */
    bool isPalindrome(int x) ;

    /**
     * 10. Regular Expression Matching
     * Implement regular expression matching with support for '.' and '*'.
     *  '.' Matches any single character.
        '*' Matches zero or more of the preceding element.

        The matching should cover the entire input string (not partial).

        The function prototype should be:
        bool isMatch(const char *s, const char *p)

        Some examples:
        isMatch("aa","a") → false
        isMatch("aa","aa") → true
        isMatch("aaa","aa") → false
        isMatch("aa", "a*") → true
        isMatch("aa", ".*") → true
        isMatch("ab", ".*") → true
        isMatch("aab", "c*a*b") → true
     * @param s
     * @param p
     * @return
     */
    bool isMatch(string s, string p);

    /**
     * 11. Contatiner With Most Water
     * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
     * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
     * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
       Note: You may not slant the container.
     * @param height
     * @return
     */
    int maxArea(vector<int> & height);

    /*
     * 14. Longest Common Prefix
     * 计算最长公共前缀
     * @param strs 要计算的各string组成的vector
     * @return 公共前缀，如果没有公共前缀时返回 ""
     */
    string longestCommonPrefix(vector<string> & strs);

    /**
     * 15. 3Sum
     * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
     * Note: The solution set must not contain duplicate triplets.
     * For example, given array S = [-1, 0, 1, 2, -1, -4],
     * A solution set is:
     * [
     *  [-1, 0, 1],
     *  [-1, -1, 2]
     * ]
     * @param nums
     * @return
     */
    vector<vector<int>> threeSum(vector<int> & nums);

    /**
     * 16. 3Sum Closest
     * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
        For example, given array S = {-1 2 1 -4}, and target = 1.
        The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
     * @param nums
     * @param target
     * @return
     */
    int threeSumClosest(vector<int>& nums, int target);

    /**
     * 17. Letter Combinations of a Phone Number
     * Given a digit string, return all possible letter combinations that the number could represent.
        A mapping of digit to letters (just like on the telephone buttons) is given below.
            Input:Digit string "23"
            Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
        Note:
            Although the above answer is in lexicographical order, your answer could be in any order you want.
     * @param digits
     * @return
     */
    vector<string> letterCombinations(string digits);

    /**
     * 18. 4Sum
     * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
        Note: The solution set must not contain duplicate quadruplets.
            For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
            A solution set is:
            [
              [-1,  0, 0, 1],
              [-2, -1, 1, 2],
              [-2,  0, 0, 2]
            ]
     * @param nums
     * @param target
     * @return
     */
    vector<vector<int>> fourSum(vector<int> & nums, int target);

    /**
     * 20. Valid Parentheses
     * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
     * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
     * @param s
     * @return
     */
    bool isValid(string s);

    /**
     * 21. Merge Two Sorted Lists
     * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
     * 从小到大排列
     * @param l1 sorted linked list
     * @param l2 sorted linked list
     * @return merged list
     */
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2);

    /**
     * 22. Generate Parentheses
     * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
     * For example, given n = 3, a solution set is:
     * [
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()"
        ]
     * @param n
     * @return
     */
    vector<string> generateParenthesis(int n);

    /**
     * 23. Merge k Sorted Lists
        Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
     * @param lists
     * @return
     */
    ListNode * mergeKLists(vector<ListNode*> & lists) ;
    ListNode * mergeTwoList(ListNode * l1, ListNode * l2);

    /**
     * 24. Swap Nodes in Pairs
     * Given a linked list, swap every two adjacent nodes and return its head.
     * For example,Given 1->2->3->4, you should return the list as 2->1->4->3.
     * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
     */
    ListNode * swapPairs(ListNode * head);

    /**
     * 25. Reverse Nodes in k-Group
     * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
     * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
     * You may not alter the values in the nodes, only nodes itself may be changed.
     * Only constant memory is allowed.
     * For example,
     * Given this linked list: 1->2->3->4->5
     * For k = 2, you should return: 2->1->4->3->5
     * For k = 3, you should return: 3->2->1->4->5
     */
    ListNode* reverseKGroup(ListNode* head, int k);

    /**
     * 26. Remove Duplicates from Sorted Array
     * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
     * Do not allocate extra space for another array, you must do this in place with constant memory.
     * For example,
     *     Given input array nums = [1,1,2],
     *     Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
     *     It doesn't matter what you leave beyond the new length.
     * @param nums
     * @return
     */
    int removeDuloicates(vector<int> & nums);

    /**
     * 27. Remove Element
     * Given an array and a value, remove all instances of that value in place and return the new length.
     * Do not allocate extra space for another array, you must do this in place with constant memory.
     * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
     * Example:
     * Given input array nums = [3,2,2,3], val = 3
     * Your function should return length = 2, with the first two elements of nums being 2.
     */
    int removeElement(vector<int> & nums, int val);

    /**
     * 28. Implement strStr()
     * Implement strStr().
     * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
     * 返回haystack中needle子串的位置
     * @param haystack
     * @param needle
     * @return
     */
    int strStr(string haystack, string needle);

    /**
     * 31. Next Permutation
        Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
        If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
        The replacement must be in-place, do not allocate extra memory.
        Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
            1,2,3 → 1,3,2
            3,2,1 → 1,2,3
            1,1,5 → 1,5,1
     * @param nums
     */
    void nextPermutation(vector<int>& nums);

    /**
     * 32. Longest Valid Parentheses
        Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
        For "(()", the longest valid parentheses substring is "()", which has length = 2.
        Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.     * @param s
     * @return
     */
    int longestValidParentheses(string s);
    int longestValidParenthesesStack(string s);


    /**
     * 33. Search in Rotated Sorted Array
     * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
        (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
        You are given a target value to search. If found in the array return its index, otherwise return -1.
        You may assume no duplicate exists in the array.
     * @param nums
     * @param target
     * @return
     */
    int search(vector<int>& nums, int target) ;

    /**
     * 34. Search for a Range
     * Given a sorted array of integers, find the starting and ending position of a given target value.
        Your algorithm's runtime complexity must be in the order of O(log n).
        If the target is not found in the array, return [-1, -1].

        For example,
        Given [5, 7, 7, 8, 8, 10] and target value 8,
        return [3, 4].
     * @param nums
     * @param target
     * @return
     */
    vector<int> searchRange(vector<int>& nums, int target);

    /**
     * 35. Search Insert Position
     * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
        You may assume no duplicates in the array.
        Here are few examples.
        [1,3,5,6], 5 → 2
        [1,3,5,6], 2 → 1
        [1,3,5,6], 7 → 4
        [1,3,5,6], 0 → 0
     * @param nums
     * @param target
     * @return
     */
    int searchInsert(vector<int>& nums, int target);

    /**
     * 36. Valid SudoKu
     * Determine if a Sudoku is valid.
     * The Sudoku board could be partially filled, where empty cells are filled with the character '.' .
     * Note:
     * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
     * @param bord
     * @return
     */
    bool isValidSudoku(vector<vector<char>> & bord);

    /**
     * 37. Sudoku Solver
     *  Write a program to solve a Sudoku puzzle by filling the empty cells.
        Empty cells are indicated by the character '.'.
     * @param board
     */
    void solveSudoku(vector<vector<char>>& board);
    bool solveSudoku(vector<vector<char>> &board, int i, int j);
    bool isValidSudoku(vector<vector<char>> & board, int i, int j, char c);

    /**
     * 38. Count and Say
     * The count-and-say sequence is the sequence of integers beginning as follows:
     * 1, 11, 21, 1211, 111221, ...
     * 1 is read off as "one 1" or 11.1
     * 1 is read off as "two 1s" or 21.
     * 21 is read off as "one 2, then one 1" or 1211.
     * Given an integer n, generate the nth sequence.
     * Note: The sequence of integers will be represented as a string.
     * @param n
     * @return
     */
    string countAndSay(int n);

    /**
     * 39. Combination Sum
     * Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
        The same repeated number may be chosen from C unlimited number of times.
        Note:
            All numbers (including target) will be positive integers.
            The solution set must not contain duplicate combinations.
        For example, given candidate set [2, 3, 6, 7] and target 7,
        A solution set is:
            [
              [7],
              [2, 2, 3]
            ]
     * @param candidates
     * @param target
     * @return
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    vector<vector<int>> combinationSum(vector<int> &, int, vector<int>&, int);

    /**
     * 40. Combination Sum II
     * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
        Each number in C may only be used once in the combination.
        Note:
            All numbers (including target) will be positive integers.
            The solution set must not contain duplicate combinations.
        For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
        A solution set is:
            [
              [1, 7],
              [1, 2, 5],
              [2, 6],
              [1, 1, 6]
            ]
     * @param candidates
     * @param target
     * @return
     */
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target, vector<int> & combination, int begin);

    /**
     * 41. First Missing Postive
     * Given an unsorted integer array, find the first missing positive integer.
        For example,
        Given [1,2,0] return 3,
        and [3,4,-1,1] return 2.
        Your algorithm should run in O(n) time and uses constant space.
     * @param nums
     * @return
     */
    int firstMissingPostive(vector<int> & nums);

    /**
     * 42. Trapping Rain Water
    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
        For example,
        Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
     * @param height
     * @return
     */
    int trap(vector<int>& height);

    /**
     * 43. Multiply Strings
     * Given two numbers represented as strings, return multiplication of the numbers as a string.
        Note:
        The numbers can be arbitrarily large and are non-negative.
        Converting the input string to integer is NOT allowed.
        You should NOT use internal library such as BigInteger.
     * @param num1
     * @param num2
     * @return
     */
    string multiply(string num1, string num2);

    /**
     * 45. Jump Game II
     * Given an array of non-negative integers, you are initially positioned at the first index of the array.
        Each element in the array represents your maximum jump length at that position.
        Your goal is to reach the last index in the minimum number of jumps.
            For example:
            Given array A = [2,3,1,1,4]
        The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

        Note:
        You can assume that you can always reach the last index.
     * @param nums
     * @return
     */
    int jump(vector<int> & nums);

    /**
     * 46. Permutations
     * Given a collection of distinct numbers, return all possible permutations.
        For example,
        [1,2,3] have the following permutations:
        [
          [1,2,3],
          [1,3,2],
          [2,1,3],
          [2,3,1],
          [3,1,2],
          [3,2,1]
        ]
     * @param nums
     * @return
     */
    vector<vector<int>> permute(vector<int>& nums);

    /**
     * 47. Permunations II
        Given a collection of numbers that might contain duplicates, return all possible unique permutations.
        For example,
        [1,1,2] have the following unique permutations:
            [
              [1,1,2],
              [1,2,1],
              [2,1,1]
            ]
     * @param nums
     * @return
     */
    vector<vector<int>> permuteUnique(vector<int> & nums);
    vector<vector<int>> permuteUnique(vector<int> nums, int i);

    /**
     * 48. Rotate Image
     * You are given an n x n 2D matrix representing an image.
     * Rotate the image by 90 degrees (clockwise).
     * Follow up:
     * Could you do this in-place?
     * @param matrix
     */
    void rotate(vector<vector<int>> & matrix);

    /**
     * 49. Group Anagrams
     * Given an array of strings, group anagrams together.
        For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
        Return:
            [
              ["ate", "eat","tea"],
              ["nat","tan"],
              ["bat"]
            ]
     * @param strs
     * @return
     */
    vector<vector<string>> groupAnagrams(vector<string> & strs);

    /**
     * 50. Pow(x, n)
     * Implement pow(x, n).
     * @param x
     * @param n
     * @return
     */
    double myPow(double x, int n);

    /**
     * 51. N-Queens
        The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
        Given an integer n, return all distinct solutions to the n-queens puzzle.
        Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
        For example,
        There exist two distinct solutions to the 4-queens puzzle:
            [
             [".Q..",  // Solution 1
              "...Q",
              "Q...",
              "..Q."],
             ["..Q.",  // Solution 2
              "Q...",
              "...Q",
              ".Q.."]
            ]
     * @param n
     * @return
     */
    vector<vector<string>> solveNQueens(int n);
    bool isValidQueens(vector<string>, int i, int j);
    vector<vector<string>> solveNQueens(vector<string> _queens,int n, int row);

    /**
     * 52.Follow up for N-Queens problem.
        Now, instead outputting board configurations, return the total number of distinct solutions.
     * @param n
     * @return
     */
    int totalNQueens(int n);
    void totalNQueens(vector<bool> & flag, int n, int row, int & num);

    /**
     * 53. Maximum Subarray
     * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
        For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
        the contiguous subarray [4,-1,2,1] has the largest sum = 6.

        If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
     * @param nums
     * @return
     */
    int maxSubArray(vector<int> & nums);

    /**
     * 54. Spiral Matrix
        Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
        For example,
        Given the following matrix:
            [
             [ 1, 2, 3 ],
             [ 4, 5, 6 ],
             [ 7, 8, 9 ]
            ]
        You should return [1,2,3,6,9,8,7,4,5].
     * @param matrix
     * @return
     */
    vector<int> spiralOrder(vector<vector<int>> & matrix);

    /**
     * 55. Jump Game
        Given an array of non-negative integers, you are initially positioned at the first index of the array.
        Each element in the array represents your maximum jump length at that position.
        Determine if you are able to reach the last index.
        For example:
            A = [2,3,1,1,4], return true.
            A = [3,2,1,0,4], return false.
     * @param nums
     * @return
     */
    bool canJump(vector<int> & nums);

    /**
     * 56. Merge Intervals
        Given a collection of intervals, merge all overlapping intervals.
        For example,
            Given [1,3],[2,6],[8,10],[15,18],
            return [1,6],[8,10],[15,18].
     * @param intervals
     * @return
     */
    vector<Interval> merge(vector<Interval> & intervals);

    /**
     * 57. Insert Interval
        Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
        You may assume that the intervals were initially sorted according to their start times.

        Example 1:
            Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

        Example 2:
            Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
            This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
     * @param intervals
     * @param newInterval
     * @return
     */
    vector<Interval> insert(vector<Interval> & intervals, Interval newInterval);

    /** 58. Length of Last Word
     * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
        If the last word does not exist, return 0.
        Note: A word is defined as a character sequence consists of non-space characters only.
            For example,
            Given s = "Hello World",
            return 5.
     * @param s
     * @return
     */
    int lengthOfLastWord(string s) ;

    /**
     * 59. Spiral Matrix II
        Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
        For example,
        Given n = 3,
        You should return the following matrix:
            [
             [ 1, 2, 3 ],
             [ 8, 9, 4 ],
             [ 7, 6, 5 ]
            ]
     * @param n
     * @return
     */
    vector<vector<int>> generateMatrix(int n);

    /**
     * 60. Permutation Sequence
        The set [1,2,3,…,n] contains a total of n! unique permutations.
        By listing and labeling all of the permutations in order,
        We get the following sequence (ie, for n = 3):
        "123"
        "132"
        "213"
        "231"
        "312"
        "321"
        Given n and k, return the kth permutation sequence.
        Note: Given n will be between 1 and 9 inclusive.
     * @param n
     * @param k
     * @return
     */
    string getPermutation(int n, int k);

    /**
     * 61. Rotate List
        Given a list, rotate the list to the right by k places, where k is non-negative.
        For example:
            Given 1->2->3->4->5->NULL and k = 2,
            return 4->5->1->2->3->NULL.
     * @param head
     * @param k
     * @return
     */
    ListNode * rotateList(ListNode * head, int k);

    /**
     * 62. Unique Paths
        A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
        The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
        How many possible unique paths are there?
     * @param m
     * @param n
     * @return
     */
    int uniquePaths(int m, int n);

    /**
     * 63. Unique Paths II
        Follow up for "Unique Paths":
        Now consider if some obstacles are added to the grids. How many unique paths would there be?
        An obstacle and empty space is marked as 1 and 0 respectively in the grid.
        For example,
        There is one obstacle in the middle of a 3x3 grid as illustrated below.
            [
              [0,0,0],
              [0,1,0],
              [0,0,0]
            ]
        The total number of unique paths is 2.
        Note: m and n will be at most 100.
     * @param obstacleGrid
     * @return
     */
    int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid);

    /**
     * 64. Minimum Path Sum
        Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
        Note: You can only move either down or right at any point in time.
     * @return
     */
    int minPathSum(vector<vector<int>> & grid);

    /**
     * 66. Plus One
     * Given a non-negative number represented as an array of digits, plus one to the number.
     * The digits are stored such that the most significant digit is at the head of the list.@param digits
     * @return
     */
    vector<int> plusOne(vector<int> & digits);

    /**
     * 67. Add Binary
        Given two binary strings, return their sum (also a binary string).
        For example,
            a = "11"
            b = "1"
            Return "100".
     * @param a
     * @param b
     * @return
     */
    string addBinary(string a, string b);

    /**
     * 70. Climbing Stairs
        You are climbing a stair case. It takes n steps to reach to the top.
        Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
        Subscribe to see which companies asked this question
     * @param n
     * @return
     */
    int climbStairs(int n);

    /**
        72. Edit Distance
        Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
        You have the following 3 operations permitted on a word:
        a) Insert a character
        b) Delete a character
        c) Replace a character
     * @param word1
     * @param word2
     * @return
     */
    int minDistance(string word1, string word2);

    /**
     * 73. Set Matrix Zeroes
        Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
     * @param matrix
     */
    void setZeroes(vector<vector<int>> & matrix);

    /**
     * 74. Search a 2D matrix
     * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
        Integers in each row are sorted from left to right.
        The first integer of each row is greater than the last integer of the previous row.
        For example,
        Consider the following matrix:
            [
              [1,   3,  5,  7],
              [10, 11, 16, 20],
              [23, 30, 34, 50]
            ]
        Given target = 3, return true.
     * @param matrix
     * @param target
     * @return
     */
    bool searchMatrix(vector<vector<int>> & matrix, int target);

    /**
     * 69. Sqrt(x)
     *Implement int sqrt(int x).
        Compute and return the square root of x.
     * @param x
     * @return
     */
    int sqrt(int x);

    /**
     * 71. Simplify Path
        Given an absolute path for a file (Unix-style), simplify it.
            For example,
            path = "/home/", => "/home"
            path = "/a/./b/../../c/", => "/c"
            click to show corner cases.
        Corner Cases:
            Did you consider the case where path = "/../"?
            In this case, you should return "/".
            Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
            In this case, you should ignore redundant slashes and return "/home/foo".
     * @param path
     * @return
     */
    string simplifyPath(string path);

    /**
     * 75. Sort Colors
        Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
        Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
        Note:
        You are not suppose to use the library's sort function for this problem.

        Follow up:
        A rather straight forward solution is a two-pass algorithm using counting sort.
        First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

        Could you come up with an one-pass algorithm using only constant space?
     * @param nums
     */
    void sortColors(vector<int> & nums);

    /**
     * 77. Combinations
        Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
            For example,
            If n = 4 and k = 2, a solution is:
            [
              [2,4],
              [3,4],
              [2,3],
              [1,2],
              [1,3],
              [1,4],
            ]
     * @param n
     * @param k
     * @return
     */
    vector<vector<int>> combine(int n, int k);
    vector<vector<int>> combine(vector<int>,int, int);

    /**
     * 78. Subsets
        Given a set of distinct integers, nums, return all possible subsets.
        Note: The solution set must not contain duplicate subsets.
        For example,
        If nums = [1,2,3], a solution is:
            [
              [3],
              [1],
              [2],
              [1,2,3],
              [1,3],
              [2,3],
              [1,2],
              []
            ]
     * @param nums
     * @return
     */
    vector<vector<int>> subsets(vector<int> & nums);

    /**
     * 79. Word Search
        Given a 2D board and a word, find if the word exists in the grid.
        The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
            For example,
            Given board =
            [
              ['A','B','C','E'],
              ['S','F','C','S'],
              ['A','D','E','E']
            ]
            word = "ABCCED", -> returns true,
            word = "SEE", -> returns true,
            word = "ABCB", -> returns false.
     * @param board
     * @param word
     * @return
     */
    bool exist(vector<vector<char>> & board, string word);
    bool exist(vector<vector<char>> & board, int row, int col, string word, int index, vector<vector<bool>> &visitBoard);

    /**
     *80. Remove Duplicates from Sorted Array II
        Follow up for "Remove Duplicates":
        What if duplicates are allowed at most twice?
        For example,
        Given sorted array nums = [1,1,1,2,2,3],
        Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
     * @param nums
     * @return
     */
    int removeDuplicatesII(vector<int> & nums);

    /**
     * 82. Remove Duplicates from Sorted List II
    Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
        For example,
        Given 1->2->3->3->4->4->5, return 1->2->5.
        Given 1->1->1->2->3, return 2->3.
     * @param head
     * @return
     */
    ListNode * deleteDuplicatesII(ListNode * head);

    /**
     * 83. Remove Duplicates from Sorted List
        Given a sorted linked list, delete all duplicates such that each element appear only once.
        For example,
        Given 1->1->2, return 1->2.
        Given 1->1->2->3->3, return 1->2->3.
     * @param head
     * @return
     */
    ListNode * deleteDuplicates(ListNode * head);

    /**
     * 86. Partition List
        Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
        You should preserve the original relative order of the nodes in each of the two partitions.
        For example,
        Given 1->4->3->2->5->2 and x = 3,
        return 1->2->2->4->3->5.
     * @param head
     * @param x
     * @return
     */
    ListNode * partition(ListNode * head, int x);

    /**
     * 87. Scramble String
        Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
        Below is one possible representation of s1 = "great":

            great
           /    \
          gr    eat
         / \    /  \
        g   r  e   at
                   / \
                  a   t
        To scramble the string, we may choose any non-leaf node and swap its two children.

        For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

            rgeat
           /    \
          rg    eat
         / \    /  \
        r   g  e   at
                   / \
                  a   t
        We say that "rgeat" is a scrambled string of "great".
        Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
            rgtae
           /    \
          rg    tae
         / \    /  \
        r   g  ta  e
               / \
              t   a
        We say that "rgtae" is a scrambled string of "great".
        Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
     * @param s1
     * @param s2
     * @return
     */
    bool isScramble(string s1, string s2);

    /**88. Merge Sorted Array
        Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
        Note:
        You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
     *
     * @param nums1
     * @param m
     * @param nums2
     * @param n
     */
    void merge(vector<int> & nums1, int m, vector<int> & nums2, int n);

    /**
     * 89. Gray Code
        The gray code is a binary numeral system where two successive values differ in only one bit.
        Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
            For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
            00 - 0
            01 - 1
            11 - 3
            10 - 2
        Note:
        For a given n, a gray code sequence is not uniquely defined.
        For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
     * @param n
     * @return
     */
    vector<int> grayCode(int n);

    /**
     * 90. Subsets II
        Given a collection of integers that might contain duplicates, nums, return all possible subsets.
        Note: The solution set must not contain duplicate subsets.
        For example,
        If nums = [1,2,2], a solution is:
        [
          [2],
          [1],
          [1,2,2],
          [2,2],
          [1,2],
          []
        ]
     * @param nums
     * @return
     */
    vector<vector<int>> subsetsWithDup(vector<int> & nums);

    /**
     * 92. Reverse Linked List II
        Reverse a linked list from position m to n. Do it in-place and in one-pass.
            For example:
            Given 1->2->3->4->5->NULL, m = 2 and n = 4,
            return 1->4->3->2->5->NULL.
        Note:
        Given m, n satisfy the following condition:
        1 ≤ m ≤ n ≤ length of list.
     * @param head
     * @param m
     * @param n
     * @return
     */
    ListNode * reverseBetween(ListNode * head, int m, int n);

    /**
     *    94. Binary Tree Inorder Traversal
        Given a binary tree, return the inorder traversal of its nodes' values.
        For example:
        Given binary tree [1,null,2,3],
           1
            \
             2
            /
           3
        return [1,3,2].
        Note: Recursive solution is trivial, could you do it iteratively?
     * @param root
     * @return
     */
    vector<int> inorderTraversal(TreeNode * root);

    /**
     * 95. Unique Binary Search Trees II
     * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
        For example,
        Given n = 3, your program should return all 5 unique BST's shown below.

           1         3     3      2      1
            \       /     /      / \      \
             3     2     1      1   3      2
            /     /       \                 \
           2     1         2                 3
     * @param n
     * @return
     */
    vector<TreeNode *> generateTrees(int n); // 动态规划方法
    vector<TreeNode *> generateTreesRecursive(int n); // 递归方法

    /**
     * 96. Unique Binary Search Trees
        Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
        For example,
        Given n = 3, there are a total of 5 unique BST's.

           1         3     3      2      1
            \       /     /      / \      \
             3     2     1      1   3      2
            /     /       \                 \
           2     1         2                 3
     * @param n
     * @return
     */
    int numTrees(int n);

	/*
	99. Recover Binary Search Tree
	Two elements of a binary search tree (BST) are swapped by mistake.
	Recover the tree without changing its structure.
	Note:
	A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
	*/
	void inorderTraversal(TreeNode *, TreeNode **, TreeNode **, TreeNode **);
	void recoverTree(TreeNode * root);

    /**
     * 100. Same Tree.
     * Given two binary trees, write a function to check if they are equal or not.
        Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
     * @param p
     * @param q
     * @return
     */
    bool isSameTree(TreeNode * p, TreeNode * q);

    /**
     * 101. Symmetric Tree
        Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
        For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

            1
           / \
          2   2
         / \ / \
        3  4 4  3
        But the following [1,2,2,null,3,null,3] is not:
            1
           / \
          2   2
           \   \
           3    3
        Note:
        Bonus points if you could solve it both recursively and iteratively.
     * @param root
     * @return
     */
    bool isSymmetric(TreeNode * root);

    /**
     * 102. Binary Tree Level Order Traversal
        Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
        For example:
        Given binary tree [3,9,20,null,null,15,7],
            3
           / \
          9  20
            /  \
           15   7
        return its level order traversal as:
        [
          [3],
          [9,20],
          [15,7]
        ]
     * @param root
     * @return
     */
    vector<vector<int>> levelOrder(TreeNode * root);

    /**
     *103. Binary Tree Zigzag Level Order Traversal
        Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
        For example:
        Given binary tree [3,9,20,null,null,15,7],
            3
           / \
          9  20
            /  \
           15   7
        return its zigzag level order traversal as:
        [
          [3],
          [20,9],
          [15,7]
        ]
     * @param root
     * @return
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode * root);

    /**
     * 104. Maximum Depth of Binary Tree
        Given a binary tree, find its maximum depth.
        The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
     * @param root
     * @return
     */
    int maxDepth(TreeNode * root);

    /**
     * 105. Construct Binary Tree from Preorder and Inorder Traversal
        Given preorder and inorder traversal of a tree, construct the binary tree.
        Note:
        You may assume that duplicates do not exist in the tree.
     * @param preorder
     * @param inorder
     * @return
     */
    TreeNode * buildTree(vector<int> & preorder, vector<int> & inorder);
    TreeNode * buildTree(vector<int> & preorder, vector<int> & inorder, int pStart, int pEnd, int iStart, int iEnd);

    /**
     *106. Construct Binary Tree from Inorder and Postorder Traversal
        Given inorder and postorder traversal of a tree, construct the binary tree.
        Note:
        You may assume that duplicates do not exist in the tree.
     * @param inorder
     * @param postorder
     * @return
     */
    TreeNode * buildTreeII(vector<int> & inorder, vector<int> & postorder);
    TreeNode * buildTreeII(vector<int> & inorder, vector<int> & postorder, int pStart, int pEnd, int iStart, int iEnd);

    /**
     * 107. Binary Tree Level Order Traversal II
        Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
        For example:
        Given binary tree [3,9,20,null,null,15,7],
            3
           / \
          9  20
            /  \
           15   7
        return its bottom-up level order traversal as:
        [
          [15,7],
          [9,20],
          [3]
        ]
     * @param root
     * @return
     */
    vector<vector<int>> levelOrderBottom(TreeNode * root);

    /**
     * 108. Convert Sorted Array to Binary Search Tree
        Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
     * @param nums
     * @return
     */
    TreeNode * sortedArrayToBST(vector<int> & nums);
    TreeNode * sortedArrayToBST(const vector<int> & nums, int start, int end);

    /**
     * 109. Convert Sorted List to Binary Search Tree
        Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
     * @param head
     * @return
     */
    TreeNode * sortedListToBST(ListNode * head);  // using sortedArrayToBST
    TreeNode * sortedListToBSTII(ListNode * head);   // using list
    TreeNode * generateBST(int n, ListNode * &list);

    /**
     * 110. Balanced Binary Tree
        Given a binary tree, determine if it is height-balanced.
        For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1
     * @param root
     * @return
     */
    bool isBalanced(TreeNode * root) ;
    int getHeightOfTree(TreeNode * root);

    /**
     * 111. Minimum Depth of Binary Tree
        Given a binary tree, find its minimum depth.
        The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
     * @param root
     * @return
     */
    int minDepth(TreeNode * root);

    /**
     * 112. Path Sum
        Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
        For example:
        Given the below binary tree and sum = 22,
                      5
                     / \
                    4   8
                   /   / \
                  11  13  4
                 /  \      \
                7    2      1
        return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
     * @param root
     * @param sum
     * @return
     */
    bool hasPathSum(TreeNode * root, int sum);

    /**
     *113. Path Sum II
        Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
        For example:
        Given the below binary tree and sum = 22,
                      5
                     / \
                    4   8
                   /   / \
                  11  13  4
                 /  \    / \
                7    2  5   1
        return
        [
           [5,4,11,2],
           [5,8,4,5]
        ]
     * @param root
     * @param sum
     * @return
     */
    vector<vector<int>> pathSum(TreeNode * root, int sum) ;

    /**
     * 114. Flatten Binary Tree to Linked List
        Given a binary tree, flatten it to a linked list in-place.

        For example,
        Given

                 1
                / \
               2   5
              / \   \
             3   4   6
        The flattened tree should look like:
           1
            \
             2
              \
               3
                \
                 4
                  \
                   5
                    \
                     6
     * @param root
     */
    void flatten(TreeNode * root);

	/*115. Distinct Subsequences
	Compute the number of distinct subsequences of S equal to T
	A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

	Here is an example:
	S = "rabbbit", T = "rabbit"

	Return 3.
	*/
	int numDistinct(string s, string t);

    /**
     * 116. Populating Next Right Pointers in Each Node
        Given a binary tree
            struct TreeLinkNode {
              TreeLinkNode *left;
              TreeLinkNode *right;
              TreeLinkNode *next;
            }
        Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
        Initially, all next pointers are set to NULL.

        Note:
        You may only use constant extra space.
        You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
        For example,
        Given the following perfect binary tree,
                 1
               /  \
              2    3
             / \  / \
            4  5  6  7
        After calling your function, the tree should look like:
                 1 -> NULL
               /  \
              2 -> 3 -> NULL
             / \  / \
            4->5->6->7 -> NULL
     */
     void connect(TreeLinkNode * root);

    /**
     * 117. Populating Next Right Pointers in Each Node II
     * 与116相比，给定的树不是full的
     * @param root
     */
    void connectII(TreeLinkNode * root);

    /**
     * 118. Pascal's Triangle
        Given numRows, generate the first numRows of Pascal's triangle.
        For example, given numRows = 5,
        Return

        [
             [1],
            [1,1],
           [1,2,1],
          [1,3,3,1],
         [1,4,6,4,1]
        ]
     * @param numRows
     * @return
     */
    vector<vector<int>> generate(int numRows);

    /**
     * 119. Pascal's Triangle II
        Given an index k, return the kth row of the Pascal's triangle.
        For example, given k = 3,
        Return [1,3,3,1].
        Note:
        Could you optimize your algorithm to use only O(k) extra space?
     * @param rowInde
     * @return
     */
    vector<int> getRow(int rowInde);

    /**
     * 120. Triangle
     * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
        For example, given the following triangle
        [
             [2],
            [3,4],
           [6,5,7],
          [4,1,8,3]
        ]
        The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

        Note:
        Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
     * @param triangle
     * @return
     */
    int minimumTotal(vector<vector<int>> & triangle);

    /**
     * 121. Best Time to Buy and Sell Stock
        Say you have an array for which the ith element is the price of a given stock on day i.
        If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

            Example 1:
            Input: [7, 1, 5, 3, 6, 4]
            Output: 5
            max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

            Example 2:
            Input: [7, 6, 4, 3, 1]
            Output: 0
            In this case, no transaction is done, i.e. max profit = 0.
     * @param prices
     * @return
     */
    int maxProfit(vector<int> & prices);

    /**
     * 122. Best Time to Buy and Sell Stock II
        Say you have an array for which the ith element is the price of a given stock on day i.
        Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie,
             buy one and sell one share of the stock multiple times).
             However, you may not engage in multiple transactions at the same time
             (ie, you must sell the stock before you buy again).
     * @param prices
     * @return
     */
    int maxProfitII(vector<int> & prices);

    /**
     * 123. Best Time to Buy and Sell Stock III
        Say you have an array for which the ith element is the price of a given stock on day i.
        Design an algorithm to find the maximum profit. You may complete at most two transactions.
        Note:
        You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
     * @param prices
     * @return
     */
    int maxProfitIII(vector<int> & prices);

    /**
     * 125. Valid Palindrome
        Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

        For example,
        "A man, a plan, a canal: Panama" is a palindrome.
        "race a car" is not a palindrome.

        Note:
        Have you consider that the string might be empty? This is a good question to ask during an interview.

        For the purpose of this problem, we define empty string as valid palindrome
     * @param s
     * @return
     */
    bool isPalindrome(string s);


    /**
     * 129. Sum Root to Leaf Numbers
     * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
        An example is the root-to-leaf path 1->2->3 which represents the number 123.
        Find the total sum of all root-to-leaf numbers.
        For example,
            1
           / \
          2   3
        The root-to-leaf path 1->2 represents the number 12.
        The root-to-leaf path 1->3 represents the number 13.
        Return the sum = 12 + 13 = 25.
     * @param root
     * @return
     */
    int sumNumbers(TreeNode * root);
    void dfsTraversal(TreeNode * root, std::stack<int> nodeStack, std::vector<int> & nums);
    int getIntFromStack(std::stack<int> nodeStack);

    /**
     * 134. Gas Station
     * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
        You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
        Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
        Note:
        The solution is guaranteed to be unique.
     * @param gas
     * @param cost
     * @return
     */
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) ;
    bool canCompleteCircuit(vector<int> &lastgas, int index);
    size_t increaseIndex(int index, int N);

    /**
     * 136. Single Number
     * Given an array of integers, every element appears twice except for one. Find that single one.
        Note:
        Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
     * @param nums
     * @return
     */
    int singleNumber(vector<int> & nums);

	/*
	137. Single Number II
     * Given an array of integers, every element appears three times except for one. Find that single one.
        Note:
        Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
	*/
	int singleNumberII(vector<int> & nums);

    /**
     * 144. Binary Tree Preorder Traversal
     * Given a binary tree, return the preorder traversal of its nodes' values.

        For example:
        Given binary tree {1,#,2,3},
           1
            \
             2
            /
           3
        return [1,2,3].

        Note: Recursive solution is trivial, could you do it iteratively?
     * @param root
     * @return
     */
    vector<int> preorderTraversal(TreeNode * root); // recursive
    vector<int> preorderTraversalIte(TreeNode * root); // iteratively

    /**
     * 145. Binary Tree Postorder Traversal
     * @param root
     * @return
     */
    vector<int> postorderTraversal(TreeNode * root);// iteratively

    /**
     * 147. Insertion Sort List
     *  sort a linked list using insertion sort.
     * @param head
     * @return
     */
    ListNode * insertionSortList(ListNode * head);

    /**
     * 142. Linked List Cycle II
     * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
        Note: Do not modify the linked list.
     * @param head
     * @return
     */
    ListNode * detectCycle(ListNode * head);

    /**
     * 155. Min Stack
     * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
        push(x) -- Push element x onto stack.
        pop() -- Removes the element on top of the stack.
        top() -- Get the top element.
        getMin() -- Retrieve the minimum element in the stack.
        Example:
        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        minStack.getMin();   --> Returns -3.
        minStack.pop();
        minStack.top();      --> Returns 0.
        minStack.getMin();   --> Returns -2.
     */
    class MinStack {
    private:
        stack<int> mainStack;
        stack<int> minStack;
    public:
        MinStack() {

        }
        void push(int x) {
            mainStack.push(x);
            if (minStack.empty()) {
                minStack.push(x);
            } else {
                int curMin = min(minStack.top(), x);
                minStack.push(curMin);
            }
        }
        void pop() {
            mainStack.pop();
            minStack.pop();
        }
        int top() {
            return mainStack.top();
        }
        int getMin() {
            return minStack.top();
        }
    };

    /**
     *160. Intersection of Two Linked Lists
     * Write a program to find the node at which the intersection of two singly linked lists begins.
    For example, the following two linked lists:

        A:          a1 → a2
                            ↘
                            c1 → c2 → c3
                            ↗
        B:     b1 → b2 → b3
        begin to intersect at node c1.
        Notes:

        If the two linked lists have no intersection at all, return null.
        The linked lists must retain their original structure after the function returns.
        You may assume there are no cycles anywhere in the entire linked structure.
        Your code should preferably run in O(n) time and use only O(1) memory.
     * @param headA
     * @param headB
     * @return
     */
    ListNode * getIntersectionNode (ListNode * headA, ListNode * headB);

    /**
     * 162. Find Peak Element
     * A peak element is an element that is greater than its neighbors.
        Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
        The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
        You may imagine that num[-1] = num[n] = -∞.
        For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
     * @param nums
     * @return
     */
    int findPeakElement(vector<int> & nums);
    int findPeakElement(vector<int> & nums, int l, int r);


    /**
     * 167. Two Sum II - Input array is sorted
     *Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
        The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
        You may assume that each input would have exactly one solution and you may not use the same element twice.
        Input: numbers={2, 7, 11, 15}, target=9
        Output: index1=1, index2=2
     * @param numbers
     * @param target
     * @return
     */
    vector<int> twoSum(vector<int> & numbers, int target);

    /**
     * 169. Majority Element
     * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
    You may assume that the array is non-empty and the majority element always exist in the array.
     * @param nums
     * @return
     */
    int majorityELement(vector<int> & nums);

    /*
     * 179. Largest Number
     * Given a list of non negative integers, arrange them such that they form the largest number.
        For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
        Note: The result may be very large, so you need to return a string instead of an integer.
     */
    string largestNumber(vector<int> & nums);
//    static   bool lowerStrInLargestNumber(const string & a, const string & b);
    /**
     * 191. Number of 1 Bits
     *Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
        For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
     * @param n
     * @return
     */
    int hammingWeight(uint32_t n);

	/*
	231. Power Of Two 
	Given an integer, write a function to determine if it is a power of two.
	*/
	bool isPowerOfTwo(int n);

	/*
	316. Remove Duplicate Letters
	Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
	Example:
		Given "bcabc"
		Return "abc"

		Given "cbacdcbc"
		Return "acdb"
	*/
	string removeDuplicateLetters(string s);
    /**
     * 318. Maximum Product of Word Lengths
     * Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
        Example 1:
        Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
        Return 16
        The two words can be "abcw", "xtfn".
        Example 2:
        Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
        Return 4
        The two words can be "ab", "cd".
        Example 3:
        Given ["a", "aa", "aaa", "aaaa"]
        Return 0
        No such pair of words.
     * @param words
     * @return
     */
    int maxProduct(vector<string> & words);

	/**
	329. Longest Increasing Path in a Matrix
	Given an integer matrix, find the length of the longest increasing path.
	From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
	Example 1:
	nums = [
		[9,9,4],
		[6,6,8],
		[2,1,1]
	]
	Return 4
	The longest increasing path is [1, 2, 6, 9].
	Example 2:
	nums = [
		[3,4,5],
		[3,2,6],
		[2,2,1]
	]
	Return 4
	The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
	*/
	int longestIncreasingPath(vector<vector<int>> & matrix);

	/**
	354. Russian Doll Envelopes
	You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
	What is the maximum number of envelopes can you Russian doll? (put one inside other)
	Example:
		Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
	*/
	int maxEnvelopes(vector<pair<int, int>> & envelopes);

	/*388. Longest Absolute File Path
	Suppose we abstract our file system by a string in the following manner:
		The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
		dir
			subdir1
			subdir2
				file.ext
		The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
		The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
		dir
			subdir1
				file1.ext
				subsubdir1
			subdir2
				subsubdir2
					file2.ext
		The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.
		We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).
		Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.
		Note:
		The name of a file contains at least a . and an extension.
		The name of a directory or sub-directory will not contain a ..
		Time complexity required: O(n) where n is the size of the input string.
		Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.	
	*/
	int lengthLongestPath(string input);// build a tree and compute the longest length recursively
	int lengthLongestPath2(string input); // compute the longest length in a iterative way

	/** 393. UTF-8 Validation
			A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
	For 1-byte character, the first bit is a 0, followed by its unicode code.
	For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
	This is how the UTF-8 encoding would work:

	   Char. number range  |        UTF-8 octet sequence
		  (hexadecimal)    |              (binary)
	   --------------------+---------------------------------------------
	   0000 0000-0000 007F | 0xxxxxxx
	   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
	   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
	   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
	Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

	Note:
	The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

	Example 1:

	data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

	Return true.
	It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
	Example 2:

	data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

	Return false.
	The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
	The next byte is a continuation byte which starts with 10 and that's correct.
	But the second continuation byte does not start with 10, so it is invalid.
	*/
	bool validUtf8(vector<int>& data);

	/* 424.  Longest Repeating Character Replacement
	Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.
	Note:
	Both the string's length and k will not exceed 104.
	Example 1:
	Input:
	s = "ABAB", k = 2
	Output:
	4
	Explanation:
	Replace the two 'A's with two 'B's or vice versa.
	Example 2:
	Input:
	s = "AABABBA", k = 1
	Output:
	4
	Explanation:
	Replace the one 'A' in the middle with 'B' and form "AABBBBA".
	The substring "BBBB" has the longest repeating letters, which is 4.
	*/
	int characterReplacement(string s, int k);

	/*
	474. Ones and Zeros
	In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.
	For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.
	Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.
	Note:
	The given numbers of 0s and 1s will both not exceed 100
	The size of given string array won't exceed 600.
	Example 1:
		Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
		Output: 4
		Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
	Example 2:
		Input: Array = {"10", "0", "1"}, m = 1, n = 1
		Output: 2
		Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".
	*/
	int findMaxForm(vector<string> & strs, int m, int n);

	/*
	477. Total Hamming Distance
	The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
	Now your job is to find the total Hamming distance between all pairs of the given numbers.
	Example:
		Input: 4, 14, 2
		Output: 6
		Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
		showing the four bits relevant in this case). So the answer will be:
		HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
	Note:
		Elements of the given array are in the range of 0 to 10^9
		Length of the array will not exceed 10^4.
	*/
	int totalHammingDistance(vector<int>& nums);

	/*	482. License Key Formatting
		Now you are given a string S, which represents a software license key which we would like to format. The string S is composed of alphanumerical characters and dashes. The dashes split the alphanumerical characters within the string into groups. (i.e. if there are M dashes, the string is split into M+1 groups). The dashes in the given string are possibly misplaced.
		We want each group of characters to be of length K (except for possibly the first group, which could be shorter, but still must contain at least one character). To satisfy this requirement, we will reinsert dashes. Additionally, all the lower case letters in the string must be converted to upper case.
		So, you are given a non-empty string S, representing a license key to format, and an integer K. And you need to return the license key formatted according to the description above.
		Example 1:
		Input: S = "2-4A0r7-4k", K = 4
		Output: "24A0-R74K"
		Explanation: The string S has been split into two parts, each part has 4 characters.
		Example 2:
		Input: S = "2-4A0r7-4k", K = 3
		Output: "24-A0R-74K"
		Explanation: The string S has been split into three parts, each part has 3 characters except the first part as it could be shorter as said above.
		Note:
		The length of string S will not exceed 12,000, and K is a positive integer.
		String S consists only of alphanumerical characters (a-z and/or A-Z and/or 0-9) and dashes(-).
		String S is non-empty.
	*/
	string licenseKeyFormating(string S, int K);

    /*
     * 486. Predict the Winner
     * Given an array of scores that are non-negative integers. Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. Each time a player picks a number, that number will not be available for the next player. This continues until all the scores have been chosen. The player with the maximum score wins.
        Given an array of scores, predict whether player 1 is the winner. You can assume each player plays to maximize his score.
        Example 1:
            Input: [1, 5, 2]
            Output: False
            Explanation: Initially, player 1 can choose between 1 and 2.
            If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).
            So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
            Hence, player 1 will never be the winner and you need to return False.
        Example 2:
            Input: [1, 5, 233, 7]
            Output: True
            Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
            Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.
            Note:
            1 <= length of the array <= 20.
        Any scores in the given array are non-negative integers and will not exceed 10,000,000.
        If the scores of both players are equal, then player 1 is still the winner.
     */
    bool PredictTheWinner(vector<int> & nums);

    /**
     * 493. Reverse Pairsven an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
        You need to return the number of important reverse pairs in the given array.
        Example1:
        Input: [1,3,2,3,1]
        Output: 2
        Example2:
        Input: [2,4,3,5,1]
        Output: 3
        Note:
        The length of the given array will not exceed 50,000.
        All the numbers in the input array are in the range of 32-bit integer.
     * @param nums
     * @return
     */
    int reversePairs(vector<int> & nums);
    int reversePairs(vector<int> & nums, int start, int end);
    int mergePairs(vector<int> & nums, int s1, int e1, int s2, int e2);

    /*
     * 494. Target Sum
     * You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
        Find out how many ways to assign symbols to make sum of integers equal to target S.
        Example 1:
            Input: nums is [1, 1, 1, 1, 1], S is 3.
            Output: 5
            Explanation:
            -1+1+1+1+1 = 3
            +1-1+1+1+1 = 3
            +1+1-1+1+1 = 3
            +1+1+1-1+1 = 3
            +1+1+1+1-1 = 3
            There are 5 ways to assign symbols to make the sum of nums be target 3.
        Note:
        The length of the given array is positive and will not exceed 20.
        The sum of elements in the given array will not exceed 1000.
        Your output answer is guaranteed to be fitted in a 32-bit integer.
     */
       int findTargetSumWays(vector<int>& nums, int S) ;

    /**
     * 507. Perfect Number
     * We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.
        Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
        Example:
        Input: 28
        Output: True
        Explanation: 28 = 1 + 2 + 4 + 7 + 14
        Note: The input number n will not exceed 100,000,000. (1e8)
     * @param num
     * @return
     */
    bool checkPerfectNumber(int num);

    /**
     * 537. Complex Number Multiply
     * Given two strings representing two complex numbers.
        You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
        Example 1:
        Input: "1+1i", "1+1i"
        Output: "0+2i"
        Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
        Example 2:
        Input: "1+-1i", "1+-1i"
        Output: "0+-2i"
        Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
        Note:

        The input strings will not have extra blank.
        The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
     * @param a
     * @param b
     * @return
     */
    string complexNumberMultiply(string a, string b);

    /**
     * 538. Convert BST to Greater Tree
     * Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
        Example:
        Input: The root of a Binary Search Tree like this:
                      5
                    /   \
                   2     13
        Output: The root of a Greater Tree like this:
                     18
                    /   \
                  20     13
     * @param root
     * @return
     */
    TreeNode * convertBST(TreeNode * root);

    /**
     * 542. 01 Matrix
     * Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
        The distance between two adjacent cells is 1.
        Example 1:
        Input:
        0 0 0
        0 1 0
        0 0 0
        Output:
        0 0 0
        0 1 0
        0 0 0
        Example 2:
        Input:
        0 0 0
        0 1 0
        1 1 1
        Output:
        0 0 0
        0 1 0
        1 2 1
     * @param matrix
     * @return
     */
    vector<vector<int>> updateMatrix(vector<vector<int>> & matrix) ;
    void updateMatrix(vector<vector<int>> & matrix, int rows, int cols) ;


    /**543. Diameter of Binary Tree
     * Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
        Example:
        Given a binary tree
                  1
                 / \
                2   3
               / \
              4   5
        Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
        Note: The length of path between two nodes is represented by the number of edges between them.
     * @param root
     * @return
     */
    int diameterOfBinaryTree(TreeNode * root);

    /**
     * 545. Boundary Of Binary Tree
        Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.
        Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.
        The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.
        The right-most node is also defined by the same way with left and right exchanged.
        Example 1
        Input:
          1
           \
            2
           / \
          3   4
        Ouput:
        [1, 3, 4, 2]
        Explanation:
        The root doesn't have left subtree, so the root itself is left boundary.
        The leaves are node 3 and 4.
        The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
        So order them in anti-clockwise without duplicates and we have [1,3,4,2].
        Example 2
        Input:
            ____1_____
           /          \
          2            3
         / \          /
        4   5        6
           / \      / \
          7   8    9  10

        Ouput:
        [1,2,4,7,8,9,10,6,3]
        Explanation:
        The left boundary are node 1,2,4. (4 is the left-most node according to definition)
        The leaves are node 4,7,8,9,10.
        The right boundary are node 1,3,6,10. (10 is the right-most node).
        So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].     * @param root
     * @return
     */
    vector<int> boundaryOfBinaryTree(TreeNode * root);

    /**
     * 549. Binary Tree Longest Consecutive Sequence II
     * Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.
        Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.
        Example 1:
        Input:
                1
               / \
              2   3
        Output: 2
        Explanation: The longest consecutive path is [1, 2] or [2, 1].
        Example 2:
        Input:
                2
               / \
              1   3
        Output: 3
        Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
     * @param root
     * @return
     */
    int longestConsecutive(TreeNode * root);
	int longestConsecutive(TreeNode * node, map<TreeNode *, vector<TreeNode *>> &);

    /**
     * 554. Brick Wall
     * There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks.
        The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right.
        If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks.
        You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.
        Example:
        Input:
        [[1,2,2,1],
         [3,1,2],
         [1,3,2],
         [2,4],
         [3,1,2],
         [1,3,1,1]]
        Output: 2
        Explanation:

        Note:
        The width sum of bricks in different rows are the same and won't exceed INT_MAX.
        The number of bricks in each row is in range [1,10,000]. The height of wall is in range [1,10,000]. Total number of bricks of the wall won't exceed 20,000.
     * @param wall
     * @return
     */
    int leastBricks(vector<vector<int>> & wall);

    /**
     * 556. Next Greater Element III
     * Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.
        Example 1:
        Input: 12
        Output: 21
        Example 2:
        Input: 21
        Output: -1
     * @param n
     * @return
     */
    int nextGreaterElement(int n);

    /**
     * 557. Reverse Words in a String III
     *Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
        Example 1:
        Input: "Let's take LeetCode contest"
        Output: "s'teL ekat edoCteeL tsetnoc"
        Note: In the string, each word is separated by single space and there will not be any extra space in the string.
     * @param s
     * @return
     */
    string reverseWords(string s) ;

    /*
     * 572. Subtree of Another Tree
     * Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
        Example 1:
        Given tree s:
             3
            / \
           4   5
          / \
         1   2
        Given tree t:
           4
          / \
         1   2
        Return true, because t has the same structure and node values with a subtree of s.

        Example 2:
        Given tree s:
             3
            / \
           4   5
          / \
         1   2
            /
           0
        Given tree t:
           4
          / \
         1   2
        Return false.
     */
    bool isSubtree(TreeNode * s, TreeNode * t);

    /*
     * 575. Distribute Candies
     * Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.
        Example 1:
        Input: candies = [1,1,2,2,3,3]
        Output: 3
        Explanation:
        There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
        Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too.
        The sister has three different kinds of candies.
        Example 2:
        Input: candies = [1,1,2,3]
        Output: 2
        Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1].
        The sister has two different kinds of candies, the brother has only one kind of candies.
        Note:

        The length of the given array is in range [2, 10,000], and will be even.
        The number in given array is in range [-100,000, 100,000].
     */
    int distributeCandies(vector<int> & candies) ;

    /*
     * 576. Out of Boundary Paths
     * There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

        Example 1:
        Input:m = 2, n = 2, N = 2, i = 0, j = 0
        Output: 6
        Explanation:

        Example 2:
        Input:m = 1, n = 3, N = 3, i = 0, j = 1
        Output: 12
        Explanation:

        Note:
        Once you move the ball out of boundary, you cannot move it back.
        The length and height of the grid is in range [1,50].
        N is in range [0,50].
     */
    int findPaths(int m, int n, int N, int i, int j) ;

    /*
     * 581.  Shortest Unsorted Continuous Subarray
     * Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:

Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:

    Then length of the input array is in range [1, 10,000].
    The input array may contain duplicates, so ascending order here means <=.

     */
    int findUnsortedSubarray(vector<int> & nums);

    /*
     * 582. Kill Process
     * Given n processes, each process has a unique PID (process id) and its PPID (parent process id).

        Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.

        We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains the corresponding PPID.

        Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.

        Example 1:

        Input:
        pid =  [1, 3, 10, 5]
        ppid = [3, 0, 5, 3]
        kill = 5
        Output: [5,10]
        Explanation:
                   3
                 /   \
                1     5
                     /
                    10
        Kill 5 will also kill 10.

        Note:

            1. The given kill id is guaranteed to be one of the given PIDs.
            2. n >= 1.

     */
    vector<int> killProcess(vector<int> & pid, vector<int> & ppid, int kill);

    /*
     * 583. Delete Operation for Two Strings
     *  Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

    Example 1:

    Input: "sea", "eat"
    Output: 2
    Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

    Note:

        The length of given words won't exceed 500.
        Characters in given words can only be lower-case letters.
     */
    int minDistance583(string word1, string word2);

	/*
	587. Erect the Fence
	There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.

	Example 1:
	Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
	Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
	Explanation:

	Example 2:
	Input: [[1,2],[2,2],[4,2]]
	Output: [[1,2],[2,2],[4,2]]
	Explanation:

	Even you only have trees in a line, you need to use rope to enclose them. 
	Note:

	All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
	All input integers will range from 0 to 100.
	The garden has at least one tree.
	All coordinates are distinct.
	Input points have NO order. No order required for output.
	*/
vector<Point> outerTrees(vector<Point> & points);


    int maxRotateFunction(vector<int> &);
};





#endif //LEETCODE_SOLUTION_H
