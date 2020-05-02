//Rukmini Bapat
#include <iostream>
using namespace std;
const int N = 2;
class SqrMatrix {
	private:
		int **table;
	public:
		SqrMatrix(int arr[N][N], int n) {
			this->table = new int*[n]; //create an array of pointers to arrays
			for(int x = 0; x<n; x++){
				table[x] = new int[n];
			}
			for(int i = 0; i<n; i++) {
				for(int j = 0; j<n; j++) {
					table[i][j] = arr[i][j];
				}
			}
		}

		SqrMatrix(const SqrMatrix& orig) {
			this->table = new int*[N];
			for(int x = 0; x<N; x++){
				table[x] = new int[N];
			}
			for(int i = 0; i<N; i++) {
				for(int j = 0; j<N; j++){
					table[i][j] = (orig.getTable())[i][j];
				}
			}
		}

		int** getTable() const {
			return table;
		}
};

ostream& operator <<(ostream& outs, const SqrMatrix& source){
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			outs<<(source.getTable())[i][j]<<" ";
		}
		outs<<"\n";
	}
	return outs;
}

SqrMatrix operator+(const SqrMatrix& source1, const SqrMatrix& source2) {
	int rand[N][N];
	for(int i = 0; i<N; i++) {
		for(int j = 0; j<N; j++) {
					rand[i][j] = (source1.getTable())[i][j] + (source2.getTable())[i][j];
		}
	}
	SqrMatrix mys(rand, N);
	return mys;
}
		
int main() {
	 int test1[N][N] = { {1,2} , {5,6} };
	 int test2[N][N]= { {9,10}, {13,14} };
	SqrMatrix m1(test1, N);
	SqrMatrix m2(test2, N);
	cout<<m1;
	cout<<m2;
//	SqrMatrix m3(m1+m2);
	cout<<m1+m2;
	//cout<<m3;
}	
