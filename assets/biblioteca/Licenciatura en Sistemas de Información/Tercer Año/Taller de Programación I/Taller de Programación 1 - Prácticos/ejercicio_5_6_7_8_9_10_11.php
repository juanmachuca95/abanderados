<?php
	/*******************************
	 *  Taller de Programación 1   *
	 *  ========================   *
	 *  Ejercicios 5,6,7,8,9,10    *
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
	
</head>
<body>

	<div id="cabecera">
		<div id="cabecera_interno"><p>Taller de Programación I</p></div>
	</div>
	<?php include('menu.php');?>	
			<p class="titulo_uno">Ejercicios 5</p>
			<p class="ejercicio_dos">Suma(23+12): <?php echo fun_ari(23,12,'+');?></p>
			<p class="ejercicio_dos">Resta(33-21): <?php echo fun_ari(33,21,'-');?></p>
			<p class="ejercicio_dos">División(50/5): <?php echo fun_ari(50,5,'/');?></p>
			<p class="ejercicio_dos">Multiplicación(36*3): <?php echo fun_ari(36,3,'*');?></p>
			
			<p class="titulo_uno">Ejercicios 6</p>
			<p class="ejercicio_dos">Número Mayor ¿33 o 22?: <?php echo max(33,22);?></p>
			<p class="ejercicio_dos">Número Mayor ¿15 o 44?: <?php echo max(15,44);?></p>
			<p class="ejercicio_dos">absoluto de -15: <?php echo abs(-15);?></p>
			<p class="ejercicio_dos">absoluto de +17: <?php echo abs(+17);?></p>
						
			<table id="table_eje_6" cellpadding="0" cellspacing="0">
				<?php for($i=1; $i <=4; $i++){
					echo '<tr>';
						for($e=1; $e <=4; $e++){
						echo '<td>'.potencias($i,$e).'</td>';
						}
					echo'</tr>';
				}
				?>
			</table>	
			
			<p class="titulo_uno">Ejercicios 7</p>
			<p class="ejercicio_dos">¿54 > 26?: <?php echo mayor(54,26);?></p>
			<p class="ejercicio_dos">¿16 > 29?: <?php echo mayor(16,29);?></p>
			<p class="ejercicio_dos">¿18 > 18?: <?php echo mayor(18,18);?></p>
			<p class="ejercicio_dos">¿18.22 > 19.34?: <?php echo mayor(18.22,19.34);?></p>
			
			<p class="titulo_uno">Ejercicios 8</p>
			<p class="ejercicio_dos">Sumatoria(54): <?php echo sumatoria(5);?></p>
			<p class="ejercicio_dos">Sumatoria(54a): <?php echo sumatoria("54a");?></p>
			
			<p class="titulo_uno">Ejercicios 9</p>
			<p class="ejercicio_dos">Resultado de Array con los 10 primeros números pares a partir de un Número dado (53)</p>
			<?php echo arraydiez(53);?>
			
			<p class="titulo_uno">Ejercicios 10</p>
				<p class="ejercicio_dos">Array Asociativo - Valores</p>
				
				<?php 
					//variable array
					$v[1]=90;
					$v[30]=7;
					$v['e']=99;
					$v['hola']=43;
					foreach($v as $valor){
						echo '<p class="p_ejercicios">'.$valor.'</p>';;
					 }
				?>
				<p class="titulo_uno">Ejercicios 11</p>
				<p class="ejercicio_dos">Array Asociativo</p>
				<?php
					$libros['Libro1']=122.14;
					$libros['Libro2']=156.54;
					$libros['Libro3']=176.22;
					$libros['Libro4']=178.11;
					foreach($libros as $nombre => $valor ){
						echo '<p class="p_ejercicios">'.$nombre.': '.$valor.'</p>';;
					 }
				?>
			
	<div id="pie_pagina">
		<p id="copyright">Taller 1</p>
	</div>
</body>
</html>