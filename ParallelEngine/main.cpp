
#include "display.h"
#include "gsm.h"
#include "state.h"
#include "playstate.h"

int main() {
	GSM* gsm = new GSM();
	// initialize display and start render/update
	Display* display = new Display(gsm);
	delete display;
	delete gsm;
	return 0;
}