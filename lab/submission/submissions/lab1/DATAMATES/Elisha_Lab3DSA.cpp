//Elisha Bt Afandi A22EC0156
//LAB 3 DATA STRUCTURE AND ALGORITHM

#include <iostream>
using namespace std;

// Task 1
class Node {
public:
    string name;
    string matric_no;
    int age;
    Node* next;
};

class List {
public:
    List(void) {
        head = NULL;
    }

    bool IsEmpty() {
        return head == NULL;
    }

    Node* AccessHead() {
        return head;
    }

    Node* InsertNode(string name, string matric_no, int age);
    void DisplayList();
    void DisplayNodeContent(Node* node);
    void DeleteFrontNode();
    void DeleteBackNode();
    

private:
    Node* head;
};

Node* List::InsertNode(string name, string matric_no, int age) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->matric_no = matric_no;
    newNode->age = age;

    newNode->next = head;
    head = newNode;
    return newNode;
}

void List::DisplayList(){
    Node* currNode = head;
    while(currNode != NULL) {
            cout <<endl;
            DisplayNodeContent(currNode);
            currNode = currNode-> next;
    }
}
void List::DisplayNodeContent(Node* node) {
    if (node) {
        cout << "Student Name: " << node->name << endl;
        cout << "Matric No: " << node->matric_no << endl;
        cout << "Age: " << node->age << endl;
    }
}

void List::DeleteFrontNode(){
    if(head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void List::DeleteBackNode(){
    if(head == NULL || head->next == NULL ) {
        DeleteFrontNode();
    }
    else {
        Node* temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
    }
}
int main() {
    List stdList;
    //task 2 inserting node
    stdList.InsertNode("Hisham", "A3567", 24);
    stdList.InsertNode("Daud", "A2312", 23);
    stdList.InsertNode("Norman", "A1122", 23);

    Node* firstNode = stdList.AccessHead();
    //task 2 display head which is norman 
    stdList.DisplayNodeContent(firstNode);

    //task 3 : Insert new node which is Lee in the front
    cout<<endl;
    cout<<"List after Inserting Lee: " <<endl;
    stdList.InsertNode("Lee", "A1110", 22);
    stdList.DisplayList();
   
   //task 4 : Deleting node at the front 
   cout<<"\nList after delete node at front "<<endl;
   stdList.DeleteFrontNode();
   stdList.DisplayList();

   //task 5: Deleting node at the back
   cout <<"\nList after delete node at back " <<endl;
   stdList.DeleteBackNode();
   stdList.DisplayList();

    return 0;
}

