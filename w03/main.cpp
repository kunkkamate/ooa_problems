#include <stdio.h>
#include <math.h>


bool next_partition_of_set(int *a, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            a[i] = 1;
            return true;
        }
        a[i] = 0;
    }
    return false;
}

int main() {
	int n=29;
	int* a = new int [n];
	int* b = new int [n];
	int* xk= new int [n];
	int* xn= new int [n];
	int i;
	float min = INFINITY;
	int T[] = {
    27257, 11737, 3417, 74732055, 7008769, 71198, 6970, 8602, 74787, 3485, 97291,
    61981162, 1938, 8551, 8051, 65105553, 8228, 10217603, 23728483, 72114322, 4896, 85845,
    6014, 84696329, 47142, 41039298, 2159, 5235466, 82838
	};
	int counter = 0;
	int counter_najbolje_podele = 0;
	for (i=0; i<n; i++) {
		a[i] = 0;
		b[i] = 0;
		xk[i] = 0;
		xn[i] = 0;
	}
	do
	{
		int sum_ones = 0;
		int sum_zeros = 0;
		int inst_k = 0;
		int inst_n = 0;
		for (i = 0; i<n; i++) {
			if (a[i]) {
				sum_ones += T[i];
				xk[inst_k++] = T[i];
			}
			else {
				sum_zeros += T[i];
				xn[inst_n++] = T[i];
			}
		}
		int opt_function = abs(sum_ones - sum_zeros);
		if (min == opt_function) {
			counter_najbolje_podele++;
			for (i = 0; i<inst_k; i++) {
				printf("%i ", xk[i]);
			}
			printf("\n");
			for (i = 0; i<inst_n; i++) {
				printf("%i ", xn[i]);
			}
			printf("\n%i\n", counter_najbolje_podele);
		}
		if (min > opt_function) {
			printf("NOVI MINIMUM!\n");
			counter_najbolje_podele = 1;
			min = opt_function;
			for (i = 0; i<inst_k; i++) {
				printf("%i ", xk[i]);
			}
			printf("\n");
			for (i = 0; i<inst_n; i++) {
				printf("%i ", xn[i]);
			}
			printf("\n%i\n", counter_najbolje_podele);
		}
		counter++;
 	} while (next_partition_of_set(a, n));
 	printf("Broj poziva optimizacione funkcije: %i\n", counter);
 	printf("Minimum optimizacione funkcije je %i\n", (int)min);
 	delete [] a;
 	delete [] b;
 	delete [] xn;
 	delete [] xk;
}
