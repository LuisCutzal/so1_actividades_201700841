# Servicio de Saludo y Fecha

Este documento proporciona instrucciones para instalar y gestionar un servicio `systemd` que imprime un saludo y la fecha actual en un bucle infinito con una pausa de un segundo.

## Instalación

### 1. Crear el Script

Primero, necesitas crear un script que se encargará de imprimir el saludo y la fecha. Puedes hacerlo con los siguientes pasos:

1. Abre una terminal y crea el archivo del script en `/usr/local/bin/saludo.sh`:

   ```bash
   sudo nano /usr/local/bin/saludo.sh

2. Añadimos el siguiente contenido al archivo:


    ```#!/bin/bash```
    ```while true; do```
        ```echo "Hola, el tiempo actual es: $(date)"```
        ```sleep 1```
    ```done```

3. Guarda el archivo y cierra el editor
4. Haz que el script sea ejecutable
sudo chmod +x "la direccion del archivo"


### 2. Crear el Archivo de Unidad systemd

1. Crea el archivo de unidad en /etc/systemd/system/saludo.service
2. Añade el siguiente contenido al archivo
   ```bash
   [Unit]
   Description=Servicio de Saludo y Fecha
   [Service]
   ExecStart=/usr/local/bin/saludo.sh
   Restart=always
   User=nobody
   Group=nogroup
   Install
   WantedBy=multi-user.target

1. Guarda el archivo y cierra el editor


### 3. Recargar la Configuración de systemd

Para que systemd reconozca el nuevo archivo de unidad, recarga la configuración de systemd

```sudo systemctl daemon-reload```

### 4. Habilitar e Iniciar el Servicio

```sudo systemctl enable saludo.service```
```sudo systemctl start saludo.service```


### Para comprobar el servicio
```sudo systemctl status saludo.service```

### Consultar los Logs del Servicio
```sudo journalctl -u saludo.service```
