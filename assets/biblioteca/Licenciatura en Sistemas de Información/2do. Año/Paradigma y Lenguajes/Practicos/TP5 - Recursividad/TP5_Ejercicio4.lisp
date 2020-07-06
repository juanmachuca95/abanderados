

(defun ejer4(l)
	(cond
		((endp l)0)
		((listp(car l)) (cons (car l) (ejer4 (cdr l))))
		(t(ejer4 (cdr l)))
	)
)

;;;devuelve
EJER4
Break 1 [3]> (ejer4 '( (2) 2 (23) (ab) ))

((2) (23) (AB) . 0)
Break 1 [3]> (ejer4 '((abcdfg) 'no' 'si' (juan)))

((ABCDFG) 'NO ''SI '(JUAN) . 0)
Break 1 [3]> (ejer4 '((abcdfg) "no" "si" (juan)))

((ABCDFG) (JUAN) . 0)
Break 1 [3]> 
