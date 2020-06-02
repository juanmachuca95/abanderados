
<form class="was-validated" action="<?=base_url('admin/cargarnoticia')?>" method="POST" enctype="multipart/form-data">
  <h3 class="font-weight-light">Crea una Noticia</h3>
  <div class="custom-control custom-text mb-3 p-0">
      <label for="validationInputTitle">Titulo de la Noticia</label>
      <input type="text" class="form-control font-weight-bold" id="validationInputTitle" name="titulo" required>
  </div>
  <div class="custom-control custom-text mb-3 p-0">
      <label for="validationInputSubtitle">Subtitulo de la Noticia</label>
      <input type="text" class="form-control font-weight-light" id="validationInputSubtitle" name="subtitulo" required>
  </div>
  <div class="container p-0">
		<div class="row">
			<div class="col-sm-12">
				<div id="frm-test">
					<div class=>
            <textarea style="width: 100%; height: 100%;" id="txt-content" 
           ></textarea>
          </div>
          <button class="btn btn-outline-success my-3" id="btn-enviar">Procesar informacion</button>
			</div>
		</div>
      <div class="form-group px-3">
        <input class="form-control" type="text" id="texto" value="" name="descripcion" required >
      </div>
		</div>
	</div>

  <div class="custom-control custom-date mb-3 p-0">
      <label for="validationFecha">Fecha de la Noticia</label>
      <input type="text" class="form-control font-weight-light" id="fecha" name="fecha" value="" readonly>
  </div>
  <div class="custom-control custom-checkbox mb-3">
    <input type="checkbox" class="custom-control-input" id="customControlValidation1" required>
    <label class="custom-control-label" for="customControlValidation1">Checkeo de Informaci&oacuten</label>
  </div>

  <div class="custom-file mb-3">
    <input type="file" class="custom-file-input" accept="image/*" id="validatedArchivo" name="imagen" required>
    <label class="custom-file-label" for="validatedArchivo">Imagen de portada en la noticia</label>
  </div>
  
  <button class="btn btn-warning mt-4" type="submit">Crear Noticia</button>
</form>