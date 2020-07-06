/* ***************** Funcion para validar formulario Trabajador ******************** */			
function validar_form(opt){
		
		var arroba=opt.correo.value.indexOf("@");
		var punto=opt.correo.value.lastIndexOf(".");
		
		
		if(opt.nombre.value.replace(/ /gi,'')==''){
			alert('Complete Nombre');
			return false;
		}
		if(opt.apellido.value.replace(/ /gi,'')==''){
			alert('Complete Apellido');
			return false;
		}
		if(opt.correo.value.replace(/ /gi,'')==''){
			alert('Complete Correo');
			return false;
		}
		if (arroba<1 || punto<arroba+2 || punto+2>=opt.correo.value.length){
			alert('El Campo Correo Electrónico no puede estar vacío y  debe poseer una sintaxis valida: usuario@e-mail.com');
			return false;
		}
}

/* ******************** Funcion para validar campos Letras y Numeros ************************* */	
function comprobar_letras(e,opt){
//validar solo letreas
		key = e.keyCode || e.which;
		tecla = String.fromCharCode(key).toLowerCase();
		letras = "áéíóúabcdefghijklmnñopqrstuvwxyz";
		numeros = "0123456789";
		switch(opt){
		case 1:
		if (key==8 || key==13 || key==32){ return true;} //permitir enter, espacio y retroceso
		if(letras.indexOf(tecla) == -1){
			alert('Introduzca solo Letras y Espacios');
			return false;
		}
		break;
//validar solo numeros		
		case 2:
		if (key==8 || key==13){ return true;} //permitir enter y retroceso
		if(numeros.indexOf(tecla) == -1){
			alert('Introduzca solo Números');
			return false;
		}
		break;
		}

}

	