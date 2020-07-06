<?php 

class Autenticar extends CI_Model{
    function __construct()
    {
        parent::__construct();
        $this->load->database();
    }

    function login($email, $pass){
        $this->db->where('correo', $email);
        if($sql = $this->db->get('usuarios')){
            if(password_verify($pass, $sql->row('password'))){
                return $sql->row();
            }
            return false; 
        }
        return false;
    }

    function registro($data){
        if($this->db->insert('usuarios', $data)){
            return $this->db->insert_id();
        }
        return false;
    }

    function get_usuario($id){
        $sql = $this->db->get_where('usuarios',array('id_usuario' => $id));
        if($sql->num_rows() == 1){
            return $sql->row();
        }
        return false;
    }

    function activar_usuario($id){
        $this->db->set('activo', true);
        $this->db->where('id_usuario', $id);
        if($this->db->update('usuarios')){
            return true;
        }
        return false;
    }

    function usuario_repetido($correo){
        $this->db->where('correo',$correo);
        $sql = $this->db->get('usuarios');
        if($sql->num_rows() > 0){
            return true;
        }
        return false;
    }

    function actualizar_imagen($data){
        $this->db->where('id_usuario',$data['id_usuario']);
        $this->db->set('imagen',$data['imagen']);
        if($this->db->update('usuarios')){
            return true;
        }
        return false;
    }

    function get_instituciones(){
        if($sql = $this->db->get('instituciones')){
            return $sql->result();
        }
        return 0;
    }
}

?>