<div class="p-3">
    <form action="<?=base_url('admin/buscarLinks')?>" method="post">
        <h4 class="font-weight-bold">Buscar videoteca existente</h4>
        <div class="row">
            <div class="col-md-7">
                <input class="form-control" type="text" name="carrera" id="carrera" placeholder="Carrera de la Materia" value="<?=(isset($carrera))? $carrera : ''?>" >
            </div>
            <div>
                <input class="form-control" type="hidden" id="id" value = "<?=(isset($id))? $id :''?>">
            </div>
            <div class="col-md-5">
                <input class="form-control" type="text" name="materia" id="materia" placeholder="Materia" value="<?=(isset($materia))? $materia : ''?>">
            </div>
        </div>
        <button type="submit" class="btn btn-outline-danger">Buscar</button>
    </form>
</div>


