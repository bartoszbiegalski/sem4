-- lib.ads
with triple; use triple;
package lib is


	function fact_loop (var : Integer) return Integer;
	function gcd_loop (a : Integer; b : Integer) return Integer;
	function gcd_ext_loop (a : Integer; b : Integer) return triple.triple;
	
	function fact_rec (var : Integer) return Integer;
	function gcd_rec (a : Integer; b : Integer) return Integer;
	function gcd_ext_rec (a : Integer; b : Integer) return triple.triple;
end lib;
