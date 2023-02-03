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

ListNode* mergeTwoLists(ListNode *list1,ListNode *list2) {
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

ListNode *mergeKLists(ListNode *arr[],int k) 
{
    ListNode *head = arr[0];
    for(int i=1;i<k;i++) head = mergeTwoLists(head,arr[i]);
    return head;
}

int main() {
    int N; cin >> N;
    struct ListNode *arr[N];
    for(int j=0;j<N;j++) {
        int n; cin >> n;
        int x; cin >> x;
        arr[j] = new ListNode(x);
        ListNode *curr = arr[j];
        n--;
        for(int i=0;i<n;i++) {
            cin >>x;
            ListNode *temp = new ListNode(x);
            curr -> next = temp;
            curr = temp;
        }
    }
    ListNode *res = mergeKLists(arr,N);
    printList(res);
    return 0;
}
