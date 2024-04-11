package main

import "C"

//export Fact_loop
func Fact_loop(n int) int {
  var output int = 1
  if n == 0 {
      return 1
    } else {
      for i := 1; i <= n; i++ {
          output = output * i
      }
      return output
    }
}

//export Gcd_loop
func Gcd_loop(a int, b int) int {
    var temp int = 0;

    if b > a {
      temp = a
      a = b
      b = temp
    }

    for
    {
        if b == 0 {
          break
        } else {
          temp = b
          b = a % b
          a = temp
        }
    }

    return a
}

//export Gcd_ext_loop
func Gcd_ext_loop(a int, b int) (int, int, int) {
var q int
var r, r_old, s, s_old, t, t_old int = b, a, 0, 1, 1, 0
var temp int

for {
    if r == 0 {
      break
    } else {
      q = r_old / r

      temp = r
      r = r_old % r
      r_old = temp

      temp = s
      s = s_old - q * s
      s_old = temp

      temp = t
      t = t_old - q * t
      t_old = temp
    }
  }
  return s_old, t_old, r_old
}

//export Fact_rec
func Fact_rec(n int) int {
    if n == 0 {
       return 1
    } else {
       return n * Fact_rec(n-1)
    }
}

//export Gcd_rec
func Gcd_rec(a int, b int) int {
  var temp int = 0;

  if b > a {
    temp = a
    a = b
    b = temp
  }

	if b == 0 {
    return a
  } else {
    return Gcd_rec(b, a % b)
    }
}

//export Gcd_ext_rec
func Gcd_ext_rec(a int, b int) (int, int, int) {
    var x int = 1
    var y int = 0
    var d int = a

    if b == 0 {
      return x, y, d
    }
    x, y, d = Gcd_ext_rec(b, a % b)

    return y, x - (a/b) * y, d
}

func main() {}
