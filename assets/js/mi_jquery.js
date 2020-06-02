$(document).ready(function(){

    var height = $(window).height();

      $('#div1').height(height);
    /*me toma el ancho de toda la pantalla 
    var height = $(window).height();
    $('#body').height(height);
    */
      
    $('#fecha').attr('value',fechaActual());
    $('#txt-content').Editor();
    $('#btn-enviar').click(function(e){
        var contenido = $('#txt-content').Editor('getText');
        $('#texto').attr('value', contenido);
    });
    

     
});

//click en Registrate, oculta el formulario de login, y muestra el form de registro
$('#registrate').on('click',function(e){
    $('#inicio').fadeOut('fast', function(){
        
        $('#registro').fadeIn('fast');

    });
});

//clicl en Login, oculta el formulario de Registro, y muestra el form de login. 
    $('#login').on('click',function(e){
    $('#registro').fadeOut('fast', function(){
        
        $('#inicio').fadeIn('fast');

    });
});


function fechaActual(){
    var actual = new Date();
    var mes = actual.getMonth()+1;
    var dia =  actual.getDate();
    var mostrar = (dia < 10? '0'+dia : dia) +'-'+(mes<10? '0'+ mes : mes)+'-'+actual.getFullYear();
    return mostrar;
}

//Agrego una fila para cargar el link de guia de la videoteca
$('#agregarfila').on('click',function(e){
    $('<tr>').append(
        $('<td>').append(
            $('<input>',{
                'class'         :'form-control',
                'placeholder'   :'Titulo de carrera'
            }),
        ),
        $('<td>').append(
            $('<textarea>',{
                'class':'form-control',
            }),
            $('<a>',{
                'class':'eliminar',
                'text':'Eliminar',
                'href':'#',
            })
        ),
    ).appendTo('#tablavideoteca');
});

/**
 * El boton que activara esta funcion, 
 * sera visible solamente si hay datos en la BD.
 * Y actualizara los cambios realizados
 */
$('#actualizarLink').click(function(e){
    var materia = $('#materia').val();
    var carrera = $('#carrera').val();
    var id      = $('#id').val();
    var filas   = $('#tablavideoteca tr'); //Todas las filas de la tabla
    var titulos = recorrerFilasTitulos(filas);
    var links   = recorrerFilasLinks(filas);
    // convertimos el array en un json para enviarlo al PHP
    console.log(titulos.length);
    console.log(links.length);
    var arrayTitulos   =     JSON.stringify(titulos);
    var arrayLinks     =     JSON.stringify(links);
    
    // mediante ajax, enviamos por POST el json en la variable: arrayDeValores
    $.post('links',{
        arrayDeLinks    : arrayLinks,
        arrayDeTitulos  : arrayTitulos, 
        materiaDeValores: materia, 
        carreraMateria  : carrera,
        idMateria       : id
        },function(data) {
        // Mostramos el texto devuelto por el archivo php
        alert(data);
    });
});

function recorrerFilasTitulos( filas ){
    var celdas;
    var titulo = new Array(); 
    for(var i = 0; i < filas.length; i ++){
        celdas  = $(filas[i]).find('td'); //Obtengo las celdas de la fila de turnno. 
        titulo.push($($(celdas[0]).children('input')[0]).val());
        console.log("Se guardo"+titulo[i]);
        //alert(titulo+ " "+ link +" "+ canal +"\n");
    }
    return titulo;
}
function recorrerFilasLinks( filas ){
    var celdas;
    var links = new Array();
    for(var i = 0; i < filas.length; i ++){
        celdas  = $(filas[i]).find('td'); //Obtengo las celdas de la fila de turnno. 
        links.push($($(celdas[1]).children('textarea')[0]).val());
        console.log("Se guardo"+links[i]);
        //alert(titulo+ " "+ link +" "+ canal +"\n");
    }
    return links;
}

/**
 * El boton que activa esta funcion estara visible
 * solamente cuando no hay resultados desde la base de datos. 
 */
$('#crearVideoteca').click(function(e){
    var materia = $('#materia').val();
    var carrera = $('#carrera').val();
    var filas   = $('#tablavideoteca tr'); //Todas las filas de la tabla
    var titulos = recorrerFilasTitulos(filas);
    var links   = recorrerFilasLinks(filas);
    // convertimos el array en un json para enviarlo al PHP
    console.log(titulos.length);
    console.log(links.length);
    var arrayTitulos   =     JSON.stringify(titulos);
    var arrayLinks     =     JSON.stringify(links);
    // mediante ajax, enviamos por POST el json en la variable: arrayDeValores
    $.post('links',{
        arrayDeLinks    : arrayLinks,
        arrayDeTitulos  : arrayTitulos, 
        materiaDeValores: materia, 
        carreraMateria  : carrera,
        },function(data) {
        // Mostramos el texto devuelto por el archivo php
        alert(data);
    });
});

/**
 * Los elementos creados dinamicamente solo puede intereactuar con eventos, 
 * solo si se les pone $(document).on para que el codigo se pueda ejecutar. 
 * importante. 
*/
$(document).on('click', '.eliminar', function(e){
    $(this).closest('tr').remove();
})

/**
 * Este jquery lo que hara es cambiar la dimension de la  etiqueta iframa dependiendo
 * de si su contenedor padre es el del video principal. 
 */
$(document).on(function(){
    
})