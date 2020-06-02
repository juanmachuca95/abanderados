<?=$head?>
<?=$nav?>
<div class="container p-0">
    <div class="container p-0">
        
        <!--Aca van los buscadores de bibliotecas-->
        
        <div class="row py-4">
        <!--Bibliotecas directas desde la base de datos-->
        <?php if(isset($bibliotecas) && !empty($bibliotecas)): 
            foreach ($bibliotecas as $row): ?>

            <div class="col-md-4">
                <div class="card p-3 m-1">

                
                <h3 class="display-3 pt-3 pb-4 font-weight-bold">&#x1f4da;<?=$row->siglas?></h3>
                <h5 class="font-weight-bold">
                    <?=$row->instituciones?>
                </h5>
                <p class="lead">
                    <a class="text-decoration-none" href="<?=base_url('biblioteca/verdirectorio/'.$row->carreras)?>"><?=$row->carreras?></a>
                </p>

                </div>
            </div>

            <?php endforeach; ?>
            <?php endif;?>
        </div>
        
        <div class="row">
            <div class="col-md-12 py-3">
                <p class="lead text-center">¡Apoyamos el aprendizaje en equipo!.</p>
            </div>
        </div>
        

    </div>
    
</div>
<?=$footer?>