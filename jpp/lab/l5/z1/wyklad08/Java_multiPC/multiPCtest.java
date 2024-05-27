class Pack {
   public int Id;
   public int No;
   Pack(int id, int n) { Id=id; No=n; }
};

class Buffer {
   private int size = 3;
   private int Count = 0;
   private int Write_Index = 0;
   private int Read_Index = 0;
   private Pack[] Buf;
   Buffer(int s) {
      size=s;
      Buf=new Pack[size];
   }
   public synchronized boolean Empty() { return Count==0; }
   public synchronized boolean Full() { return Count==size; }
   public synchronized Pack Read() {
      Pack tmp = Buf[Read_Index];
      Count--;
      Read_Index=(Read_Index+1)/size;
      return tmp;
   }
   public synchronized void Write(Pack Item) {
      Buf[Write_Index]=Item;
      Count++;
      Write_Index=(Write_Index+1)/size;
   }
}

class Producer extends Thread {
   private Buffer Channel;
   private int Id;
   private int Production;
   Producer(int id, int pr, Buffer Ch) {
      Channel=Ch;
      Id=id;
      Production=pr;
   }
   public void run() {
      int i;
      for(i=0;i<Production;i++) {
         boolean ok=false;
         while(!ok) {
            synchronized(Channel) {
               if(!Channel.Full()) {
                  Channel.Write(new Pack(Id,i));
                  ok=true;
               }
            }
         }
      }
   }
}

class Consumer extends Thread {
   private Buffer Channel;
   private int Id;
   Consumer(int id, Buffer Ch) {
      Channel=Ch;
      Id=id;
   }
   public void run() {
      while(true) {
         synchronized(Channel) {
            if(!Channel.Empty()) {
               Pack msg=Channel.Read();
               System.out.println(Id+": ("+msg.Id+","+msg.No+")");
            }
         }
      }
   }
}

public class multiPCtest {
   public static void main(String[] args) {
      if(args.length==4) {
         try {
            int nP = Integer.parseInt(args[0]);
            int Production = Integer.parseInt(args[1]);
            int nC = Integer.parseInt(args[2]);
            int buf_size = Integer.parseInt(args[3]);

            Buffer Ch=new Buffer(buf_size);
            Producer[] P=new Producer[nP];
            Consumer[] C=new Consumer[nC];

            for(int i=0;i<nP;i++) P[i]=new Producer(i,Production,Ch);
            for(int i=0;i<nC;i++) C[i]=new Consumer(i,Ch);
            for(int i=0;i<nP;i++) P[i].start();
            for(int i=0;i<nC;i++) C[i].start();
            for(int i=0;i<nP;i++) P[i].join();

            Thread.sleep(1);
         }
         catch (NumberFormatException e) { e.printStackTrace(); }
         catch(InterruptedException e) { e.printStackTrace(); }
         System.exit(0);
      }
   }
}
