TARGET   := DrumMixer
BUILD    := build
SOURCES  := source
DATA     := data
INCLUDES := include

# devkitPro rules will produce:
#   build/$(TARGET).elf
#   $(TARGET).3dsx

LIBS     := -lctru -lm

# Meta assets for CIA
META_DIR := meta
ICON_PNG := $(META_DIR)/icon.png
BANNER_PNG := $(META_DIR)/banner.png
BANNER_WAV := $(META_DIR)/audio.wav
APP_RSF := $(META_DIR)/app.rsf

SMDH := $(TARGET).smdh
BANNER_BIN := banner.bin

include $(DEVKITPRO)/libctru/base_rules

# ---- CIA packaging (requires makerom + bannertool in PATH) ----

$(SMDH): $(ICON_PNG)
	bannertool makesmdh -s "$(TARGET)" -l "$(TARGET)" -p "Homebrew" -i $(ICON_PNG) -o $(SMDH)

$(BANNER_BIN): $(BANNER_PNG) $(BANNER_WAV)
	bannertool makebanner -i $(BANNER_PNG) -a $(BANNER_WAV) -o $(BANNER_BIN)

cia: $(TARGET).elf $(SMDH) $(BANNER_BIN)
	makerom -f cia -o $(TARGET).cia -elf $(TARGET).elf -rsf $(APP_RSF) -icon $(SMDH) -banner $(BANNER_BIN) -exefslogo

all: $(TARGET).3dsx

clean-cia:
	@rm -f $(TARGET).cia $(SMDH) $(BANNER_BIN)

.PHONY: cia clean-cia
