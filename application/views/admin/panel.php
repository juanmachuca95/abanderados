<?=$head?>
<?=$nav?>
<div class="container p-0">
    <div class="row" id="videoteca">
        <div class="col-md-8">
            <div class="bg-dark text-white p-4">
                <?=$form_videoteca;?>
                <?php if(isset($links_existentes) && !empty($links_existentes)): ?> 
                <table class="table table-strippe table-dark">
                    <tbody id="tablavideoteca">
                        <?php foreach ($links_existentes as $key => $row) : ?>
                        <tr>
                            <td>
                                <input class="form-control" type="text" placeholder="Titulo del Tema" value="<?=$key?>" >
                            </td>
                            <td>
                                <textarea class="form-control" name="link" id="" cols="30" rows="2" placeholder="Introduce los links de guia" ><?=$row?></textarea>
                                <a href="#" class="eliminar">Eliminar</a>
                            </td>
                        </tr>
                        <?php endforeach; ?> 
                    </tbody>
                </table>
                <p class="px-3">
                    <button class="btn btn-warning" type="button" id="agregarfila">Agregar &#x1f517;</button>
                    <button class="btn btn-success" type="button" id="actualizarLink">Actualizar</button>
                </p> 

                <?php else: ?>
                    <p class="lead px-3"><?=$this->session->flashdata('No encontrado')?></p>
                    <table class="table table-strippe table-dark">
                        <tbody id="tablavideoteca">
                            <!--Filas creadas dinamicamente jQuery-->
                        </tbody>
                    </table>
                    <p class="px-3">
                        <button class="btn btn-warning" type="button" id="agregarfila">Agregar &#x1f517;</button>
                        <button class="btn btn-success" type="button" id="crearVideoteca">Crear Videoteca</button>
                    </p>
                <?php endif;?>
            </div>
        </div>
        <div class="col-md-2 ">

        </div>
    </div>
        <!--Fin de fila-->
</div>
<div class="container bg-light p-0">
    <div class="row  m-0" id="noticias">
        <div class="col-md-8 p-0">
            <div id="crearnoticia">
                <div class="card card-body">
                    <?=$form_noticias?>
                </div>
            </div>
        </div>
        <div class="col-md-2">

        </div>
    </div>
</div>  
<?=$footer?>