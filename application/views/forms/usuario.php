<div class="container">
    <div class="card p-4"> 
        <div class="row">
            <div class="col-md-6">
                <p>
                    <h4 class="font-weight-light">
                        <?=$this->session->userdata('nombre')." ".$this->session->userdata('apellido')?>
                    </h4>
                </p>
                <p class="font-weight-lighter"> 
                    Correo electronico: <?=$this->session->userdata('correo')?>
                </p>
            </div>
            <div class="col-md-6">
                <img src="<?=base_url($this->session->userdata('imagen'))?>" alt="">
            </div>
        </div>
        <form action="" method="post">
           

        </form>
    </div>
</div>
