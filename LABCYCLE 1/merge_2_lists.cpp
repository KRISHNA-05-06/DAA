#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

void printList(ListNode *ksks) {
    while(ksks) {
        cout << ksks -> val << " ";
        ksks = ksks -> next;
    }
    cout << endl;
}

ListNode *mergeTwoLists(ListNode* list1,ListNode* list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    ListNode *ptr;
    if(list1 -> val > list2 -> val) {
        ptr = list2;
        list2 = list2 -> next;
    }
    else {
        ptr = list1;
        list1 = list1 -> next;
    }
    ListNode *curr=ptr;

    while(list1 && list2) {
        if(list1 -> val > list2 -> val) {
            curr -> next = list2;
            list2 = list2 -> next;
        }
        else {
            curr -> next = list1;
            list1 = list1 -> next;
        }
        curr = curr -> next;
    }
    if(list1) {
        curr -> next = list1;
    }
    if(list2) {
        curr -> next = list2;
    }
    return ptr;
}

int main() {
    ListNode *list1 = new ListNode(1);
    list1 -> next = new ListNode(2);
    list1 -> next -> next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2 -> next = new ListNode(3);
    list2 -> next -> next = new ListNode(4);

    ListNode *ans1 = mergeTwoLists(list1,list2);
    printList(ans1);
    return 0;
}
