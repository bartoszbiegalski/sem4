-- lib.adb

package body lib is

	function fact_loop (var : Integer) return Integer
	is
	i : Integer := 1;
	n : Integer := 1;
	begin
		while i <= var loop
			n := n * i;
			i := i + 1;
		end loop;
		
		return n;
	end fact_loop;
	
	function gcd_loop (a : Integer; b : Integer) return Integer
	is
	a1 : Integer := a;
	b1 : Integer := b;
	temp : Integer := 0;
	begin 
		if a < b then
			a1 := b;
			b1 := a;
		end if;
		
		while b1 /= 0 loop
			temp := b1;
			b1 := a1 mod b1;
			a1 := temp;
		end loop;
		
		return a1;
	end gcd_loop;
	
	function gcd_ext_loop (a : Integer; b : Integer) return triple.triple
	is
	q: Integer;
	r, r_old : Integer;
	s, s_old : Integer;
	t, t_old : Integer;
	temp : Integer;
	output : triple.triple;
	begin
	
	r_old := a;
	r := b;
	s_old := 1;
	t_old := 0;
	s := 0; 
	t := 1;
	while r /= 0 loop 
			q := r_old / r;
		
			temp := r;
			r := r_old mod r;
			r_old := temp;
			
			temp := s;
			s := s_old - q * s;
			s_old := temp;
			
			temp := t;
			t := t_old - q * t;
			t_old := temp;
		end loop;		
		
		output := (x=>s_old, y=>t_old, d=> r_old);
		return output;
	end gcd_ext_loop;
	-- recursion
	
	function fact_rec (var : Integer) return Integer
	is
	i : Integer := 1;
	n : Integer := 1;
	begin
		if var = 0 then
			return 1;
		else 
			return fact_rec (var-1) * var;
		end if;
	end fact_rec;
	
	function gcd_rec (a : Integer; b : Integer) return Integer
	is 
	temp : Integer := 0;
	begin		
		if b = 0 then
			return a;
		else
			if b > a then 
				return gcd_rec(a, b mod a);
			else 
				return gcd_rec(b, a mod b);
			end if;
		end if;
	end gcd_rec;
	
	function gcd_ext_rec (a : Integer; b : Integer) return triple.triple
	is
	a1 : Integer := a;
	b1 : Integer := b;
	temp : triple.triple := (x=>1, y=>0, d=>a1);
	output : triple.triple;
	begin
		if b = 0 then
			return temp;
		else
			temp := gcd_ext_rec (b1, a1 mod b1);
		end if;
		
		output := (x=>temp.y, y=>temp.x - (a1/b1) * temp.y, d=> temp.d);
		return output;
	end gcd_ext_rec;
		
end lib;
