<?=$head?>

<?=$nav?>
<!--
<h1 class="display-4 text-center p-5">Welcome</h1>
-->
<div class="container p-0">
    <div class="row p-0 m-0">    
        
        <div class="col-md-9 bg-light p-0 m-0">
            <?php if(isset($noticias) && !empty($noticias)): 
                foreach(array_reverse($noticias) as $row): ?>
            
            <div class="card mb-3">
                <!--Titulo-->
                <h1 class="font-weight-bold py-3 px-5"><?=$row->titulo?></h1>
                <p class="px-5 pt-0 m-0 font-weight-lighter"><?=$row->subtitulo?></p>
                    <!--Fecha noticia-->
                <p class="ml-auto px-5 mt-0 mx-0 mb-3 font-italic text-muted">
                    <small><?="Fecha de creaci&oacuten: ".$row->fecha?></small>
                </p>
                <img class="px-2 bg-light rounded" src="<?=base_url($row->imagen)?>" width="100%;" height="auto" alt="imagen-portada">
                <div class="px-5 pt-3">
                    <p><?=$row->descripcion?></p>
                </div>
                <p class="pb-3">
                <small class="text-muted px-5">Autor: Abanderados</small>
                </p>
            </div>
            <?php endforeach; ?>

            <!--Paginacion-->
            <nav aria-label="Page navigation example">
            <ul class="pagination justify-content-center">
            <?php
                $next = $current_page + 1;
                $prev = $current_page - 1;

                if($prev < 0){
                    $prev = 0;
                }
                if($next > $last_page){
                    $next = $last_page;
                }
                ?>
                <li class="page-item">
                    <a class="page-link" href="<?=base_url('welcome/noticias/'.$prev)?>">Anterior</a>
                </li>
                
                <?php for($i = 1; $i <= $last_page; $i++) { ?>
                
                <li class="page-item">
                    <a class="page-link" href="<?=base_url('welcome/noticias/'.$i)?>"><?=$i?></a>
                </li>
                
                <?php } ?>
                <li class="page-item">
                    <a class="page-link" href="<?=base_url('welcome/noticias/'.$next)?>">Siguiente</a>
                </li>
            </ul>
            </nav>
            
        </div>
            <?php endif;  ?>
            <div class="col-md-2">
                <?=$aside?>
            </div>
        </div>
    </div>
</div>
<?=$footer;?>