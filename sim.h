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