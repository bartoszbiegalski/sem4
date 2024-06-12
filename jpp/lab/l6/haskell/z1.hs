import Data.List

binomial n 0 = 1
binomial n k
  | k == n    = 1
  | k > n     = 0
  | otherwise = binomial (n-1) (k-1) + binomial (n-1) k


binomial2 n k = let
  bin2 n
    | n == 0 = [1]
    | otherwise = zipWith (+) ([0] ++ bin2 (n-1)) (bin2 (n-1) ++ [0])
  in
    if k > n then 0
    else bin2 n !! k

merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys)
  | x < y     = x : merge xs (y:ys)
  | otherwise = y : merge (x:xs) ys

mergesort :: [Int] -> [Int]
mergesort xs
  | length xs == 1 = xs
  | otherwise = merge (mergesort (take (length xs `div` 2) xs)) (mergesort (drop (length xs `div` 2) xs))


db 0 b = [0, 1, b]
db a b =
  let [s, t, g] = db (b `mod` a) a
  in [t - (b `div` a) * s, s, g]

prime_factors 0 = []
prime_factors 1 = []
prime_factors n = let
  prime n k
    | k == n || n == 0 = [k]
    | n `mod` k == 0 = k : prime (n `div` k) k
    | otherwise = prime n (k+1)
  in prime n 2

totient n = length [ k | k <- [1..n], gcd n k == 1 ]

totient2 n = let
  factors = prime_factors n
  uniqueFactors = nub factors
  phi = foldl (\acc x -> acc * (x - 1)) 1 uniqueFactors
  in phi

isprime 0 = 0
isprime 1 = 0
isprime n = let
  loop n k
    | n == k = 1
    | n `mod` k == 0 = 0
    | otherwise = loop n (k+1)
  in loop n 2

primes n = [ m | m <- [2 .. n], isprime m == 1]
