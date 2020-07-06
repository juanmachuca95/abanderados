(defun enviarLista()
	(let (a)
		(write "lista: ")
		(setq a (read))
		(if (consp a)
			(ejer1 a)
			'error
		)
	)
)


(defun ejer1(l1)
	(cond 
		((endp l1)0)
		((and (numberp (car l1)) (oddp (car l1))) (+ 1(ejer1 (cdr l1))))
		(t(ejer1 (cdr l1)))
	)
)


;;;devuelve
EJER1
Break 9 [11]> (ejer1 '(2 2 2222 3 7 9 1 5))

5
Break 9 [11]> (ejer1 '(2a 2c 22c22 3c 7 9 1 5))

4


;;;prueba con errores en el ingreso de lista
Break 9 [11]> 
(defun enviarLista()
	(let (a)
		(write "lista: ")
		(setq a (read))
		(if (consp a)
			(ejer1 a)
			'error
		)
	)
)

ENVIARLISTA
Break 9 [11]> (enviarLista)
"lista: "2

ERROR
Break 9 [11]> (enviarLista)
"lista: "(a v c 2 3 1)

2
Break 9 [11]> 