<?=$head?>
<?=$nav?>
<div class="container-fluid p-0" style="background-color: white;">
    <div class="container p-0">
        <!--Row-->
        <div class="row m-0">
            <!--Biblioteca-->
            <div class="col-md-5 p-0">
                <div class="font-weight-lighter p-4 shadow p-3 mb-5 bg-white rounded mx-1">
                    <?php $dato = $this->session->userdata('interes');?>
                    <h3 class="font-weight-bold azulMarino">
                        <i class="fas fa-book" style="color:#00cc99"></i>
                        Mi Biblioteca
                    </h3>
                    <hr>
                    <p class="fontGoogle">¡Navega por las carpetas y comenza a estudiar!</p>
                    <small class="text-muted">Utiliza la fecha para volver atras en el directorio</small>
                    <p class="d-none" id="principal"><?=$dato->carreras?></p>
                    <p class="lead azulFuerte" id="nivelesDir"><a id="nombreDirectorio"><?=$dato->carreras?></a> <a id="subirNivelDirectorio" style="cursor:pointer;"><i class="fas fa-arrow-alt-circle-left text-primary"></i></a></p>
                    
                    <div class="card p-3 bg-light lead" id="dir">
                    <!--Carga dinamica de los directorios-->
                    </div>
                </div>    
            </div>

            <!--Foro-->
            <div class="col-md-7 p-0 card">
                <div class="p-4 text-left">
                    <p>
                        <h3 class="font-weight-bold azulMarino"><i class="fas fa-comments" style="color:#33ccff"></i> 
                            Foro Activo 
                            <button class="btn btn-warning btn-sm dropdown-toggle text-right" type="button" id="dropdownMenu2" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                                <span><i class="fas fa-users"></i> <b id="cantUsuariosActivos"></b></span>
                              </button>
                              <div class="dropdown">
                              
                              <div class="dropdown-menu" id="usuariosConectados" aria-labelledby="dropdownMenu2">
                              </div>
                            </div>
                        </h3>
                    </p>
                    <hr>
                    <p class="fontGoogle">¡Conecta con amigos! ¿Podemos ayudarte? ¿Puedes ayudar a alguien? No dudes en escribir. </p>
                    <small class="text-muted">De ser posible sigue el siguiente formato:</small>
                    <p class="font-weight-bold text-warning">#Materia + ¿LoQueQuierasSaber?</p>
                    <input type="number" id="cantidadMensajes" hidden="true">
                    <input type="number" id="id_usuario" hidden="true" value="<?=$this->session->userdata('id_usuario')?>">
                    <div id="chatBox" class="controlScroll p-1 text-left" style="background-color: #e6fff2">
                    </div>
                    <div class="form-row">
                        <div class="col-12 p-4 bg-light">
                            <input class="form-control" type="text" id="mensaje" min="1" placeholder="#Materia + LoQueQuierasSaber">        
                        </div>
                    </div>
                </div>
            </div>
        </div>
        <div class="row m-0">
            <div class="col-md-12 text-center">
                <div class="pt-5 pb-3">
                    <h1 class="font-weight-bold azulMarino"><i class="text-warning fas fa-video"></i> Videoteca</h1>
                    <?php if(isset($videoteca)) : ?>
                        <p class="p-3">
                        <?php foreach ($videoteca as $row) : ?>
                            <a id="showListaDeReproduccion" class="text-decoration-none" href="#">
                                <b class="d-none" id="codMateria"><?=$row->id_materia?></b> 
                                <b><i class="fas fa-location-arrow"></i> <?=$row->materia?> - </b>
                            </a>
                        <?php endforeach; ?>
                        </p>
                    <?php endif; ?>
                </div>
            </div>
        </div>

        <div class="row mx-0 pb-5">
            <div class="col-md-5">
                <div class="bg-light p-3" id="listaTemas" style="display: none">
                    <p class="lead text-center"><i class="fas fa-photo-video text-info"></i> Lista De Reproducción</p>
                    <hr>
                    <div class="text-left" id="ListaDeReproduccion">
                        
                    </div>
                </div>
            </div>
            <div class="col-md-7">
                <!--TV - Caja Iframe-->
                
                <div id="salaDeVideo" class="p-1 shadow-lg p-3 mb-5 bg-white rounded" style="display:none">
                </div>
            </div>
        </div>

        <div class="row m-0">
            
        </div>

    </div>
</div>
<?=$footer?>
<script type="text/javascript" src="<?=base_url('assets/js/funciones_videoteca.js')?>"></script>
<script type="text/javascript" src="<?=base_url('assets/js/funciones_foro.js')?>"></script>