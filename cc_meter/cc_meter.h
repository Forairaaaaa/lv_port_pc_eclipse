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


            struct SimplePage_t {
                public:
                    lv_obj_t* screen = nullptr;
                    lv_obj_t* label_value = nullptr;
                    lv_obj_t* label_banner = nullptr;
                    lv_obj_t* panel_bottom = nullptr;

                    static void _lvgl_event_cb(lv_event_t* e);
                    void create(uint8_t pageNum, uint32_t themeColor, void* eventUserData = nullptr);
            };

            struct PageManager_t {
                public:
                    PageManager_t() : _current_page_num(0) {}

                    uint32_t _theme_color_list[5] = {0xE56363, 0x87A271, 0x6F8CC8, 0x9B77B4, 0x000000};
                    SimplePage_t _current_page;
                    uint8_t _current_page_num;

                    void go_to_page(uint8_t pageNum);
                    void go_next();
                    void go_last();

            };

        }


        class CCMeter : public APP_BASE {
            private:
                CCMETER::PageManager_t _page;


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


