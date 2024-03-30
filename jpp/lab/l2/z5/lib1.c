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

struct triple gcd_ext_loop(int a, int b) {
	int q;
	int r, r_old;
	int s, s_old;
	int t, t_old;
	
	int temp;
	
	r_old = a;
	r = b;
	s_old = 1;
	t_old = 0;
	s = 0; 
	t = 1;
	while (r != 0) {
		q = r_old / r;
	
		temp = r;
		r = r_old % r;
		r_old = temp;
		
		temp = s;
		s = s_old - q * s;
		s_old = temp;
		
		temp = t;
		t = t_old - q * t;
		t_old = temp;
	}
	struct triple output;
	output.x = s_old;
	output.y = t_old;
	output.d = r_old;
	return output;
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

struct triple gcd_ext_rec(int a, int b) {
	struct triple temp;
	temp.x = 1;
	temp.y = 0;
	temp.d = a;
	if( b == 0 ) return temp;
	temp = gcd_ext_rec(b, a % b);
	struct triple output;
	output.x = temp.y;
	output.y = temp.x - (a/b) * temp.y;
	output.d = temp.d;
	return output;
}

