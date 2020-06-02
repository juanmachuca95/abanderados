;;;;(mapcar 'atom '(a (b) () (()) “AA” 3));;;;
(mapcar 'atom '(a (b) () (()) "AA" 3))

;;;;evalua en cada elemento de la lista;;;
;;;;si existe un atomo, y devuelve;;;;
(T NIL T NIL T T)

;;;;(mapcar 'listp '(a (b) () (()) "AA" 3));;;;
(mapcar 'listp '(a (b) () (()) "aa" 3))
;;;evalua en cada elemento de la lista;;;
;;;si existe una lista, en el tercera evaluacion;;;
;;;una lista vacia, es una lista y un atomo a la vez;;;
;;;y devuelve;;;
(NIL T T T NIL NIL)

;;;;(mapcar '> '(5 8 3) '(4 9 2));;;;
(mapcar '> '(5 8 3) '(4 9 2)) 
;;;evalua y compara el elemento de la lista;;;
;;;con el que le corresponde de la siguiente lista;;;
;;;y devuelve T, si el elemento de la primera lista;;;
;;;es mayor al elemento de la segunda lista y devuelve;;;
(T NIL T)


;;;;(mapcar '< '(2 8 3) '(4 9 2) '(5 1 7));;;;
(mapcar '< '(2 8 3) '(4 9 2) '(5 1 7))
;;;evalua la primer lista, con las dos siguientes,;;;
;;;si se cumple la misma condicion en las dos listas;;;
;;;devolvera true, y si es distinta la condicion en las dos listas;;
;;;devolvera false;;;
(T NIL NIL)

;;;;(mapcar '> '(5 8 3) '(4 9) '(3 8 1));;;;
(mapcar '> '(5 8 3) '(4 9) '(3 8 1)) 
;;;devuelve el resultado de evaluar, en los dos elementos;;;
(T NIL)


;;;;(mapcar '+ '(1 2) '(3 4) '(2 2));;;;
(mapcar '+ '(1 2) '(3 4) '(2 2))
;;;devuelve la suma entre elementos de lista;;;
(6 8)

;;;;(mapcar '- '(1 8) '(3 4) '(2 2 9));;;;
(mapcar '- '(1 8) '(3 4) '(2 2 9))
;;;devuelve;;;
(-4 2)

;;;;(mapcar 'cons '(1 2) '((a b) (3 4) ((7 8))));;;;
(mapcar 'cons '(1 2) '((a b) (3 4) ((7 8))))
;;;agrega a la lista 1 , y 2 a la lista siguiente;;;
;;; y devuelve;;;
((1 A B) (2 3 4))

;;;;(mapcar 'abs '(0 -8 10 3 -2.5 -1/4 ));;;;
(mapcar 'abs '(0 -8 10 3 -2.5 -1/4))
;;;abs saca el valor absoluto de cada elemento de la lista;;;
;;;y devuelve;;;
(0 8 10 3 2.5 1/4)

;;;;(mapcar 'length '((1 1 1) () ((8)) (a b)));;;;
(mapcar 'length '((1 1 1) () ((8)) (a b)))
;;;devuelve la longitud de cada lista;;;
(3 0 1 2)

;;;;(mapcar 'list '(a b c d));;;;
(mapcar 'list '(a b c d))
;;;construye una lista de cada elemento de la lista;;;
;;; y devuelve;;;
((A) (B) (C) (D))

;;;;(mapcar 'car '((2 3 4) (a b) ((c)) ) );;;;
(mapcar 'car '((2 3 4) (a b) ((c)) ))
;;;me devuelve el car de cada lista;;;
(2 A (C))


