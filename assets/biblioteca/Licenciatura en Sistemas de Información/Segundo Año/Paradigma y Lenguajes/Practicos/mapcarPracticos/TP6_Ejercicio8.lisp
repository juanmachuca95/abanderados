(defun defineListas()
	(let (lista1 lista2)
		(print "primer lista: ")
		(setq lista1 (read))
		(print "segunda lista: ")
		(setq lista2 (read))
		(ejer8 lista1 lista2)
	)
)

(defun ejer8 (l1 l2)
	(if (and (consp l1)(consp l2))
		(mapcar 
			(lambda (x) (if (not(numberp x)) (list x (car(last l2)))))l1
		)
	)
)