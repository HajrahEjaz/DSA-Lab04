// Implement SearchNode(int searchData) to display the position of the first matching value, 
// counting the first node as position 1. Print "Value not found" when there is no match. 
// Also implement PrintSecondNode() to display only the second node, or a suitable message if fewer than two nodes exist. 
// Test an empty list, a one-node list, and the list 10, 20, 30, 20. Search for 20 and 99; 
// the results should be position 2 and not found.

#include<iostream>
using namespace std;
// Defining List class
class List
{
    private:
        // defining node structure
        struct node
        {
            int data;
            node* next;
        };
        node* head;
        node* curr;
        node* temp;
    
    public:
        List();
        void AddNode(int addData);
        void PrintList();
        void ClearList();
        void SearchNode(int searchData);
        void PrintSecondNode();
};

List::List()
{
    // Initialize all pointers to nullptr for an empty list
    head = nullptr;
    curr = nullptr;
    temp = nullptr;
}

void List::AddNode(int addData)
{
    // Create a new node and set its next to nullptr
    node* n = new node;
    n->data = addData;
    n->next = nullptr;

    // Add the node at the end of the list
    if(head!= nullptr)
    {
        curr=head;
        while(curr->next!=nullptr)
        {
            curr = curr->next;
        }
        curr->next = n;
    } 
    else
    {
        head = n;
    }   
}

void List::SearchNode(int searchData)
{
    curr = head;
    int position = 1;

    // Search the list while keeping track of the position
    while(curr!=nullptr && curr->data!=searchData)
    {
        curr = curr->next;
        position++;
    }

    if (curr!=nullptr && curr->data == searchData)
    {
        cout<<"Value found at position "<<position<<endl;
    }
    else
    {
        cout<<"Value not found"<<endl;
    }
}

void List::PrintSecondNode()
{
    // check if the list is empty
    if(head == nullptr)
    {
        cout<<"The list is empty."<<endl;
        return;
    }

    // Check if the list has fewer than two nodes
    if(head->next == nullptr)
    {
        cout<<"Only 1 node in the list."<<endl;
        return;
    }

    temp = head->next;
    cout<<"Second node: "<<temp->data<<endl;
}

void List::PrintList()
{
    
    curr = head;

    // display message if list is empty
    if (head == nullptr)
    {
        cout << "The list is empty." << endl;
        return;
    }

    // traverse and print all nodes
    while(curr!=nullptr)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;

}
void List::ClearList()
{
    curr = head;
    // delete all nodes to free memory
    while (curr != nullptr)
    {
        temp = curr->next;   // save the link before deleting
        delete curr;
        curr = temp;
    }
    cout<<"List deleted."<<endl;
    head = nullptr;
}
int main()
{
   List myList;

    // empty list
    myList.SearchNode(20);
    myList.PrintSecondNode();

    // one-node list
    myList.AddNode(10);
    myList.PrintSecondNode();

    // adding 10, 20, 30, 20
    myList.AddNode(20);
    myList.AddNode(30);
    myList.AddNode(20);
    myList.PrintList();

    myList.SearchNode(20);   // position 2
    myList.SearchNode(99);   // not found
    myList.PrintSecondNode();

    myList.ClearList();
}