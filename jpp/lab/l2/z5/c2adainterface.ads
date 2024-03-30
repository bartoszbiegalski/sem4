WITH Interfaces.C;
with triple; use triple;

Package c2adainterface is
	function fact_loop(n : Integer) return Integer;
	function gcd_loop(a : Integer; b : Integer) return Integer;
	function gcd_ext_loop (a : Integer; b : Integer) return triple.triple;
	PRAGMA IMPORT(C, fact_loop, "fact_loop");
	PRAGMA IMPORT(C, gcd_loop, "gcd_loop");
	PRAGMA IMPORT(C, gcd_ext_loop, "gcd_ext_loop");
	
	function fact_rec(n : Integer) return Integer;
	function gcd_rec(a : Integer; b : Integer) return Integer;
	function gcd_ext_rec (a : Integer; b : Integer) return triple.triple;
	PRAGMA IMPORT(C, fact_rec, "fact_rec");
	PRAGMA IMPORT(C, gcd_rec, "gcd_rec");
	PRAGMA IMPORT(C, gcd_ext_rec, "gcd_ext_rec");
	
end c2adainterface;
