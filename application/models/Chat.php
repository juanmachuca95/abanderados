<?php 

class Chat extends CI_Model{
	function __construct(){
		parent::__construct();
		$this->load->database();
	}

	function get_chat($codigo){
		$this->db->where('id_institucion', $codigo);
		$sql = $this->db->get('chat');
		return $sql->result();
	}

	function insert_chat($data){
		if($this->db->insert('chat', $data)){
			return true;
		}
		return false;
	}
}

?>