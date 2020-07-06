<?php 

class Configuraciones extends CI_Model{

    public function __construct(){
        parent::__construct();
        $this->load->database();
    }

    function get_datos(){
        if($sql = $this->db->get('configuraciones')){
            return $sql->result();
        }
        return false;
    }

}

?>