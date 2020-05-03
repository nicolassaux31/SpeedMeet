#ifndef CUSTOM_NUM_SCROLL_SEL_HPP
#define CUSTOM_NUM_SCROLL_SEL_HPP

#include <gui_generated/containers/custom_num_scroll_selBase.hpp>

class custom_num_scroll_sel : public custom_num_scroll_selBase
{
public:
    custom_num_scroll_sel();
    virtual ~custom_num_scroll_sel() {}

    virtual void initialize();

    virtual void set_txt_num(uint16_t val){
    	Unicode::snprintf(txt_digitBuffer, TXT_DIGIT_SIZE, "%d", val);
        txt_digit.invalidate();
    }
protected:
};

#endif // CUSTOM_NUM_SCROLL_SEL_HPP
