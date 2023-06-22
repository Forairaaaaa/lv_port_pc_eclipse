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

#include <iostream>
#include <array>
#include <string>


namespace MOONCAKE {
    namespace USER_APP {


        namespace CCMETER {


            static void _lvgl_event_cb(lv_event_t* e);


            struct SimplePage_t {
                public:
                    lv_obj_t* screen = nullptr;
                    lv_obj_t* label_value = nullptr;

                    void create(uint8_t pageNum, void* pmPtr);
            };


            struct DashBoardPage_t {
                public:
                    lv_obj_t* screen = nullptr;
                    lv_obj_t* label_value_1 = nullptr;
                    lv_obj_t* label_value_2 = nullptr;
                    lv_obj_t* label_value_3 = nullptr;
                    lv_obj_t* label_value_4 = nullptr;

                    void create(void* pmPtr);
            };


            struct PageManager_t {
                public:
                    PageManager_t() : _current_page_num(0) {}

                    uint32_t _theme_color_list[5] = {0xE56363, 0x87A271, 0x6F8CC8, 0x9B77B4, 0x715B69};
                    const char* _banner_list[5] = {"Bus Volt (V)", "Bus Pow (W)", "Shunt Volt (V)", "Shunt Cur (A)", "6"};
                    const char* _banner_list_dashboard[5] = {"Bus Volt", "Bus Power", "Shunt Volt", "Shunt Cur", "6"};
                    SimplePage_t _simple_page;
                    DashBoardPage_t _dashboard_page;
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


                inline CCMETER::PageManager_t* getPageMG() { return &_page; }
                void updatePageValue(const std::array<std::string, 4>& valueList);


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


