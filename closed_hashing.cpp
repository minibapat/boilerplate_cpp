//program to demonstrate closed hashing
#include <string>
#include <iostream>
using namespace std;
class closedMap {
	private:
		string names[26];
	public:
		int hash_function(string name) {
			return name[0] - 'a';
		}		
		void print_names(void) {
			for(int ii = 0; ii<26; ii++) {
				cout<<ii<<": "<<names[ii]<<endl;
			}
		}
		void insert(string name) {
			int index = this->hash_function(name);
			names[index] = name;
		}
		string find(string name) {
			int index = this->hash_function(name);
			return names[index];
		}
};

int main() {
	static string a[] = {"avenal", "costa mesa", "paso robles", "mesa verde", "anaheim"};
	//anaheim collides with avenal because both start at index 0 (a) so anaheim will replace avenal. We fix this 
	//drawback by using open hashing.
	closedMap cm;
	for(int jj = 0; jj<sizeof(a)/sizeof(a[0]); jj++) {
		cm.insert(a[jj]);
	}
	cm.print_names(); 
}
