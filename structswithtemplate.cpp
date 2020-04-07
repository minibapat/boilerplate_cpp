#include <iostream>
using namespace std;

struct Mystruct{
	string word;
	int age;
};

bool operator> (Mystruct& a, Mystruct& b){
	if(a.word > b.word) {
		return true;
	}
	return false;
}

template<class Item>
Item maximal(Item a, Item b) {
	if(a>b)
		return a;
	return b;
}



int main() {
	Mystruct m1 = {"pencil", 10};
	Mystruct m2 = {"eraser", 6};
	Mystruct answer = maximal(m1, m2);
	cout<<answer.word<<endl;
}
