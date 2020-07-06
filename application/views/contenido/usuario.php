<div class="container p-0">
    <div class="card p-4"> 
        <div class="row">
            
            <div class="col-md-3">
                <a href="#">
                    <!--Imagen actual del usuario-->
                    <img class="img-fluid" src="<?=base_url($this->session->userdata('imagen'))?>" id="foto_perfil" alt="Imagen de Perfil">
                </a>
                <form method="post" enctype="multipart/form-data">
                <label for="imagen" class="input_carga_imagen font-weight-lighter bg-info">
                    <input class="form-control" type="file" id="imagen" name="file" accept="image/*" >
                    Actualizar Imagen <i class="fas fa-image"></i>
                </label>
                </form>
            </div>
            <div class="col-md-9 fontGoogle">
                <p>
                    <h4>
                        <?=$this->session->userdata('nombre')." ".$this->session->userdata('apellido')?>
                    </h4>
                </p>
                <p> 
                    Correo electronico: <b><?=$this->session->userdata('correo')?></b>
                </p>
                <p>
                    Inter&eacutes: <b><?php $data = $this->session->userdata('interes'); echo $data->carreras;?></b>
                </p>
            </div>
            
        </div>
    </div>
    <div class="row">
        <div style="height: 180px;">

        </div>
    </div>
</div>
