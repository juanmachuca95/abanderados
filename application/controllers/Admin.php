<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Admin extends CI_Controller{

    public function __construct()
    {
        parent::__construct();
        $this->load->library('session');
        $this->load->model('Noticias');
        $this->load->model('Hemeroteca');
        $this->load->model('Videoteca');
        $this->load->model('Configuraciones');
        $this->load->model('Roots');
        $this->load->helper('directory');
    }

    function index(){
        if($this->session->userdata('habilitado')){
            $data = $this->getTemplate();
            $this->load->view('admin/panel',$data);
        }else{
            $data['head'] = $this->load->view('layout/head','',true);
            $this->load->view('admin/ingreso', $data);
        }
        
    }

    function getTemplate(){
        $codigo = $this->session->userdata('cod_institucion');
        $data = array(
            //'hemeroteca'     => $this->Hemeroteca->get_datos(),
            'configuraciones'   => $this->Configuraciones->get_datos(),
            'videoteca'         => $this->Videoteca->get_datos($codigo),
            'institucion'    => $this->Hemeroteca->biblioteca_individual($codigo),
            'form_noticias'  => $this->load->view('forms/noticias','',true),
            //'form_videoteca' => $this->load->view('forms/videoteca','',true),
            'head'           => $this->load->view('layout/head','',true),
            'footer'         => $this->load->view('layout/footer','',true)
        );
        return $data;
    }

    function ingreso(){
        $correo = $this->input->post('correo','',true);
        $pass   = $this->input->post('password','',true);
        $codigo = $this->input->post('codigo', '', true);//Codigo referido a Insti-Escuela, Etc. 

        if($dato = $this->Roots->habilitar($correo, $pass, $codigo)){
            $this->session->set_userdata('habilitado',true);
            $this->session->set_userdata('cod_institucion', $dato->institucion);
            redirect('admin');
        }else{
            $this->session->set_flashdata('Mensaje', '¡Acceso denegado! Datos erroneos.');
            $this->session->set_userdata('habilitado', false);
            redirect('admin','refresh');
        }
    }

    function logout(){
        $this->session->unset_userdata('habilitado');
        $this->session->sess_destroy();

        redirect('admin','refresh');
    }

    function cargarnoticia(){
        $titulo         = $this->input->post('titulo','',true);
        $subtitulo      = $this->input->post('subtitulo', '', true);
        $descripcion    = addslashes($this->input->post('descripcion','',true));
        $resumen        = $this->input->post('resumen','', true);
        $imagen         = $_FILES['imagen']['name'];
        $fecha          = $this->input->post('fecha','',true);
        $fuente         = $this->input->post('fuente','',true);
        $id_institucion = $this->session->userdata('cod_institucion');

        //var_dump($fecha);
        $fecha_sql = explode("-",$fecha);
        $fecha = $fecha_sql[2]."-".$fecha_sql[1]."-".$fecha_sql[0];
        //echo "<br>".$titulo."<br>".$subtitulo."<br>".$descripcion."<br>".$imagen."<br>".$fecha;
        $this->load->library('upload');
		//Configuracion para el archivo img
		$config['upload_path'] = 'assets/img/noticias/';
		$config['allowed_types'] = 'jpg|jpeg|png';
		$config['max_size'] = '10024';
		$config['max_width']  = '6000';
		$config['max_height']  = '6000';
		// Inicializa la configuración para el archivo 
		$this->upload->initialize($config);
        
        if($this->upload->do_upload('imagen')){
            // Mueve archivo a la carpeta indicada en la variable $data
            //$data = $this->upload->data();
            $url ="assets/img/noticias/".$imagen;
            $data = array(
                'id_institucion'=> $id_institucion,
                'titulo'        => $titulo,
                'subtitulo'     => $subtitulo,
                'descripcion'   => $descripcion,
                'resumen'       => $resumen,
                'imagen'        => $url,
                'fecha'         => $fecha,
                'fuente'        => $fuente
            );
            if($this->Noticias->crearnoticia($data)){
                $msg = "La noticia se creo correctamente";
                $this->session->set_flashdata('msj_noticia_bien',$msg);
                redirect('admin', 'refresh');
            }else{
                $msg = "Ha ocurrido un error al crear la noticia";
                $this->session->set_flashdata('msj_noticia_mal',$msg);
                redirect('admin', 'refresh');
            }
        }else{
            "No se pudo cargar la imagen";
        }
    }

    function links(){
        if(isset($_POST['arrayDeLinks']) && isset($_POST['arrayDeTitulos']) && isset($_POST['codigoMateria']) ){
            $listaDeLinks       = json_decode($_POST["arrayDeLinks"], true );
            $listaDeTitulos     = json_decode($_POST["arrayDeTitulos"], true);
            $materia            = $_POST["codigoMateria"];

            for($i=0; $i < count($listaDeLinks); $i++){
                $links[$listaDeTitulos[$i]] = $listaDeLinks[$i];
            }    
            $links = serialize($links);
            $data  = array(
                'links'     => $links
            );
            ($this->Videoteca->actualizar($materia, $data)) ? print "Actualizacion exitosa." : print'No se actualizaron los datos';
        }
    }

    function directorio(){
        if( isset($_POST['dir']) ){
            $dato = json_decode($_POST['dir']);
            $ruta   = './assets/biblioteca/'.$dato;
            $datos  = directory_map($ruta, 1, true);
            echo json_encode($datos);
        }else{
            echo "No llego";
        }
    }

    function getLinks(){
        if(isset($_POST['codigo'])){
            $cod_materia = $_POST['codigo'];
            $datos = $this->Videoteca->get_linksMateria($cod_materia);
            $enlace = preg_replace_callback('!s:\d+:"(.*?)";!s', function($m) { return "s:" . strlen($m[1]) . ':"'.$m[1].'";'; }, $datos->links);
            $enlace = unserialize($enlace);
            echo json_encode($enlace);
        }else{
            echo false;
        }
    }
}