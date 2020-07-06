(defun ingresar()
	(let (a)
		(write "lista: ")
		(setq a (read))
		(if (consp a)
			(suma a)
		)
	)
)


(defun suma (l1)
	(cond
		((endp l1)0)
		((numberp (car l1))(+ (car l1) (suma (cdr l1))))
		(t(suma (cdr l1)))
	)
)

;;;devuelve
SUMA
Break 19 [21]> (suma '(2 3 c 4))

9
Break 19 [21]> 

;;;lo que devuelve tras usar la funcion (ingresar)
INGRESAR
Break 19 [21]> (ingresar)
"lista: "2

NIL
Break 19 [21]> (ingresar)
"lista: "(2 3 c 4)

9
Break 19 [21]> 