(defun tp3ejer2 ()
	(let (x)
		(write "ingres una lista x: ")
		(setq x (read))
		(if (and (consp x) (numberp (car (last x)))) 
			(pprint "es un elemento numerico")
			(pprint "no es un elemento numerico")
		)
	)
)

Break 7 [9]> (numberp(Car(last '(2 as (2) (2)))))

NIL
Break 7 [9]>
(TP3EJER2)
"ingres una lista x: "(2 3 4 (2) 2)

"es un elemento numerico"

Break 7 [9]> (TP3EJER2)
"ingres una lista x: "(2 3 (juan))

"no es un elemento numerico"

Break 7 [9]> 
