<?php
defined('BASEPATH') OR exit('No direct script access allowed');


class Home extends CI_Controller {

    public function index()
	{
		$data = $this->getTemplate();
		$this->load->view('home',$data);
	}

	public function getTemplate(){
		$data =  array(
			'head' => $this->load->view('layout/head','',true),
			'footer' => $this->load->view('layout/footer', '', true),
		 );
		return $data;
	}
}

