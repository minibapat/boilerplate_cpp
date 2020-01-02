#include <iostream>
using namespace std;

struct Coins{
  int quarters;
  int dimes;
  int nickels;
  int pennies;
};

Coins* findSum(int value);

int main(int argc, char* argv[]) {
  if(argc != 2){
    cerr<<"Usage: "<<argv[0]<< "A value"<<endl;
    exit(1);
  }
  int value = atoi(argv[1]);
  Coins* ptr = findSum(value);
  cout<<"Quarters: "<<ptr->quarters<<endl;
  cout<<"Dimes: "<<ptr->dimes<<endl;
  cout<<"Nickels: "<<ptr->nickels<<endl;
  cout<<"Pennies: "<<ptr->pennies<<endl;
}

Coins* findSum(int value){

  Coins* mycoin = new Coins;
  int quarters = 0; int dimes =0; int nickels = 0;
  int pennies = 0;
  quarters = value%25;
  if(quarters == 0){
    quarters = value/25;
    mycoin->quarters = quarters;
    mycoin->dimes = 0;
    mycoin->nickels = 0;
    mycoin->pennies = 0;
    return mycoin;
  }
  else{ 
    dimes = quarters%10;
    if(dimes == 0){
  	dimes = quarters/10;
 	mycoin->quarters = value/25;
	mycoin->dimes = dimes;
	mycoin->nickels = 0;
	mycoin->nickels = 0;
	return mycoin;
    }
    else{
       nickels = dimes%5;
       if(nickels == 0){
   	 nickels = dimes/5;
 	 dimes = quarters/10;
	 quarters = value/25;
	 mycoin->quarters = quarters;
	 mycoin->dimes = dimes;
	 mycoin->nickels = nickels;
	 mycoin->pennies = 0;
	 return mycoin;
       }
       else{
  	 pennies = nickels;
	 mycoin->quarters = value/25;
 	 mycoin->dimes = quarters/10;
	 mycoin->nickels = dimes/5;
	 mycoin->pennies = pennies;
	 return mycoin;
      } 
   }
 }
}







      
  
