#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *sortList(ListNode *head) // Time : O(n^2) , Space : O(1)
{
    if (head == NULL)
        return NULL;
    ListNode *first = head->next, *sec = head;
    while (sec->next != NULL)
    {
        while (first != NULL)
        {
            if (sec->val >= first->val)
            {
                int t = sec->val;
                sec->val = first->val;
                first->val = t;
            }
            first = first->next;
        }
        sec = sec->next;
        first = sec->next;
    }
    return head;
}
void viewlist(ListNode *head) // here head is a local variable //time : O(n) , space : none
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    ListNode *n = new ListNode(20);
    n->next = new ListNode(45);
    n->next->next = new ListNode(56);
    n->next->next->next = new ListNode(23);
    n->next->next->next->next = new ListNode(67);
    n->next->next->next->next->next = new ListNode(14);
    viewlist(n);
    sortList(n);
    viewlist(n);
    return 0;
}