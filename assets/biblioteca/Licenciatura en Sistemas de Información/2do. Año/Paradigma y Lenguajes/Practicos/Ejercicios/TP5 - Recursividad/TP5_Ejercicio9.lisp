(defun mireverse(L)
	(cond
		((endp L)())
		((and (consp l)) (append (list(car (last l))) (mireverse (butlast l))))
		(t(mireverse (butlast l)))
	)	
)



MIREVERSE
Break 5 [7]> (mireverse'(1 2 4))

(4 2 1 . 0)
Break 5 [7]> (mireverse'(a b c d e f g h i j k l m n ñ o p q))

(Q P O ñ N M L K J I H G F E D C B A . 0)
Break 5 [7]> 

MIREVERSE
Break 5 [7]> (mireverse'(a b c d e f g h i j k l m n ñ o p q))

(Q P O ñ N M L K J I H G F E D C B A)
Break 5 [7]> 


Break 6 [8]> (mireverse '(1 2 3))

(3 2 1)
Break 6 [8]> 


