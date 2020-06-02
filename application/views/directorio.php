<?=$head?>
<?=$nav?>
<div class="container p-0">
    <div class="row m-0">
        <div class="col-md-5 p-0">
            <div class="card p-5">
            <?php if( isset( $ruta ) ) : ?>
                <p class="lead"><?=$ruta?></p>
            <?php endif; ?>
            <h4 class="font-weight-bold pb-3">Informaci&oacuten disponible: </h4>
            <?php if(isset($directorio) && !empty($directorio) ) : 
                foreach ($directorio as $key => $value) : 
                if (strrpos($value, '\\' ) ) : ?>
                    <!--Carpetas-->
                    <p class="font-weight-light">
                        <a class="text-decoration-none text-info font-weight-bold" href="<?=base_url('biblioteca/verdirectorio/'.$ruta.'_'.$value)?>"> &#x1f5c2; <?=$value?>
                        </a>
                    </p>
                <?php else : ?>
                    <!--Archivos-->
                    <p class="font-weight-light">
                        <a class="text-decoration-none text-info font-weight-bold" href="<?=base_url('biblioteca/visualizar/'.$ruta.'_'.$value)?>">
                        <img src="<?=(strrpos($value, 'pdf') ) ? base_url('assets/icons/pdf.png') : ''?>" width="30px">
                            <?=$value?>
                        </a>
                    </p>
                <?php endif;?>
            <?php endforeach; endif;?>
            </div>
        </div>
        <!--Aqui va la galeria de Videos-->
        <div class="col-md-7 p-0">
            <div class="card p-1">
                
                <?php if(isset($videoteca) && !empty($videoteca)) : ?>
                    <p class="lead text-center font-weight-bold px-5 pt-2">
                        &#x1f3a5; Videoteca Gu&iacutea de la Materia.
                    </p>
                    <!--Acá va el primer video-->
                <div class="embed-responsive embed-responsive-16by9">
                    <?=array_values($videoteca)[0];?>
                </div>
            </div>
            <div class="col-md-12 p-0" style="background-color: white;">
                <!--Acá va la lista de reproducción-->
                <p class="px-4 pt-4 font-weight-bold">Lista de Reproducci&oacuten &#x1f3ac;</p>
                <div class="table-responsive">
                    <table>
                        <tr>
                    <?php foreach ($videoteca as $key => $value) : ?>
                            <td>
                                <div class="card" style="width: 18rem;">
                                    <div class="card-body">
                                        <h5 class="card-title"><?=$key?></h5>
                                        <div class="embed-responsive embed-responsive-16by9">
                                        <a href=""><?=$value?></a>
                                        </div>    
                                    </div>
                                    <div class="card-footer">
                                        <small class="text-muted">Canal Recomendado</small>
                                    </div>
                                </div>
                            </td>
                    <?php endforeach;?>
                        </tr>
                    </table>
                </div>
            </div>
            <!--Cierre de Seccion de lista de reproducción-->
                <?php else :?> 
            <div class="bg-dark text-white text-center"><!--Si no hay videoteca para mostrar entonces muestra el mensaje -->
                <h2 class="p-5 font-weight-bold">
                    ¿Tienes material? Ay&uacutedanos a mejorar el contenido.
                </h3>
                <p class="font-weight-light pb-4">Escribinos al correo: &#x2709; <b class="font-weight-bold">abanderadosargentina@gmail.com</b></p>
                <?php endif; ?>
            </div>
        </div>
        <!--Aqui va el Foro de ayuda.-->
        <div class="row m-0">
            <div class="col-md-12 p-5">
                <p class="text-center lead"> 
                    Abanderados esta trabajando en un foro de ayuda  &#x1f6e0;. Proximamente.
                </p>
            </div>
        </div>
    </div>
</div>
</div>

<?=$footer?>