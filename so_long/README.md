1. MAIN.C - Punto de entrada
2. MAP_INIT.C - Carga del mapa
3. MAP_CHECKS.C y MAP_UTILS.C - Validación
4. GAME.C - Inicialización del juego
5. SISTEMA DE RENDERIZADO
6. SISTEMA DE EVENTOS
    ESC: Cierra el juego.
    WASD o flechas: Mover el personaje por el mapa.
7. LOOP PRINCIPAL
8. LIMPIEZA DE MEMORIA

🔄 RESUMEN DEL FLUJO:
```
MAIN → Validar argumentos → Cargar mapa → Validar mapa → 
Inicializar juego → Cargar sprites → Renderizar → 
LOOP (Esperar eventos → Mover jugador → Renderizar → Verificar victoria) → 
Limpiar y salir
```
