open Int;
open List;

fun binomial n 0 = 1
  | binomial n k =
      if k = n then 1
      else if k > n then 0
      else binomial (n-1) (k-1) + binomial (n-1) k;

fun addList ([], []) = []
  | addList (x::xs, y::ys) = (x+y) :: addList(xs, ys);

fun findElement (x::xs, 0) = x
  | findElement (x::xs, k) = findElement (xs, k-1);

fun binomial2 n k =
  let
    fun bin2 0 = [1]
      | bin2 n = addList (([0] @ bin2 (n-1)), (bin2 (n-1) @ [0]))
    in
      if k > n then 0
      else findElement (bin2 n, k)
end;


fun merge [] ys = ys
  | merge xs [] = xs
  | merge (x::xs) (y::ys) =
    if x < y then x :: merge xs (y::ys)
    else y :: merge (x::xs) ys;

fun mergesort xs =
  if length xs = 1 then xs
  else merge (mergesort (List.take(xs, length xs div 2))) (mergesort (List.drop(xs, length xs div 2)));

fun db 0 b = (0, 1, b)
  | db a b =
    let
      val (s, t, g) = db (b mod a) a
    in
      (t - (b div a) * s, s, g)
end;

fun prime_factors 0 = []
 | prime_factors 1 = []
 | prime_factors n =
  let
   fun prime n k =
    if k = n orelse n = 0 then [k]
    else if n mod k = 0 then k :: prime (n div k) k
    else prime n (k+1)
  in
   prime n 2
end;

fun gcd(a, b) =
    if b = 0 then a
    else gcd(b, a mod b);

fun totient n =
  let
    fun totient_list n k =
     if k = n then 0
     else
      if gcd(n, k) = 1 then 1 + totient_list n (k + 1)
      else totient_list n (k+1)
  in
    totient_list n 1
end;


fun isprime 0 = 0
  | isprime 1 = 0
  | isprime n =
  let
    fun loop n k =
      if n = k then 1
      else if n mod k = 0 then 0
      else loop n (k+1)
  in
   loop n 2
end;

fun primes 0 = []
  | primes 1 = []
  | primes n =
  let
    fun loop n k =
      if n = k then
        if isprime k = 1 then [k]
        else []
      else
        if isprime k = 1 then k :: loop n (k+1)
        else loop n (k+1)
    in
      loop n 2
end;
