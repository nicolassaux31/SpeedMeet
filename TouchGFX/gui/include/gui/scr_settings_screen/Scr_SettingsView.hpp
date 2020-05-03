#ifndef SCR_SETTINGSVIEW_HPP
#define SCR_SETTINGSVIEW_HPP

#include <gui_generated/scr_settings_screen/Scr_SettingsViewBase.hpp>
#include <gui/scr_settings_screen/Scr_SettingsPresenter.hpp>

#include <gui/common/CustomKeyboard.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>

#define MAX_SLOTS_NUM 20

extern Model::slot slots[4];
extern int num_of_slots;

class Scr_SettingsView : public Scr_SettingsViewBase
{
public:
    Scr_SettingsView();
    virtual ~Scr_SettingsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    CustomKeyboard keyboard;

    virtual void scroll_min1UpdateItem(custom_num_scroll_side& item, int16_t itemIndex);
    virtual void scroll_min1UpdateCenterItem(custom_num_scroll_sel& item, int16_t itemIndex);
    virtual void scroll_sec1UpdateItem(custom_num_scroll_side& item, int16_t itemIndex);
    virtual void scroll_sec1UpdateCenterItem(custom_num_scroll_sel& item, int16_t itemIndex);
    virtual void scroll_numofslotsUpdateItem(custom_num_scroll_side& item, int16_t itemIndex);
    virtual void scroll_numofslotsUpdateCenterItem(custom_num_scroll_sel& item, int16_t itemIndex);

    virtual void fcn_nextslot_settings();
    virtual void fcn_prevslot_settings();
    virtual void fcn_moreslots();
    virtual void fcn_lessslots();
    virtual void update_total_timing_txt();

    int i = 0;
    char curr_edited_slot = 1;
    int total_timing[2];

//    int scroll_digits_positions[MAX_SLOTS_NUM];

protected:

    Callback<Scr_SettingsView, int16_t> scroll_numofslots_changed;
    void scroll_numofslots_changed_handler(int16_t itemSelected);

    Callback<Scr_SettingsView, int16_t> scroll_min1_changed;
    void scroll_min1_changed_handler(int16_t itemSelected);

    Callback<Scr_SettingsView, int16_t> scroll_sec1_changed;
    void scroll_sec1_changed_handler(int16_t itemSelected);

};

#endif // SCR_SETTINGSVIEW_HPP
