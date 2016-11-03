//============================================================================
// Name        : fibonacci.cpp
// Author      : Hanxi Ye
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include<iostream>
using namespace std;

const int MOD = 1000000;

struct matrix {
	long long int m[2][2];
}ans;


matrix multi(matrix a, matrix b) {	//multiplication of matrices
	matrix tmp;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			tmp.m[i][j] = 0;
			for(int k = 0;  k < 2; k++)
				tmp.m[i][j] = (tmp.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;
		}
	}
	return tmp;
}

int matrix_pow(matrix a, int n) {	//n-th power of matrix a
	ans.m[0][0] = ans.m[1][1] = 1;	//initialization as identity matrix
	ans.m[0][1] = ans.m[1][0] = 0;
	while(n) {
		if(n %2 != 0) ans = multi(ans, a);
		a = multi(a, a);
		n = n / 2;
	}
	return ans.m[0][1];
}

int main() {
	int n;
	matrix base = {1, 1, 1, 0};
	while(cin >> n, n != -1) {
		cout <<  matrix_pow(base, n) << endl;
	}


	return 0;
}

