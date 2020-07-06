$(document).ready(function(){
    if($('#nombreDirectorio').html() !== null){
        var carrera = $('#nombreDirectorio').html();
        obtenerArchivos(carrera);
    }
})

function obtenerArchivos(direccion){
    var url = direccion;
    direccion = JSON.stringify(direccion);
    $.post('http://localhost/Abanderados/admin/directorio',
        {dir   : direccion},
        function(data) {
        // Mostramos el texto devuelto por el archivo php
        var json = JSON.parse(data);
        if(json.length > 0){
            $('#dir').empty();
            //console.log(json.length);
            //console.log(json);
            //console.log(json[0]);
            $('#nombreDirectorio').html(url);
            json.forEach(crearListaDirectorio);
        }
    });
}

function crearListaDirectorio(element, index, array){
    if(element.includes('\\') || element.includes('//')){
        element = element.replace('/','');
        element = element.replace('\\','');

        //console.log("Es una carpeta: "+element);
        $('<a>',{
            'id'    : 'directorio',
            'html'  : '<i class="fas fa-folder text-primary"></i> '+ element,
        }).css(
            'cursor','pointer'
        ).addClass(
            'text-decoration-none'
        ).appendTo('#dir');
    }else{
        var URLdomain = "http://localhost/Abanderados";
        var ruta = $('#nombreDirectorio').html();
        //console.log(ruta);
        $('<a>',{
            'id'    : 'archivo',
            'html'  : "<i class='fas fa-file-pdf text-danger'></i> "+element,
            'href'  : URLdomain+'/'+'assets/biblioteca/'+ruta+'/'+element,
            'target' : true,
        }).css(
            'cursor','pointer'
        ).addClass(
            'text-decoration-none text-dark'
        ).appendTo('#dir');
    }
}

//Carpetas Dinamicas. 
$(document).on('click', '#directorio',function(){
    var nombreDirectorio = $('#nombreDirectorio').html();
    var directorio = $(this).html();
    console.log(directorio);
    console.log('El directorio tal cual: '+directorio);
    //directorio = directorio.replace("<i class='fas fa-folder'></i> ",'');
    directorio = directorio.slice(62); //Rebana la parte del icono que no necesita para buscar el directorio
    //console.log('El directorio Preparado: '+directorio);
    nombreDirectorio+='/'+directorio; //Slash
    //console.log($('#nombreDirectorio').html());
    obtenerArchivos(nombreDirectorio);
})

/**
 * Para evitar que la funcion vaya mas arriba en los directorios de los que le 
 * corresponde administrar uso, el valor de id="principal", ubicado en el panel debajo de abanderados. 
 * Cuidado con eliminar este Id. 
 */
$('#subirNivelDirectorio').on('click', function(){
    var directorio = $('#nombreDirectorio').html();
    if(directorio != $('#principal').html()){
        //console.log(directorio);
        var array = directorio.split('/');
        //console.log('Divisiones: '+array);
        array.pop();
        //console.log('Volver a: '+array);
        directorio = array.join('/'); //Slash 
        obtenerArchivos(directorio);
    }
});