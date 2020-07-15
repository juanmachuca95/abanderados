<?php 
use function PHPSTORM_META\type;

defined('BASEPATH') OR exit('No direct script access allowed');

class Foro extends CI_Controller{

	function __construct(){
		parent::__construct();
		$this->load->library('session');
		$this->load->model('Chat');
		$this->load->model('User');
	}

	function showChat(){
        if(isset($_GET['recargar'])){
            $codigo = $this->session->userdata('cod_institucion');
            $data   = $this->Chat->get_chat($codigo);
            if(count($data) > $_GET['recargar']){
                echo json_encode($data);
            }else{
                echo json_encode(0);
            }
        }
    }

    /*Mensajes de usuario*/
    function actualizarChat(){
        if(isset($_GET['cargar'])){
            $codigo = $this->session->userdata('id_usuario');
            $imagen = $this->session->userdata('imagen');
            $inst   = $this->session->userdata('cod_institucion');
            $nombre = $this->session->userdata('nombre');
            $mensaje = $_GET['cargar'];
            $data = array('texto' => $mensaje, 'nombre'=>$nombre, 'id_usuario' => $codigo, 'id_institucion' => $inst);
            if($this->Chat->insert_chat($data)){
                echo "Datos cargados";
            }else{
                echo "Fallo la carga";
            }
        }
    }

    /*Mensajes de Administrador*/
    function actualizarChatAdmin(){
        if(isset($_GET['cargar'])){
            $codigo = '00';
            $inst   = $this->session->userdata('cod_institucion');
            $nombre = '&#x1f393; Abanderados';
            $mensaje = $_GET['cargar'];
            $data = array('texto' => $mensaje, 'nombre'=>$nombre, 'id_usuario' => $codigo, 'id_institucion' => $inst);
            if($this->Chat->insert_chat($data)){
                echo "Datos cargados";
            }else{
                echo "Fallo la carga";
            }
        }
    }

    function usuariosConectados(){
    	if(isset($_POST['user_activos'])){
			$datos = $this->User->get_userConectados();
			echo json_encode($datos);
    	}
    }
}

?>