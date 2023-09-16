----------------------------------------------- Clases que ayudan a procesar la configuracion del simulador y los threads ---------------------------------------------
class Simulacion{
    private:
    cTiempoEscalaSeg: // json

    cCajeros: // json
    cCocineros: // json
    cMeseros: // json

    cPlatos: // json
    cVectorRest: // json

    cTiempoAtencionSeg: // json
    cTiempoLavaplatos: // json
    cTiempoCocina: // json
    cTiempoMonchona: // json

    public:
        setTiempoEscalaSeg(){
            // 
        }
        setCajeros(){
            // 
        }
        setCocineros(){
            //
        }
        setMeseros(){
            //
        }
        setPlatos(){
            //
        }
        setMesas(){
            //
        }
        setSillas(){
            //
        }
        setTiempoAtencionSeg(){
            //
        }
        setTiempoLavaplatos(){
            //
        }
        setTiempoCocina(){
            //
        }
        setTiempoMonchona(){
            //
        }

}

------------------------------------------------------------------------------ Structs ------------------------------------------------------------------------------
    struct pedido{
        string item = /* Lo que haya pedido el cliente */
        int num_orden = /* Contador */
    };
    
------------------------------------------------------------------------------ Clases ------------------------------------------------------------------------------

class Cliente
{
    private:
        string name = /* Nombre sacado de la lista json */
        string orden = /* lo que quieren ordenar, sacada de la lista json */
    public:
        Cliente(){
            // Constructor
        }
        getCliente(){
            // Accesa el nombre y la orden del cliente
        }
        moverCliente(){
            /* Dependiendo de donde este el cliente (cola, caja, restaurante) se mueve al la
            siguiente estacion (cola->caja, caja->restaurante, restaurante->afuera)*/
        }
        comerMoncha(){
            /* El cliente come su comida en un rango de tiempo, generando un plato sucio 
            y eliminando el struct pedido*/
        }
}

class Mesero
{
    private:
        string name = /* Nombre sacado de la lista json */
        pedido orden = /* Item deseado por el cliente, mas el numero de orden dado en la caja */
    public:
        Mesero(){
            // Constructor
        }
        getMesero(){
            // Accesa el nombre del mesero y su numero de orden actual si tiene
        }
        apuntarOrden(orden_cliente){
            // Atiende a un cliente en la caja SOLO si hay espacio en el vector restaurante
        }
        comunicarOrden(orden_cliente, chef){
            // Le lleva la informacion de la orden al chef para que la cocine
        }
        servirOrden(nombre_cliente, pedido){
            // Recoje la orden preparada por el chef y la lleva a la mesa
        }
        limpiarMesa(){
            // Limpia la mesa y lleva el plato sucio dejado por la persona a la pila de platos sucios
        }
}

class Chef
{
    private:
        string name = /* Nombre sacado de la lista json */
        pedido orden = /* Orden dada por un mesero */
        plato plato = /* Aca se sabe si el cocinero tiene o no un plato ya agarrado */
    public:
        Chef(){
            // Constructor
        }
        getChef(){
            // Accesa el nombre del chef y la orden que esta cocinando
        }
        agarrarPlato(plato){
            // Agarra un plato de la pila de platos
        }
        quitarPlato(plato){
            // Le quita el plato al preparar la comida
        }
        cocinarPedido(pedido){
            // Si tiene un plato y una orden alista un pedido en un rango de tiempo
        }
        alistarPedido(){
            // Al terminar el pedido lo alista para ser llevado por un mesero a una mesa
        }
}

class Lavaplatos
    {
    private:
        string name = /* Nombre sacado de la lista json */
    public:
        Lavaplatos(){
            // Constructor
        }
        getLavaplatos(){
            // Accesa el nombre del lavaplatos
        }
        limpiarPlato(){
            // Agarra un plato de la pila de platos sucios, lo limpia y lo coloca en la pila de platos limpios
        }
}

class Plato
{
    private:
        bool limpio = /* True o False */
    public:
        Plato(){
            // Constructor
        }
        getPlato(){
            // Accesa la condicion de limpio del plato
        }
        cambiarLimpio(){
            // Cambia limpio por sucio y sucio por limpio
        }
}

------------------------------------------------------------------------------ Pilas, Colas, Problemas ------------------------------------------------------------------------------
Colas:
    - arrayLlegada[] //Acá se colocan los clientes conforme llega, una cola que funciona como fila de espera.
    - arrayCaja[] // Acá los clientes realizan el pedido antes de pasar a las mesas, cola que funciona para ubicar a la gente.
Pilas:
    - arrayPlatosLimpios[] //Pila de platos limpios, se llevan al cocinero para los pedidos.
    - arrayPlatosSucios[] //Pila de platos sucios que se llevan al lavaplatos para lavarlos.

Problemas en la simulación que generen deficiencias:
    - arrayCaja[] 
    /* Si no se pasa a la gente lo suficientemente rapido se puede generar una fila 
    muy grande y se pueden ir los clientes al ver esperar tanto tiempo de espera*/
    - Class Cocinero
    /* Que el cocinero no pueda cocinar lo suficientemente rapido*/
    - Class Lavaplatos
    /* Que no se puedan lavar platos lo suficientemente rapido*/
    - Vector Restaurante
    /* Si se llega al maximo de espacios del restaurante no se pueden procesar mas personas*/