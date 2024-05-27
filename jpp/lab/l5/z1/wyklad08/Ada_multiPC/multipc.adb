----------------------------------------------------------------------
-- Symulacja problemu wielu producentów i konsumentów
----------------------------------------------------------------------
with Ada.Text_IO; use Ada.Text_IO;

package body multiPC is

procedure Simulation( nP : Positive; 
                      Production : Positive; 
                      nC : Positive; 
                      Buf_Size : Positive ) is
   -- Produkt Producenta
   type Pack is record
     Id : Positive;
     No : Positive;
   end record;

   -- Bufor (kanał)
   type Internal_Buf is array ( Natural range 0 .. Buf_Size-1 ) of Pack;

   protected Buffer is
      entry Read  ( Item : out Pack );
      entry Write ( Item : in Pack  );
   private
      Count       : Natural := 0;
      Buf         : Internal_Buf;
      Write_Index : Natural := 0;
      Read_Index  : Natural := 0;
   end Buffer;

   protected body Buffer is
      entry Read  ( Item : out Pack )
         when Count > 0 is
      begin
         Item       := Buf ( Read_Index );
         Count      := Count - 1;
         Read_Index := ( Read_Index + 1 ) mod Buf_Size;
      end Read;

      entry Write (Item : in Pack)
         when Count < Buf_Size is
      begin
         Buf ( Write_Index ) := Item;
         Count               := Count + 1;
         Write_Index         := ( Write_Index + 1 ) mod Buf_Size;
      end Write;
   end Buffer;

   -- Licznik Producentów (work group)
   protected ProducersGroup is
      procedure Register;
      procedure Done;
      function  Work return Boolean;
   private
      Producers_Number : Natural := 0;
   end ProducersGroup;

   protected body ProducersGroup is
      procedure Register is
      begin
         Producers_Number := Producers_Number + 1;
      end Register;
      
      procedure Done is
      begin
         Producers_Number := Producers_Number - 1;
      end Done;
      
      function Work return Boolean is
      begin
         return ( Producers_Number > 0 );
      end Work;
   end ProducersGroup;

   -- Producent
   task type Producer ( Product_Number : Positive ) is
      entry Set_Id ( Label : Positive );
   end Producer;

   task body Producer is
      Id : Positive;
   begin
      ProducersGroup.Register;
      accept Set_Id ( Label : Positive ) do
         Id := Label;
      end Set_Id;
      for I in 1 .. Product_Number loop
         Buffer.Write ( Pack'(Id,I) );
      end loop;
      ProducersGroup.Done;
   end Producer;

   -- Konsument
   task type Consumer is
      entry Set_Id ( Label : Positive );
   end Consumer;

   task body Consumer is
      Id    : Positive;
      Value : Pack;
   begin
      accept Set_Id ( Label : Positive ) do
         Id := Label;
      end Set_Id;
      loop
         select
             Buffer.Read ( Value );
             Put_Line ( Id'Image & ": (" & Value.Id'Image & "," & Value.No'Image & ")" );
         else
            if not ProducersGroup.Work then 
               exit; 
            end if;
         end select;
      end loop;
   end Consumer;

   P : array ( Natural range 1 .. nP ) of Producer ( Production );
   C : array ( Natural range 1 .. nC ) of Consumer;

begin
   for I in 1 .. nP loop
      P(I).Set_Id( I );
   end loop;
   
   for I in 1 .. nC loop
      C(I).Set_Id( I );
   end loop;
end Simulation;

end multiPC;
