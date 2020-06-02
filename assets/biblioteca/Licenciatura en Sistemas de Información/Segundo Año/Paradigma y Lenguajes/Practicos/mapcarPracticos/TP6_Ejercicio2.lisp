;;;;((lambda (H) (last H)) '((2 3 4) a b c));;;;
((lambda (H) (last H)) '((2 3 4) a b c))
;;;devuelve el ultimo elemento de la lista en forma de lista;;;
(C)

;;;;((lambda (X Y) (cons X Y)) '( 2 3 4) 'W);;;;
((lambda (x y) (cons x y)) '(2 3 4) 'w)
;;;devuelve;;;
((2 3 4) . W)

;;;;((lambda (A) (reverse (cdr A))) '((2 3 4) a b c));;;;
((lambda (a) (reverse (cdr a))) '((2 3 4) a b c))
;;;devuelve;;;
(C B A)

;;;;((lambda (X) (if (numberp (car X)) (* 2 (car X)))) '(5 6 7));;;;
((lambda (x) (if (numberp (car x)) (* 2 (car x)))) '(5 6 7))
;;;devuelve la multiplicacion de 2 por el car de la lista;;;
10

;;;;((lambda (A) (car A)) '((2 3 4) a b c));;;;
((lambda (a) (car a)) '((2 3 4) a b c))
;;;devuelve el car de la lista;;;
(2 3 4)


