<?=$head?>
<div class="font-weight-light p-5" style="background: white;">
    <a class="navbar-brand" href="<?=base_url('admin')?>">&#x1f393;Abanderados</a>
    <p class="m-0 p-2" id="principal"><?=$institucion->carreras?></p>
</div>

<div class="row m-0">
  <div class="col-12 col-sm-3 col-md-3 bg-white p-0">

    <!--Menu Opciones Administrador-->
    <div class="nav flex-column nav-pills text-center" id="v-pills-tab" role="tablist" aria-orientation="vertical">
      <a class="nav-link active" id="v-pills-home-tab" data-toggle="pill" href="#v-pills-home" role="tab" aria-controls="v-pills-home" aria-selected="true"><i class="far fa-newspaper"></i> Articulos</a>
      <a class="nav-link" id="v-pills-profile-tab" data-toggle="pill" href="#v-pills-profile" role="tab" aria-controls="v-pills-profile" aria-selected="false"><i class="fas fa-book-open"></i> Biblioteca</a>
      <a class="nav-link" id="v-pills-messages-tab" data-toggle="pill" href="#v-pills-messages" role="tab" aria-controls="v-pills-messages" aria-selected="false"><i class="fas fa-video"></i> Videoteca</a>
      <a class="nav-link" id="v-pills-settings-tab" data-toggle="pill" href="#v-pills-settings" role="tab" aria-controls="v-pills-settings" aria-selected="false"><i class="fas fa-cogs"></i> Configurar </a>
    </div>
  </div>
  <!---->

  <div class="col-12 col-sm-9 col-md-9 p-0">
    <div class="tab-content" id="v-pills-tabContent">
      
      <!--Crear Noticia-->
      <div class="tab-pane fade show active" id="v-pills-home" role="tabpanel" aria-labelledby="v-pills-home-tab">
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
              <p class="lead"><i class="fas fa-video"></i> Videotecas disponibles:</p>
              <?php if(isset($videoteca) && !empty($videoteca)) : ?>
                <p> 
                <?php  foreach ($videoteca as $row) : ?>
                  <a id="showLinks" class="text-decoration-none" href="<?=$row->id_materia?>">
                    <?=$row->materia?>
                  </a> - 
                <?php endforeach; ?>
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