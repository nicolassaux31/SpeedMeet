#include <gui/scr_settings_screen/Scr_SettingsView.hpp>

Scr_SettingsView::Scr_SettingsView()
{
	keyboard.setPosition(440, 220, 320, 240);
	add(keyboard);

}

void Scr_SettingsView::setupScreen()
{
    Scr_SettingsViewBase::setupScreen();
}

void Scr_SettingsView::tearDownScreen()
{
    Scr_SettingsViewBase::tearDownScreen();
}
