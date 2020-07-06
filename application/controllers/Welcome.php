<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Welcome extends CI_Controller {

	function __construct()
	{
		parent::__construct();
		$this->load->model('Noticias');
		$this->load->library('session');
	}
	
	function index( $offset = 0 )
	{
		if($this->session->userdata('is_logged')){
			$codigo = $this->session->userdata('cod_institucion');
			$data 	= $this->getTemplate();

			$noticias = $this->getNoticias();
			$this->load->library('pagination');
			$config['base_url'] = base_url('welcome/index');
			$config['total_rows'] = count($noticias);
			$config['per_page'] = 3;

			/*Estilos Bootstrap para la paginacion*/
			$config['full_tag_open'] 	= '<div class="pagging text-center"><nav><ul class="pagination m-0 px-1 pb-4">';
			$config['full_tag_close'] 	= '</ul></nav></div>';
			$config['num_tag_open'] 	= '<li class="page-item"><span class="page-link">';
			$config['num_tag_close']	= '</span></li>';
			$config['cur_tag_open']		= '<li class="page-item active"><span class="page-link">';
			$config['cur_tag_close']	= '<span class="sr-only">(current)</span></span></li>';
			$config['next_tag_open']	= '<li class="page-item"><span class="page-link">';
			$config['next_tagl_close']	= '<span aria-hidden="true">&raquo;</span></span></li>';
			$config['prev_tag_open']	= '<li class="page-item"><span class="page-link">';
			$config['prev_tagl_close']  = '</span></li>'; 
			$config['first_tag_open']	= '<li class="page-item"><span class="page-link">';
			$config['first_tagl_close']	= '</span></li>';
			$config['last_tag_open']	= '<li class="page-item"><span class="page-link">';
			$config['last_tagl_close'] = '</span></li>';

			$this->pagination->initialize($config);

			$lista = $this->Noticias->getPaginacion($config['per_page'], $offset, $codigo);
			$data['noticias_inst'] = $lista;
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
			/*'noticias_inst' => $this->Noticias->noticias_institucion($this->session->userdata('cod_institucion')),*/
			'head' 			=> $this->load->view('layout/head','',true),
			'nav'			=> $this->load->view('layout/nav','',true),
			'footer' 		=> $this->load->view('layout/footer','',true),
			'aside'			=> $this->load->view('layout/aside','',true),
		);
		return $data; 
	}

	function getTemplateLogin(){
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
		$codigo = $this->session->userdata('cod_institucion');
		if($noticias = $this->Noticias->noticias_institucion($codigo)){
			return $noticias;
		}else{
			return false;
		}
	}

	function noticia( $id_noticia ){
		if($dato = $this->Noticias->noticia_individual($id_noticia)){
			$data = $this->getTemplate();
			$data['head'] = '';
			$data['info'] = $dato;
			$this->load->view('layout/noticia', $data);
		}
	}
}
