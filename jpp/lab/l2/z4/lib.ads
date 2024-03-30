-- lib.ads
with triple; use triple;
package lib is

	function fact_loop (var : Integer) return Integer;
	function gcd_loop (a : Integer; b : Integer) return Integer;
	function gcd_ext_loop (a : Integer; b : Integer) return triple.triple;
	PRAGMA EXPORT(C, fact_loop, "fact_loop");
	PRAGMA EXPORT(C, gcd_loop, "gcd_loop");
	PRAGMA EXPORT(C, gcd_ext_loop, "gcd_ext_loop");
	
	function fact_rec (var : Integer) return Integer;
	function gcd_rec (a : Integer; b : Integer) return Integer;
	function gcd_ext_rec (a : Integer; b : Integer) return triple.triple;
	PRAGMA EXPORT(C, fact_rec, "fact_rec");
	PRAGMA EXPORT(C, gcd_rec, "gcd_rec");
	PRAGMA EXPORT(C, gcd_ext_rec, "gcd_ext_rec");
end lib;
