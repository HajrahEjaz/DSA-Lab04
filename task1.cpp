// Define the node structure and List class. Write CreateThreeNodes() to input three integers,
// allocate three nodes, and link them in input order. Call it once on an empty list. 
// Implement PrintList() using a loop and ClearList() for cleanup. Display an appropriate message for an empty list. 
// Test PrintList() before creation and after entering 10, 20, and 30; the values must appear in that order.

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
        void CreateThreeNodes();
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

// function to input 3 integers
void List::CreateThreeNodes()
{
    // Input 3 integers
    int num1, num2, num3;
    cout<<"Enter integer 1: ";
    cin>>num1;
    cout<<"Enter integer 2: ";
    cin>>num2;
    cout<<"Enter integer 3: ";
    cin>>num3;

    // allocate 3 nodes
    node* n1 = new node;
    node* n2 = new node;
    node* n3 = new node;

    n1->data = num1;
    n2->data = num2;
    n3->data = num3;

    // link the nodes in input order
    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;
    head = n1;
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

    // test the empty list before creating nodes
    myList.PrintList();

    // create and print 3 nodes
    myList.CreateThreeNodes();
    myList.PrintList();

    // clear the list and print again
    myList.ClearList();
    myList.PrintList();
}