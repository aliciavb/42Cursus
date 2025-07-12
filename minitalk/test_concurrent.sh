#!/bin/bash
echo "=== Test de múltiples clientes consecutivos ==="
make re

echo "Iniciando servidor..."
./server &
SERVER_PID=$!
echo "Server PID: $SERVER_PID"
sleep 1

echo "Cliente 1 enviando mensaje..."
./client $SERVER_PID "Primer mensaje del cliente 1" &
CLIENT1_PID=$!

echo "Cliente 2 enviando mensaje (interrumpe al 1)..."
sleep 0.5  # Dar tiempo para que el cliente 1 empiece
./client $SERVER_PID "Segundo mensaje del cliente 2" &
CLIENT2_PID=$!

echo "Cliente 3 enviando mensaje..."
sleep 1
./client $SERVER_PID "Tercer mensaje del cliente 3" &
CLIENT3_PID=$!

# Esperar a todos
wait $CLIENT1_PID 2>/dev/null
wait $CLIENT2_PID 2>/dev/null  
wait $CLIENT3_PID 2>/dev/null

sleep 1
kill $SERVER_PID 2>/dev/null
echo "=== Test completado ==="