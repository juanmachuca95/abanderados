(defun tp3ejer3 (R)
	(if (numberp (R))
		(* 2 pi R)
		(pprint "error en los parametros")
	)
)


Break 12 [14]> (tp3ejer3 '(2))

"error en los parametros"

Break 12 [14]> (defun tp3ejer3 (R)
	(if (numberp R)
		(* 2 pi R)
		(pprint "error en los parametros")
	)
)

TP3EJER3
Break 12 [14]> (tp3ejer3 2)

12.566370614359172954L0
Break 12 [14]> (tp3ejer3 4)

25.132741228718345908L0
Break 12 [14]> 
