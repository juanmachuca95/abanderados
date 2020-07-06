<?php
	/*******************************
	 *  Taller de Programación 1   *
	 *  ========================   *
	 *  Ejercicios 1,2,3           *
	 *******************************/
	 //Variables
	 $nombre="Alumno, Alumno";
	 $ciudad="Corrientes-Argentina";
	 $talleruno="Taller de Programación I";
	 $tallerdos="Programación II";
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
			
			<p class="titulo_uno">Ejercicios 1</p>
			<p class="ejercicio_uno"><span>Apellido y Nombre:</span> <?php echo $nombre;?></p>
			<p class="ejercicio_uno"><span>Ciudad de Nacimiento:</span> <?php echo $ciudad;?></p>		
			
			<p class="titulo_uno">Ejercicios 2</p>
			<p class="ejercicio_dos"><?php echo $talleruno.' - '.$tallerdos;?></p>
			
			<p class="titulo_uno">Ejercicios 3</p>
			<p class="ejercicio_dos">Suma(15+23):<?php echo 15+23;?></p>
			<p class="ejercicio_dos">Resta(28-7):<?php echo 28-7;?></p>
			<p class="ejercicio_dos">División(130+10):<?php echo 130/10;?></p>
			<p class="ejercicio_dos">Multiplicación(12*17):<?php echo 12*17;?></p>
		</div>
	
	<div id="pie_pagina">
		
		<p id="copyright">Taller 1</p>
	</div>
</body>
</html>