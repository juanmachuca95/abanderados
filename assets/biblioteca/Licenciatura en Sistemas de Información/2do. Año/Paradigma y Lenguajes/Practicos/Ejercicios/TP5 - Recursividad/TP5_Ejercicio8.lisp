(defun mimax (l &optional (a 0))
	(cond
		((endp l)a)
		((> (car l)a) (mimax (cdr l) (car l)))
		(t(mimax (cdr l)a))
	)
)