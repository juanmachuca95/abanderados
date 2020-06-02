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
        $this->load->model('Roots');
    }

    public function index(){
        if($this->session->userdata('habilitado')){
            $data = $this->getTemplate();
            $this->load->view('admin/panel',$data);
        }else{
            $data['head'] = $this->load->view('layout/head','',true);
            $this->load->view('admin/ingreso', $data);
        }
        
    }

    function getTemplate(){
        $data = array(
            'hemeroteca'     => $this->Hemeroteca->get_datos(),
            'form_noticias'  => $this->load->view('forms/noticias','',true),
            'form_videoteca' => $this->load->view('forms/videoteca','',true),
            'head'           => $this->load->view('layout/head','',true),
            'nav'            => $this->load->view('admin/nav_admin','',true),
            'footer'         => $this->load->view('layout/footer','',true)
        );
        return $data;
    }

    function ingreso(){
        $correo = $this->input->post('correo','',true);
        $pass   = $this->input->post('password','',true);

        if($this->Roots->habilitar($correo, $pass)){
            $this->session->set_userdata('habilitado',true);
            $data = $this->getTemplate();
            $this->load->view('admin/panel', $data); 
        }else{
            $this->session->set_userdata('habilitado', false);
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
        $descripcion    = $this->input->post('descripcion','',true);
        $imagen         = $_FILES['imagen']['name'];
        $fecha          = $this->input->post('fecha','',true);
        //var_dump($fecha);
        $fecha_sql = explode("-",$fecha);
        $fecha = $fecha_sql[2]."-".$fecha_sql[1]."-".$fecha_sql[0];
        //echo "<br>".$titulo."<br>".$subtitulo."<br>".$descripcion."<br>".$imagen."<br>".$fecha;
        $this->load->library('upload');
		//Configuracion para el archivo img
		$config['upload_path'] = 'assets/img/noticias/';
		$config['allowed_types'] = 'gif|jpg|jpeg|png';
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
                'titulo'        => $titulo,
                'subtitulo'     => $subtitulo,
                'descripcion'   => $descripcion,
                'imagen'        => $url,
                'fecha'         => $fecha,
            );
            if($this->Noticias->crearnoticia($data)){
                $msg = "La noticia se creo correctamente";
                $this->session->set_flashdata('mensaje',$msg);
                redirect('admin', 'refresh');
            }else{
                $msg = "Ha ocurrido un error al crear la noticia";
                $this->session->set_flashdata('mensaje',$msg);
                redirect('admin', 'refresh');
            }
        }else{
            "No se pudo cargar la imagen";
        }
    }

    function buscarLinks(){
        $carrera = $this->input->post('carrera','',true);
        $materia = $this->input->post('materia','',true);
        if($datos = $this->Videoteca->get_links($carrera, $materia)){
            $enlace = preg_replace_callback('!s:\d+:"(.*?)";!s', function($m) { return "s:" . strlen($m[1]) . ':"'.$m[1].'";'; }, $datos->links);
            $datos_form = array(
                'carrera'            => $datos->carrera,
                'materia'            => $datos->materia,
                'id'                 => $datos->id_materia
            );
            $enlace = unserialize($enlace);
            $data = $this->getTemplate();
            $data['form_videoteca'] = $this->load->view('forms/videoteca',$datos_form,true);
            $data['links_existentes']   = $enlace;
            $this->load->view('admin/panel',$data);
        }else{
            $this->session->set_flashdata('No encontrado', "¡Ups! No existen links de ayuda para esta materia.");
            $data = $this->getTemplate();
            $this->load->view('admin/panel',$data);
        }
    }

    public function links(){
        $listaDeLinks       = json_decode($_POST["arrayDeLinks"], true );
        $listaDeTitulos     = json_decode($_POST["arrayDeTitulos"], true);
        $materia        = $_POST["materiaDeValores"];
        $carrera        = $_POST["carreraMateria"];

        for($i=0; $i < count($listaDeLinks); $i++){
            $links[$listaDeTitulos[$i]] = $listaDeLinks[$i];
        }
        print_r($links);
        $links = serialize($links);
        var_dump($links);
        $data = array(
            'materia'    => $materia,
            'carrera'   => $carrera,
            'links'     => $links
        );
        if(isset($_POST['idMateria'])){
            $id = $_POST['idMateria'];
            //echo "Hemos recibido en el PHP un array de ".count($listaDeLinks)." elementos PARA ACTUALIZACION<br>";
            //echo "<br>.Carrera: ".$carrera; 
            //echo "<br>.materia: ".$materia;
            //echo "<br>.id: ".$id;
            ($this->Videoteca->actualizar($id, $data)) ? print"Actualizacion exitosa." : print'No se actualizaron los datos';
        }else{
            //echo "Hemos recibido en el PHP un array de ".count($listaDeLinks)." elementos PARA CREACION DE VIDEOTECA<br>";
            //echo "<br>.Carrera: ".$carrera; 
            //echo "<br>.materia: ".$materia;
            ($this->Videoteca->cargar($data)) ? print"Se cargo en la base de datos." : print 'No se cargo en BD.';
        }
    }
}