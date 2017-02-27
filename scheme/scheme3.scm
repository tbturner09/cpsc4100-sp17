
(define (pair-parts p1)
                                        ;(car (cdr p1)))
  (cadr p1))

(define (foo p1)
  (cons (car p1) (pair-parts p1)))

(define make-adder (lambda (x)
                     (lambda (y) (+ x y))))


(define make-adder2 (lambda (x)
                      (let ((square (* x x)))
                        (lambda (y) (+ y square)))))


(define (add-to-all x lst)
  (map (lambda (z) (+ x z)) lst))


(define (purge10 lst)
  (filter (lambda (x) (not (eq? x 10))) lst))

(define (add x)
  (lambda (c) (+ c x)))


(define (bar x)
  (begin
    (display "i'm in a bar!!")
    (set! x 33)
    x))

;; (define (countdown x)
;;   (lambda ()
;;     (set! x (- x 1))
;;     x))

(define countdown (let ((x 100))
                    (lambda ()
                      (if (> x 0)
                          (begin
                            (set! x (- x 1))
                            x)
                          #f))))

(define (go)
  (letrec ((loop (lambda()
                   (let ((c (countdown)))
                     (when c
                       (display c)
                       (newline)
                       (loop))))))
    (loop)))
