<?=$head?>
<?=$nav?>
<div class="container-fluid p-0" style="background-color: white;">
    <div class="container p-0">
        <div class="row m-0">
            <div class="col-md-12">
                <!--Seleccion de seccion de Noticias-->
                <!-- <?php if($inst = $this->session->userdata('interes')) : ?>
                <h5 class="font-weight-bold text-info p-3"><?=$inst->carreras?></h5>
                <?php endif;?> -->
            </div>
        </div>
        
        <div class="row mx-0 py-4">
            <div class="col-md-10">
            <?php if(isset($noticias_inst) && !empty($noticias_inst)) : ?>            
                <div class="card-columns" style="background-color: white;">
                <?php foreach( array_reverse($noticias_inst) as $row ) : ?>

                    <div class="card shadow mb-5 bg-white rounded">
                        <!--Titulo-->
                        
                        <h4 class="card-title p-3 font-weight-bold">
                            <a class="text-decoration-none azulFuerte" href="<?=base_url('welcome/noticia/').$row->id_noticias?>">
                                <?=$row->titulo?>
                            </a>
                        </h4>
                        <img class="card-img-top img-fluid w-100" src="<?=base_url($row->imagen)?>" width="100%;" height="auto" alt="imagen-portada">
                        <div class="card-body">
                            <h6 class="card-subtitle py-1 text-muted text-uppercase font-weight-bold">
                                <?=$row->subtitulo?>
                            </h6>
                        </div>
                        <div class="px-3 font-weight-light text-justify">
                            <?=$row->resumen?><br>
                        </div>
                        <p class="px-3 pt-2">
                            <small class="text-muted">Fuente: <?=$row->fuente?></small>
                        </p>
                        <div class="card-footer bg-transparent borde-light">
                            <small class="text-muted">
                                <?php $fecha = explode('-', $row->fecha);?>
                                <i class="fas fa-calendar-check"></i> Publicado: 
                                <?=$fecha[2]."/".$fecha[1]."/".$fecha[0];?>
                            </small>
                        </div>
                    </div>

                <?php endforeach;?>
                </div>
            <?php endif; ?>
            </div>
           
        </div>
        <?php echo $this->pagination->create_links();?>
        <!--Fin de Fila-->
    </div>
<!--Fin de container Fluid-->
</div>
<?=$footer;?>

