DrumMixer (3DS/2DS Homebrew) — Browser-only build via GitHub Actions

This repo builds:
- DrumMixer.3dsx (homebrew launcher)
- DrumMixer.cia (installable CIA) including banner + icon

Your WAV drum hits are included in samples_for_sd_card/ and should be copied to:
  sdmc:/3ds/DrumMixer/

Build locally (optional):
  make
  make cia

GitHub Actions:
- pushes build artifacts so you can download the CIA without installing toolchains locally.
