<?php

use function PHPSTORM_META\type;

defined('BASEPATH') OR exit('No direct script access allowed');

class Terminos extends CI_Controller{

	public function __construct(){
		parent::__construct();
	}

	function index(){
		$this->load->view('politica_privacidad.html');
	}

}