#include <stdio.h>
#include "lib1.h"
int main(int argc, char *argv[]) {
        
      for (int i = 0; i < argc; i++) {
        printf("%d: \n", (int) argv[i]);
    }
    
    return 0;
}
