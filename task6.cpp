// Combine your functions in one menu-driven program with options to insert at the beginning, 
// insert at the end, search by value, delete by value, display all nodes, count nodes, display the second node, and exit. 
// Start with an empty list. Repeat the menu until Exit is selected, handle invalid menu choices, and release all remaining nodes before exiting. 
// Reuse the functions developed in Tasks 1–5; CreateThreeNodes() is not needed here.
// Check the menu with an empty list, several insertions, duplicate values, a missing search value, deletion until empty, and exit while nodes remain. 

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
        void SearchNode(int searchData);
        void DeleteNode(int delData);
        void PrintList();
        void CountNodes();
        void PrintSecondNode();
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

void List::CountNodes()
{
     int count = 0;
    curr = head;

    // traverse the entire list and count each node
    while(curr!=nullptr)
    {
        count++;
        curr = curr->next;
    }
    cout<<"Number of nodes in the list: "<<count<<endl;
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
    int choice, value;

    //displaying the menu until the user chooses Exit
    do
    {
        cout<<"\n--- Linked List Menu ---"<<endl;
        cout<<"1. Insert at beginning"<<endl;
        cout<<"2. Insert at end"<<endl;
        cout<<"3. Search by value"<<endl;
        cout<<"4. Delete by value"<<endl;
        cout<<"5. Display all nodes"<<endl;
        cout<<"6. Count nodes"<<endl;
        cout<<"7. Display second node"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                myList.InsertAtBeginning(value);
                break;
            case 2:
                cout<<"Enter value: ";
                cin>>value;
                myList.AddNode(value);
                break;
            case 3:
                cout<<"Enter value to search: ";
                cin>>value;
                myList.SearchNode(value);
                break;
            case 4:
                cout<<"Enter value to delete: ";
                cin>>value;
                myList.DeleteNode(value);
                break;
            case 5:
                myList.PrintList();
                break;
            case 6:
                myList.CountNodes();
                break;
            case 7:
                myList.PrintSecondNode();
                break;
            case 8:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice, please try again."<<endl;
        }

    } 
    while(choice != 8);

    myList.ClearList();   // release any remaining nodes before the program ends
}