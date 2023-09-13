Colas:
    - arrayLlegada[] //Acá se colocan los clientes conforme llega, una cola que funciona como fila de espera.
    - arrayCaja[] // Acá los clientes realizan el pedido antes de pasar a las mesas, cola que funciona para ubicar a la gente.
Pilas:
    - arrayPlatosLimpios[] //Pila de platos limpios, se llevan al cocinero para los pedidos.
    - arrayPlatosSucios[] //Pila de platos sucios que se llevan al lavaplatos para lavarlos.

Threads:
    - Los tiempos que se dura en preparar comida, limpiar platos y que 
    un cliente termine su comida

Clases que ayudan a procesar la configuracion del simulador:
    - Class Cliente // Comensales
    - Class Empleado // Gente del local
    - Class Platos
    - Class Lavaplatos
    - Class Cocinero
    - Class Meseros

Structs:
    - matrizMesas[][] // Matriz para colocar a la gente y que puedan comer.

Clases que manejan la lógica:
    - Class Lavaplatos // Cambian el valor de Limpieza del plato
    - Class Cocinero // Preparan pedidos
    - Class Meseros // Reciben y entregan pedidos
    - Class Clientes // Comensales

Clases por las cuales se va a saber que está pasando en la simulación:
    - Class Mesero
    - Class Cocinero
    - Class Lavaplatos
    - Class Cliente

Problemas en la simulación que generen deficiencias:
    - arrayCaja[] 
    /* Si no se pasa a la gente lo suficientemente rapido se puede generar una fila 
    muy grande y se pueden ir los clientes al ver esperar tanto tiempo de espera*/
    - Class Cocinero
    /* Que el cocinero no pueda cocinar lo suficientemente rapido*/
    - Class Lavaplatos
    /* Que no se puedan lavar platos lo suficientemente rapido*/