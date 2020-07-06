<?php 
	/*******************************
	 *  Taller de Programación 1   *
	 *  ========================   *
	 *   Funciones Practico 2	   *
	 *******************************/
/****************** Funcion para calcular operaciones aritmeticas *********************/
	
	function fun_ari($num1,$num2,$ope){
		
		switch($ope){ //segun operacion deseada realizamos el calculo
			case "+": return $num1+$num2; break; //suma
			case "-": return $num1-$num2; break; //resta
			case "/": return $num1/$num2; break; //division
			case "*": return $num1*$num2; break; //division
			}
	}	
	
/****************** Funcion para calcular mayor *********************/	 
	function mayor($num1,$num2){
		if(is_int($num1) and is_int($num2)){
			if($num1 == $num2){return $num1.' es Igual que '.$num2;
				}else{
					return ($num1 > $num2)? $num1.' es Mayor que '.$num2 : $num1.' no es Mayor que '.$num2;
				}
		}else{
			return "Ambos Números deben ser Enteros.";
			}
	}
	
/****************** Funcion para calcular potencias *********************/		
	function potencias($num1,$num2){
		return pow($num1,$num2);
		}
		
/****************** Funcion para calcular sumatoria *********************/		
	function sumatoria($num){
		if(is_int($num)){ //si es numerico
			while($num >= 1){ //mientras numero ingresadosea mayorigual que 1
				$resultado+=$num; //al resultado a mostrar le sumamos el num
				$num--;
				}
			return $resultado;	
				}else{
					return "El dato ingresado no es un Número Entero.";
				}
		}
	
/****************** Funcion array primeros diez pares *********************/		
	function arraydiez($num){
		
		if(is_numeric($num)){ //si es numerico procedemos

			$arrayuno=array();//creamos array

			$control=0;//variable de control
			
			 $resultado="";//retornar resultado
			while($control < 10){//mientras control sea menor a 10
								
					if (($num % 2) == 0 and $num != 0) { //si el numero ingresado divivido 2 da resultado 0 agregamos al array
							$resultado=$resultado.'<p class="p_ejercicios">'.$num.'</p>';
							$control++;//aumentamos el contador de control
					} 
				
					$num++;//aumentamos el numero ingresado
					
				}
								
							
				return $resultado;
		}else{
			return "El Datos Ingresado No es Numérico.";
			}
		}

 ?> 
