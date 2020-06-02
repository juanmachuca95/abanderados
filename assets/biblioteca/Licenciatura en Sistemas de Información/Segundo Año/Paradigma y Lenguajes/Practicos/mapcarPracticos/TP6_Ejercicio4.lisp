(defun ing_lista()
	(let (q)
	(write"ingresa lista:")
	(setq q (read))
	(ejer4 q)
	)
)


(defun ejer4 (a)
	(mapcar (lambda (x) (if (numberp x)'si 'no)) a)
)