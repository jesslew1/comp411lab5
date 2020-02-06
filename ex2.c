#include <stdio.h>

int A[10][10];
int B[10][10];
int C[10][10];

int main() {
	// code here
    int d;
    scanf("%d", &d);
    
    for (int i = 0; i < d; i++) {
		for ( int j = 0; j < d; j++) {
			scanf("%d", &A[j][i]);
		}
	}

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			scanf("%d", &B[j][i]);
		}
	}

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			int sum = 0;
			for (int k = 0; k < d; k++) {
				sum += A[k][i] * B[j][k];
			}

			C[i][j] = sum;
		}
	}

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			printf("%6d", C[i][j]);
		}
		printf("\n");
	}

}