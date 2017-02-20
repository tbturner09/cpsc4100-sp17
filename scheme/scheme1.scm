;; this is a comment

(define (x a b)
  (+ a b))                              ;add them together!


(define (cdr-or-not lst)
  (if (null? lst)
      #f
      (cdr lst)))

;; (define (cdr-or-not lst)
;;   (unless (null? lst)
;;     (cdr lst)
;;     #f))


(define (lookup arg)
  (cond
   ((eq? arg 'a) 1)
   ((eq? arg 'b) 2)
   ((eq? arg 'c) 3)
   ((eq? arg 'd) 'four)
   (#t 'none)))

;; scheme@(guile-user)> (memq 'a '(x y z a 1 2 3))
;; $37 = (a 1 2 3)
;; scheme@(guile-user)> (if (memq 'a '(x y z a 1 2 3)) 1 2)
;; $38 = 1
      
;; (map (lambda (x)
;;        (* x 2))
;;      '(1 2 3 4 5))

;; scheme@(guile-user)> (map + '(1 2 3 4) '(10 20 30 40))
;; $49 = (11 22 33 44)
;; scheme@(guile-user)> (+ 1 22 3 4)
;; $50 = 30
;; scheme@(guile-user)> (+ '(1 22 3 4))
;; $51 = (1 22 3 4)
;; scheme@(guile-user)> (apply + '(1 22 3 4))
;; $52 = 30

;(filter even? '(1 2 3 4 5 6 7))

;; (filter (lambda (x)
;;           (and (number? x)
;;                (< x 5))) '(3 4 5 6 7 -1 -2 -3 hello))

(define (my-map proc lst)
  (if (null? lst) '()
      (cons (proc (car lst))
            (my-map proc (cdr lst)))))

(define (my-filter proc lst)
  (if (null? lst) '()
      (if (proc (car lst))
          (cons (car lst) (my-filter proc (cdr lst)))
          (my-filter proc (cdr lst)))))



(set! x2 (lambda (a b) (+ a b)))
