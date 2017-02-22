
(define (add10 x)
  (+ 10 x))

(define add10 (lambda (x)
                (+ x 10)))

(define (add10 x)
  (let ((inc 10))
    (+ x inc)))

(define (make-adder inc)
  (lambda (x)
    (+ x inc)))
