//click en Registrate, oculta el formulario de login, y muestra el form de registro
$('#registrate').on('click',function(e){
    $('#inicio').fadeOut('fast', function(){
        if($("#registro").height() > $("body").height()){
            $("body").height($("#registro").height());
        }
        $('#registro').fadeIn('fast');
        $.ajax({
            url:'login/preferencias',
            type:'GET',
            success: function(data){
                //console.log(data);
                var json = JSON.parse(data);
                //console.log(json[0].id_instituciones);
                //console.log(json[0].edificio_principal);
                //console.log(json.length);
                var opciones = $('#preferencias').children();
                if(opciones.length <=1){
                    json.forEach(crearPreferencia);
                }
            },
            error: function(xhr,status){
                alert("Peticion Rechazada");
            }
        });
    });
});

/**Funcion que crea la lista en el selecto del form registro */
function crearPreferencia(element, index, array){
    $('<option>',{
        'value' :   element.id_instituciones,
        'text'  :   index +' - '+element.edificio_principal,
    }).appendTo('#preferencias');
}

//clicl en Login, oculta el formulario de Registro, y muestra el form de login. 
$('#login').on('click',function(e){
    $('#registro').fadeOut('fast', function(){
        
        $('#inicio').fadeIn('fast');

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
 * Ajax para la actualizacion de la imagen de perfil del usuario. 
 */
$('#imagen').on('change',function(){
    var formData = new FormData();
    formData.append('file', $('input[type=file]')[0].files[0]);
    $.ajax({
        url     : 'usuario/actualizarImagen',
        type    : 'POST',
        data    : formData,
        contentType : false,
        processData : false,
        success : function(datos){
            //console.log(datos);
            var json = JSON.parse(datos);
            //console.log(json.actualizacion);
            //console.log(json.imagen);
            if(json.actualizacion){
                $('#foto_perfil').attr('src',json.imagen);
            }else{
                alert("La imagen es la misma o tiene el mismo nombre");
            }
        }
    })
})

/*Ajax que me muestra la lista de materias que contienen links de videos guia.*/
$(document).on('click', '#showLinks', function(e){
    e.preventDefault();
    var asignatura = $(this).html();
    var cod        = $(this).attr('href');
    $('#codMateria').html(cod);
    $('#listaDeLinks').empty();
    $('#materia').html(asignatura);

    $.ajax({
        url     : 'http://localhost/Abanderados/Admin/getLinks',
        type    : 'POST',
        data    : {codigo : cod},
        success : function(data){
            if(data != false && data != null){
                crearListado(data);
                $('#opcionLinks').removeClass('d-none');
            }else{
                alert("Sin Datos.");
            }     
        },
        error   : function(xhr, status){
            alert("Peticion Rechazada.");
        }
    });
})

/*Creacion de los elementos dinamicos para editar filas*/
function crearListado(data){
    //console.log('Los datos son: \n'+data);
    var json = JSON.parse(data);
    $.each(json, function(index, value){
        $('<div>',{
            'class' : 'p-3 card',
        }).append(
            $('<input>',{
                'value'     : index,
                'readonly'  : true,
                'class'     : 'font-weight-light border-0 m-0 p-3',
            }),
            $('<div>',{
                'class' : 'form-row'
            }).append(
                $('<input>',{
                    'value'      : value, 
                    'readonly'   : true,
                    'type'       : 'text',
                    'class'      : 'form-control col-10',
                }),                
                $('<a>',{
                    'id'    : 'editarLink',
                    'html'  : '<i class="fas fa-edit"></i>',
                    'href'  : '#',
                    'class' : 'text-decoration-none col-1 text-center', 
                }),
                $('<a>',{
                    'id'    : 'eliminarLink',
                    'html'  : '<i class="fas fa-trash-alt"></i>',
                    'href'  : '#',
                    'class' : 'text-decoration-none col-1 text-center',
                }),
            )
        ).appendTo('#listaDeLinks');
    })
}

/*Funcion para editar las filas de los de los links.*/
$(document).on('click', '#editarLink', function(e){
    e.preventDefault();
    $(this).parent().children().attr('readonly',false);
    $(this).parent().parent().children().attr('readonly',false);
    alert("Edicion abierta");
    $(this).attr('id', 'cerrarEdicion');
});

/*Cierre de la edición de los links*/
$(document).on('click', '#cerrarEdicion', function(e){
    e.preventDefault();
    $(this).parent().children().attr('readonly',true);
    $(this).parent().parent().children().attr('readonly',true);
    alert('Cerrar la edicicon');
    $(this).attr('id', 'editarLink');
});

/*Eliminar una fila de un regitro*/
$(document).on('click', '#eliminarLink', function(e){
    e.preventDefault();
    $(this).parent().parent().css('background-color', '#ffdccc');
    if(confirm("¿Seguro que quieres eliminar este link?")){
        $(this).parent().parent().remove();    
    }else{
        $(this).parent().parent().css('background-color', '');
    }
})

/*Actualización de los datos */
$(document).on('click','#actualizarLinks', function(e){
    e.preventDefault();
    var datos = $('#listaDeLinks').children();
    var indice = new Array();
    var links  = new Array(); 
    $.each(datos, function(index, link){
        indice.push(link.children[0].value);
        links.push(link.children[1].children[0].value);
    })
    indice = JSON.stringify(indice);
    links  = JSON.stringify(links);
    codigo = $('#codMateria').html();
    $.post('http://localhost/Abanderados/admin/links',{
        arrayDeLinks    : links,
        arrayDeTitulos  : indice, 
        codigoMateria   : codigo, 
        },function(data) {
        // Mostramos el texto devuelto por el archivo php
            alert(data);
        }
    );
})

/*Agregar fila para link*/
$('#agregarLink').on('click',function(e){
    e.preventDefault(); 
    var elemento = 
    $('<div>', {
        'class' : 'card p-3',
        'id'            : 'elementoNuevo',
    }).append(
        $('<input>',{
            'value'         :  '',
            'readonly'      : false,
            'placeholder'   : 'Completa el Titulo',
            'class'         : 'font-weight-light border-0 m-0 p-3',
        }),
        $('<div>',{
            'class' : 'form-row'
        }).append(
            $('<input>',{
                'value'      : '', 
                'readonly'   : false,
                'type'       : 'text',
                'placeholder'   : 'Completa el Link',
                'class'         : 'form-control col-10',
            }),                
            $('<a>',{
                'id'    : 'editarLink',
                'html'  : '<i class="fas fa-edit"></i>',
                'href'  : '#',
                'class' : 'text-decoration-none col-1 text-center', 
            }),
            $('<a>',{
                'id'    : 'eliminarLink',
                'html'  : '<i class="fas fa-trash-alt"></i>',
                'href'  : '#',
                'class' : 'text-decoration-none col-1 text-center',
            })
        )
    ).appendTo('#listaDeLinks');
    location.hash = '#elementoNuevo';
    $('#elementoNuevo').attr('id','');
});

