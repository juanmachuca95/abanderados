<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Construccion extends CI_Controller{
    public function __construct()
    {
        parent::__construct();
    }

    public function index(){
        $data['head'] = $this->load->view('layout/head','', true);
        $this->load->view('construccion', $data);
    }

}