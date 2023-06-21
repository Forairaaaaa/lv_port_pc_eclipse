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
#include "asserts/ui_helpers.h"


LV_IMG_DECLARE(ui_img_pic_round_panel_png);
LV_IMG_DECLARE(ui_img_pic_spinner_png);

LV_FONT_DECLARE(ui_font_MontserratSemiBoldItalic24);
LV_FONT_DECLARE(ui_font_MontserratSemiBoldItalic72);


///////////////////// ANIMATIONS ////////////////////
void anim_spinner_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = (ui_anim_user_data_t *)lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 7200);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle);
    lv_anim_set_values(&PropertyAnimation_0, 0, 3600);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void anim_bottom_pop_up_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = (ui_anim_user_data_t *)lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 200);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 160, 87);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void anim_value_pop_in_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = (ui_anim_user_data_t *)lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 400);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, -240, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}
void anim_banner_pop_in_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = (ui_anim_user_data_t *)lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 400);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 240, 28);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_start(&PropertyAnimation_0);

}


namespace MOONCAKE {
    namespace USER_APP {


        namespace CCMETER {


            void SimplePage_t::_lvgl_event_cb(lv_event_t* e)
            {
                /* Get event code */
                lv_event_code_t code = lv_event_get_code(e);

                if (code == LV_EVENT_GESTURE) {

                    if (lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
                        printf("go next\n");

                        PageManager_t* page_mg = (PageManager_t*)lv_event_get_user_data(e);
                        page_mg->go_next();
                        
                    }

                    else if (lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
                        printf("go last\n");

                        PageManager_t* page_mg = (PageManager_t*)lv_event_get_user_data(e);
                        page_mg->go_last();
                    }

                }
                
            }


            void SimplePage_t::create(uint8_t pageNum, uint32_t themeColor, void* eventUserData)
            {
                /* Screen */
                this->screen = lv_obj_create(NULL);
                lv_obj_clear_flag(this->screen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
                lv_obj_set_style_bg_color(this->screen, lv_color_hex(themeColor), LV_PART_MAIN | LV_STATE_DEFAULT);

                /* Label value */
                this->label_value = lv_label_create(this->screen);
                lv_obj_set_x(this->label_value, 0);
                lv_obj_set_y(this->label_value, -59);
                lv_obj_set_align(this->label_value, LV_ALIGN_CENTER);
                lv_label_set_text(this->label_value, "12.233");
                lv_obj_set_style_text_color(this->label_value, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(this->label_value, &ui_font_MontserratSemiBoldItalic72, LV_PART_MAIN | LV_STATE_DEFAULT);

                /* Label banner */
                this->label_banner = lv_label_create(this->screen);
                lv_obj_set_x(this->label_banner, 28);
                lv_obj_set_y(this->label_banner, 5);
                lv_obj_set_align(this->label_banner, LV_ALIGN_CENTER);
                lv_label_set_text(this->label_banner, "Bus Volt (V)");
                lv_obj_set_style_text_color(this->label_banner, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(this->label_banner, &ui_font_MontserratSemiBoldItalic24, LV_PART_MAIN | LV_STATE_DEFAULT);

                /* Panel bottom */
                this->panel_bottom = lv_obj_create(this->screen);
                lv_obj_set_width(this->panel_bottom, 240);
                lv_obj_set_height(this->panel_bottom, 66);
                lv_obj_set_x(this->panel_bottom, 0);
                lv_obj_set_y(this->panel_bottom, 87);
                lv_obj_set_align(this->panel_bottom, LV_ALIGN_CENTER);
                lv_obj_clear_flag(this->panel_bottom, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
                lv_obj_set_style_radius(this->panel_bottom, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(this->panel_bottom, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_opa(this->panel_bottom, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(this->panel_bottom, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_opa(this->panel_bottom, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

                lv_obj_t* ui_ImageRoundPanel = lv_img_create(this->panel_bottom);
                lv_img_set_src(ui_ImageRoundPanel, &ui_img_pic_round_panel_png);
                lv_obj_set_x(ui_ImageRoundPanel, 25);
                lv_obj_set_y(ui_ImageRoundPanel, 0);
                lv_obj_set_align(ui_ImageRoundPanel, LV_ALIGN_CENTER);
                lv_obj_add_flag(ui_ImageRoundPanel, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
                lv_obj_clear_flag(ui_ImageRoundPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

                lv_obj_t* ui_ImageSpiner = lv_img_create(this->panel_bottom);
                lv_img_set_src(ui_ImageSpiner, &ui_img_pic_spinner_png);
                lv_obj_set_x(ui_ImageSpiner, -89);
                lv_obj_set_y(ui_ImageSpiner, -3);
                lv_obj_set_align(ui_ImageSpiner, LV_ALIGN_CENTER);
                lv_obj_add_flag(ui_ImageSpiner, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
                lv_obj_clear_flag(ui_ImageSpiner, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

                lv_obj_t* ui_LabelPage = lv_label_create(this->panel_bottom);
                lv_obj_set_x(ui_LabelPage, 82);
                lv_obj_set_y(ui_LabelPage, 13);
                lv_obj_set_align(ui_LabelPage, LV_ALIGN_CENTER);
                lv_label_set_text_fmt(ui_LabelPage, "- %d -", pageNum + 1);
                lv_obj_set_style_text_color(ui_LabelPage, lv_color_hex(themeColor), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_opa(ui_LabelPage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(ui_LabelPage, &ui_font_MontserratSemiBoldItalic24, LV_PART_MAIN | LV_STATE_DEFAULT);

                /* Add event */
                lv_obj_add_event_cb(this->screen, _lvgl_event_cb, LV_EVENT_GESTURE, eventUserData);
            }


            void PageManager_t::go_to_page(uint8_t pageNum)
            {
                /* Create a page */
                _current_page.create(pageNum, _theme_color_list[pageNum], this);

                /* Load screen */
                if (pageNum >= _current_page_num) {
                    lv_scr_load_anim(_current_page.screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 0, true);
                }
                else {
                    lv_scr_load_anim(_current_page.screen, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 0, true);
                }

                /* Load widgets */



                _current_page_num = pageNum;
            }


            void PageManager_t::go_next()
            {
                if (_current_page_num == 4) {
                    return;
                }
                else {
                    go_to_page(_current_page_num + 1);
                }
            }


            void PageManager_t::go_last()
            {
                if (_current_page_num == 0) {
                    return;
                }
                else {
                    go_to_page(_current_page_num - 1);
                }
            }



        }


        void CCMeter::onSetup()
        {
            setAppName("CC Meter");
            setAllowBgRunning(false);
            
        }



        /* Life cycle */
        void CCMeter::onCreate()
        {
            printf("[%s] onCreate\n", getAppName().c_str());


            _page.go_to_page(0);

        }


        void CCMeter::onResume()
        {
            printf("[%s] onResume\n", getAppName().c_str());
        }


        void CCMeter::onRunning()
        {
            // printf("66666\n");


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



