with Ada.Text_IO; use Ada.Text_IO;
with c2adainterface; use c2adainterface;
with interfaces.c; use interfaces.c;
with triple; use triple; 
procedure Main is
	t, s : triple.triple;
	i : Integer;
begin
	for i in 0 .. 9 loop
		Put_Line(Integer'Image(fact_loop(i)));	
	end loop;
	
	Put_Line("");
	
	for i in 0 .. 9 loop
		Put_Line(Integer'Image(fact_rec(i)));	
	end loop;
	
	Put_Line("");
	
	Put_Line(Integer'Image(gcd_loop(77, 30)) & Integer'Image(gcd_rec(77, 30)));
	
	Put_Line("");
	
	Put_Line(Integer'Image(gcd_loop(44, 14)) & Integer'Image(gcd_rec(44, 14)));
	
	Put_Line("");
	
	t := gcd_ext_loop(77, 30);
	s := gcd_ext_rec(77, 30);
	
	Put_Line (Integer'Image (t.x) & " " & Integer'Image (t.y) & Integer'Image (t.d));	
	
	Put_Line("");
	
	Put_Line (Integer'Image (s.x) & " " & Integer'Image (s.y) & Integer'Image (s.d));
	
	Put_Line("");
	
	t := gcd_ext_loop(44, 14);
	s := gcd_ext_rec(44, 14);
	
	Put_Line (Integer'Image (t.x) & " " & Integer'Image (t.y) & Integer'Image (t.d));	
	
	Put_Line("");
	
	Put_Line (Integer'Image (s.x) & " " & Integer'Image (s.y) & Integer'Image (s.d));	
	
	
end Main;
