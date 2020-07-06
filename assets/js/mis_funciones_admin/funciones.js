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






