#include <stdio.h>
#include "lib1.c"
int main(int argc, char *argv[]) {

	
    struct triple t;
    t = gcd_ext_loop(33, 12, 1);
    printf("%d, %d, %d\n", t.x, t.y, t.d);
    
    t = gcd_ext_rec(33, 12, 1);
    printf("%d, %d, %d\n", t.x, t.y, t.d);
    return 0;
}
