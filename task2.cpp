// Extend your class with AddNode(int addData), which inserts a new node at the end, 
// and CountNodes(), which returns the number of nodes. In main(), input a non-negative number n 
// and use a loop to read and append n integers. Display the list and its count. 
// Test n = 0, n = 1, and n = 5. Each new node must have next set to nullptr.

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
        int CountNodes();
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

int List::CountNodes()
{
    int count = 0;
    curr = head;

    // traverse the entire list and count each node
    while(curr!=nullptr)
    {
        count++;
        curr = curr->next;
    }
    return count;

}

void List::PrintList()
{
    
    curr = head;

    // display a message if the list is empty
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
    List myList; // class object
    int value,n;

    // Input the number of nodes
    cout << "Enter number of nodes: ";
    cin >> n;

    // Read and append n integers
    for(int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        myList.AddNode(value);
    }

    // Display the list and its node count
    myList.PrintList();
    cout<<"Number of nodes: "<<myList.CountNodes()<<endl;

    myList.ClearList();
}