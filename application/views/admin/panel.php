<?=$head?>
<div class="font-weight-light p-5" style="background: white;">
    <a class="navbar-brand" href="<?=base_url('admin')?>">&#x1f393;Abanderados</a>
    <p class="m-0 p-2" id="principal"><?=$institucion->carreras?></p>
</div>

<div class="row m-0">
  <div class="col-12 col-sm-3 col-md-3 bg-white p-0">

    <!--Menu Opciones Administrador-->
    <div class="nav flex-column nav-pills text-left py-2" id="v-pills-tab" role="tablist" aria-orientation="vertical">
      <a class="nav-link active px-4" id="v-pills-foro-tab" data-toggle="pill" href="#v-pills-foro" role="tab" aria-controls="v-pills-foro" aria-selected="true"><i class="fas fa-comments" style="color:#33ccff"></i> Foro Activo </a>

      <a class="nav-link px-4" id="v-pills-home-tab" data-toggle="pill" href="#v-pills-home" role="tab" aria-controls="v-pills-home" aria-selected="true"><i class="far fa-newspaper"></i> Articulos</a>
      <a class="nav-link px-4" id="v-pills-profile-tab" data-toggle="pill" href="#v-pills-profile" role="tab" aria-controls="v-pills-profile" aria-selected="false"><i class="fas fa-book-open"></i> Biblioteca</a>
      <a class="nav-link px-4" id="v-pills-messages-tab" data-toggle="pill" href="#v-pills-messages" role="tab" aria-controls="v-pills-messages" aria-selected="false"><i class="fas fa-video"></i> Videoteca</a>
      <a class="nav-link px-4" id="v-pills-settings-tab" data-toggle="pill" href="#v-pills-settings" role="tab" aria-controls="v-pills-settings" aria-selected="false"><i class="fas fa-cogs"></i> Configurar </a>
    </div>
  </div>
  <!---->

  <div class="col-12 col-sm-9 col-md-9 p-0">
    <div class="tab-content" id="v-pills-tabContent">
      <!--Foro-->
      <div class="tab-pane fade show active" id="v-pills-foro" role="tabpanel" aria-labelledby="v-pills-foro-tab">
        <div class="row m-0 bg-light" id="noticias">
          <div class="col-md-12 p-0">
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
                            <input class="form-control" type="text" id="mensajeAdmin" min="1" placeholder="Escribe la Respuesta como Administrador.">        
                        </div>
                    </div>
                </div>
          </div>
        </div>
      </div>


      <!--Crear Noticia-->
      <div class="tab-pane fade" id="v-pills-home" role="tabpanel" aria-labelledby="v-pills-home-tab">
        <div class="row m-0 bg-light" id="noticias">
          <div class="col-md-6 p-0">
              <div id="crearnoticia">
                  <div class="card card-body">
                      <?=$form_noticias?>
                  </div>
              </div>
          </div>
        </div>
      </div>

      <!--Biblioteca-->
      <div class="tab-pane fade" id="v-pills-profile" role="tabpanel" aria-labelledby="v-pills-profile-tab">
        <div class="p-5 font-weight-lighter bg-light">
            <p>Bibliografia de la Carrera</p>
            <p id="nivelesDir"><a id="nombreDirectorio"><?=$institucion->carreras?></a><a id="subirNivelDirectorio" style="cursor:pointer;"> &#x25c0;</a></p>
            <div class="card p-4" id="dir">
              <!--Carga dinamica de los directorios-->
            </div>
        </div>
      </div>

      <!--Videoteca-->
      <div class="tab-pane fade" id="v-pills-messages" role="tabpanel" aria-labelledby="v-pills-messages-tab">
        <div class="row m-0 bg-light">
          <div class="col-12 p-0">
            <div class="p-3 font-weight-lighter">
              <p class="lead"><i class="fas fa-video"></i> Videotecas disponibles</p>
              <p><a id="cMateria" href="#">Crear Materia</a></p>
              <div id="edicionVideoteca"></div>
              <?php if(isset($videoteca) && !empty($videoteca)) : ?>
                <p id="addShowLinks"> 
                <?php  foreach ($videoteca as $row) : ?>
                  <a id="showLinks" class="text-decoration-none" href="<?=$row->id_materia?>">
                    <?=$row->materia?> /
                  </a>
                <?php endforeach; ?>
                </p>
              <?php endif;?>

            </div>
          </div>
          <div class="col-12 p-0">
            <div class="p-3">
              <p class="lead" >Asignatura: <b id="materia"></b> - Codigo: <b id="codMateria"></b>
              </p>
              <p id="opcionLinks" class="d-none">
                <a class="btn" id="agregarLink" href="#">
                  Agregar <i class="fas fa-link"></i>
                </a> / 
                <a class="btn" id="actualizarLinks" href="#"> 
                  Aplicar Cambios <i class="fas fa-sync"></i>
                </a>
              </p>

              <div id="listaDeLinks">
                
              </div>
            </div>
          </div>
        </div>   
      </div>

      <!--Configuraciones-->
      <div class="tab-pane fade" id="v-pills-settings" role="tabpanel" aria-labelledby="v-pills-settings-tab">
        <div class="p-5 bg-light">
          <p class="lead"> Configuraciones.
              <?php 
                if(isset($configuraciones) && !empty($configuraciones)) : 
                  $datos = $configuraciones; else : echo 'Vacio'; 
                endif;
              ?>
          <div class="col-md-6 p-0">
          <?php if(!empty($datos)) : foreach ($datos as $value) : ?>
              <label class="font-weight-bold" for="<?=$value->item?>"><?= ucwords($value->item)?></label>
              <input class="form-control" type="text" id="<?=$value->item?>" value="<?=$value->valor?>" readonly>
          </div>
            <?php endforeach; endif; ?>
          </p>
        </div>
      </div>

    </div>
  </div>
</div>



<?=$footer?>
<script src="<?=base_url('assets/js/mis_funciones_admin/funciones.js')?>"></script>