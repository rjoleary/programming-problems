#lang scheme

(define (pentagonal? p)
  (integer? (/ (+ 1 (sqrt (+ 1 (* 24 p)))) 6)))

(define (pentagonal n)
  (/ (* n (- (* 3 n) 1)) 2))

(define (minimize-iter j k)
  (let* ((Pj (pentagonal j))
         (Pk (pentagonal k))
         (D (- Pj Pk))
         (S (+ Pj Pk)))
    (cond ((zero? k) (minimize-iter (+ j 1) j))
          ((and (pentagonal? D) (pentagonal? S)) D)
          (else (minimize-iter j (- k 1))))))

(minimize-iter 1 1)
