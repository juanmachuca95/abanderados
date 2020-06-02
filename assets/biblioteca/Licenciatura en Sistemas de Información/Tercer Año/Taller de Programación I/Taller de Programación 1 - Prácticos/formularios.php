<?php
	/*******************************
	 *  Taller de Programación 1   *
	 *  ========================   *
	 *  Ejercicios 11 Formularios    *
	 *******************************/
	//incluimos funciones
	include('funciones_uno.php');
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
	<link rel="shortcut icon" href="images/icon_logo.ico" />
	<title>Taller 1</title>
 	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link href="css/style_general.css" rel="stylesheet" type="text/css" />
	<script type="text/javascript" src="js/js.js"></script>
</head>
<body>

	<div id="cabecera">
		<div id="cabecera_interno"><p>Taller de Programación I</p></div>
	</div>
	<?php include('menu.php');?>	
		
				<p class="titulo_uno top">Formulario Uno</p>	
			<form action="nombreciudad.php" method="post">
				<p class="ejercicio_dos"><span>Ingrese Nombre:</span> <input type="text" name="nombre" /></p>
				<p class="ejercicio_dos"><span>Ingrese Ciudad:</span> <input type="text" name="ciudad" /></p>		
				<p class="ejercicio_dos"><input type="submit" name="submit" value="Enviar" /></p>
			</form>	
				<p class="titulo_uno top">Formulario Dos</p>	
			<form action="aritmetico.php" method="post">	
				<p class="ejercicio_dos">Ingrese X:<input type="text" name="x" /> Ingrese Y:<input type="text" name="y" /></p>
				<p class="ejercicio_dos"><input type="submit" name="submit" value="Enviar" /></p>
			</form>
			
				<p class="titulo_uno top">Formulario Tres</p>	
			<form action="resultados_formulario.php" method="post" onsubmit="return validar_form(this);">	
				<p class="ejercicio_form"><span>Nombres:</span> <input type="text" name="nombre" value="<?php echo $_GET['nombre'];?>" /></p>
				<p class="ejercicio_form"><span>Apellidos:</span> <input type="text" name="apellido" value="<?php echo $_GET['apellido'];?>" /></p>	
				<p class="ejercicio_form"><span>Correo Electrónico:</span> <input type="text" name="correo" value="<?php echo $_GET['correo'];?>" /></p>	
				<p class="ejercicio_form"><span>Ubicación Administrativa:</span> 
					<select name="ubicacion">
						<option value="1">Recursos Humanos</option>
						<option value="2">Administración</option>
					</select>
				</p>
				<p class="ejercicio_form"><span>Observaciones:</span> <textarea name="observacion"><?php echo $_GET['observacion'];?></textarea></p>	
				<p class="ejercicio_dos"><input type="submit" name="submit" value="Enviar" /></p>
			</form>	
	<div id="pie_pagina">
		<p id="copyright">Taller 1</p>
	</div>
</body>
</html>