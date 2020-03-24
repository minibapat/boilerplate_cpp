#include <iostream>
#include <map>
#include <vector>
using namespace std;
/* Given an array of elements, return the length of the longest subarray where all its elements are distinct. 
For example, given the array [5, 1, 3, 5, 2, 3, 4, 1], return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1]. */

void printMap(map<int, vector<int> > mymap){
    for (map<int, vector<int> >::iterator ii = mymap.begin(); ii != mymap.end(); ii++) {
        cout<<ii->first<<": ";
        vector<int> val = ii->second;
        for (vector<int>::iterator jj = val.begin(); jj < val.end(); jj++) {
	            cout << *jj << " ";  
        }
        cout<<endl;
    }
}

/*This function contains a map which stores an index and a vector consisting of all unique numbers up until a repeat is reached. Sample 
diagram can be pictured when the printMap function is called. */
int findUnique(int* arr, int len) { 
    map< int, vector<int> > mymap;  //a map with unique subarrays and their sizes 
    for(int x = 0; x<len; x++){
        for(int i = x; i<len; i++){
            if(find(mymap[x].begin(), mymap[x].end(), arr[i]) == mymap[x].end()){ //if the number doesn't already exist in the given index's vector, insert it
                mymap[x].push_back(arr[i]);
            } 
            else { //else the number already exists, so we want to break out of our vector creation and move onto next element
                break;
            }
        } 
    } 
    printMap(mymap);

    int max = 0;
    map<int, vector<int> >::iterator maxindex;
    for (map<int, vector<int> >::iterator i = mymap.begin(); i != mymap.end(); i++) {
	    if((i->second).size() > max){
            max = (i->second).size();
            maxindex = i;
        }
    }
    return (maxindex->second).size(); 


}
 

int main(int argc, char* argv[]){
	if(argc < 2){
		cerr<<"Usage: "<<argv[0]<<" Enter a list of numbers separated by spaces"<<endl;
		exit(1);
	}
	int arr[argc-1];
	for(int i = 0; i<argc-1; i++){
		arr[i] = atoi(argv[i+1]);
	}
	int len = sizeof(arr)/sizeof(arr[0]);
    	int longest = findUnique(arr, len);
	cout<<"The length of the longest subarray is "<<longest<<endl;
}
