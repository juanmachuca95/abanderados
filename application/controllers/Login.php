<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Login extends CI_Controller{
    public function __construct(){
        parent::__construct();
        $this->load->model('Autenticar');
        $this->load->model('Noticias');
        $this->load->library(array('session'));
    }

    public function index(){
        if($this->session->userdata('is_logged')){
            $data = $this->templateWelcome();
            $this->load->view('welcome',$data);
        }else{
            $data = $this->getTemplate();
            $this->load->view('login', $data);    
        }
    }

    function ingresar(){
        $correo = $this->input->post('correo','', true);
        $pass   = $this->input->post('password','', true);
        //echo $correo." ".$pass;
        //echo "<br>".password_hash($pass, PASSWORD_BCRYPT);
        if($dato = $this->Autenticar->login($correo, $pass)){

            //Si el usuario activo la cuenta por correo entrara. 
            //echo "<br>Datos encontrados";
            if($dato->activo == true){
                $data = array(
                    'id_usuario' => $dato->id_usuariv,
                    'nombre'     => $dato->nombre,
                    'apellido'   => $dato->apellido,
                    'correo'     => $dato->correo,
                    'imagen'     => $dato->imagen,
                    'is_logged'  => true,
                );
                //Variables de session
                $this->session->set_userdata($data);
                $data =  $this->templateWelcome();
                $this->load->view('welcome',$data);
            }else{
                //echo "<br>Usuario no confirmado";
                $this->session->set_flashdata('mensaje', 'Necesitas activar tu cuenta antes de ingresar.');
                $data = $this->getTemplate();
                $this->load->view('login', $data);
            }
        }else{
            $this->session->set_flashdata('mensaje', '¡Ups! Datos incorrectos intentalo de nuevo o registrate.');
            $data = $this->getTemplate();
            $this->load->view('login', $data);
        }
    }

    
    public function getTemplate(){
		$data =  array(
			'head' => $this->load->view('layout/head','',true),
			'footer' => $this->load->view('layout/footer', '', true),
			'contenido' => $this->load->view('contenido/contenido_login.php',$data = array(
				'form_login'	=> $this->load->view('forms/login','', true),
				'form_registro'	=> $this->load->view('forms/registro','',true)), 
			true ),
		 );
		return $data;
    }
    
    function templateWelcome(){
        $data =  array(
            'noticias' 		=> $this->Noticias->bloquenoticias(2,0), 
            'current_page' 	=> 0,
            'last_page' 	=> ceil($this->Noticias->cantidadnoticias() / 2 ),
            'head'          => $this->load->view('layout/head','',true),
            'footer'        => $this->load->view('layout/footer', '', true),
            'nav'           => $this->load->view('layout/nav','',true),
            'aside'         => $this->load->view('layout/aside','',true)
        );
        return $data;
    }

    function registro(){
        $nombre     = $this->input->post('nombre','',true);
        $apellido   = $this->input->post('apellido','',true);
        $correo     = $this->input->post('correo','',true);
        $password   = $this->input->post('password','',true);

        //echo $nombre." ".$apellido." ".$correo." ".$password;
        $password =  password_hash($password, PASSWORD_BCRYPT);
        //esto genera un codigo unico para el usuario. 
        $codigo = uniqid();
        //echo "<br>Codigo de activacion : ".$codigo;
        //echo "<br>Contraseña encryptada : ".$password;
        $data = array(
            'nombre'    => $nombre,
            'apellido'  => $apellido,
            'correo'    => $correo,
            'password'  => $password,
            'activo'    => false,
            'codigo'    => $codigo,
        );

        //si no es un usuario registrado con un correo existente, registrara. 
        if($this->Autenticar->usuario_repetido($correo) == false){
            //Una vez cargado, se procede al envio del email. 
            $id = $this->Autenticar->registro($data);
            $asunto = "Verificación y Activación de cuenta.";
            
            $data_user = array(
                'asunto'    => $asunto, 
                'nombre'    => $nombre, 
                'id'        => $id,
                'codigo'    => $codigo
            );

            $mensaje = $this->formatoemail($data_user);

            $this->load->library('email');
            $config['mailtype'] = 'html';
            $this->email->initialize($config);

            $this->email->from('machucajuangabriel', 'Juan Machuca');
            $this->email->to($correo);
            //$this->email->cc('another@another-example.com'); 
            $this->email->subject($asunto);
            $this->email->message($mensaje);
            
            //$this->email->send();
            if($this->email->send()){
                $this->session->set_flashdata('mensaje','
                Se te ha enviado un email de confirmacion &#x2709;.');
                $dato = $this->getTemplate();
                $this->load->view('login',$dato);
            }else{
                $this->session->set_flashdata('mensaje','
                Vuelve a intentarlo y asegurate de escribir bien el correo electronico.');
                $dato = $this->getTemplate();
                $this->load->view('login',$dato);
            }
        }else{
            $this->session->set_flashdata('mensaje', 'Ya existe un usuario con el mismo correo');
            $data = $this->getTemplate();
            $this->load->view('login',$data);
        } 
    }

    function logout(){
        $data = array('id_usuario','nombre','correo','is_logged');
        $this->session->unset_userdata($data);
        $this->session->sess_destroy();

        redirect('login','refresh');
    }
    //Lo puse aparte por si luego le quiero cambiar el formato. 
    function formatoemail($data_user){
        $nombre = $data_user['nombre'];
        $id     = $data_user['id'];
        $codigo = $data_user['codigo'];
        $mensaje = " 
        <h1 style='
            align-text: center;
            font-weight: light;
            padding: 40px;'
        >
            !Bienvenido a Abanderados $nombre!    
        </h1>
        <h4 style='font-weight: bold;' >Nos honra tenerte aqui, esperamos poder cumplir todas tus espectativas. </h4>
        
        <p style='font-weight: light;' >
            Para comenzar a enterarte de todo lo que sucede en Abanderados solo tienes que activar tu cuenta: 
        </p>
        <a style='font-weight: light; text-decoration-none' href='".base_url('login/activarusuario/'.$id.'/'.$codigo)."'>
            Confirmacion de cuenta
        </a>'";
        
        return $mensaje;
    }

    function activarusuario(){
        $id     =   $this->uri->segment(3);
        $codigo =   $this->uri->segment(4);

        $user = $this->Autenticar->get_usuario($id);
        //var_dump($user);
        if($user->codigo == $codigo){
            
            if($this->Autenticar->activar_usuario($id)){
                $this->session->set_flashdata('mensaje','Tu cuenta ha sido activada con exito!');
                $data = $this->getTemplate();
                $this->load->view('login',$data);

            }

        }
    }

}