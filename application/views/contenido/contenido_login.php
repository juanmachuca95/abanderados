<!--Contenido del home, utilizo jquery para mostrar el formulario de login y registro-->

<div class="container p-0" >
    <div class="row p-0 m-0">
        <div class="col- col-md-12 p-0">
            <div class="d-flex justify-content-center align-items-center" id="div1">
                <div class="col- col-md-5 p-0">
                    <div>   
                        <p class="lead text-center">
                            <?= (null != $this->session->flashdata('mensaje')) ? $this->session->flashdata('mensaje') : ''; ?>
                        </p>
                        <div id="inicio">
                            <?= $form_login?>
                        </div>
                        <div id="registro" style="display: none;">
                            <?= $form_registro?>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

