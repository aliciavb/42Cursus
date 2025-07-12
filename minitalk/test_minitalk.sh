#!/bin/bash
# test_minitalk.sh

echo "=== Testing minitalk ==="
echo "Starting server..."
./server &
SERVER_PID=$!
sleep 1

echo "Getting server PID..."
PID=$(ps aux | grep './server' | grep -v grep | awk '{print $2}')
echo "Server PID: $PID"

echo "Testing single character..."
./client $PID "A"
sleep 1

echo "Testing short word..."
./client $PID "hello"
sleep 1

echo "Killing server..."
kill $SERVER_PID