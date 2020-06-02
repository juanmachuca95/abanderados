<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Nosotros extends CI_Controller {

    public function __construct(){
        parent:: __construct();
        $this->load->library('session');
    }

    public function index(){
        if($this->session->userdata('is_logged')){
            $data = $this->getTemplate();
            $this->load->view('nosotros',$data);
        }else{
            show_404();
        }
    }

    function getTemplate(){
        $data = array(
            'footer'    => $this->load->view('layout/footer','',true),
            'nav'       => $this->load->view('layout/nav','',true),
            'head'      => $this->load->view('layout/head','',true),
        );
        return $data;
    }

}