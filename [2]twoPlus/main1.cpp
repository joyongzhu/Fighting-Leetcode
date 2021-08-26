/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <vector>
#include <iostream>
#include <stdlib.h>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        else if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;

        // 余数
        int remainder = 0;
        ListNode* result = l2;

        int i = 0;
        while (true) {
            i = 0;
            if (l1 && l2) {
                i = (remainder + l1->val + l2->val) % 10;
                if (remainder + l1->val + l2->val >= 10) {
                    remainder = 1;
                }
                else {
                    remainder = 0;
                }
                l2->val = i;

                if (l1->next && l2->next) {
                    l1 = l1->next;
                    l2 = l2->next;
                    continue;
                }
                else if (l1->next) {
                    l2->next = l1->next;
                    l2 = l1->next;
                    l1 = NULL;
                    continue;
                }
                else if (l2->next) {
                    l1 = NULL;
                    l2 = l2->next;
                    continue;
                }
                else {
                    if (remainder) {
                        l2->next = new ListNode;
                        l2->next->next = NULL;
                        l2->next->val = 1;
                    }
                    return result;
                }
            }
            else if (l1) {
                return result;
            }
            else if (l2) {
                if (remainder == 0) {
                    return result;
                }
                else {
                    i = (remainder + l2->val) % 10;
                    if (remainder + l2->val >= 10) {
                        remainder = 1;
                    }
                    else {
                        remainder = 0;
                    }
                    l2->val = i;
                }

                l1 = NULL;
                if (l2->next) {
                    l2 = l2->next;
                    continue;
                }
                else {
                    if (remainder) {
                        l2->next = new ListNode;
                        l2->next->next = NULL;
                        l2->next->val = 1;
                    }
                    return result;
                }
            }
            else {
                return result;
            }
        } //!while
    }
};
// @lc code=end
