
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
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/sdl/sdl.h"


static void hal_init(void);





LV_IMG_DECLARE(ui_img_icon1_hdpi_png);    // assets\icon1_hdpi.png
LV_IMG_DECLARE(ui_img_icon2_hdpi_png);    // assets\icon2_hdpi.png
LV_IMG_DECLARE(ui_img_icon3_hdpi_png);    // assets\icon3_hdpi.png
LV_IMG_DECLARE(ui_img_icon4_hdpi_png);    // assets\icon4_hdpi.png
LV_IMG_DECLARE(ui_img_icon5_hdpi_png);    // assets\icon5_hdpi.png
LV_IMG_DECLARE(ui_img_icon6_hdpi_png);    // assets\icon6_hdpi.png
LV_IMG_DECLARE(ui_img_icon7_hdpi_png);    // assets\icon7_hdpi.png
LV_IMG_DECLARE(ui_img_icon8_hdpi_png);    // assets\icon8_hdpi.png
LV_IMG_DECLARE(ui_img_icon9_hdpi_png);    // assets\icon9_hdpi.png
LV_IMG_DECLARE(ui_img_icon10_hdpi_png);    // assets\icon10_hdpi.png
LV_IMG_DECLARE(ui_img_icon11_hdpi_png);    // assets\icon11_hdpi.png




#include <mooncake.h>




MOONCAKE::Mooncake mooncake;

int btn_value = 0;

class AppTest : public MOONCAKE::APP_BASE {
    private:

        lv_obj_t* screen;
        int bbb1;
        int bbb2;

        uint32_t ticks;

        static void event_handler(lv_event_t * e)
        {
            lv_event_code_t code = lv_event_get_code(e);

            if(code == LV_EVENT_CLICKED) {

                btn_value = *(int*)lv_event_get_user_data(e);
                
            }

        }


    public:
        AppTest(const char* name, void* icon = nullptr) {
            setAppName(name);
            setAppIcon(icon);
        }

        void onSetup() {
        }

        /* Life cycle */
        void onCreate() {
            printf("[%s] onCreate\n", getAppName().c_str());

            setAllowBgRunning(false);

        }
        void onResume() {
            printf("[%s] onResume\n", getAppName().c_str());


            btn_value = 0;


            screen = lv_obj_create(NULL);
            lv_scr_load_anim(screen, LV_SCR_LOAD_ANIM_MOVE_TOP, 100, 0, false);
            

            lv_obj_t * label;

            lv_obj_t * btn1 = lv_btn_create(screen);
            bbb1 = 1;
            lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, (void*)&bbb1);
            lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);

            label = lv_label_create(btn1);
            // lv_obj_add_flag(btn1, LV_OBJ_FLAG_CHECKABLE);
            lv_obj_add_state(btn1, LV_STATE_CHECKED);
            lv_label_set_text(label, "Quit App");
            lv_obj_center(label);



            lv_obj_t * btn2 = lv_btn_create(screen);
            bbb2 = 2;
            lv_obj_add_event_cb(btn2, event_handler, LV_EVENT_ALL, (void*)&bbb2);
            lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 40);

            label = lv_label_create(btn2);
            lv_label_set_text(label, "Run background");
            lv_obj_center(label);



        }
        void onRunning() {
            // printf("[%s] onRunning\n", getAppName().c_str());

            if ((lv_tick_get() - ticks) > 1000) {
                printf("[%s] onRunning\n", getAppName().c_str());
                ticks = lv_tick_get();
            }


            // printf("%d\n", btn_value);
            if (btn_value == 1) {
                setAllowBgRunning(false);
                destroyApp();
            }
            else if (btn_value == 2) {
                setAllowBgRunning(true);
                closeApp();
            }



        }   
        void onRunningBG() {
            // printf("[%s] onRunningBG\n", getAppName().c_str());

            if ((lv_tick_get() - ticks) > 1000) {
                printf("[%s] onRunningBG\n", getAppName().c_str());
                ticks = lv_tick_get();
            }
        }
        void onPause() {
            printf("[%s] onPause\n", getAppName().c_str());
        }
        void onDestroy() {
            printf("[%s] onDestroy\n", getAppName().c_str());
        }
};





extern const uint8_t walking_icon[];



#include "cc_meter/cc_meter.h"



