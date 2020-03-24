/*Write a program that checks whether an integer is a palindrome. For example,
 121 is a palindrome, as well as 888. 678 is not a palindrome. Do not convert the 
 integer into a string. */
#include <iostream> 
#include <stack>
using namespace std;

bool checkPal(int num){
    stack<int> digits;
    int n = num; 
    while(n > 0){
        digits.push(n%10);
        n = n/10;
    }
    while(!digits.empty()) {
        if(digits.top() != num%10){
            return false;
        }
        digits.pop();
        num = num/10;
    }
    return true;
}


int main(int argc, char* argv[]) {
	if(argc != 2){ 
		cerr<<"Usage: "<<argv[0]<<" Enter a number to check whether it is a palindrome"<<endl;
		exit(1);
	}
    int num = atoi(argv[1]);
    bool answer = checkPal(num);
    if(answer == 0){
        cout<<"Not a palindrome"<<endl;
    }
    else{
        cout<<"Is a palindrome"<<endl;
    }
}
