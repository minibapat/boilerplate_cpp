#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

void insert(Node* head, Node* newnode) {
  Node* tmp = head;
  if(tmp->next == NULL){
	tmp->next = newnode;
  }
  else{
    while(tmp->next != NULL) {
	tmp = tmp->next;
    }
    tmp->next = newnode;
  }
}

/*void printList(Node* head){
	Node* tmp = head;
	while(tmp != NULL){
		cout<<tmp->data<<endl;
		tmp = tmp->next;
  }
} */

void printList(Node* head) {
  if(head == NULL){
     return;
  }
  cout<<head->data<<endl;
	printList(head->next);
}


int main() {
   Node* head = new Node;
   head->data = 5;
   head->next = NULL;
   Node* n1 = new Node;
   n1->data = 10;
   n1->next = NULL;
   Node* n2 = new Node;
   n2->data = 15; 
   n2->next = NULL;
   insert(head, n1);
   insert(head, n2);
   printList(head);
}
