#!/bin/bash

# Colores para la salida
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}=== TESTING SO_LONG MAPS ===${NC}\n"

# Compilar el proyecto
echo -e "${YELLOW}Compilando proyecto...${NC}"
make re > /dev/null 2>&1

if [ $? -ne 0 ]; then
    echo -e "${RED}Error al compilar el proyecto${NC}"
    exit 1
fi

echo -e "${GREEN}✓ Compilación exitosa${NC}\n"

# Función para probar un mapa
test_map() {
    local map_file=$1
    local expected_result=$2  # "valid" o "invalid"
    local description=$3

    echo -e "${BLUE}Probando: ${map_file}${NC}"
    echo -e "Descripción: ${description}"
    
    # Ejecutar so_long con timeout de 2 segundos
    timeout 2s ./so_long "${map_file}" > /dev/null 2>&1
    local exit_code=$?
    
    if [ "$expected_result" = "invalid" ]; then
        if [ $exit_code -eq 1 ] || [ $exit_code -eq 124 ]; then
            echo -e "${GREEN}✓ CORRECTO: El mapa fue rechazado como se esperaba${NC}"
        else
            echo -e "${RED}✗ ERROR: El mapa debería haber sido rechazado${NC}"
        fi
    else
        if [ $exit_code -eq 124 ]; then
            echo -e "${GREEN}✓ CORRECTO: El mapa se cargó exitosamente${NC}"
        else
            echo -e "${RED}✗ ERROR: El mapa válido fue rechazado${NC}"
        fi
    fi
    echo ""
}

echo -e "${YELLOW}=== PROBANDO MAPAS INVÁLIDOS ===${NC}\n"

test_map "maps/no_player.ber" "invalid" "Mapa sin jugador"
test_map "maps/no_exit.ber" "invalid" "Mapa sin salida"
test_map "maps/no_collectibles.ber" "invalid" "Mapa sin coleccionables"
test_map "maps/multiple_players.ber" "invalid" "Mapa con múltiples jugadores"
test_map "maps/open_wall.ber" "invalid" "Mapa con pared abierta"
test_map "maps/invalid_chars.ber" "invalid" "Mapa con caracteres inválidos"
test_map "maps/unreachable_collectible.ber" "invalid" "Coleccionable inaccesible"
test_map "maps/unreachable_exit.ber" "invalid" "Salida inaccesible"
test_map "maps/empty.ber" "invalid" "Mapa vacío"
test_map "maps/too_small.ber" "invalid" "Mapa demasiado pequeño"
test_map "maps/not-rectangular.ber" "invalid" "Mapa no rectangular"
test_map "maps/multiple_exits.ber" "invalid" "Mapa con múltiples salidas"
test_map "maps/enemy_blocked.ber" "invalid" "Mapa con enemigos bloqueando coleccionables"

echo -e "${YELLOW}=== PROBANDO MAPAS VÁLIDOS ===${NC}\n"

test_map "maps/example.ber" "valid" "Mapa de ejemplo básico"
test_map "maps/minimal_valid.ber" "valid" "Mapa mínimo válido"
test_map "maps/many_collectibles.ber" "valid" "Mapa con muchos coleccionables"
test_map "maps/long_narrow.ber" "valid" "Mapa largo y estrecho"
test_map "maps/tall_narrow.ber" "valid" "Mapa alto y estrecho"
test_map "maps/maze.ber" "valid" "Mapa tipo laberinto"
test_map "maps/large_open.ber" "valid" "Mapa grande con espacios abiertos"
test_map "maps/snake_path.ber" "valid" "Mapa con camino serpenteante"
test_map "maps/big_map.ber" "valid" "Mapa grande existente"
test_map "maps/one_enemy.ber" "valid" "Mapa simple con un enemigo"

echo -e "${YELLOW}=== PROBANDO MAPAS CON ENEMIGOS (BONUS) ===${NC}\n"

test_map "maps/with_enemies.ber" "valid" "Mapa básico con enemigos (completable)"
test_map "maps/enemy_maze.ber" "valid" "Laberinto con enemigos (completable)"
test_map "maps/enemy_challenge.ber" "valid" "Desafío con enemigos (completable pero difícil)"

echo -e "${BLUE}=== TESTING COMPLETADO ===${NC}"
