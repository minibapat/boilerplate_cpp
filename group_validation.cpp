#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

// g++ --std=c++2a <this-file>
using namespace std;

bool is_valid_node_groups(map<string, vector<string> > in_node_groups);
int main() {
  map<string, vector<string> > node_group = {
    { "group1", { "h1.example.com", "h2.example.com","h3.example.com" } },
    { "group2", { "h4.example.com", "h5.example.com", "h6.example.com" } },
    { "group3", { "h7.example.com", "h8.example.com", "h9.example.com","h10.example.com","h11.example.com","h12.example.com" } },
    { "group4", { "h13.example.com", "h14.example.com", "h15.example.com","h16.example.com","h17.example.com","h18.example.com" } },
    { "group5", { "h7.example.com", "h8.example.com", "h9.example.com","h10.example.com","h11.example.com","h12.example.com", "h13.example.com", "h14.example.com", "h15.example.com","h16.example.com","h17.example.com","h18.example.com", "h19.example.com", "h20.example.com", "h21.example.com","h22.example.com","h23.example.com","h24.example.com" } },
  };


  if ( is_valid_node_groups(node_group) ) {
    cout << "\nNode group assignments are GOOD..!!!\n";
  } else {
    cout << "\nPlease review node group assignments and re-run the program\n";
  }
  return 0;
}

bool myIntersection(set<string> s1, set<string> s2) {
  set<string> intersection_set;
  for (set<string>::iterator i = s1.begin(); i != s1.end(); i++) {
		if(s1.find(*i) != s2.end()){ //then you know the element from s1 exists in s2
      intersection_set.insert(*i); return true; //if found, return false;
    }
	}
  return false;
}

set<string> makeSet(vector<string> myvector){
  set<string> s1;
  for (vector<string>::iterator i =myvector.begin(); i < myvector.end(); i++) {
    s1.insert(*i); 
  }
  return s1;
}

void printSet(set<string> s3){
  for (set<string>::iterator i = s3.begin(); i != s3.end(); i++) {
		cout << *i << endl;
	}
}

bool is_valid_node_groups(map<string, vector<string> > in_node_group) {
  // fill here
  //group 1's elements cannot be in any of the other groups
vector<string> firstblock = {"group1", "group2"}; 
for(vector<string>::iterator ii = firstblock.begin(); ii < firstblock.end(); ii++) {
  vector<string> group1elements = in_node_group[*ii];
  set<string> myset = makeSet(group1elements); //group1
  for(map< string, vector<string> >::iterator jj = in_node_group.begin(); jj != in_node_group.end(); jj++){
    if(jj->first == *ii) { 
      continue;
    }
    vector<string> otherset = in_node_group[jj->first]; //othergroups
    set<string> restSet = makeSet(otherset);
    set<string> s3;
    set_intersection(myset.begin(), myset.end(), restSet.begin(), restSet.end(), inserter(s3,s3.begin()));
    printSet(s3);
    if(!s3.empty()){
      return false;
    } 

  }
}

// second check
vector<string> secondblock = {"group3", "group4"};
for(vector<string>::iterator ii = secondblock.begin(); ii < secondblock.end(); ii++) {
  vector<string> group1elements = in_node_group[*ii];
  set<string> blockset = makeSet(group1elements); //secondblock groups

  for(map< string, vector<string> >::iterator jj = in_node_group.begin(); jj != in_node_group.end(); jj++){
    if(jj->first == *ii) {  //first means key, second means values
      continue;
    }
    vector<string> otherset = in_node_group[jj->first]; //othergroups
    set<string> restSet = makeSet(otherset);
    set<string> s3;
    set_intersection(blockset.begin(), blockset.end(), restSet.begin(), restSet.end(), inserter(s3,s3.begin()));
 
    if ( (jj->first== "group5") && ( *ii == "group3" || *ii == "group4") ) { 
      if(s3.size() != blockset.size()){ 
        printSet(s3);
        printSet(blockset); 
        return false;
      } 
      s3.clear();
    }

    printSet(s3);
    if(!s3.empty()){
      return false;
    }  
  }
}
 

  return true;
 
}
