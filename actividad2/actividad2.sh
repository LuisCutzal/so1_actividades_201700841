#!/bin/bash

# URL del API de GitHub
GITHUB_USER="LuisCutzal"
URL="https://api.github.com/users/"
#echo "$GITHUB_USER"

#Fecha
fecha=$(date)
echo "$fecha"
# Archivo de log
LOGFILE="actividad2.log"

# Consultar los datos del usuario
response=$(curl -s -H "User-Agent: Mozilla/5.0" "$URL""$GITHUB_USER")

# Extraer los datos usando jq
username=$(echo "$response" | jq -r '.login')
user_id=$(echo "$response" | jq -r '.id')
created_at=$(echo "$response" | jq -r '.created_at')

# Crear el mensaje
message="Hola ${username}. User ID: ${user_id}. Cuenta fue creada el: ${created_at}."

# Escribir el mensaje en el archivo de log
echo "$message" > "$LOGFILE"

# Mostrar el mensaje en la consola
echo "$message"
