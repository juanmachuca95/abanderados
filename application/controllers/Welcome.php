<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Welcome extends CI_Controller {

	public function __construct()
	{
		parent::__construct();
		$this->load->model('Noticias');
		$this->load->library('session');
	}
	
	public function index()
	{
		if($this->session->userdata('is_logged')){
			$data = $this->getTemplate();
			$this->load->view('welcome',$data);
		}else{
			$data = $this->getTemplateLogin();
			$this->load->view('login', $data);
		}
	}

	function getTemplate(){
		$datos = $this->getNoticias();
		$cantidad = $this->Noticias->cantidadnoticias();
		//var_dump($cantidad);//output int(1)
		//var_dump($datos);//recibo las noticias. 
		$data = array(
			'noticias' 		=> $this->Noticias->bloquenoticias(2,0), 
			'current_page' 	=> 0,
			'last_page' 	=> ceil($this->Noticias->cantidadnoticias() / 2 ),
			'head' 			=> $this->load->view('layout/head','',true),
			'nav'			=> $this->load->view('layout/nav','',true),
			'footer' 		=> $this->load->view('layout/footer','',true),
			'aside'			=> $this->load->view('layout/aside','',true),
		);
		return $data; 
	}

	public function getTemplateLogin(){
		$data =  array(
			'head' => $this->load->view('layout/head','',true),
			'footer' => $this->load->view('layout/footer', '', true),
			'contenido' => $this->load->view('contenido/contenido_login.php',$data = array(
				'form_login'	=> $this->load->view('forms/login','', true),
				'form_registro'	=> $this->load->view('forms/registro','',true)), 
			true ),
		 );
		return $data;
    }

	function getNoticias(){
		if($noticias = $this->Noticias->obtenernoticias()){
			return $noticias;
		}else{
			return false;
		}
	}

	function noticias($page = 1){
		if($this->session->userdata('is_logged')):
		$page--;
			if($page < 0){
				$page = 0;
			}
			$page_size = 2;
			$offset = $page * $page_size;

			$data = $this->getTemplate();
			$data['noticias'] = $this->Noticias->bloquenoticias($page_size, $offset);
			$data['current_page'] = $page;
			$data['last_page'] = ceil($this->Noticias->cantidadnoticias() / $page_size );
			$this->load->view('welcome',$data);
		endif;
	}

}
