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

    virtual void set_txt_slotnum(int val){
    	Unicode::snprintf(txt_slotnumBuffer, TXT_SLOTNUM_SIZE, "%d", val);
    }

    virtual void set_txt_slotname(string name){
//    	int i;
    	//Unicode::snprintf(txt_slotnameBuffer, TXT_SLOTNAME_SIZE, "%s", name.c_str());
    	Unicode::strncpy(txt_slotnameBuffer, name.c_str(), TXT_SLOTNAME_SIZE);
//    	for(i=0;i<TXT_SLOTNAME_SIZE;i++)
//    		txt_slotnameBuffer[i] = name[i];
//    	txt_slotnameBuffer[TXT_SLOTNAME_SIZE] = 0;
    }

protected:
};

#endif // CUSTOM_CNT_SLOT_HPP
