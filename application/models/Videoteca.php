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

        //Lista las materias que contienen los links de video guias. 
        function get_datos($codigo){
            $this->db->where('id_institucion',$codigo);
            if($sql = $this->db->get('videoteca')){
                return $sql->result();
            }
            return false;
        }

        //lista todos los links de una materia en especifico. 
        function get_linksMateria($codigo){
            $this->db->select('links');
            $this->db->where('id_materia', $codigo);
            if($sql = $this->db->get('videoteca')){
                return $sql->row();
            }
            return false;
        }
    }
?>