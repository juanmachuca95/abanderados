$(document).ready(function(){
    $('#fecha').attr('value', fechaActual() );
})

function fechaActual(){
    var actual = new Date();
    var mes = actual.getMonth()+1;
    var dia =  actual.getDate();
    var mostrar = (dia < 10? '0'+dia : dia) +'-'+(mes<10? '0'+ mes : mes)+'-'+actual.getFullYear();
    return mostrar;
}


/*Mensaje Admin*/
$(document).keypress(function(e){
	if(e.which == 13 && $('#mensajeAdmin').val() != ''){
		var mensaje = $('#mensajeAdmin').val();
		$('#mensajeAdmin').val(null);
		console.log(mensaje);
		$.ajax({
			url 	: 'http://localhost/Abanderados/foro/actualizarChatAdmin/',
			type    : 'GET',
			data	: {cargar : mensaje},
			success : function(data){
				console.log(data);
			},
			error : function(error, xhr, status){
				alert("Petición Rechazada");
			}
		})
	}
})

//Actualizacion de chatBox
setInterval(function(){  
	var cantMensajes = $('#cantidadMensajes').val();
	//console.log(cantMensajes);
	$.get('http://localhost/Abanderados/foro/showChat',
		{ recargar : cantMensajes },
		function(data){
			if(data !== '0'){
				var json = JSON.parse(data);
				$('#chatBox').empty();
				crearMensajeChatBox(json);
				$("#chatBox").animate({ scrollTop: $('#chatBox')[0].scrollHeight}, 1000);
				$('#cantidadMensajes').val(json.length);
			}
		}
	);
}, 3000);

function crearMensajeChatBox(chat){	
	$.each(chat, function(index, value){
		$('<p>',{
			'class': 'font-weight-bold py-2 px-3 m-1 rounded bg-white'
		}).append(
			$('<b>',{
				'html'  : value.nombre+': ',
				'class' : (value.id_usuario != $('#id_usuario').val())? 'text-warning' : 'azulMarino',
			}),
			$('<p>',{
				'html'  : value.texto,
				'class' : 'font-weight-lighter'
			})
		).appendTo('#chatBox');
	});	
}


/*Actualizacion de usuarios conectados*/
setInterval(function(){  
	$.ajax({
		url 	: 'http://localhost/Abanderados/foro/usuariosConectados/',
		type 	: 'POST',
		data	: {user_activos:true},
		success: function(data){
			if(data != false || data !=0){
				var json = JSON.parse(data);
				//console.log(json.length);
				$('#cantUsuariosActivos').html(json.length);
				$('#usuariosConectados').empty();
				listaDeUsuarios(json);
			}
		},
		error: function(xhr, status, error){
			alert("#Rechazo de Petición");
		}
	})
}, 3000);

function listaDeUsuarios(array){
	$.each(array, function(index, value){
		$('<button>',{
			'class' : 'dropdown-item',
			'html'	: '<i class="fas fa-user text-success"></i> '+ value.nombre+' '+value.apellido,
		}).appendTo('#usuariosConectados');
	})
}


