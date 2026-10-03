// Implement InsertAtBeginning(int addData). Allocate a node, connect it to the current first node, 
// and update head. Keep AddNode() available for insertion at the end. Starting with an empty list, 
// insert 20 at the beginning, then 10 at the beginning, and finally append 30. Display the list after each operation. 
// The final order must be 10, 20, 30.
// Functions to retain: AddNode(), InsertAtBeginning(), PrintList(), and ClearList().

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
        void InsertAtBeginning(int addData);
        void PrintList();
        void ClearList();
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

void List::InsertAtBeginning(int addData)
{
    // Create a new node and store the given data
    node* n = new node;
    n->data = addData;

    // Connect the new node to the current first node
    n->next = head;

    // Make the new node the first node
    head = n;
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
    myList.InsertAtBeginning(20);   // [20]
    myList.PrintList();

    myList.InsertAtBeginning(10);   // [10, 20]
    myList.PrintList();

    myList.AddNode(30);             // [10, 20, 30]
    myList.PrintList();

    // delete all nodes and free memory
    myList.ClearList();
}