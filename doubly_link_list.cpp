#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node( int val ){
        data=val;
        next=NULL;
    }
    Node(){
    }
};
void insert_at_head(Node* &head,int val  ){
   Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }
}
void display(Node*head ){
    Node* temp=head;
    if (temp == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = temp;
        do {
            cout << current->data << " <-> ";
            current = current->next;
        } while (current != head);
        cout <<endl;
}

void insertAt_tail(int data,class Node  *head)
{
     Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
}
void insert_at_pos(Node* &head,int data, int position){
     Node* newNode = new Node(data);
        if (position == 1) {
            insert_at_head(head,data);
        } else {
            Node* current = head;
            for (int i = 1; i < position - 1; i++) {
                current = current->next;
                if (current == head) {
                cout << "Invalid position for insertion." << std::endl;
                    return;
                }
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
}

void deleteNode(Node* &head,int position) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete from an empty list." <<endl;
            return;
        }
        if (position == 1) {
            Node* temp = head;
            if (head->next == head) {
                head = nullptr;
            } else {
                head->prev->next = head->next;
                head->next->prev = head->prev;
                head = head->next;
            }
            delete temp;
        } else {
            Node* current = head;
            for (int i = 1; i < position; i++) {
                current = current->next;
                if (current == head) {
                    cout << "Invalid position for deletion." << std::endl;
                    return;
                }
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
}
int main() {
    
   Node *head =NULL;
 insert_at_head(head,1);
 insert_at_head(head,2);
insertAt_tail(1999, head);
insertAt_tail(20000, head);
insert_at_pos(head,3000000,2);
 display(head);
 deleteNode(head,2);

 display(head);
    return 0;
}
