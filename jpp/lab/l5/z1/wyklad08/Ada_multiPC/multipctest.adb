----------------------------------------------------------------------
-- Symulacja problemu wielu producentów i konsumentów
----------------------------------------------------------------------
with Ada.Command_Line; use Ada.Command_Line;
with multiPC; use multiPC;

procedure multiPCtest is
begin
   if Argument_Count = 4 then
      Simulation ( Positive'Value( Argument(1) ),
                   Positive'Value( Argument(2) ),
                   Positive'Value( Argument(3) ),
                   Positive'Value( Argument(4) ) );
   end if;
end multiPCtest;
