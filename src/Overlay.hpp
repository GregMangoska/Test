#pragma once

#include <Geode/Geode.hpp>

// Small on-screen status label shown while playing
namespace pbuf::overlay {

void attach(PlayLayer* pl);
void detach();
void refresh(PlayLayer* pl, bool force = false);
void toast(std::string const& text);   // hotkey feedback (Geode notification)

// Actions wired to both the keybinds and the on-screen pause-menu buttons
namespace hotkeys {
    void toggle();
    void cycleWindow();
    void cycleStrategy();
    void cyclePreset();
    void overlay();
    void debug();
}

} // namespace pbuf::overlay
