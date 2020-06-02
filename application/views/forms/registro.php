<div class="card p-4">
<h1 class="font-weight-light text-center pb-2">
    🎓Abanderados
</h1>
<form id="form_usuario" action="<?=base_url('login/registro')?>" method="post">
    <h3 class="font-weight-bold py-3">Crea tu cuenta</h3>
    <div class="form-group">     
        <input class="form-control" id="inputNombre" name="nombre" minlength="4" maxlength="30" type="text" placeholder="Ingresa un nombre" required
        title="No se aceptan numeros en el nombre o caracteres especiales">
        <small class="text-primary" id="outputNombre"></small>
    </div>

    <div class="form-group">
        <input class="form-control" id="inputApellido" name="apellido" minlength="4" maxlength="30" type="text" placeholder="Ingresa un Apellido" required
        title="No se aceptan numeros en el nombre o caracteres especiales">
        <small class="text-primary" id="outputApellido"></small>
    </div>
    
    <div class="form-group">
        <input class="form-control" id="inputEmail" type="email" name="correo" maxlength="80" placeholder="Correo. Ej.: nombre@gmail.com " required>
        <small class="text-primary" id="outputEmail"></small>
    </div>
    <div class="form-row">
        <div class="form-group col-xs-12 col-ms-12 col-md-6">
            <label for="inputPassword">Contraseña
                <i id="show_pss" class="cerrados">
                    &#x1f573;
                </i>
            </label>
            <input class="form-control" id="inputPassword" minlength="8" maxlength="12" pattern="[A-Za-z0-9]+" type="password" name="password" placeholder="No mayor de 12 digitos" required>
        </div>
        <div class="form-group col-xs-12 col-ms-12 col-md-6">
            <label for="inputPasswordRepet">Repite Contraseña 
                <i id="show_pss_repet" class="cerrados_repet">
                    &#x1f573;
                </i>
            </label>

            <input class="form-control" id="inputPasswordRepet" minlength="8" maxlength="12" pattern="[A-Za-z0-9]+" type="password"
            name="password2" placeholder="No mayor de 12 digitos" required>
        </div>
        <div class="mb-3">
            <small class="text-primary" id="outputPassword"></small>
        </div>
    </div>
    <div class="form-group">
        <div class=" justify-content-center">
            <button type="submit" class="btn btn-warning form-control">Registrarse</button>
        </div>
    </div>
    <p><?php if (isset($error)) { echo $error; }  ?></p>

    <small class="font-weight-light">¿Ya tienes una cuenta a&uacuten?. Haz click aqu&iacute 
        <a class="text-decoration-none" href="#" id="login">Login.</a>
    </small>

</form>
</div>