int main(int argc, char **argv)
{
  (void)argc; /*Unused*/
  (void)argv; /*Unused*/

  /*Initialize LVGL*/
  lv_init();

  /*Initialize the HAL (display, input devices, tick) for LVGL*/
  hal_init();

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

    // lv_demo_widgets();



    // lv_example_rlottie_1();
    // lv_example_rlottie_2();






    // lv_obj_t * lottie = lv_rlottie_create_from_file(lv_scr_act(), 500, 500, "icons/49879-walking-duck.json");
    // lv_obj_t* lottie = lv_rlottie_create_from_raw(lv_scr_act(), 500, 500, (const char *)walking_icon);
    // lv_obj_t * lottie = lv_rlottie_create_from_file(lv_scr_act(), 100, 100, "icons/142051-toucan-walk-cycle.json");
    // lv_obj_center(lottie);


    // lv_rlottie_set_play_mode(lottie, LV_RLOTTIE_CTRL_PLAY | LV_RLOTTIE_CTRL_FORWARD | LV_RLOTTIE_CTRL_LOOP);





    // while(1) {
    //     /* Periodically call the lv_task handler.
    //     * It could be done in a timer interrupt or an OS task too.*/
    //     lv_timer_handler();
    //     usleep(5 * 1000);
    // }


    MOONCAKE::USER_APP::CCMeter cc_meter;


    cc_meter.onSetup();
    cc_meter.onCreate();
    cc_meter.onResume();



    while (1) {
        lv_timer_handler();


        cc_meter.onRunning();


        usleep(5 * 1000);
    }




    

    // mooncake.setDisplay(SDL_HOR_RES, SDL_VER_RES);
    
    // // MOONCAKE::BUILTIN_APP::Launcher_Bubble* launcher = new MOONCAKE::BUILTIN_APP::Launcher_Bubble;
    // // mooncake.setLauncher(launcher);

    // mooncake.init();
    // mooncake.installBuiltinApps();


    // std::string name;
    // AppTest* app_ptr = nullptr;



    // // app_ptr = new AppTest("a", (void*)&ui_img_icon1_hdpi_png);
    // // mooncake.install(app_ptr);
    // app_ptr = new AppTest("b", (void*)&ui_img_icon2_hdpi_png);
    // mooncake.install(app_ptr);
    // app_ptr = new AppTest("c", (void*)&ui_img_icon3_hdpi_png);
    // mooncake.install(app_ptr);
    // app_ptr = new AppTest("d", (void*)&ui_img_icon4_hdpi_png);
    // mooncake.install(app_ptr);
    // app_ptr = new AppTest("e", (void*)&ui_img_icon5_hdpi_png);
    // mooncake.install(app_ptr);
    // app_ptr = new AppTest("f", (void*)&ui_img_icon6_hdpi_png);
    // mooncake.install(app_ptr);
    // app_ptr = new AppTest("g", (void*)&ui_img_icon7_hdpi_png);
    // mooncake.install(app_ptr);
    // app_ptr = new AppTest("h", (void*)&ui_img_icon8_hdpi_png);
    // mooncake.install(app_ptr);
    // app_ptr = new AppTest("i", (void*)&ui_img_icon9_hdpi_png);
    // mooncake.install(app_ptr);
    // app_ptr = new AppTest("j", (void*)&ui_img_icon10_hdpi_png);
    // mooncake.install(app_ptr);




    // // for (int i = 0; i < 10; i++) {
    // //     name = "Test-" + std::to_string(i);
    // //     // printf("%s\n", name.c_str());

    // //     app_ptr = new AppTest(name.c_str());
    // //     mooncake.install(app_ptr);

    // // }



    // while (1) {
    //     mooncake.update();
    //     lv_timer_handler();

    //     usleep(5 * 1000);
    // }
















  return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static void hal_init(void)
{
  /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
  sdl_init();

  /*Create a display buffer*/
  static lv_disp_draw_buf_t disp_buf1;
//   static lv_color_t buf1_1[SDL_HOR_RES * 100];
//   lv_disp_draw_buf_init(&disp_buf1, buf1_1, NULL, SDL_HOR_RES * 100);
    static lv_color_t buf1_1[SDL_HOR_RES * SDL_VER_RES];
    lv_disp_draw_buf_init(&disp_buf1, buf1_1, NULL, SDL_HOR_RES * SDL_VER_RES);

  /*Create a display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv); /*Basic initialization*/
  disp_drv.draw_buf = &disp_buf1;
  disp_drv.flush_cb = sdl_display_flush;
  disp_drv.hor_res = SDL_HOR_RES;
  disp_drv.ver_res = SDL_VER_RES;

  lv_disp_t * disp = lv_disp_drv_register(&disp_drv);

  lv_theme_t * th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
  lv_disp_set_theme(disp, th);

  lv_group_t * g = lv_group_create();
  lv_group_set_default(g);

  /* Add the mouse as input device
   * Use the 'mouse' driver which reads the PC's mouse*/
  static lv_indev_drv_t indev_drv_1;
  lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
  indev_drv_1.type = LV_INDEV_TYPE_POINTER;

  /*This function will be called periodically (by the library) to get the mouse position and state*/
  indev_drv_1.read_cb = sdl_mouse_read;
  lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);

  static lv_indev_drv_t indev_drv_2;
  lv_indev_drv_init(&indev_drv_2); /*Basic initialization*/
  indev_drv_2.type = LV_INDEV_TYPE_KEYPAD;
  indev_drv_2.read_cb = sdl_keyboard_read;
  lv_indev_t *kb_indev = lv_indev_drv_register(&indev_drv_2);
  lv_indev_set_group(kb_indev, g);

  static lv_indev_drv_t indev_drv_3;
  lv_indev_drv_init(&indev_drv_3); /*Basic initialization*/
  indev_drv_3.type = LV_INDEV_TYPE_ENCODER;
  indev_drv_3.read_cb = sdl_mousewheel_read;
  lv_indev_t * enc_indev = lv_indev_drv_register(&indev_drv_3);
  lv_indev_set_group(enc_indev, g);

  /*Set a cursor for the mouse*/
//   LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
//   lv_obj_t * cursor_obj = lv_img_create(lv_scr_act()); /*Create an image object for the cursor */
//   lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
//   lv_indev_set_cursor(mouse_indev, cursor_obj);             /*Connect the image  object to the driver*/
}
