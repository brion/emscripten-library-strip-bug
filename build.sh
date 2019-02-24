export EMCC_WASM_BACKEND=1

emcc -s VERBOSE=1 test.c -L. -lvpx -o test-stripped.js
emcc -s VERBOSE=1 test.c -L. -lvpx_g -o test-unstripped.js

