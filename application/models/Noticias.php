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

    function obtenernoticias(){
        if($sql = $this->db->get('noticias')){
            return $sql->result();
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

}