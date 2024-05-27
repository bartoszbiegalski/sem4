;; 1
(defun binomial (n k)
  (if (>= n k) 
    (if (>= n 0) 
      (if (>= k 0) 
          (if (= k 0) 1 (+ (binomial (- n 1) (- k 1)) (binomial (- n 1) k)))
        0
      )
      0
    )
  0
  )
)
(defun binomial2 (n k)
  (labels ((binomial_line (n)
             (if (= n 0)
                 1
               (if (= n 1)
                   '(1 1)
                 (cons (car (binomial_line (- n 1)))
                       (car (car (binomial_line (- n 2)))))))))
    (binomial_line n))
)


;; 5 nie zrobione
(defun prime_factors (n)
  (labels ((inner_prime_factors (n k)
      

      (if (= (rem n k) 0)
      (cons k (inner_prime_factors (/ n k) k)))
       (inner_prime_factors n (+ k 1))
      )
  (inner_prime_factors n 2)))
)


;; 6
(defun totient (n)
  (labels ((inner_totient (n k) 
      (if (= k 1)
      1
      (+ (inner_totient n (- k 1))
      (if (= (gcd n k) 1) 1 0)))))
  (inner_totient n (- n 1))
  )
)