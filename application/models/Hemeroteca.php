<?php 

class Hemeroteca extends CI_Model{
    
    function __construct()
    {
        parent::__construct();
        $this->load->database();
    }

    /**
     * Todos los registros correspondientes a las carreras con sus respectivas instituciones
     */
    function get_datos(){
        if($sql = $this->db->get('biblioteca')){
            return $sql->result();
        }else{
            return false;
        }
    }

    function biblioteca_individual($codigo){
        $this->db->where('id_institucion', $codigo);
        $sql = $this->db->get('biblioteca');
        if($sql->num_rows() == 1){
            return $sql->row();
        }
        return false;
    }   
}

?>