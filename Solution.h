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
     * 计算最长公共前缀
     * @param strs 要计算的各string组成的vector
     * @return 公共前缀，如果没有公共前缀时返回 ""
     */
    string longestCommonPrefix(vector<string> & strs);

    /**
     * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
     * 从小到大排列
     * @param l1 sorted linked list
     * @param l2 sorted linked list
     * @return merged list
     */
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2);

    /**
     * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
     * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
     * @param s
     * @return
     */
    bool isValid(string s);

    /**
     * Given a linked list, swap every two adjacent nodes and return its head.
     * For example,Given 1->2->3->4, you should return the list as 2->1->4->3.
     * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
     */
    ListNode * swapPairs(ListNode * head);

    /**
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
     * Given an array and a value, remove all instances of that value in place and return the new length.
     * Do not allocate extra space for another array, you must do this in place with constant memory.
     * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
     * Example:
     * Given input array nums = [3,2,2,3], val = 3
     * Your function should return length = 2, with the first two elements of nums being 2.
     */
    int removeElement(vector<int> & nums, int val);

    /**
     * Determine whether an integer is a palindrome. Do this without extra space.
     */
    bool isPalindrome(int x) ;

    /**
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
     * Given a string, find the length of the longest substring without repeating characters.
     * Examples:
     * Given "abcabcbb", the answer is "abc", which the length is 3.
     * Given "bbbbb", the answer is "b", with the length of 1.
     * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
     * @param s
     * @return
     */
    size_t lengthOfLongestSubstring(string s);

    /**
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

    /**
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
     * Implement strStr().
     * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
     * 返回haystack中needle子串的位置
     * @param haystack
     * @param needle
     * @return
     */
    int strStr(string haystack, string needle);

    /**
     * Determine if a Sudoku is valid.
     * The Sudoku board could be partially filled, where empty cells are filled with the character '.' .
     * Note:
     * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
     * @param bord
     * @return
     */
    bool isValidSudoku(vector<vector<char>> & bord);

    /**
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
     * You are given an n x n 2D matrix representing an image.
     * Rotate the image by 90 degrees (clockwise).
     * Follow up:
     * Could you do this in-place?
     * @param matrix
     */
    void rotate(vector<vector<int>> & matrix);

    /**
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
     * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
     * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
     * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
       Note: You may not slant the container.
     * @param height
     * @return
     */
    int maxArea(vector<int> & height);

    /**
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
     * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
        For example, given array S = {-1 2 1 -4}, and target = 1.
        The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
     * @param nums
     * @param target
     * @return
     */
    int threeSumClosest(vector<int>& nums, int target);

    /**
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
     * 二分查找
     * @param nums
     * @param target
     * @return
     */
    int binarySearch(vector<int> & nums, int target);

    /**
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

    /**
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
     *
    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
        For example,
        Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
     * @param height
     * @return
     */
    int trap(vector<int>& height);

    /**
     *  Write a program to solve a Sudoku puzzle by filling the empty cells.
        Empty cells are indicated by the character '.'.
     * @param board
     */
    void solveSudoku(vector<vector<char>>& board);
    bool solveSudoku(vector<vector<char>> &board, int i, int j);
    bool isValidSudoku(vector<vector<char>> & board, int i, int j, char c);

    /**
     * Given a non-negative number represented as an array of digits, plus one to the number.
     * The digits are stored such that the most significant digit is at the head of the list.@param digits
     * @return
     */
    vector<int> plusOne(vector<int> & digits);

    /**
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
     * 23. Merge k Sorted Lists
        Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
     * @param lists
     * @return
     */
    ListNode * mergeKLists(vector<ListNode*> & lists) ;
    ListNode * mergeTwoList(ListNode * l1, ListNode * l2);

    /**
     * 50. Pow(x, n)
     * Implement pow(x, n).
     * @param x
     * @param n
     * @return
     */
    double myPow(double x, int n);

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
};



#endif //LEETCODE_SOLUTION_H
