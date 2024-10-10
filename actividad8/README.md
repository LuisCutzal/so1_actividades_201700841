# Actividad 8

## Instalación de un ambiente local de Minikube

1. **Instalar Minikube:**
   - Abre la terminal y asegúrate de que Docker está corriendo:
     ```bash
     sudo systemctl start docker
     ```
   - Descarga el instalador de Minikube:
     ```bash
     curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
     ```
   - Mueve el binario a una ubicación en tu PATH:
     ```bash
     sudo install minikube-linux-amd64 /usr/local/bin/minikube
     ```
   - Verifica la instalación:
     ```bash
     minikube version
     ```

2. **Iniciar un clúster de Minikube:**
   - Inicia Minikube con Docker como controlador:
     ```bash
     minikube start --driver=docker
     ```

## Despliegue de un contenedor web (Nginx) en Kubernetes

1. **Crear un archivo de configuración para el despliegue:**
   - Crea un archivo llamado `deployment.yaml` y agrega el siguiente contenido para desplegar Nginx:
     ```yaml
     apiVersion: apps/v1
     kind: Deployment
     metadata:
       name: nginx-deployment
     spec:
       replicas: 2
       selector:
         matchLabels:
           app: nginx
       template:
         metadata:
           labels:
             app: nginx
         spec:
           containers:
           - name: nginx
             image: nginx:latest
             ports:
             - containerPort: 80
     ```

2. **Desplegar en el clúster de Minikube:**
   - Aplica el archivo de configuración:
     ```bash
     minikube kubectl -- apply -f deployment.yaml
     ```

3. **Verifica que el contenedor está corriendo:**
   - Lista los pods para confirmar que Nginx está desplegado:
     ```bash
     minikube kubectl -- get pods
     ```

4. **Exponer el servicio Nginx:**
   - Para acceder a Nginx desde tu navegador, expón el servicio:
     ```bash
     minikube kubectl -- expose deployment nginx-deployment --type=NodePort --port=80
     ```
   - Obtén la URL para acceder al servicio:
     ```bash
     minikube service nginx-deployment --url
     ```

## Pregunta: ¿En un ambiente local de Kubernetes existen los nodos masters y workers, como es que esto funciona?

En un ambiente local de Kubernetes, como el que se instala con Minikube, el clúster se ejecuta en una sola máquina, y tanto el nodo maestro (master) como los nodos trabajadores (workers) están en la misma instancia.

- **Nodo Maestro:** Se encarga de la gestión del clúster, incluyendo la programación de pods, la gestión del estado del clúster y la toma de decisiones.
- **Nodos Workers:** Ejecutan las aplicaciones en contenedores.

En un entorno local, Minikube configura un nodo maestro y nodos trabajadores en una arquitectura simplificada, permitiendo desarrollar y probar aplicaciones en un entorno similar al de producción, aunque no tiene las mismas capacidades de escalabilidad y resiliencia que un clúster en la nube o en servidores físicos.

## **Detener el clúster de Minikube**
- minikube stop

## **Eliminar el servicio**
- minikube kubectl -- delete service nginx-deployment
