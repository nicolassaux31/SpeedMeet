#ifndef CUSTOM_CNT_SLOT_HPP
#define CUSTOM_CNT_SLOT_HPP

#include <gui_generated/containers/custom_cnt_slotBase.hpp>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class custom_cnt_slot : public custom_cnt_slotBase
{
public:
    custom_cnt_slot();
    virtual ~custom_cnt_slot() {}

    virtual void initialize();

    virtual void set_container_Alpha(int alpha){
    	box_leftborder.setAlpha(alpha);
    	box_rightborder.setAlpha(alpha);
    	box_topborder.setAlpha(alpha);
    	box_bottomborder.setAlpha(alpha);
    	txt_slotnum.setAlpha(alpha);
    	txt_slotname.setAlpha(alpha);
    }

    void set_txt_slotnum(int val);
    void set_txt_slotname(string name);

protected:
};

#endif // CUSTOM_CNT_SLOT_HPP
