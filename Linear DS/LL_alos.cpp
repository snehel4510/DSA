#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};
ListNode *head = NULL;

// to reverse a linked list
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *current = head;
    ListNode *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

// swap nodes in pairs
ListNode *swapPairs(ListNode *head)
{
    ListNode *ptr = head;
    if (head == NULL)
    {
        return NULL;
    }
    while (ptr != NULL && ptr->next != NULL)
    {

        swap(ptr->val, ptr->next->val);

        ptr = ptr->next->next;
    }
    return head;
}

// merge 2 sorted lists
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    // iterative
    // ListNode *l1 = list1;
    // ListNode *l2 = list2;
    // ListNode *head = NULL;
    // ListNode *ptr = head;
    // while(l1!=NULL and l2!=NULL)
    // {
    //     if(l1->val<=l2->val)
    //     {
    //         if(ptr==NULL)
    //         {
    //             ptr = l1;
    //             head = ptr;
    //         }
    //         else
    //         {
    //             ptr->next = l1;
    //             ptr = l1;
    //         }
    //         l1 = l1->next;
    //     }
    //     else
    //     {
    //         if(ptr==NULL)
    //         {
    //             ptr = l2;
    //             head = ptr;
    //         }
    //         else
    //         {
    //             ptr->next = l2;
    //             ptr = l2;
    //         }
    //         l2 = l2->next;
    //     }
    // }
    // while(l1!=NULL)
    // {
    //     if(ptr==NULL)
    //         {
    //             ptr = l1;
    //             head = ptr;
    //         }
    //         else
    //         {
    //             ptr->next = l1;
    //             ptr = l1;
    //         }
    //         l1 = l1->next;
    // }
    // while(l2!=NULL)
    // {
    //     if(ptr==NULL)
    //         {
    //             ptr = l2;
    //             head = ptr;
    //         }
    //         else
    //         {
    //             ptr->next = l2;
    //             ptr = l2;
    //         }
    //         l2 = l2->next;
    // }
    // return head;

    // recursive
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

int main()
{
    return 0;
}