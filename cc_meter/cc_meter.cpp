/**
 * @file cc_meter.cpp
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "cc_meter.h"


namespace MOONCAKE {
    namespace USER_APP {


        void CCMeter::_lvgl_event_cb(lv_event_t* e)
        {
            /* Get event code */
            lv_event_code_t code = lv_event_get_code(e);

            /* Quit */
            #ifndef ESP_PLATFORM
            if (code == LV_EVENT_GESTURE) {
                // printf("gesture\n");


                if (lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
                    


                }
            }
            #endif
            
        }





        void CCMeter::onSetup()
        {
            setAppName("CC Meter");
            setAllowBgRunning(false);
            
        }



        /* Life cycle */
        void CCMeter::onCreate()
        {

        }


        void CCMeter::onResume()
        {

        }


        void CCMeter::onRunning()
        {

        }


        void CCMeter::onRunningBG()
        {

        }


        void CCMeter::onPause()
        {
            printf("[%s] onPause\n", getAppName().c_str());
        }


        void CCMeter::onDestroy()
        {
            printf("[%s] onDestroy\n", getAppName().c_str());
        }


    }
}



