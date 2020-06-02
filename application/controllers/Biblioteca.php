<?php

use function PHPSTORM_META\type;

defined('BASEPATH') OR exit('No direct script access allowed');


class Biblioteca extends CI_Controller{
    public function __construct()
    {
        parent::__construct();
        $this->load->model('Hemeroteca');
        $this->load->model('Videoteca');
        $this->load->helper('directory');
        $this->load->library('session');
    }

    function index(){
        //echo "biblioteca de abanderados";
        if($this->session->userdata('is_logged')){
            $data = $this->getTemplate();
            $this->load->view('biblioteca',$data);
        }else{
            show_404();
        }
    }

    public function getTemplate(){
		$data =  array(
            'bibliotecas' => $this->libreria(),
            'head'      => $this->load->view('layout/head','',true),
            'nav'       => $this->load->view('layout/nav','',true),
            'footer'    => $this->load->view('layout/footer', '', true),
		 );
		return $data;
    }

    /**
     * Este metodo retornara a la vista las bibliotecas disponibles en el servidor
     */
    function libreria(){    
         if($datos = $this->Hemeroteca->get_datos()){
            return $datos;
        }else{
            return false;
        }
    }


    /**
     * Importante tener en cuenta que los datos que reciba los datos a traves de los enlaces
     * no se puede enviar conteniendo slash /, ya que la informacion no llega completa. 
     * por ello, dividi los para metros por _ guion bajo y luego reemplace por el slash ya en el conntrolado,
     * para buscar dentro del directorio. use funciones auxiliares para limpiar y hacer accesible a la url y las rutas. 
     */
    function verdirectorio($ruta = 0){
        if( $this->session->userdata('is_logged') ):
            $ruta =  $this->aux_limpiar_cadena($ruta);
            $divideRuta = explode("/",$ruta);
            $carpetaPadre = $divideRuta[0];     //Primera carpeta
            $ultimaCarpeta = end($divideRuta);  //Ultima carpeta
            $videoteca = '';
            //var_dump($carpetaPadre);
            //busco los videos correspondientes a esta carpeta
            $videoteca = $this->cargarvideoteca($carpetaPadre, $ultimaCarpeta);
            $buscar = './assets/biblioteca/';
            $buscar = $buscar.$ruta;
            //echo $buscar;
            $directorio = directory_map($buscar, 1, true);
            //print_r($directorio);
            $ruta = $this->aux_limpiar_ruta($ruta);
            //echo "<br><br> La ruta que se mmanda a la vista es : $ruta";
            $data = $this->getTemplate();
            $data['videoteca']          = $videoteca;
            $data['ruta']               = $ruta;
            $data['directorio']         = $directorio;     
            $this->load->view('directorio',$data);
        else:
            show_404();
        endif;
    }

    function visualizar($archivo = 0){
        $ruta_base = '/assets/biblioteca/';
        $archivo =  $this->aux_limpiar_cadena($archivo);
        //echo "El archivo que hay que ver es: ".$archivo;
        $ruta_base = $ruta_base.$archivo;
        redirect($ruta_base);
    }

    function aux_limpiar_cadena($cadena){
        //Limpia los espacios;
        $cadena_limpia = str_replace('%20',' ', $cadena);
        //coloca las tildes en las o
        $cadena_limpia = str_replace('%C3%B3', 'ó', $cadena_limpia);
        //coloca las ñ
        $cadena_limpia = str_replace('%C3%B1', 'ñ', $cadena_limpia);
        //quita los barras 
        $cadena_limpia = str_replace('"\"', '/', $cadena_limpia);
        //quita el 0 cuando el parametro llega vacio
        $cadena_limpia = str_replace('0', '', $cadena_limpia);
        //opciones de ruta importante si hay _ (guiones bajos se reemplaza por el slash /)
        $cadena_limpia = str_replace('_', '/', $cadena_limpia);

        return $cadena_limpia;
    }

    function aux_limpiar_ruta($ruta){
        $ruta = str_replace('/', '_', $ruta);
        return $ruta;
    }

    /**
     * Esta funcion cargara la videoteca correspondiente 
     * a una Biblioteca ($prinicipal) y su Materia ($carpeta)
     * Si la encuentra en la BD. 
     */
    function cargarvideoteca($principal, $carpeta){
        if($data = $this->Videoteca->get_links($principal, $carpeta)){
            $data = unserialize($data->links);
            return $data;
        }
        return false;
    }
}