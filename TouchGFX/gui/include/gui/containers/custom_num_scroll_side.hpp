#ifndef CUSTOM_NUM_SCROLL_SIDE_HPP
#define CUSTOM_NUM_SCROLL_SIDE_HPP

#include <gui_generated/containers/custom_num_scroll_sideBase.hpp>

class custom_num_scroll_side : public custom_num_scroll_sideBase
{
public:
    custom_num_scroll_side();
    virtual ~custom_num_scroll_side() {}

    virtual void initialize();

    void set_txt_num(uint16_t val);
protected:
};

#endif // CUSTOM_NUM_SCROLL_SIDE_HPP
