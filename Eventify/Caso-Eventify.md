# Caso Eventify

Eventify (https://eventify.io/) es una empresa de gestión de eventos que tiene como objetivo revolucionar la industria de la planificación de eventos. Con un fuerte enfoque en la atención al detalle, un servicio al cliente excepcional y un compromiso con la excelencia, se esfuerzan por crear eventos que se destaquen de la competencia, asegurándose de que cada uno sea memorable y verdaderamente inolvidable.

Son un equipo de profesionales experimentados con una pasión por crear eventos perfectos e inolvidables. La plataforma de eventos está diseñada para simplificar la planificación y ejecución de eventos, lo que le permite concentrarse en lo que más importa: crear experiencias significativas para sus invitados.

Los mejores organizadores de eventos están incorporando las últimas tecnologías de IoT para mejorar su desempeño. Como resultado, el uso de IoT en la planificación de eventos está generando una nueva ola de revolución.

### RFID Bands
Entify ofrece una experiencia de los eventos mejorada con tecnología RFID. Desde un ingreso más rápido hasta pagos sin efectivo, las pulseras RFID mejoran la participación y la comodidad de los asistentes. Quieren que sus clientes digan adiós a las largas colas y den la bienvenida a datos más completos y patrocinadores más comprometidos (ver la sección de Referencias).

### Smart Food Dispensers
Entify pone disposición de sus clientes Organizers equipos conocidos como Smart Food Dispenser con control de temperatura. Este equipo permite un control total sobre el inventario del proveedor en un entorno refrigerado y con control de temperatura para una máxima longevidad, seguridad y frescura del producto. El sistema de refrigeración del dispositivo garantiza que los productos se mantendrán frescos hasta que estén listos para usarse. Estos productos pueden incluir bocadillos, productos nutricionales o sándwiches. Esta máquina dispensadora refrigerada respalda el cumplimiento de las normas regulatorias y garantiza que los productos mantengan su frescura y usabilidad, lo que le permite ahorrar miles de dólares anuales en costos de reemplazo. Entre su configuración se incluye un panel con un módulo lector de RFID RC522, un 4x4 Membrane KeyPad y un display LCD 1602. Adicionalmente cuentan en su interior con 4 Sensores de temperatura DHT-22, junto con 20 Micro Servo Motors para controlar la parte mecánica de dispensación. El sistema de control del dispositivo se basa en un microcontrolador ESP32 (ver sección de Referencias). El dispositivo soporta la conexión a la red WiFi del evento, con el fin de recibir actualizaciones de configuración o proporcionar información sobre el stock de productos para dispensar o notificar cada vez que un asistente al evento hace uso de su RFID Band para consumir un producto. El Dispenser está conectado a a una toma de fuente de energía eléctrica estándar de 220 V. Para eventos que ofrecen esta facilidad, Eventify recomienda un Dispenser por cada 50 registrados. 


### Smart Coffee Makers
La Smart Coffee Maker es una máquina que prepara café muy parecido al café hecho en casa en solo un par de segundos presionando un botón. La máquina está completamente automatizada con puerta modular. Según los requisitos, el asistente puede elegir diferentes sabores de la máquina. Las máquinas son fáciles de mantener y se ven fantásticas para eventos. Tiene un bajo consumo de energía. Al usar esta máquina, puede obtener el sabor del café preparado en casa en el evento, al dar la mezcla adecuada de premezcla y agua caliente. Los asistentes pueden elegir el sabor según su elección y el producto estará listo para servir en un minuto. Es posible configurarlos para ofrecer dos opciones, tres opciones hasta cuatro opciones de tipos de café a
los asistentes al evento. También ofrecen una pantalla que se puede personalizar con la marca del evento. Entre su configuración se incluye un panel con un módulo lector de RFID RC522, un 4x4 Membrane KeyPad y un display LCD 1602. Adicionalmente cuentan en su interior con 1 Sensor de temperatura DHT-22, junto con 4 Micro Servo Motors para el módulo de dispensación. El sistema de control del dispositivo se basa en un microcontrolador ESP32 (ver sección de Referencias). El dispositivo soporta la conexión a la red WiFi del evento, con el fin de recibir actualizaciones de configuración o proporcionar información sobre el stock de insumos para dispensar o notificar cada vez que un asistente al evento hace uso de su RFID Band para consumir un producto.El Dispenser está conectado a a una toma de fuente de energía eléctrica estándar de 220 V. Para eventos que ofrecen esta facilidad, Eventify recomienda un Coffee Maker por cada 50 registrados.
### Event Organizer Platform
El sistema permite al Event Organizer la configuración de información del evento, analíticos, así como la carga masiva de información de personas registradas.
### Event Registration and Check-In Platform
Eventify ofrece a las personas registradas en un evento una aplicación móvil que facilita el proceso de check-in. Al momento del ingreso, el la persona registrada presenta un código QR generado por la aplicación y es validado en el puesto de control que cuenta con varias estaciones cada una con una aplicación móvil de control de asistencia y un lector de QR. Dicha aplicación también permite la activación y asignación de las RFID Bands disponibles para el evento. Una vez confirmado, la persona registrada pasa a ser asistente al evento, recibiendo a continuación un RFID Band que le brinda acceso a las salas y facilidades dentro del evento. Eventify recomienda a los organizers una estación en el puesto de control por cada 60 registrados en el evento.
### Event Food Partner Management Platform
La solución de Evently incluye una aplicación web y una aplicación móvil para usuarios que sean parte del Partner designado por el Event Organizer para el abastecimiento de insumos y productos para los Smart Food Dispensers y Smart Coffee Makers. Con el ello el Food Partner User puede revisar el estado de inventarios de productos e insumos de los Food Dispensers y Coffee Makers distribuidos en las instalaciones del evento, a fin de mantenerlos abastecidos y en operación normal. La plataforma cuenta con un RESTful API para que el Partner pueda integrar la información con sus sistemas internos.
### Event Device Maintenance Partner Management Platform
Eventify ofrece a sus proveedores de mantenimiento de equipos y dispositivos una plataforma web y aplicación móvil que brinda acceso a información de estado en tiempo real sobre los dispositivos desplegados en cada evento de los clientes de Eventify, a fin de que cada partner asignado a uno o más eventos cercanos, pueda brindar mantenimiento preventivo antes de colocar un equipo o dispositivo en un evento y atención correctiva durante el evento. La aplicación móvil está destinada a los Agentes de Soporte Técnico, mientras que la aplicación web está orientada a personal en las oficinas de cada partner. La plataforma cuenta con un RESTful API para que el Partner pueda integrar la información con sus sistemas internos.

Eventify desea una configuración de arquitectura que brinde los mejores tiempos de respuesta, estabilidad, tanto a las operaciones que se realizan en cada evento como a las operaciones de gestión centralizada vía cloud para Eventify a nivel global. Ellos le indican que la estación de control de cada evento cuenta con un servidor de procesamiento de datos que centraliza la información del evento, está conectado a la red WiFi del evento, pero también tiene conexión vía internet con la plataforma cloud de Eventify, para envío y sincronización de información relevante.

En los últimos meses, Eventify ha visto un incremento en su demanda y sus clientes recientes suelen organizan eventos presenciales para niveles de asistencia entre 500 y 1000 asistentes.

Los representantes de Eventify le solicitan que, bajo el marco de los 12 pasos del IoT System Design Steps (ver Anexo A), Domain-Driven Design y Object-Oriented Software Design, presente para su siguiente reunión un avance de su propuesta de requisitos para el diseño de la actual IoT Solution.

## Identificación de Sensores y Actuadores

A partir del caso de negocio expuesto, se identifican los siguientes sensores y actuadores para los dispositivos y sistemas IoT de **Eventify**:

### 1. Smart Food Dispenser (Dispensador de Comida Inteligente)
Este dispositivo cuenta con un microcontrolador **ESP32** y gestiona el inventario y estado físico de alimentos refrigerados.
*   **Sensores (Entradas):**
    *   **Sensores de Temperatura DHT-22 (4 unidades):** Monitorean la temperatura interna en diferentes zonas del entorno refrigerado para garantizar la conservación, frescura y seguridad de los alimentos.
    *   **Lector de RFID RC522 (1 unidad):** Identifica y lee los tags de las pulseras RFID (*RFID Bands*) de los asistentes para validar su acceso y registrar consumos.
    *   **Teclado Matricial de Membrana 4x4 (1 unidad):** Dispositivo de interfaz de entrada que detecta las pulsaciones de teclas para la selección de productos y navegación de menús.
*   **Actuadores (Salidas):**
    *   **Microservomotores (20 unidades):** Dispositivos electromecánicos que controlan la compuerta y el mecanismo físico de dispensación de alimentos individuales.
    *   **Display LCD 1602 (1 unidad):** Pantalla de caracteres para mostrar instrucciones, stock y estados de la transacción de forma visual.
    *   **Sistema de Refrigeración:** Unidad de enfriamiento que mantiene el compartimiento a la temperatura de refrigeración programada.

### 2. Smart Coffee Maker (Cafetera Inteligente)
Este dispositivo cuenta con un microcontrolador **ESP32** y automatiza la preparación y entrega de café.
*   **Sensores (Entradas):**
    *   **Sensor de Temperatura DHT-22 (1 unidad):** Monitorea la temperatura del sistema e insumos para asegurar la calidad de la infusión del café.
    *   **Lector de RFID RC522 (1 unidad):** Identifica las pulseras RFID de los asistentes para autorizar el servicio y registrar la transacción.
    *   **Teclado Matricial de Membrana 4x4 (1 unidad):** Permite al asistente seleccionar el sabor, intensidad u opciones disponibles de café.
*   **Actuadores (Salidas):**
    *   **Microservomotores (4 unidades):** Controlan el movimiento mecánico y dosificación en el módulo de dispensación de café e insumos.
    *   **Display LCD 1602 (1 unidad):** Pantalla visual personalizable para mostrar la marca del evento, menú interactivo y progreso de preparación.
    *   **Sistema de Calentamiento de Agua / Calentador:** Actuador térmico que genera el agua caliente requerida para disolver la premezcla de café.

### 3. Puestos de Control de Acceso y Check-In
*   **Sensores (Entradas):**
    *   **Lector de Códigos QR (Múltiples estaciones):** Escáner de imagen o cámara que lee el código QR generado por la app móvil para validar el ingreso del asistente. 