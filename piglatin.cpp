#include <iostream>
#include <string>
using namespace std;

string turnPigLatin(string& str);

int main(int argc, char* argv[]){
  if(argc != 2){
   cerr<<"Usage: "<<argv[0]<< "a string"<<endl;
 	 exit(1);
  }
  string sc = argv[1];
  string answer = turnPigLatin(sc);
  cout<<"The pig latin version of your string is: "<<answer<<endl;
}

string turnPigLatin(string& str){
   string result = "";
   if(str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u'){
      result = str + "ay";
   	  return result;
   }
   char first = tolower(str[0]);
   result = str.substr(1) + first + "ay";
	 return result;
}
