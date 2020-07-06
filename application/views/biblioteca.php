<?=$head?>
<?=$nav?>
<div class="container-fluid p-0" style="background-color: white;">
    <div class="container p-0">
        <!--Row-->
        <div class="row m-0">
            <div class="col-md-12 p-0">
                <div class="font-weight-lighter py-5 shadow p-3 mb-5 bg-white rounded">
                    <?php $dato = $this->session->userdata('interes');?>
                    <h3 class="px-3 font-weight-bold">
                        Mi Biblioteca
                        <i class="fab fa-readme azulFuerte"></i>
                    </h3>
                    <p class="d-none" id="principal"><?=$dato->carreras?></p>
                    <p class="px-3 lead" id="nivelesDir"><a id="nombreDirectorio"><?=$dato->carreras?></a> <a id="subirNivelDirectorio" style="cursor:pointer;"><i class="fas fa-arrow-alt-circle-left text-primary"></i></a></p>
                    
                    <div class="mx-4 card p-4 bg-light" id="dir">
                    <!--Carga dinamica de los directorios-->
                    </div>
                </div>    
            </div>
        </div>
        <div class="row m-0">
            <div class="col-md-12 text-center">
                <div class="pt-5 pb-3">
                    <h1 class="font-weight-bold"><i class="text-warning fas fa-video"></i> Videoteca</h1>
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
    </div>
</div>
<?=$footer?>
<script type="text/javascript" src="<?=base_url('assets/js/funciones_videoteca.js')?>"></script>