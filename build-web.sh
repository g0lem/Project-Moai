clear
emcc ./src/webmain.c -s ASYNCIFY -s USE_GLFW=3 -o server/public/main.html
firefox localhost:8000/main.html

./run-server.sh 