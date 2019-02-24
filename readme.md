Test case with failed builds of libvpx on emscripten with LLVM native wasm backend on Linux
The library built ok, but linking it into a module using it wouldn't see the codec's exported functions.

Narrowed it down to the stripping of debug info from the .a library, which was being done with the native Linux `strip` command as in `strip.sh`.

The non-stripped version of the binary works fine, whereas the stripped version fails. I'm not too sure why, they both seem to contain all the same .o files (which are bitcode here).

There was no problem with the fastcomp backend, where the same strip command would have been issued in the build.

Test `build.sh` issues compiles of a small test program that tries to link one of the codec functions, on each of the stripped and unstripped libraries.
