<?php
class Roots extends CI_Model{
    function __construct()
    {
        parent::__construct();
        $this->load->database();
    }

    function habilitar($correo,$pass,$codigo){
        $this->db->where('correo', $correo);
        $this->db->where('password', $pass);
        $this->db->where('codigo', $codigo);
        $datos = $this->db->get('administradores');
        if($datos->num_rows() == 1){
            return $datos->row();
        }
        return false;
    }
}

?>