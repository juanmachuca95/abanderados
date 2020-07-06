(defun inglista()
	(let (a)
		(write"ingresa lista numerica: ")
		(setq a (read))
		(ejer6 a)
	)
)

(defun ejer6 (l)
	(mapcar
		(lambda (x) (if (< x 0) (list x'<'0) (list x'>'0)))l
	)
)