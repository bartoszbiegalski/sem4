package main;

import "os"
import "strconv"

func main() {
   if len(os.Args)==5 {
      nP, _ := strconv.Atoi(os.Args[1])
      products, _ := strconv.Atoi(os.Args[2])
      nC, _ := strconv.Atoi(os.Args[3])
      bufsize, _ := strconv.Atoi(os.Args[4])
      simulation(nP,products,nC,bufsize)
   }
}
