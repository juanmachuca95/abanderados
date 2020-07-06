(defun inglista()
	(let (a)
		(print"ingresa lista: ")
		(setq a (read))
		(ejer7 a)
	)
)


(defun ejer7(l)
	(if (consp l)
		(mapcar
			(lambda (x) (if (listp x) (length x) 'no_existe ))l
		)
	)
)