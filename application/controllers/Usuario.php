
<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Usuario extends CI_Controller {

    public function __construct(){
        parent:: __construct();
        $this->load->library('session');
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
            'info_user' => $this->load->view('forms/usuario','',true)
        );
        return $data;
    }
}