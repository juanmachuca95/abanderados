<div class="container-fluid bg-light p-0 sticky-top">
  <div class="container p-0">
      <nav class="navbar navbar-expand-lg navbar-light p-2">
        <a class="navbar-brand font-weight-light" href="<?=base_url('usuario')?>">
            <img class="rounded-circle" src=<?=(($imagen = $this->session->userdata('imagen')) !== null) ? base_url($imagen) : '' ?> width="40" height="40" alt="perfil" loading="lazy">
              <?=(($nombre = $this->session->userdata('nombre')) !== null ) ? $nombre : '&#x1f393;Abanderados'?>
        </a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarNav">
          <ul class="navbar-nav ml-auto font-weight-bold text-center">
            <li class="nav-item">
              <a class="nav-link fontGoogle" href="<?=base_url('welcome')?>"><i class="fas fa-bell azulMarino"></i> Novedades</a>
            </li>
            <li class="nav-item">
              <a class="nav-link fontGoogle" href="<?=base_url('biblioteca')?>"> <i class="fas fa-book-reader azulMarino"></i> Biblioteca</a>
            </li>
            <li class="nav-item">
              <a class="nav-link fontGoogle" href="<?=base_url('nosotros')?>"><i class="fas fa-graduation-cap azulMarino"></i> Nosotros</a>
            </li>
            <li class="nav-item dropdown">
              <a class="nav-link fontGoogle dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                <i class="fas fa-palette azulMarino"></i> Menu
              </a>
              <div class="dropdown-menu dropdown-menu-right" aria-labelledby="navbarDropdown">
                <a class="dropdown-item fontGoogle" href="#"><i class="fas fa-cog azulMarino"></i> Configuraciones</a>
                <div class="dropdown-divider"></div>
                <?php if($this->session->userdata('is_logged')) : ?>
                <a class="dropdown-item fontGoogle" href="<?=base_url('login/logout')?>"><i class="fas fa-power-off azulMarino"></i> Salir</a>
                <?php endif;?>
              </div>
            </li>
          </ul>
        </div>
    </nav>
  </div>  
</div>