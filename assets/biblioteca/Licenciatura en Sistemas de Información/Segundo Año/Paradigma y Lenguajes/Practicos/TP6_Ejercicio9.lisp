



(defun sumo-ambos (l1 l2)
	(if (and(consp l1) (consp l2))
		(mapcar (lambda (x y) (if (numberp x) (+ x y)))l1 l2) 	
	)
)


;;;devuelve;;;
SUMO-AMBOS
Break 6 [9]> (sumo-ambos '(23 2 1)'(2 3 4))

(25 5 5)
Break 6 [9]>

Break 11 [14]> (sumo-ambos '(23 a 1)'(2 3 4))

(25 NIL 5)
Break 11 [14]> 