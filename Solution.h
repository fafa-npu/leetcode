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
};



#endif //LEETCODE_SOLUTION_H
