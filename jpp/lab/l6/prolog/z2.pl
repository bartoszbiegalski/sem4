merge([], [], []).
merge([A|AS], [], [A|AS]).
merge([], [B|BS], [B|BS]).

merge([A|AS], [B|BS], [A|C]) :- A =< B, merge(AS, [B|BS], C).
merge([A|AS], [B|BS], [B|C]) :- A > B, merge([A|AS], BS, C).

mergesort([], []).
mergesort([A], [A]).
mergesort(List, Sorted) :-
    length(List, Len),
    Len > 1,
    HalfLen is Len // 2,
    split(List, HalfLen, Left, Right),
    mergesort(Left, SortedLeft),
    mergesort(Right, SortedRight),
    merge(SortedLeft, SortedRight, Sorted).

split(List, 0, [], List).
split([H|T], N, [H|Left], Right) :-
    N > 0,
    N1 is N - 1,
    split(T, N1, Left, Right).


    
gcd(A, 0, A) :- A > 0.
gcd(A, B, GCD) :-
    B > 0,
    R is A mod B,
    gcd(B, R, GCD).

de(A, B, X, Y, GCD) :-
    gcd(A, B, GCD),
    (GCD =:= 0 -> 
        false % brak rozwiązania, gdy a = b = 0
    ;
        db(A, B, X, Y) % znajdowanie rozwiązania
    ).

db(A, 0, 1, 0) :- A > 0.
db(A, B, X, Y) :-
    B > 0,
    R is A mod B,
    db(B, R, X1, Y1),
    X is Y1,
    Y is X1 - (A // B) * Y1.


prime_factors(1, []).
prime_factors(N, [P|F]) :-
    N > 1,
    isprime(N, P),
    N1 is N // P,
    prime_factors(N1, F).


isprime(2, 2).
isprime(N, P) :-
    N > 2,
    isprime(2, N, P).

isprime(P, N, P) :- 
    P * P > N, !.
isprime(P, N, P) :-
    0 is N mod P, !.
isprime(P, N, R) :-
    P1 is P + 1,
    isprime(P1, N, R).
    
    
totient(N, T) :-
    totient(N, 1, T).

totient(1, T, T).
totient(N, T, R) :-
    N > 1,
    prime_factors(N, Factors),
    list_product(Factors, Product),
    T1 is T * (N - N // Product),
    N1 is N // head(Factors),
    totient(N1, T1, R).


list_product([], 1).
list_product([H|T], P) :-
    list_product(T, P1),
    P is P1 * H.

head([H|_], H).


primes(N, X) :-
    primes(N, 2, X).

primes(N, N, []) :- !.
primes(N, P, [P|T]) :-
    isprime(P),
    P1 is P + 1,
    primes(N, P1, T).
primes(N, P, T) :-
    P1 is P + 1,
    primes(N, P1, T).

isprime(2).
isprime(P) :-
    P > 2,
    \+ (between(2, P-1, X), P mod X =:= 0).



