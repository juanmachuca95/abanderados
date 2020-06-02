<?=$head?>
<div class="card">
    <form action="<?=base_url('admin/ingreso')?>" method="post">
        <input class="form-control" type="email" name="correo" placeholder="Correo" required>
        <input type="password" placeholder="Password" name="password" required>
        <button class="btn btn-outline-warning">Ingresar</button>
    </form>
</div>
