<?php if($this->session->userdata('is_logged') === true) : ?>
<head>
<meta charset="UTF-8">
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="<?php echo base_url();?>/assets/css/bootstrap.css">
    <link rel="stylesheet" href="<?=base_url('assets/miestilo.css')?>">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <link rel="shortcut icon" href="<?=base_url('assets/img/sistema/abanderados.svg')?>" type="image/x-icon">
    <!--Fuentes de Google-->
    <link href="https://fonts.googleapis.com/css2?family=Raleway:wght@200&display=swap" rel="stylesheet">
    <!--Font-Awesome-->
    <link href="https://fonts.googleapis.com/css2?family=Raleway:wght@200&display=swap" rel="stylesheet">
    <script src="https://kit.fontawesome.com/3b9095d4bc.js" crossorigin="anonymous"></script>
    <title>Abanderados</title>
    <!-- Coloca este código dentro de la etiqueta <head> de tu web -->
    <title>Abanderados | <?=$info->titulo?></title>
    <meta name="description" content="<?=$info->descripcion?>"/>
    <!-- Open Graph data -->
    <meta property="og:title" content="<?=$info->titulo?>" />
    <meta property="og:type" content="<?=$info->subtitulo?>" />
    <meta property="og:url" content="<?=base_url('welcome/noticia/').$info->id_noticias?>" />
    <meta property="og:image" content="<?=base_url($info->imagen)?>" />
    <meta property="og:description" content="<?=base_url($info->descripcion)?>" />
    <meta property="og:site_name" content="&#x1f393;Abanderados">
    </meta property="fb:app_id" content="2314571125511723"/><!--Id en Facebook-->
</head>
<?=$nav?>
<body>
    <div class="container-fluid bg-white p-0">
    <div class="row m-0 py-4">
    <div class="container p-0">
        <div class="col-md-9 p-0">

            <div class="card shadow mb-5 bg-white rounded">
                <!--Titulo-->
                 <?php $row = $info;?>
                <h1 class="card-title p-3 font-weight-bold">
                    <a class="text-decoration-none azulFuerte" href="<?=base_url('welcome/noticia/').$row->id_noticias?>">
                        <?=$row->titulo?>
                    </a>
                </h1>
                <img class="card-img-top img-fluid w-100" src="<?=base_url($row->imagen)?>" width="100%;" height="auto" alt="imagen-portada">
                <div class="card-body">
                    <h3 class="card-subtitle py-1 text-muted text-uppercase font-weight-bold">
                        <?=$row->subtitulo?>
                    </h3>
                </div>
                <div class="px-3 font-weight-light text-justify">
                    <?=$row->descripcion?><br>
                </div>
                <p class="px-3 pt-2">
                    <small class="text-muted">Fuente: <?=$row->fuente?></small>
                </p>
                <div id="fb-root"></div>
                <script>
                    (function(d, s, id) {
                        var js, fjs = d.getElementsByTagName(s)[0];
                        if (d.getElementById(id)) 
                            return;
                            js = d.createElement(s); js.id = id;
                            js.src = "https://connect.facebook.net/en_US/sdk.js#xfbml=1&version=v3.0";
                            fjs.parentNode.insertBefore(js, fjs);
                    }(document, 'script', 'facebook-jssdk'));
                </script>

                    <!-- Your share button code -->
                <div class="p-3"> 
                    <div class="fb-share-button" 
                        data-href="<?=base_url('welcome/noticias/'.$info->id_noticias)?>" 
                        data-layout="button"
                        data-size="large">
                    </div>
                </div>
                <div class="card-footer bg-transparent borde-light">
                    <small class="text-muted">
                        <?php $fecha = explode('-', $row->fecha);?>
                        <i class="fas fa-calendar-check"></i> Publicado: 
                        <?=$fecha[2]."/".$fecha[1]."/".$fecha[0];?>
                    </small>
                </div>

            </div>
        </div>

        
    </div>
    </div>
    </div>
</body>
<?=$footer?>

<?php else : redirect(base_url()); endif;?>