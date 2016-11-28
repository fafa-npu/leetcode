//
// Created by fa－apple on 2016/11/26.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H
#include <string>

#include <iostream>
#include <vector>
#include <set>
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
};


#endif //LEETCODE_SOLUTION_H
