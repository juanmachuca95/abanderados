<div class="card p-4">
<?= (null != $this->session->flashdata('mensaje')) ? 
    '<p class="lead text-center">'.$this->session->flashdata('mensaje').'</p>' : 
    '';
?>
<h2 class="fontGoogle text-center py-4 align-items-center justify-content-center">
    <img src="<?=base_url('assets/img/sistema/abanderados.svg')?>" width="45">Abanderados
</h2>
<hr>
<form  action="<?=base_url('login/ingresar')?>" method="post">
    <h4 class="font-weight-bold py-2 azulFuerte">Iniciar Session</h4>
    <div class="form-group">
        <input class="form-control font-weight-light" type="email" name="correo" placeholder="Correo electronico" required>
    </div>
    <div class="form-group">
        <input class="form-control font-weight-light" type="password" name="password" minlength="4" maxlength="15" placeholder="Contraseña" required>
    </div>
    <div class="form-group">
        <button type="submit" class="btn btn-info form-control">Iniciar</button>
    </div>
    <div class="form-group">
        <div class="fb-login-button" data-size="large" data-button-type="login_with"  data-auto-logout-link="false" data-use-continue-as="true" data-width=""></div>
    </div>
     <small class="font-weight-light">¿No tienes cuenta a&uacuten?. Haz click aqu&iacute 
        <a class="text-decoration-none" href="#" id="registrate" >Registrate.</a>
    </small>
</form>
</div>