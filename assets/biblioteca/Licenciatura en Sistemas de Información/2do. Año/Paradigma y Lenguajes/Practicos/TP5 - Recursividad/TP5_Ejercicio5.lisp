(defun ejer5(l)
	(cond
		((endp l)t);;si llega a recorrer toda la lista es porque es true
		((numberp (car l)) (ejer5 (cdr l)))
		(t nil);;no es necesario pero esta bien ponerle
	)
)

;;;devuelve
EJER5
[9]> (ejer5 '(2 c 2))

NIL
[10]> (ejer5 '(2 2 2))

T
[11]> 

