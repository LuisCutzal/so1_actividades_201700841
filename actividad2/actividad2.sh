#!/bin/bash

# URL del API de GitHub
URL="https://api.github.com/users/"
#echo "$GITHUB_USER"

#Fecha
fecha=$(date +'%d-%m-%Y')
#echo "$fecha"

#directorio carpeta tmp
directorio="/tmp/$fecha"
mkdir -p "$directorio"

# Archivo de log
LOGFILE="$directorio/saludos.log"

# Consultar los datos del usuario
response=$(curl -s -H "User-Agent: Mozilla/5.0" "$URL""$GITHUB_USER")

# Extraer los datos usando jq
user_id=$(echo "$response" | jq -r '.id')
created_at=$(echo "$response" | jq -r '.created_at')

# Crear el mensaje
message="Hola ${GITHUB_USER}. el id del usuario es: ${user_id} la cuenta fue creada el: ${created_at}."

# Escribir el mensaje en el archivo de log
echo "$message" > "$LOGFILE"

# Mostrar el mensaje en la consola
echo "$message"
