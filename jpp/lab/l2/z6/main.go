package main

// #include "triple.c"
// #include "lib1.c"
import "C"
import "fmt"

func main() {

	fmt.Printf("%v\n", C.fact_loop(5))

	fmt.Printf("%v\n", C.fact_rec(5))

	fmt.Printf("%v\n", C.gcd_loop(45, 20))

	fmt.Printf("%v\n", C.gcd_rec(45, 20))

	t := C.gcd_ext_rec(77, 34)

	s := C.gcd_ext_loop(77, 34)

	fmt.Printf("%v %v %v\n", t.x, t.y, t.d)

	fmt.Printf("%v %v %v\n", s.x, s.y, s.d)

}
