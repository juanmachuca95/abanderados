
<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Usuario extends CI_Controller {

    public function __construct(){
        parent:: __construct();
        $this->load->library('session');
        $this->load->model('Autenticar');
        $this->load->model('User');
    }

    public function index(){
        if($this->session->userdata('is_logged')){
            $data = $this->getTemplate();
            $this->load->view('usuario',$data);
        }else{
            show_404();
        }
    }

    function getTemplate(){
        $data = array(
            'head'      => $this->load->view('layout/head','',true),
            'nav'       => $this->load->view('layout/nav','',true),
            'footer'    => $this->load->view('layout/footer','',true),
            'info_user' => $this->load->view('contenido/usuario','',true)
        );
        return $data;
    }

    function actualizarImagen(){
        $this->load->library('upload');
		$config['upload_path']      = 'assets/img/Usuarios/';
		$config['allowed_types']    = 'gif|jpg|jpeg|png';
		$config['max_size']         = '10024';
		$config['max_width']        = '6000';
		$config['max_height']       = '6000';
        $this->upload->initialize($config);

        if(isset($_FILES['file'])){
            $imagen     = $this->session->userdata('imagen');
            $url        = "assets/img/Usuarios/".$_FILES['file']['name'];
            if($url != $imagen){ //carga la imagen si no es repetida
                $this->upload->do_upload('file');
                //print_r($url);
                $id_user    = $this->session->userdata('id_usuario');
                $data       = array('id_usuario' => $id_user, 'imagen' => $url);
                //echo "El id es $id_user y la imagen es $url";
                if($this->Autenticar->actualizar_imagen($data)){
                    unlink($imagen);//elimina la imagen existente;
                    $this->session->set_userdata('imagen', $url);
                    $datos['actualizacion']  = true;
                    $datos['imagen']         = base_url().$url;
                    echo json_encode($datos);
                }
			}else{
                $data['actualizacion'] = false;
                echo json_encode($data);
            }
        }
    }

}