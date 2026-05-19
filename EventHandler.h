#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H


/**
 * @brief Representa un evento con un identificador único.
 * 
 * Explicación para principiantes: Un Evento (Event) es simplemente un mensaje ligero que avisa que "algo sucedió" 
 * (por ejemplo: un sensor detectó movimiento, o un botón fue presionado). Cada tipo de evento tiene un número único (id) para identificarlo.
 */
struct Event {
    int id; ///< Identificador único para el tipo de evento.

    // Constructor explícito. Permite crear un evento pasando su ID (ej. Event(0)).
    explicit Event(int eventId) : id(eventId) {}
    
    // Sobrecarga de operador == para poder comparar si dos eventos son iguales de manera sencilla: eventA == eventB
    bool operator==(const Event& other) const { return id == other.id; }
};

/**
 * @brief Interfaz abstracta para manejar eventos.
 * 
 * Explicación para principiantes: En C++, una clase con métodos '= 0' (virtuales puros) actúa como un "contrato" o interfaz.
 * Cualquier clase que herede de EventHandler PROMETE implementar la función `on(Event event)`.
 * Esto permite al sistema reaccionar a cualquier evento de manera genérica.
 */
class EventHandler {
public:
    /**
     * @brief Método virtual puro para manejar un evento.
     * @param event El evento que acaba de ocurrir.
     * 
     * Toda clase que herede de EventHandler debe definir este método con su propia lógica de reacción.
     */
    virtual void on(Event event) = 0; 
    
    virtual ~EventHandler() = default; ///< Destructor virtual para asegurar una correcta liberación de memoria en clases heredadas.
};

#endif // EVENT_HANDLER_H