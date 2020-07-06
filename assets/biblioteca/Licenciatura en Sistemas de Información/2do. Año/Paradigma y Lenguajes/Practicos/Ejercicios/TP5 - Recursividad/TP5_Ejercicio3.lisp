
(defun cantNotas(l)
	(cond
		((endp l)0)
		((numberp(car l)) (+ 1(cantNotas (cdr l))) )
		(t(cantNotas (cdr l)))
	)
)

(defun totalnotas(e)
	(cond
		((endp e)0)
		((numberp (car e)) (+ (car e) (totalnotas (cdr e))))
		(t(totalnotas (cdr e)))
	)
)

(defun promedio()
	(let (a)
		(write "ingresa lista de notas: ")
		(setq a (read))
		(if (consp a)
			(float (/ (totalnotas a)(cantNotas a)))
		)
	)
)

;;;devuelve
CANTNOTAS
Break 2 [3]> 
TOTALNOTAS
Break 2 [3]> 
PROMEDIO
Break 2 [3]> (promedio)
"ingresa lista de notas: "(a 7 7)

7.0
Break 2 [3]> (promedio)
"ingresa lista de notas: "(af 8 9 0 2 10 10 10)

7.0
Break 2 [3]> 
