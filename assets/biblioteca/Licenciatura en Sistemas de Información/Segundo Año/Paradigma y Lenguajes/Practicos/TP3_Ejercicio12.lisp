(defun tp3ejer12 ()
	(let (a b)
		(write "ingresa lista a: ")
		(setq a(read))
		(write "ingresa lista b: ")
		(setq b(read))

		(if (and (consp a) (consp b))
			(append a b)
			(pprint "error")
		)
	)
)

TP3EJER12
Break 10 [14]> (tp3ejer12)
"ingresa lista a: "(a b c)
"ingresa lista b: "(d e f g)

(A B C D E F G)
Break 10 [14]> 