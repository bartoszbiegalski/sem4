#include "lib1.h"

int fact_loop(int n) {
	int result = 1;
	int i = 2;
	while (i <= n) {
		result = result * i;
		i = i + 1;
	}
	return result;
}

int gcd_loop(int a, int b) {
	int temp = 0;
		if(b > a) {
		temp = a;
		a = b;
		b = temp;
	}
	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp; 		
	}
	return a;
}

int fact_rec(int n) {
	if (n == 0) return 1;
	else return n*fact_rec(n-1);
}

int gcd_rec(int a, int b) {
	if(b > a) {
		int temp = a;
		a = b;
		b = temp;
	}
	if(b == 0) return a;
	else return gcd_rec(b, a % b);
}

