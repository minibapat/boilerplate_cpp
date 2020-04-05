//program to demonstrate open hashing
//this means we handle collisions and allow for more data to be inserted into the same 
//index (in the form of a linked list).

#include <string>
#include <iostream>
using namespace std;
struct Node {
    string data;
    Node* next;
};
class openMap {
	private:
		Node* names[26];
	public:
        openMap() {
            for(int ii = 0; ii<26; ii++) {
                names[ii]=NULL;
            }
        }
		int hash_function(string name) {
			return name[0] - 'a';
		}		
		void print_names(void) {
			for(int ii = 0; ii<26; ii++) {
				cout<<ii<<": ";
                LL_print(ii);
                cout<<endl;
			}
		}
		void insert(string name) {
			int index = this->hash_function(name);
			LL_insert(index, name);
		}

		bool find(string name) {
			int index = this->hash_function(name);
			return LL_find(index, name);
		}
        void mydelete(string name) {
            int index = this->hash_function(name);
			LL_delete(index, name);
        }

        bool LL_find(int index, string name) {
            Node* tmp_ptr = names[index];
            while(tmp_ptr->next != NULL) {
                if(tmp_ptr->data == name){
                    return true;
                }
                tmp_ptr = tmp_ptr->next;
            }
            return false;
        }

        void LL_insert(int index, string name) {
            if(names[index] == NULL){
                Node* newnode = new Node;
                newnode->data = name;
                newnode->next = NULL;
                names[index] = newnode; 
                return;
            }
            Node* tmp_ptr = names[index];
            while(tmp_ptr->next != NULL) { 
                tmp_ptr = tmp_ptr->next;
            }
            Node* newnode = new Node;
            newnode->data = name;
            newnode->next = NULL;
            tmp_ptr->next = newnode; 
        }

        void LL_print(int index) {
            Node* ptr = names[index];
            while(ptr) {
                cout<<ptr->data<<", ";
                ptr = ptr->next;
            }
        }
        void LL_delete(int index, string name) { 
            Node* head = names[index];
            Node* tmp = head;
            if(head->data == name){
                Node* to_delete = head;
                head = head->next;
                names[index] = head;
                delete to_delete;
                return;
            } 
            while(tmp->next->data != name){
                 tmp = tmp->next; 
            }
            Node* to_delete = tmp->next;
            tmp->next = tmp->next->next;
            delete to_delete;
            return;
        }
};

int main() {
	static string a[] = {"alameda", "anaheim","capitola", "costa mesa", "fullerton", "hayward", "paso robles", "avenal", "atascadero"};
	openMap cm;
	for(int jj = 0; jj<sizeof(a)/sizeof(a[0]); jj++) {
		cm.insert(a[jj]);
	}
	cm.print_names();
    cm.mydelete("alameda");
    cm.mydelete("avenal");
    cm.print_names(); 
}
