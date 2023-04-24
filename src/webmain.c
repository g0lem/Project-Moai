#define EMSCRIPTEN 1
#include "game.h"

void setupWebGL() {
	// setting up EmscriptenWebGLContextAttributes
	EmscriptenWebGLContextAttributes attr;
	emscripten_webgl_init_context_attributes(&attr);
	attr.alpha = 0;

	// target the canvas selector
	EMSCRIPTEN_WEBGL_CONTEXT_HANDLE ctx = emscripten_webgl_create_context("#canvas", &attr);
	emscripten_webgl_make_context_current(ctx);
// this goes after you have activated the webgl context
}

int main(){ // beginning of main function

	setupWebGL();
	gameRun();
	return 1;
} // end of main function