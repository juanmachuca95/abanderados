<?php 

class User extends CI_Model{
	function __construct(){
		parent::__construct();
		$this->load->database();
	}

	/*Actualiza el estado de un usuario Conectado o Desconectado*/
	function conectado($id, $estado){
		$this->db->where('id_usuario', $id);
		$this->db->set('conectado',$estado);
		$this->db->update('usuarios');
		return true;
	}

	/**/
	function get_userConectados(){
		$this->db->select('nombre');
		$this->db->select('apellido');
		$this->db->where('conectado', true);
		if($sql = $this->db->get('usuarios')){
			return $sql->result();
		}
		return false;
	} 
}

?>