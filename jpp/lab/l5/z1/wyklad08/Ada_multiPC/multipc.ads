----------------------------------------------------------------------
-- Symulacja problemu wielu producentów i konsumentów
----------------------------------------------------------------------
package multiPC is

procedure Simulation ( nP : Positive; 
                       Production : Positive; 
                       nC : Positive; 
                       Buf_Size : Positive );
end multiPC;
