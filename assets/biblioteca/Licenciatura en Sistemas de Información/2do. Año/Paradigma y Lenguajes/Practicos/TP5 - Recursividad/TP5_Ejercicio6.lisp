(defun aprobado (l)
	(cond
		((endp l)t)
		((and (numberp (car l)) (<= 4 (car l))) (aprobado(cdr l)) )
		(t nil)
	)
)


;;;devuelve
Break 2 [4]> APROBADO
Break 2 [4]> (aprobado '( 4  5 6))

T
Break 2 [4]> (aprobado '(2 2 2))

NIL
Break 2 [4]> 