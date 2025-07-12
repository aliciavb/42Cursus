#!/bin/bash
echo "=== Test simple primero ==="
make re

echo "Iniciando servidor..."
./server &
SERVER_PID=$!
echo "Server PID: $SERVER_PID"
sleep 1

echo "Enviando mensaje corto..."
./client $SERVER_PID "Hello"

sleep 2

echo "Enviando mensaje largo..."
./client $SERVER_PID "Este es un mensaje muy largo para probar si funciona correctamente"

sleep 2

# Limpiar
kill $SERVER_PID 2>/dev/null
echo "=== Test simple completado ==="
