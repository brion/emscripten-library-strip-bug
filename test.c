#include <stdlib.h>

extern void *vpx_codec_get_frame(void *codec, void *iter);

int main(int argc, char **argv) {
	// just link, don't care it'll fail at runtime
	vpx_codec_get_frame(NULL,NULL);
	return 0;
}

