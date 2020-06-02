<?php
	/*******************************
	 *  Taller de Programación 1   *
	 *  ========================   *
	 *  Ejercicios Formulario Dos  *
	 *******************************/
	 ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
	<link rel="shortcut icon" href="images/icon_logo.ico" />
	<title>Taller 1</title>
 	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link href="css/style_general.css" rel="stylesheet" type="text/css" />
</head>
<body>

	<div id="cabecera">
		<div id="cabecera_interno"><p>Taller de Programación I</p></div>
	</div>
		<?php include('menu.php');?>
		<div id="contenedor_general">
			
			<p class="titulo_uno">Resultado Operaciones / * + -</p>
			<p class="ejercicio_dos">Suma(<?php echo $_POST['x'].' + '.$_POST['y'];?>):<?php echo $_POST['x'] + $_POST['y'];?></p>
			<p class="ejercicio_dos">Resta(<?php echo $_POST['x'].' - '.$_POST['y'];?>):<?php echo $_POST['x'] - $_POST['y'];?></p>
			<p class="ejercicio_dos">División(<?php echo $_POST['x'].' / '.$_POST['y'];?>):<?php echo $_POST['x'] / $_POST['y'];?></p>
			<p class="ejercicio_dos">Multiplicación(<?php echo $_POST['x'].' * '.$_POST['y'];?>):<?php echo $_POST['x'] * $_POST['y'];?></p>
		</div>	
	<div id="pie_pagina">
		
		<p id="copyright">Taller 1</p>
	</div>
</body>
</html>