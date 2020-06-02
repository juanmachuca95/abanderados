<?php
    class Videoteca extends CI_Model{

        function __construct(){
            parent::__construct();
            $this->load->database();
        }

        function cargar($data){
            if($this->db->insert('videoteca', $data)){
                return true;
            }
        }

        function actualizar($id, $data){
            $this->db->where('id_materia', $id);
            if($this->db->update('videoteca', $data)){
                return true;
            }
            return false;
        }

        function get_links($carrera, $materia){
            $this->db->select('*');
            $this->db->where('carrera',$carrera);
            $this->db->where('materia',$materia);
            $sql = $this->db->get('videoteca');
            if($sql->num_rows() == 1){
                return $sql->row();
            }
            return false;
        }

    }
?>