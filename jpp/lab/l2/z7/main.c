#include <stdio.h>
#include "lib.h"


int main() {
	printf("%d\n", Fact_loop(4));
	
	printf("%d\n", Fact_rec(4));
	
	printf("%d\n", Gcd_loop(55, 33));
	
	printf("%d\n", Gcd_rec(55, 33));
	
	struct Gcd_ext_loop_return t1 = Gcd_ext_loop(77, 34);
	struct Gcd_ext_rec_return t2 = Gcd_ext_rec(77, 34);
	
	printf("%d %d %d\n", t1.r0, t1.r1, t1.r2);
	printf("%d %d %d\n", t2.r0, t2.r1, t2.r2);
}
