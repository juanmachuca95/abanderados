<script src="https://cdn.ckeditor.com/4.14.0/standard/ckeditor.js"></script>
<link rel="stylesheet" href="<?php echo base_url();?>/assets/miestilo.css">
<?php if ($msj = $this->session->flashdata('msj_noticia_bien')) : ?>
  <p class="font-weight-light text-info">¡<?=$msj?>&#x1f44d;!</p>
<?php endif; ?>
<?php if ($msj = $this->session->flashdata('msj_noticia_mal')) : ?>
  <p class="font-weight-light text-danger">¡<?=$msj?>!</p>
<?php endif; ?>
<form action="<?=base_url('admin/cargarnoticia')?>" method="POST" enctype="multipart/form-data">
  <div class="form-group">
    <h5 class="font-weight-lighter mb-3">Crea una Noticia</h5>
    <input class="form-control font-weight-lighter"  type="text" id="titulo"    name="titulo"    placeholder="Titulo de la Noticia" required>
  </div>
  <div class="form-group">
    <input class="form-control font-weight-lighter" type="text"  id="subtitulo" name="subtitulo" placeholder="Subtitulo" required>
  </div>
  <div class="form-group">
    <textarea class="form-control" style="width: 100%; height: 100%;" id="txt-content" name="descripcion" 
      required></textarea>
    <script>
      CKEDITOR.replace( 'descripcion' );
    </script>
  </div>
  <div class="form-group">
      <label class="font-weight-lighter" for="fecha">Fecha actual de publicación</label>
      <input class="form-control font-weight-light" type="text" id="fecha" name="fecha" value="" readonly>
  </div>
  <div class="form-group">
    <textarea class="form-control" name="resumen" id="resumen" cols="30" rows="3" placeholder="Breve resumen de la noticia (Maximo 200 caracteres)"></textarea>
  </div>
  <div class="form-group">
    <input class="form-control font-weight-lighter" type="text" name="fuente" placeholder="Fuente de la Noticia" required>
  </div>
  <div class="custom-file">
    <input type="file" class="custom-file-input" id="etiqueta" accept="image/*" name="imagen" required>
    <label class="custom-file-label font-weight-lighter" for="etiqueta">Imagen de Portada</label>
  </div>
  <button class="btn btn-warning mt-4" type="submit">Crear Noticia</button>
</form>
