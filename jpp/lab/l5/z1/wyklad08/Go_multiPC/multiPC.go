package main;

import "fmt"
import "time"
import "sync"

type pack struct {
   Id int
   No int
}

func simulation(producerSize, production, consumerSize, channelSize int) {
   ch := make(chan pack, channelSize)
   var wg sync.WaitGroup

   for i := 0; i < producerSize; i++ {
      wg.Add(1);
      go producer(i, ch, production, &wg)
   }

   for i := 0; i < consumerSize; i++ {
      go consumer(i, ch)
   }
   wg.Wait();
   time.Sleep(100*time.Millisecond)
}

func producer(index int, ch chan pack, production int, wg *sync.WaitGroup) {
   for i := 0; i < production; i++ {
      ch <- pack{index,i}
   }
   wg.Done()
}

func consumer(index int, ch chan pack) {
   for {
     msg := <- ch;
     fmt.Printf("%v : (%v,%v)\n", index, msg.Id, msg.No)
   }
}
