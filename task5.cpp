// Implement DeleteNode(int delData) to remove only the first node containing the requested value. 
// Handle an empty list, deletion of the first, middle, or last node, a missing value, and deletion of the only node. 
// Reconnect the remaining nodes before releasing the removed node. Test each case; for 10, 20, 20, 30, 
// deleting 20 once must leave 10, 20, 30. Display the list after each deletion.

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
        void DeleteNode(int delData);
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

void List::DeleteNode(int delData)
{
    node* delptr = NULL;

    // Start searching from the first node
    temp = head;
    curr= head;

    // Search for the first node containing the requested value
    while(curr!=nullptr && curr->data!=delData)
    {
        temp = curr;
        curr = curr->next;
    }

    // Value was not found or the list was empty
    if(curr == nullptr)
    {
        cout<<"Element not found"<<endl;
    }

    // The node to delete is the first node
    else if(curr == head)
    {
        delptr = head;
        head = head->next;

        // Delete the old first node
        delete delptr;
        delptr = nullptr;

        cout << "Element deleted successfully" << endl;
    }
    else
    {
        // Connect the previous node to the node after the one being deleted
        delptr = curr;
        temp->next = curr->next;

        // Delete the requested node
        delete delptr;
        delptr = nullptr;

        cout << "Element deleted successfully" << endl;
    }
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
    myList.DeleteNode(5);

    // build 10, 20, 20, 30
    myList.AddNode(10);
    myList.AddNode(20);
    myList.AddNode(20);
    myList.AddNode(30);
    myList.PrintList();

    myList.DeleteNode(20);   // delete first matching 20 -> 10, 20, 30
    myList.PrintList();

    myList.DeleteNode(10);   // delete first node -> 20, 30
    myList.PrintList();

    myList.DeleteNode(30);   // delete last node -> 20
    myList.PrintList();

    myList.DeleteNode(99);   // missing value
    myList.PrintList();

    myList.DeleteNode(20);   // delete the only remaining node -> empty
    myList.PrintList();

    myList.ClearList();
    
}