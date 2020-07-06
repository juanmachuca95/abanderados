<?php

use function PHPSTORM_META\type;

defined('BASEPATH') OR exit('No direct script access allowed');


class Biblioteca extends CI_Controller{
    public function __construct()
    {
        parent::__construct();
        $this->load->model('Hemeroteca');
        $this->load->model('Videoteca');//Revisar
        $this->load->helper('directory');
        $this->load->library('session');
    }

    function index(){
        //echo "biblioteca de abanderados";
        if($this->session->userdata('is_logged')){
            $data = $this->getTemplate();
            $this->load->view('biblioteca',$data);
        }else{
            show_404();
        }
    }

    function getTemplate(){
        $codigo = $this->session->userdata('cod_institucion');
		$data =  array(
            'videoteca' => $this->Videoteca->get_datos($codigo),
            'head'      => $this->load->view('layout/head','',true),
            'nav'       => $this->load->view('layout/nav','',true),
            'footer'    => $this->load->view('layout/footer', '', true),
		 );
		return $data;
    }
    
    function listaReproduccion(){
        if(isset($_POST['codigoMateria'])){
            $cod    = $_POST['codigoMateria'];
            $datos  = $this->Videoteca->get_LinksMateria($cod);
            $enlace = preg_replace_callback('!s:\d+:"(.*?)";!s', function($m) { return "s:" . strlen($m[1]) . ':"'.$m[1].'";'; }, $datos->links);
            $enlace = unserialize($enlace);
            echo json_encode($enlace);
        }
    }
    
}