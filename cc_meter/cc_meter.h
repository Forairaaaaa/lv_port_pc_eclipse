/**
 * @file cc_meter.h
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "mooncake_new/src/app/app.h"
#include <lvgl.h>




namespace MOONCAKE {
    namespace USER_APP {


        namespace CCMETER {

            struct Data_t {

                lv_obj_t* screen_list[5];
                uint8_t current_screen;

            };

        }


        class CCMeter : public APP_BASE {
            private:
                CCMETER::Data_t _data;

                static void _lvgl_event_cb(lv_event_t* e);
                


            public:
                CCMeter() = default;
                ~CCMeter() = default;


                /**
                 * @brief Lifecycle callbacks for derived to override
                 * 
                 */
                /* Setup App configs, called when App "install()" */
                void onSetup();

                /* Life cycle */
                void onCreate();
                void onResume();
                void onRunning();
                void onRunningBG();
                void onPause();
                void onDestroy();
            
        };


    }
}


