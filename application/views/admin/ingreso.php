<?=$head?>
<div class="col-md-12 d-flex justify-content-center align-items-center p-0 w-100 h-100">
    <div class="col-md-4 card p-4">
        <p class="font-weight-light text-danger">
            <?=($dato = $this->session->flashdata('Mensaje')) ? $dato : ''; ?>
        </p>
        <h5 class="font-weight-bold pb-3">Ingreso Administrador</h5>
        <form action="<?=base_url('admin/ingreso')?>" method="post">
            <input class="form-control my-3" type="email" name="correo" placeholder="Correo" required>
            <input class="form-control my-3" type="password" placeholder="Password" name="password" required>
            <input class="form-control my-3" type="text" placeholder="Codigo: Ej. 1-2-4" name="codigo" maxlength="6" minlength="6" required>
            <button class="btn btn-warning form-control my-3">Ingresar</button>
        </form>
    </div>
</div>

