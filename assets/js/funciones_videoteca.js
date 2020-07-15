/**
*Funciones de Videoteca manejadas para el usuario. 
*/
$(document).on('click', '#showListaDeReproduccion', function(e){
	e.preventDefault();
	var codigo = $(this).children().html();
	$('#listaTemas').fadeIn('slow');
	$.post('http://localhost/Abanderados/biblioteca/listaReproduccion',
		{codigoMateria : codigo},
		function(data){
			if(data != null || data != ''){
				data = JSON.parse(data);
				$('#ListaDeReproduccion').empty();
				$.each(data, function(index, value){
					$('<p>').append(
						$('<small>').append(
							$('<a>',{
								'html' : '<i class="fas fa-play text-warning"></i> '+index,
								'href' : value,
								'class': 'text-decoration-none text-dark',
								'id'   : 'showVideo',
							}),
						)	
					).appendTo('#ListaDeReproduccion');
				});
			}
		}
	)
	.done(function($msj){
		console.log("La petición se completo correctamente");
	})
	.fail(function(xhr, status, error){
		alert("Algo Fallo");
	})
})


$(document).on('click', '#showVideo',function(e){
	e.preventDefault();
	$('#salaDeVideo').empty();
	$('#salaDeVideo').fadeIn('slow');
	if($('body').width() < 754){
		location.hash = '#salaDeVideo';
	}
	var dato = $(this).attr('href');
	$('<div>',{
		'class' : 'embed-responsive embed-responsive-16by9',
		'html'	: dato,
	}).appendTo('#salaDeVideo');
	$('<p>',{
		'class' : 'text-center p-2 m-0',
		'html'	: '<small class="font-weight-light"><i class="fas fa-tv"></i> Abanderados [ Para mas información recomendamos visitar los canales de youtube de los videos. ] </small>' ,
	}).appendTo('#salaDeVideo');
})