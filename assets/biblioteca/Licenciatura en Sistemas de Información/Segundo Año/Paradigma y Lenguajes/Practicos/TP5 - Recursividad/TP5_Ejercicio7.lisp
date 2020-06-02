Definir la función soloListas, 
la que a partir de una lista heterogénea, 
devuelva una lista cuyos elementos serán sublistas, 
donde cada sublista estará conformada por el 
elemento que sea una sublista de la lista original 
junto con su longitud.

(defun soloListas(l)
	(cond 
		((endp l)0)
		((listp (car l)) (cons (append (car l) (longitud (car l))) (soloListas (cdr l))) )
		(t(soloListas (cdr l)))
	)
)

(defun longitud(a)
	(length a)
)


;;;devuelve
SOLOLISTAS
Break 12 [19]> 
LONGITUD
Break 12 [19]> (soloListas '( (a b) (cd e) (fgh i)  ))

((A B . 2) (CD E . 2) (FGH I . 2) . 0)
Break 12 [19]> (soloListas '( (a b 56 7) 6 (cd e) (fgh i)  ))

((A B 56 7 . 4) (CD E . 2) (FGH I . 2) . 0)
Break 12 [19]> 

;;;tambien vale probar que lo que es sublista este encerrado en parentesis
;;;agregando a (append (list(car l)) (longitud (car l))


(defun soloListas(l)
	(cond 
		((endp l)0)
		((listp (car l)) (cons (append (list(car l)) (longitud (car l))) (soloListas (cdr l))) )
		(t(soloListas (cdr l)))
	)
)

(defun longitud(a)
	(length a)
)


SOLOLISTAS
Break 12 [19]> 
LONGITUD
Break 12 [19]> (soloListas '( (a b 56 7) 6 (cd e) (fgh i)  ))

(((A B 56 7) . 4) ((CD E) . 2) ((FGH I) . 2) . 0)
Break 12 [19]> 

;;;esta ultima queda mucho mas
