//
// Created by fa－apple on 2016/11/26.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

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


};



#endif //LEETCODE_SOLUTION_H
