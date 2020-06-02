<div class="container-fluid bg-light p-0 sticky-top">
  <div class="container p-0">
        <nav class="navbar navbar-expand-lg navbar-light p-2">
      <a class="navbar-brand font-weight-light" href="<?=base_url('usuario')?>">
          <img class="rounded-circle" src=<?=(($imagen = $this->session->userdata('imagen')) !== null) ? base_url($imagen) : '' ?> width="30" height="30" alt="" loading="lazy">
            <?=(($nombre = $this->session->userdata('nombre')) !== null ) ? $nombre : '&#x1f393;Abanderados'?>
      </a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNav">
          <ul class="navbar-nav ml-auto font-weight-bold">
            <li class="nav-item">
              <a class="nav-link" href="<?=base_url('welcome')?>">Noticias</a>
            </li>
            <li class="nav-item">
              <a class="nav-link" href="<?=base_url('biblioteca')?>">Biblioteca</a>
            </li>
            <li class="nav-item">
              <a class="nav-link" href="<?=base_url('nosotros')?>">Nosotros</a>
            </li>
            <li class="nav-item">
              <?php if($this->session->userdata('is_logged')) : ?>
              <a class="nav-link" href="<?=base_url('login/logout')?>">Salir</a>
              <?php endif;?>
            </li>
          </ul>
        </div>
      </nav>
  </div>  
</div>