# Changelog

## v2.1.0 (Android port)
- **Android support**: the mod now declares `android64` and `android32` for GD 2.2081 and builds there.
- The Win32 live console is guarded behind `GEODE_IS_WINDOWS`. On Android, iOS and macOS the console
  setting is ignored and saved inputs go to the Geode log (readable in the launcher or via `adb logcat`).
- **On-screen quick buttons** in the pause menu (BUF / WIN / STRAT / PRESET / UI / LOG) that run the
  same actions as the keybinds, for phones without a keyboard. Toggle with the new *On-screen Quick Buttons* setting.
- CI now builds Windows, Android64 and Android32 in a matrix and uploads one artifact per target.
- README/about updated with Android installation and building instructions.

## v2.0.0
- New engine: every jump input goes through a per-player event queue, injected at the start of its target physics step (at most one transition per step, strict chronological order).
- **7 strategies**, chosen per gamemode: Predictive, Landing Buffer, Hybrid, Min Hold, Min Gap, Grid Snap, Debounce.
- **Presets**: Original v1, Classic Input Buffer, Light, Balanced, Aggressive, Consistency.
- Per-gamemode windows (`-1` = main window, `0` = off), wave cap like v1 (16 / 8).
- **Auto TPS detection** from the physics step (TPS bypass supported), manual override available.
- Predictive tuning: lookahead per mode, strictness, release prediction toggle, configurable spam guard (wave only or all modes).
- **Lethal input filter** (optional): ignores an input that kills you at every delay when not doing it survives.
- Landing buffer also fires on orbs; held clicks are left to the game.
- 2-player levels: player 2 is buffered independently. 1-player dual keeps the v1 mirroring.
- Platformer support (jump button only) and practice-only option.
- On-screen overlay (mode, strategy, window, TPS, saved inputs) that flashes on every saved input.
- Native Geode keybinds (rebindable, only while the game is focused) instead of a global F6 poll.
- Pause menu **BUF** button opening the settings.
- The v1 live console is now optional (setting), saved inputs always go to the Geode log.
- Simulation: collision log reset now also clears the last-collision markers.
- CMake: C++23 (required by Geode 5).

## v1.0.0
- Trajectory-based 1-2 frame press and wave release input buffer (lilWC).
