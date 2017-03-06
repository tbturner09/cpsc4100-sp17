;; this is a comment

;create a function that add up two parameters
(define (x a b)
  (+ a b))                              ;add them together!

;create a function that will return the cdr of list.
;If the list is null, it will return false
(define (cdr-or-not lst)
  (if (null? lst)
      #f
      (cdr lst)))

;This commented example shows another way of doing the above function
;; (define (cdr-or-not lst)
;;   (unless (null? lst)
;;     (cdr lst)
;;     #f))

;A switch statement in Scheme. Takes an argument, looks for a match
;A returns the matched value. If nothing is matched, it will default 
;to true, which will return "none"
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
      
;;Maps a lambda function over a list, multiplying the elements by 2      
;; (map (lambda (x)
;;        (* x 2))
;;      '(1 2 3 4 5))

;;Explaining the Map function, dot product of the two list
;; scheme@(guile-user)> (map + '(1 2 3 4) '(10 20 30 40))
;; $49 = (11 22 33 44)
;; scheme@(guile-user)> (+ 1 22 3 4)
;; $50 = 30
;; scheme@(guile-user)> (+ '(1 22 3 4))
;; $51 = (1 22 3 4)
;; scheme@(guile-user)> (apply + '(1 22 3 4))
;; $52 = 30

;Filter function, a built-in function, will remove elements with a provided condition from a given list
;In this case, it will remove the even numbers
;(filter even? '(1 2 3 4 5 6 7))

;This filter will check if the elements are less than or equal to 5, if they are a number
;; (filter (lambda (x)
;;           (and (number? x)
;;                (< x 5))) '(3 4 5 6 7 -1 -2 -3 hello))


;This will take in a procedure and apply it to the list.
;An example of the running coe is below this function
(define (my-map proc lst)
  (if (null? lst) '()
      (cons (proc (car lst))
            (my-map proc (cdr lst)))))

;scheme@(guile-user) [7]> (my-map even? '(1 2 3 4))
;$26 = (#f #t #f #t)

;Similar to above except elements will removed if the condition is true, example below function
(define (my-filter proc lst)
  (if (null? lst) '()
      (if (proc (car lst))
          (cons (car lst) (my-filter proc (cdr lst)))
          (my-filter proc (cdr lst)))))


;set! can change the value of variable, in this case we are changing the variable x2
;to be a lambda function with parameters
(set! x2 (lambda (a b) (+ a b)))


;scheme@(guile-user) [13]> (define x2 0)
;scheme@(guile-user) [13]> (set! x2 (lambda (a b) (+ a b)))
;scheme@(guile-user) [13]> x2
;$32 = #<procedure x2 (a b)>

;We can also call this function

;scheme@(guile-user) [22]> (x2 1 2)
;$39 = 3

;Or change it to something else entirely:

;scheme@(guile-user) [27]> (set! x2 "Pickles")
;scheme@(guile-user) [27]> x2
;$45 = "Pickles"

