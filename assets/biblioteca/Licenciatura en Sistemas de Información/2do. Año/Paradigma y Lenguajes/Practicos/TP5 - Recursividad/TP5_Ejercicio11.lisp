(defun tp5ejer11(l1 l2)
	(cond 
		((endp l2)())
		((numberp (car l1)) (numberp (car l2))  (list(- (car l1) (car l2))) (tp5ejer11 (cdr l1)(cdr l2))   )
		(t(tp5ejer11(cdr l1) (cdr l2)))
	)
)