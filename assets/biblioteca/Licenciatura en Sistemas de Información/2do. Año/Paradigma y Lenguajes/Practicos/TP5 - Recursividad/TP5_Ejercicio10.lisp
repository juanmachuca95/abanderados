(defun ordenado? (l &optional (a 0))
	(cond 
		((endp l)t)
		((and (consp l) (numberp (car l)) (> (car l)a)) (ordenado? (cdr l) (car l))) 
	)
)


ORDENADO?
Break 16 [18]> (ordenado? '(1 2 3))

T
Break 16 [18]> (ordenado? '(1 3 2))

NIL
Break 16 [18]> (ordenado? '(1 2 3 4 5 6 7 3))

NIL
Break 16 [18]> (ordenado? '(1 2 3 4 5 6 7 10))

T
Break 16 [18]> (ordenado? '(3 2 3 4 5 6 7 10))

NIL
Break 16 [18]> 