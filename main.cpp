
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"

static lv_disp_t * hal_init(lv_coord_t w, lv_coord_t h);



#include <iostream>

// #include <app/app_manager.h>
#include <framework/framework.h>
#include <SDL2/SDL.h>



MOONCAKE::Framework app_manager;




class testApp1 : public MOONCAKE::APP_BASE {
    public:
        testApp1(const char* name) {
            setAppName(name);
        }
        void onSetup() {
            setAllowBgRunning(true);
            printf("%s onSetup\n", getAppName().c_str());
        }
        void onCreate() {
            printf("%s onCreate\n", getAppName().c_str());
            // lv_demo_widgets();
            lv_demo_benchmark(LV_DEMO_BENCHMARK_MODE_REAL);
        }
        void onResume() {
            printf("%s onResume\n", getAppName().c_str());
        }
        void onRunning() {
            printf("%s onRunning\n", getAppName().c_str());
        }
        void onRunningBG() {
            printf("%s onRunningBG\n", getAppName().c_str());
        }
        void onPause() {
            printf("%s onPause\n", getAppName().c_str());
        }
        void onDestroy() {
            printf("%s onDestroy\n", getAppName().c_str());
        }
};

class testApp2 : public MOONCAKE::APP_BASE {
    public:
        testApp2(const char* name) {
            setAppName(name);
            setAllowBgRunning(true);
        }
        void onSetup() {
            printf("%s onSetup\n", getAppName().c_str());
        }
        void onCreate() {
            printf("%s onCreate\n", getAppName().c_str());
        }
        void onResume() {
            printf("%s onResume\n", getAppName().c_str());
        }
        void onRunning() {
            printf("%s onRunning\n", getAppName().c_str());
        }
        void onRunningBG() {
            printf("%s onRunningBG\n", getAppName().c_str());
        }
        void onPause() {
            printf("%s onPause\n", getAppName().c_str());
        }
        void onDestroy() {
            printf("%s onDestroy\n", getAppName().c_str());
        }
};



int main(int argc, char **argv)
{

  lv_init();

  /*Create a default group for keyboard navigation*/
  lv_group_set_default(lv_group_create());

  /*Initialize the HAL (display, input devices, tick) for LVGL*/
  hal_init(480, 320);

//  lv_example_switch_1();
//  lv_example_calendar_1();
//  lv_example_btnmatrix_2();
//  lv_example_checkbox_1();
//  lv_example_colorwheel_1();
//  lv_example_chart_6();
//  lv_example_table_2();
//  lv_example_scroll_2();
//  lv_example_textarea_1();
//  lv_example_msgbox_1();
//  lv_example_dropdown_2();
//  lv_example_btn_1();
//  lv_example_scroll_1();
//  lv_example_tabview_1();
//  lv_example_tabview_1();
//  lv_example_flex_3();
//  lv_example_label_1();

//   lv_demo_widgets();


    
    


    std::cout << app_manager.init() << "\n";


    while (1) {
        app_manager.update();
        lv_timer_handler();

        usleep(200 * 1000);
    }




    MOONCAKE::APP_BASE* test_app_A = new testApp1("[AAA]");
    MOONCAKE::APP_BASE* test_app_B = new testApp2("[BBB]");
    MOONCAKE::APP_BASE* test_app_C = new testApp2("[CCC]");

    std::cout << "install-----\n";
    app_manager.install(test_app_A, nullptr);
    app_manager.install(test_app_B, nullptr);
    app_manager.install(test_app_C, nullptr);


    std::cout << "start-----\n";
    app_manager.startApp(test_app_A);
    app_manager.startApp(test_app_B);
    app_manager.startApp(test_app_C);
    // app_manager.closeApp(test_app_C);
    // app_manager.destroyApp(test_app_C);
    // app_manager.closeApp(test_app_C);
    // app_manager.destroyApp(test_app_C);

    /* 2 app test */
    int count = 0;
    while (1)
    {
        lv_timer_handler();




        app_manager.update();
        usleep(5 * 1000);
        // usleep(200 * 1000);

        count++;

        if (count == 4) {
            // std::cout << app_manager.closeApp(test_app_1) << "\n";
            // app_manager.closeApp(test_app_A);
            app_manager.closeApp(test_app_B);
            std::cout << "444-----\n";
        }
        if (count == 8) {
            // std::cout << app_manager.startApp(test_app_1) << "\n";
            app_manager.startApp(test_app_A);

            std::cout << "888-----\n";
        }
        if (count == 12) {
            // std::cout << app_manager.destroyApp(test_app_1) << "\n";
            app_manager.destroyApp(test_app_A);
            app_manager.destroyApp(test_app_B);
            app_manager.startApp(test_app_C);
            app_manager.destroyAllApps();
            std::cout << "121212-----\n";
        }
        printf("\n");
    }


















//   while(1) {
//       /* Periodically call the lv_task handler.
//        * It could be done in a timer interrupt or an OS task too.*/
//       lv_timer_handler();
//       usleep(5 * 1000);
//   }

  return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/


/**
 * Initialize the Hardware Abstraction Layer (HAL) forLVGL
 */
static lv_disp_t * hal_init(lv_coord_t w, lv_coord_t h)
{
  lv_disp_t * disp = lv_sdl_window_create(w, h);
  lv_indev_t * mouse = lv_sdl_mouse_create();
  lv_indev_set_group(mouse, lv_group_get_default());
  lv_indev_set_disp(mouse, disp);

//   LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
//   lv_obj_t * cursor_obj;
//   cursor_obj = lv_img_create(lv_scr_act());         /*Create an image object for the cursor */
//   lv_img_set_src(cursor_obj, &mouse_cursor_icon);   /*Set the image source*/
//   lv_indev_set_cursor(mouse, cursor_obj);           /*Connect the image  object to the driver*/

  lv_indev_t * mousewheel = lv_sdl_mousewheel_create();
  lv_indev_set_disp(mousewheel, disp);
  lv_indev_set_group(mousewheel, lv_group_get_default());

  lv_indev_t * keyboard = lv_sdl_keyboard_create();
  lv_indev_set_disp(keyboard, disp);
  lv_indev_set_group(keyboard, lv_group_get_default());

  return disp;
}
