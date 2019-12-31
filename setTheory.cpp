#include <iostream>
#include "setTheory.h"

using namespace std;

struct CProduct{
  int x;
  int y;
};

Myset* get_union(int* arr, int len1, int* arr2, int len2){
  bool state = true;
  int count = 0;
  int counter = 0;
  int localarr[len1 + len2];

  Myset *myset_data = new Myset;
  count = len1;
  int i = 0, j = 0;
  while((i<len1 && j<len2) && counter<len1+len2){   
      if(arr2[j] == arr[i]) {
          localarr[counter] = arr[i];
          i++; j++;
          counter++;
      } 
      else if(arr[i] < arr2[j]){
        localarr[counter] = arr[i];
        counter++; i++;
      } 
      else if(arr[i] > arr2[j]){
        localarr[counter] = arr2[j];
        counter++; j++;
        state = false;
      }
    if(state == false){
       count++; 
    }
    state = true;
  }
  while(i<len1){
     localarr[count] = arr[i];
     count++; i++;
  }
  while(j<len2){
    localarr[count] = arr2[j];
    count++; j++;
  }
  myset_data->myList = new int[count];
  for(int k = 0; k<count; k++){
    myset_data->myList[k] = localarr[k];
  }
  
  myset_data->count = count;

  return myset_data;
 
}

Myset* get_inter(int* arr, int len1, int* arr2, int len2){
  Myset* mydata = new Myset;
  int localarr[len1+len2];
  int counter = 0;
  bool exists = false;
  int element = 0;
  for(int i = 0; i<len1; i++){
   for(int j =0; j<len2; j++){
     if(arr[i] == arr2[j]){
       exists = true;
       element = arr[i];
     }      
   }
   if(exists == true){
     localarr[counter] = element;
     counter++;
     exists = false;
   }
  }
  mydata->myList = new int[counter];
  for(int k = 0; k<counter; k++){
     mydata->myList[k] = localarr[k];
  }
  mydata->count = counter;
 
  return mydata; 
}

CProduct* get_cartesian(int* arr, int len1, int* arr2, int len2) {
  CProduct* myprod = new CProduct[sizeof(CProduct) * sizeof(arr) * sizeof(arr2)];
  int index = 0;
  for(int i = 0; i<len1; i++){
  	for(int j = 0; j<len2; j++){
      myprod[index].x = arr[i];
      myprod[index].y = arr2[j];
      index++;
    }
	}
  return myprod;
}

Myset* diff_of_sets(int* arr, int len1, int* arr2, int len2){
  Myset* diff = new Myset;
  //expected diff of A-B: 4,5
  //expected diff of B-A: 12
  int localarr[len1+len2];
  int counter = 0;
  int element = 0;
  bool state = true;
  for(int i = 0; i<len1; i++){
  	for(int j = 0; j<len2; j++){
  		if(arr[i] == arr2[j]){
  	 		 state = false;
 			}
   }
   if(state == true){
     element = arr[i];
     localarr[counter] = element;
     counter++;
   }
   state = true;
	}
  diff->myList = new int[counter];
  for(int k = 0; k<counter; k++){
     diff->myList[k] = localarr[k]; 
  }
  diff->count = counter;

  return diff;
}

int main(){
  int arr[] = { 4,5,6, 9};
  int arr2[] = {6,9,12};
  //expected union: 4,5,6,9,12
  //expected intersection: 6,9
  int size1 = sizeof(arr)/sizeof(arr[0]);
  int size2 = sizeof(arr2)/sizeof(arr2[0]);
  cout<<"Set A is: ";  
  for(int a = 0; a<size1; a++){
    cout<<arr[a]<<" ";
  }
  cout<<endl;
  cout<<"Set B is: ";
  for(int b = 0; b<size2; b++){
  	cout<<arr2[b]<<" ";
  }
  cout<<endl; 
  CProduct* prod = get_cartesian(arr, size1, arr2, size2);
	cout<<"The Cartesian products of the two sets are: "<<endl;
  for(int a = 0; a<12; a++){
    cout<<"("<<prod[a].x<<","<<prod[a].y<<")";
  }
  cout<<endl;  
  Myset* get_diff = diff_of_sets(arr, size1, arr2, size2);
  cout<<"A-B is: "<<endl;
  for(int k = 0; k<get_diff->count; k++){
  	cout<<get_diff->myList[k]<< " ";
  }
	cout<<endl;
  get_diff = diff_of_sets(arr2, size2, arr, size1);
  cout<<"B-A is: "<<endl;
	for(int k = 0; k<get_diff->count; k++){
     cout<<get_diff->myList[k]<< " ";
	}
	cout<<endl;
  Myset* answer = get_union(arr, size1, arr2, size2);
  cout<<"Union: "<<endl;
  for(int i = 0; i<answer->count; i++){ 
     cout<<answer->myList[i]<<" ";
  }
  cout<<endl;
  cout<<"Intersection: "<<endl;
  Myset* intersection = get_inter(arr,size1, arr2, size2);
  for(int j = 0; j<intersection->count; j++){
    cout<<intersection->myList[j]<<" ";
  } 
} 
