# Actividad 5

## Tipos de Kernel y sus diferencias

Es el encargado de gestionar los recursos del sistema y permitir la interacción entre el hardware y el software

### 1. Monolitico: 
   Es un solo bloque de código que gestiona todos los servicios del sistema operativo el cual incluye todos los controladores de dispositivos y servicios en un único espacio de memoria. Es mas eficiente en terminos de rendimiento pero también más propenso a fallos, ya que un error en un componente puede afectar a todo el sistema.
### 2. Microkernel: 
   Delega la mayor parte de los servicios a procesos que se ejecutan en espacio de usuario, fuera del kernel el cual mejora la estabilidad y seguridad ya que los fallos no afectan al nucleo pero esto crea una sobrecarga entre la comunicacion del kernel y los servicios.

### 3. Kernel Híbrido:
   Combina elementos de los kernels monolíticos y microkernels. Este enfoque busca equilibrar rendimiento, estabilidad y seguridad

### 4. Nanokernel:
   Es una versión extremadamente reducida de un microkernel el cual solo ofrece las funciones mas basicas del sistema. La mayor parte de los servicios del sistema operativo se ejecuta en el espacio de usuario.

### 5. Exokernel:
   Es un diseño experimental que permite a las aplicaciones tener un control directo sobre el hardware. Se centra en ofrecer un acceso eficiente y seguro al hardware.

## User vs Kernel Mode

### 1. Modo de Usuario:
   El código que se ejecuta tiene acceso limitado a los recursos del sistema. Las aplicaciones no pueden interactuar directamente con el hardware ni realizar operaciones privilegiadas, como acceder a la memoria o a los dispositivos de E/S directamente.

### 2. Modo Kernel:
   El código tiene acceso total a todos los recursos del sistema, incluyendo el hardware y la memoria. Este nivel de acceso es necesario para que el kernel pueda gestionar correctamente los recursos y ejecutar operaciones críticas. Sin embargo, cualquier error en el modo kernel puede tener consecuencias graves, como un bloqueo completo del sistema


## Interruptions vs traps

### 1. Interrrupciones:
   Son señales enviadas al procesador desde dispositivos externos para indicar que necesitan atención. Por ejemplo, cuando presionas una tecla, el teclado envía una interrupción al procesador. El procesador detiene temporalmente su ejecución actual para manejar la interrupción y luego retoma su trabajo.

### 2. Trampas:
   Son interrupciones generadas por el propio procesador, normalmente en respuesta a una condición específica que ocurre durante la ejecución de un programa, como una operación ilegal o una solicitud de servicio del sistema operativo. A diferencia de las interrupciones, las trampas son síncronas, ya que ocurren como resultado directo de la ejecución del código.