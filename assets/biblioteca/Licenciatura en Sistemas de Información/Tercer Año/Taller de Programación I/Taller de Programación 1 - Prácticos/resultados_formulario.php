<?php
	/*******************************
	 *  Taller de Programación 1   *
	 *  ========================   *
	 *  Ejercicios Formularios     *
	 *******************************/
if(!empty($_POST['nombre']) and !empty($_POST['apellido']) and !empty($_POST['correo'])){

$email = $_POST['correo'];

$resultadosvalidos=true;

if (filter_var($email, FILTER_VALIDATE_EMAIL)){}else{$resultadosvalidos=false;}

}else{$resultadosvalidos=false;}
	
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
			
			<p class="titulo_uno">Resultado Formulario</p>
			<p class="ejercicio_dos"><?php if($resultadosvalidos){echo 'El Registro ha sido Exitoso';}else{
			echo 'Algunos campos no fueron completados correctamente, haga clic <a href="formularios.php?nombre='.$_POST['nombre'].'&amp;apellido='.$_POST['apellido'].'&amp;correo='.$_POST['correo'].'&amp;observacion='.$_POST['observacion'].'">Aquí</a> para proceder al completado';
			}?></p>
			
		</div>	
	<div id="pie_pagina">
		
		<p id="copyright">Taller 1</p>
	</div>
</body>
</html>