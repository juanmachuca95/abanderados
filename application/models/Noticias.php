<?php

class Noticias extends CI_Model{

    function __construct()
    {
        parent::__construct();
        $this->load->database();
    }

    function crearnoticia($data){
        if($this->db->insert('noticias',$data)){
            return true;
        }else{
            return false;
        }
    }


    function cantidadnoticias(){
        $this->db->select( '*');
        $this->db->from('noticias');
        if($query = $this->db->get()){
            return $query->num_rows();
        }else{
            return false;
        }
    }

    function bloquenoticias($page_size, $offset){
        $this->db->select( '*');
        $this->db->limit($page_size, $offset);
        if($query = $this->db->get('noticias')){
            return $query->result();
        }else{
            return false;
        }
    }

    function noticias_institucion($codigo){
        $this->db->select('*');
        $this->db->where('id_institucion',$codigo);
        if($sql = $this->db->get('noticias')){
            return $sql->result();
        }
        return false;
    }

    function getPaginacion($limit, $offset, $codigo){
        $this->db->where('id_institucion', $codigo);
        $sql = $this->db->get('noticias', $limit, $offset);
        return $sql->result();
    }

    function noticias_abanderados(){
        $this->db->select('*');
        $this->db->where('id_institucion',0);
        if($sql = $this->db->get('noticias')){
            return $sql->result();
        }
        return false;
    }

    function noticia_individual($id){
        $this->db->where('id_noticias',$id);
        $sql = $this->db->get('noticias');
        if($sql->num_rows() == 1){
            return $sql->row();
        }
        return false;
    }

}