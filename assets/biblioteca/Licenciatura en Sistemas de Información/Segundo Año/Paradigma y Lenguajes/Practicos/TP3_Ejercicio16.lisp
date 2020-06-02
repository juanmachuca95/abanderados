(cons 5(list t nil))

(5 T NIL)


Break 20 [24]> (cons 5'(t nil))

(5 T NIL)
Break 20 [24]> 

Break 20 [24]> (cddr (cons T (cons nil (cons 5 (cons T (cons nil nil ))))))

(5 T NIL)


Break 20 [24]> (cons 5(append (list t)(list nil)))

(5 T NIL)

Break 20 [24]> (cons 5(append (list(list t)) (list(list nil))))

(5 (T) (NIL))

Break 20 [24]> (append (cons 5 nil) (list 't) '(()))

(5 T NIL)
