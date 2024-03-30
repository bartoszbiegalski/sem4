package main

import (
	"fmt"
 	"example.com/z3/lib"
	)

func main() {
	fmt.Println(lib.Fact_loop(4))
	fmt.Println(lib.Fact_rec(4))
	fmt.Println(lib.Gcd_loop(77, 31))
	fmt.Println(lib.Gcd_rec(77, 31))
	fmt.Println(lib.Gcd_ext_loop(77, 31))
	fmt.Println(lib.Gcd_ext_rec(77, 31))

}
