#include <gui/containers/custom_num_scroll_side.hpp>

custom_num_scroll_side::custom_num_scroll_side()
{

}

void custom_num_scroll_side::initialize()
{
    custom_num_scroll_sideBase::initialize();
}

void custom_num_scroll_side::set_txt_num(uint16_t val){
    	Unicode::snprintf(txt_digitBuffer, TXT_DIGIT_SIZE, "%d", val);
    	txt_digit.invalidate();
}
