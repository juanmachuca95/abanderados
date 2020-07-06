(defun tp3ejer14()
	(let (a b)
		(write "ingresa lista:")
		(setq a (read))
		(write "ingresa lista:")
		(setq b (read))

		(if (and (consp a) (consp b))
			(append (list a) b)
			(pprint "error")
		)
	)
)

TP3EJER14
Break 14 [18]> (tp3ejer14)
"ingresa lista:"(a b c)
"ingresa lista:"(d e f)

((A B C) D E F)
Break 14 [18]> 