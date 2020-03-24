//Below is a command line argument template to use for allowing the user to create their own array

int main(int argc, char* argv[]) {
	if(argc < 2){ //change the 2 to another number as your array constraints require.
		cerr<<"Usage: "<<argv[0]<<" Enter a list of numbers separated by spaces"<<endl;
		exit(1);
	}
	int arr[argc-1];
	for(int i = 0; i<argc-1; i++){
		arr[i] = atoi(argv[i+1]);
	}
	int len = sizeof(arr)/sizeof(arr[0]);
  int longest = findUnique(arr, len); //Change this line as necessary 
	cout<<"The length of the longest subarray is "<<longest<<endl; //Change this line as necessary
}
