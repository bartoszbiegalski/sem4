with Ada.Text_IO; use Ada.Text_IO;
with lib; use lib;
with triple; use triple;

procedure Main is
	n : Integer := 0;
	variable : Integer := 1;
	t, s : triple.triple;
	
begin
	
	-- for variable in 1 .. 10 loop
	--	Put_Line (Integer'Image (variable) & Integer'Image (fact_loop(variable)) & Integer'Image (fact_rec(variable)));	
	-- end loop;
	--t := gcd_ext_rec(77, 30);
	s := gcd_ext_loop(52, 27);
	--Put_Line (Integer'Image (t.x) & " " & Integer'Image (t.y) & Integer'Image (t.d));	
	Put_Line (Integer'Image (s.x) & " " & Integer'Image (s.y) & Integer'Image (s.d));	
end Main;
