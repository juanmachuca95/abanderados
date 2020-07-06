(defun ambos-enteros(l1 l2)
	(if (and (consp l1) (consp l2))
		(mapcar 
			(lambda (x y) 
				(if (and(numberp x)(numberp y))
					 (list x y)
				) 
			)l1 l2
		)
	)
)

;;;devuelve
AMBOS-ENTEROS
Break 11 [14]> (ambos-enteros '(a 2 1 3)'(d d 2 2))

(NIL NIL (1 2) (3 2))
Break 11 [14]> 