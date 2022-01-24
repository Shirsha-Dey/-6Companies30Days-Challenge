#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};
struct Node *start = NULL;
void printList(struct Node *node){
    while (node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void insert(int n1){
    int n, value;
    n = n1;
    struct Node *temp;

    for (int i = 0; i < n; i++){
        cin >> value;
        if (i == 0){
            start = new Node(value);
            temp = start;
            continue;
        }
        else{
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

class Solution15{
public:
    void linkdelete(struct Node  *head, int m, int n){

        Node * temp = head;
        Node *temp2 = temp;
        int count = 1;
        if (m == 0){
            return;
        }

        while (temp2 != NULL && temp != NULL){
            while (count != m && temp != NULL){
                temp = temp -> next;
                count++;
            }
            if (temp == NULL){
                break;
            }
            count = 0;
            int count2 = 0;
            temp2 = temp;
            while (count2 != n && temp2 != NULL){
                temp2 = temp2 -> next;
                count2++;
            }
            if (temp2 == NULL) temp->next = temp2;
            count2 = 0;
            if (temp2 != NULL)
                temp -> next = temp2-> next;
            temp2 = temp -> next;
        }
    }
};

int main(){
    int t, n1;
    cin >> t;
    while (t--) {
        cin >> n1;
        int m, n;
        cin >> m;
        cin >> n;
        insert(n1);
        Solution15 obj1;
        obj1.linkdelete(start, m, n);
        printList(start);
    }

    return 0;
}