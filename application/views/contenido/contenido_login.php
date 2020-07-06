<!--Contenido del home, utilizo jquery para mostrar el formulario de login y registro-->

<div class="container p-0 d-flex justify-content-center align-items-center w-100 h-100"> 
    <div class="col-md-5 m-0 p-0">
        
        <div id="inicio">
            <?= $form_login?>
        </div>
        <div id="registro" style="display: none;">
            <?= $form_registro?>
        </div>
    </div>
</div>

