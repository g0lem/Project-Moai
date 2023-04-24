clear
emcc em_main.c  -lglut -lGL -lGLEW -lGLU -s ASYNCIFY -s WASM=1 -O3 -o server/public/hello.html
