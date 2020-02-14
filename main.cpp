// Ruben Navarro
// 02/14/2020
// Determines if a linked list has a cycle

#include <iostream>
#include <algorithm>
#include <map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };

// displays list
void printList( ListNode * head )
{
    int i = 0;
    while( i < 5 ) {
        std::cout << head->val << "-->";
        head = head->next;
        ++i;
    }
}

int main()
{
    // constructs list
    ListNode * head = new ListNode(3);
    ListNode * newNode1 = new ListNode(2);
    ListNode * newNode2 = new ListNode(0);
    ListNode * newNode3 = new ListNode(4);

    head->next = newNode1;
    newNode1->next = newNode2;
    newNode2->next = newNode3;
    newNode3->next = head;

    std::cout << "Current List:\n";
    printList( head );

    ListNode * curr = head;

    // map to hold listnode pointers
    std::map<int, ListNode*>mymap;

    // iterator to traverse through map of list node pointers
    auto it = mymap.begin();

    mymap[0] = head;
    int i = 1;

    // traverses through the list comparing pointers to find the cycle point
    while (curr != NULL) {
        for (; it != mymap.end(); ++it) {
            if (it->second == curr) {
                std::cout << "Found\n";
                break;
            }
        }

        if (it != mymap.end()) {
            std::cout << "True!\n";
            return 0;
        }
        else if (it == mymap.end()) {
            mymap[i] = curr;
            curr = curr->next;
        }
        it = mymap.begin();
        ++i;
    }
    std::cout << "False!\n";
    return 0;
}