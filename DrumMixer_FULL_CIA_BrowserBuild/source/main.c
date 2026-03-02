#include <3ds.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    printf("Drum Mixer (CIA + 3DSX)\n\n");
    printf("Put samples here:\n");
    printf("  sdmc:/3ds/DrumMixer/\n\n");
    printf("Expected filenames:\n");
    printf("  kick.wav\n  snare.wav\n  hat.wav\n  clap.wav\n  tom1.wav\n  crash.wav\n  ride.wav\n\n");
    printf("Controls:\n");
    printf("  A Kick | B Snare | X Hat | Y Clap\n");
    printf("  L Crash | R Ride\n");
    printf("  START Exit\n\n");
    printf("This build is the packaging-ready template.\n");
    printf("Next step: add audio playback + mixer.\n");

    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();
        if (kDown & KEY_START) break;

        // (Audio triggers go here next)
        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}
