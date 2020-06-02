<?php
class Roots extends CI_Model{
    function __construct()
    {
        parent::__construct();
        $this->load->database();
    }

    function habilitar($correo,$pass){
        $this->db->where('correo', $correo);
        $this->db->where('password', $pass);
        if($datos = $this->db->get('administradores')){
            return true;
        }
        return false;
    }
}

?>