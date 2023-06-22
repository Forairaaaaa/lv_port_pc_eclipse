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
    lv_anim_set_values(&PropertyAnimation_0, 240, 20);
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

void anim_bar_pop_in_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = (ui_anim_user_data_t *)lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 400);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_x);
    lv_anim_set_values(&PropertyAnimation_0, 240, 0);
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


            void _lvgl_event_cb(lv_event_t* e)
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


            void SimplePage_t::create(uint8_t pageNum, void* pmPtr)
            {
                /* Screen */
                this->screen = lv_obj_create(NULL);
                lv_obj_clear_flag(this->screen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
                lv_obj_set_style_bg_color(this->screen, lv_color_hex(((PageManager_t*)pmPtr)->_theme_color_list[pageNum]), LV_PART_MAIN | LV_STATE_DEFAULT);

                /* Label value */
                this->label_value = lv_label_create(this->screen);
                // lv_obj_set_x(this->label_value, 0);
                lv_obj_set_x(this->label_value, -240);
                lv_obj_set_y(this->label_value, -59);
                lv_obj_set_align(this->label_value, LV_ALIGN_CENTER);
                lv_label_set_text(this->label_value, "12.233");
                lv_obj_set_style_text_color(this->label_value, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(this->label_value, &ui_font_MontserratSemiBoldItalic72, LV_PART_MAIN | LV_STATE_DEFAULT);

                /* Label banner */
                lv_obj_t* label_banner = lv_label_create(this->screen);
                // lv_obj_set_x(this->label_banner, 28);
                lv_obj_set_x(label_banner, 240);
                lv_obj_set_y(label_banner, 5);
                lv_obj_set_align(label_banner, LV_ALIGN_CENTER);
                lv_label_set_text(label_banner, ((PageManager_t*)pmPtr)->_banner_list[pageNum]);
                lv_obj_set_style_text_color(label_banner, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(label_banner, &ui_font_MontserratSemiBoldItalic24, LV_PART_MAIN | LV_STATE_DEFAULT);

                /* Panel bottom */
                lv_obj_t* panel_bottom = lv_obj_create(this->screen);
                lv_obj_set_width(panel_bottom, 240);
                lv_obj_set_height(panel_bottom, 66);
                lv_obj_set_x(panel_bottom, 0);
                // lv_obj_set_y(panel_bottom, 87);
                lv_obj_set_y(panel_bottom, 160);
                lv_obj_set_align(panel_bottom, LV_ALIGN_CENTER);
                lv_obj_clear_flag(panel_bottom, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
                lv_obj_set_style_radius(panel_bottom, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(panel_bottom, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_opa(panel_bottom, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(panel_bottom, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_opa(panel_bottom, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

                lv_obj_t* ui_ImageRoundPanel = lv_img_create(panel_bottom);
                lv_img_set_src(ui_ImageRoundPanel, &ui_img_pic_round_panel_png);
                lv_obj_set_x(ui_ImageRoundPanel, 25);
                lv_obj_set_y(ui_ImageRoundPanel, 0);
                lv_obj_set_align(ui_ImageRoundPanel, LV_ALIGN_CENTER);
                lv_obj_add_flag(ui_ImageRoundPanel, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
                lv_obj_clear_flag(ui_ImageRoundPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

                lv_obj_t* ui_ImageSpiner = lv_img_create(panel_bottom);
                lv_img_set_src(ui_ImageSpiner, &ui_img_pic_spinner_png);
                lv_obj_set_x(ui_ImageSpiner, -89);
                lv_obj_set_y(ui_ImageSpiner, -3);
                lv_obj_set_align(ui_ImageSpiner, LV_ALIGN_CENTER);
                lv_obj_add_flag(ui_ImageSpiner, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
                lv_obj_clear_flag(ui_ImageSpiner, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

                lv_obj_t* ui_LabelPage = lv_label_create(panel_bottom);
                lv_obj_set_x(ui_LabelPage, 82);
                lv_obj_set_y(ui_LabelPage, 13);
                lv_obj_set_align(ui_LabelPage, LV_ALIGN_CENTER);
                lv_label_set_text_fmt(ui_LabelPage, "- %d -", pageNum + 1);
                lv_obj_set_style_text_color(ui_LabelPage, lv_color_hex(((PageManager_t*)pmPtr)->_theme_color_list[pageNum]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_opa(ui_LabelPage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(ui_LabelPage, &ui_font_MontserratSemiBoldItalic24, LV_PART_MAIN | LV_STATE_DEFAULT);

                /* Add event */
                lv_obj_add_event_cb(this->screen, _lvgl_event_cb, LV_EVENT_GESTURE, pmPtr);

                /* Load screen */
                if (pageNum >= ((PageManager_t*)pmPtr)->_current_page_num) {
                    lv_scr_load_anim(this->screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 0, true);
                }
                else {
                    lv_scr_load_anim(this->screen, LV_SCR_LOAD_ANIM_OVER_RIGHT, 200, 0, true);
                }

                /* Load anims */
                anim_spinner_Animation(ui_ImageSpiner, 0);
                anim_value_pop_in_Animation(label_value, 200);
                anim_banner_pop_in_Animation(label_banner, 200);
                anim_bottom_pop_up_Animation(panel_bottom, 150);
            }


            void DashBoardPage_t::create(void* pmPtr)
            {
                /* Screen */
                this->screen = lv_obj_create(NULL);
                lv_obj_clear_flag(this->screen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
                lv_obj_set_style_bg_color(this->screen, lv_color_hex(((PageManager_t*)pmPtr)->_theme_color_list[4]), LV_PART_MAIN | LV_STATE_DEFAULT);



                lv_obj_t* ui_BarBanner1 = lv_obj_create(this->screen);
                lv_obj_set_width(ui_BarBanner1, 240);
                lv_obj_set_height(ui_BarBanner1, 30);
                lv_obj_set_x(ui_BarBanner1, 240);
                lv_obj_set_y(ui_BarBanner1, -105);
                lv_obj_set_align(ui_BarBanner1, LV_ALIGN_CENTER);
                lv_obj_clear_flag(ui_BarBanner1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
                lv_obj_set_style_radius(ui_BarBanner1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(ui_BarBanner1, lv_color_hex(0xEFEFEF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_opa(ui_BarBanner1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

                lv_obj_t* ui_LabelBanner1 = lv_label_create(ui_BarBanner1);
                lv_obj_set_align(ui_LabelBanner1, LV_ALIGN_CENTER);
                lv_obj_set_style_text_color(ui_LabelBanner1, lv_color_hex(((PageManager_t*)pmPtr)->_theme_color_list[4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(ui_LabelBanner1, &ui_font_MontserratSemiBoldItalic24, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_text(ui_LabelBanner1, ((PageManager_t*)pmPtr)->_banner_list_dashboard[0]);

                lv_obj_t* ui_BarValue1 = lv_obj_create(this->screen);
                lv_obj_set_width(ui_BarValue1, 240);
                lv_obj_set_height(ui_BarValue1, 30);
                lv_obj_set_x(ui_BarValue1, 240);
                lv_obj_set_y(ui_BarValue1, -75);
                lv_obj_set_align(ui_BarValue1, LV_ALIGN_CENTER);
                lv_obj_clear_flag(ui_BarValue1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
                lv_obj_set_style_radius(ui_BarValue1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(ui_BarValue1, lv_color_hex(((PageManager_t*)pmPtr)->_theme_color_list[0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_opa(ui_BarValue1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

                this->label_value_1 = lv_label_create(ui_BarValue1);
                lv_obj_set_align(this->label_value_1, LV_ALIGN_CENTER);
                lv_obj_set_style_text_color(this->label_value_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(this->label_value_1, &ui_font_MontserratSemiBoldItalic24, LV_PART_MAIN | LV_STATE_DEFAULT);

                lv_obj_t* ui_BarBanner2 = lv_obj_create(this->screen);
                lv_obj_set_width(ui_BarBanner2, 240);
                lv_obj_set_height(ui_BarBanner2, 30);
                lv_obj_set_x(ui_BarBanner2, 240);
                lv_obj_set_y(ui_BarBanner2, -45);
                lv_obj_set_align(ui_BarBanner2, LV_ALIGN_CENTER);
                lv_obj_clear_flag(ui_BarBanner2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
                lv_obj_set_style_radius(ui_BarBanner2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(ui_BarBanner2, lv_color_hex(0xEFEFEF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_opa(ui_BarBanner2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

                lv_obj_t* ui_LabelBanner2 = lv_label_create(ui_BarBanner2);
                lv_obj_set_align(ui_LabelBanner2, LV_ALIGN_CENTER);
                lv_obj_set_style_text_color(ui_LabelBanner2, lv_color_hex(((PageManager_t*)pmPtr)->_theme_color_list[4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(ui_LabelBanner2, &ui_font_MontserratSemiBoldItalic24, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_text(ui_LabelBanner2, ((PageManager_t*)pmPtr)->_banner_list_dashboard[1]);

                lv_obj_t* ui_BarValue2 = lv_obj_create(this->screen);
                lv_obj_set_width(ui_BarValue2, 240);
                lv_obj_set_height(ui_BarValue2, 30);
                lv_obj_set_x(ui_BarValue2, 240);
                lv_obj_set_y(ui_BarValue2, -15);
                lv_obj_set_align(ui_BarValue2, LV_ALIGN_CENTER);
                lv_obj_clear_flag(ui_BarValue2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
                lv_obj_set_style_radius(ui_BarValue2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(ui_BarValue2, lv_color_hex(((PageManager_t*)pmPtr)->_theme_color_list[1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_opa(ui_BarValue2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

                this->label_value_2 = lv_label_create(ui_BarValue2);
                lv_obj_set_align(this->label_value_2, LV_ALIGN_CENTER);
                lv_obj_set_style_text_color(this->label_value_2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(this->label_value_2, &ui_font_MontserratSemiBoldItalic24, LV_PART_MAIN | LV_STATE_DEFAULT);

                lv_obj_t* ui_BarBanner3 = lv_obj_create(this->screen);
                lv_obj_set_width(ui_BarBanner3, 240);
                lv_obj_set_height(ui_BarBanner3, 30);
                lv_obj_set_x(ui_BarBanner3, 240);
                lv_obj_set_y(ui_BarBanner3, 15);
                lv_obj_set_align(ui_BarBanner3, LV_ALIGN_CENTER);
                lv_obj_clear_flag(ui_BarBanner3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
                lv_obj_set_style_radius(ui_BarBanner3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(ui_BarBanner3, lv_color_hex(0xEFEFEF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_opa(ui_BarBanner3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

                lv_obj_t* ui_LabelBanner3 = lv_label_create(ui_BarBanner3);
                lv_obj_set_align(ui_LabelBanner3, LV_ALIGN_CENTER);
                lv_obj_set_style_text_color(ui_LabelBanner3, lv_color_hex(((PageManager_t*)pmPtr)->_theme_color_list[4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(ui_LabelBanner3, &ui_font_MontserratSemiBoldItalic24, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_text(ui_LabelBanner3, ((PageManager_t*)pmPtr)->_banner_list_dashboard[2]);

                lv_obj_t* ui_BarValue3 = lv_obj_create(this->screen);
                lv_obj_set_width(ui_BarValue3, 240);
                lv_obj_set_height(ui_BarValue3, 30);
                lv_obj_set_x(ui_BarValue3, 240);
                lv_obj_set_y(ui_BarValue3, 45);
                lv_obj_set_align(ui_BarValue3, LV_ALIGN_CENTER);
                lv_obj_clear_flag(ui_BarValue3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
                lv_obj_set_style_radius(ui_BarValue3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(ui_BarValue3, lv_color_hex(((PageManager_t*)pmPtr)->_theme_color_list[2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_opa(ui_BarValue3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

                this->label_value_3 = lv_label_create(ui_BarValue3);
                lv_obj_set_align(this->label_value_3, LV_ALIGN_CENTER);
                lv_obj_set_style_text_color(this->label_value_3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(this->label_value_3, &ui_font_MontserratSemiBoldItalic24, LV_PART_MAIN | LV_STATE_DEFAULT);

                lv_obj_t* ui_BarBanner4 = lv_obj_create(this->screen);
                lv_obj_set_width(ui_BarBanner4, 240);
                lv_obj_set_height(ui_BarBanner4, 30);
                lv_obj_set_x(ui_BarBanner4, 240);
                lv_obj_set_y(ui_BarBanner4, 75);
                lv_obj_set_align(ui_BarBanner4, LV_ALIGN_CENTER);
                lv_obj_clear_flag(ui_BarBanner4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
                lv_obj_set_style_radius(ui_BarBanner4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(ui_BarBanner4, lv_color_hex(0xEFEFEF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_opa(ui_BarBanner4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

                lv_obj_t* ui_LabelBanner4 = lv_label_create(ui_BarBanner4);
                lv_obj_set_align(ui_LabelBanner4, LV_ALIGN_CENTER);
                lv_obj_set_style_text_color(ui_LabelBanner4, lv_color_hex(((PageManager_t*)pmPtr)->_theme_color_list[4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(ui_LabelBanner4, &ui_font_MontserratSemiBoldItalic24, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_text(ui_LabelBanner4, ((PageManager_t*)pmPtr)->_banner_list_dashboard[3]);

                lv_obj_t* ui_BarValue4 = lv_obj_create(this->screen);
                lv_obj_set_width(ui_BarValue4, 240);
                lv_obj_set_height(ui_BarValue4, 30);
                lv_obj_set_x(ui_BarValue4, 240);
                lv_obj_set_y(ui_BarValue4, 105);
                lv_obj_set_align(ui_BarValue4, LV_ALIGN_CENTER);
                lv_obj_clear_flag(ui_BarValue4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
                lv_obj_set_style_radius(ui_BarValue4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(ui_BarValue4, lv_color_hex(((PageManager_t*)pmPtr)->_theme_color_list[3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_opa(ui_BarValue4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

                this->label_value_4 = lv_label_create(ui_BarValue4);
                lv_obj_set_align(this->label_value_4, LV_ALIGN_CENTER);
                lv_obj_set_style_text_color(this->label_value_4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_font(this->label_value_4, &ui_font_MontserratSemiBoldItalic24, LV_PART_MAIN | LV_STATE_DEFAULT);
                

                /* Add event */
                lv_obj_add_event_cb(this->screen, _lvgl_event_cb, LV_EVENT_GESTURE, pmPtr);

                /* Load screen */
                lv_scr_load_anim(this->screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 0, true);

                /* Load anims */
                anim_bar_pop_in_Animation(ui_BarBanner1,    200);
                anim_bar_pop_in_Animation(ui_BarValue1,     200 + 50 * 1);
                anim_bar_pop_in_Animation(ui_BarBanner2,    200 + 50 * 2);
                anim_bar_pop_in_Animation(ui_BarValue2,     200 + 50 * 3);
                anim_bar_pop_in_Animation(ui_BarBanner3,    200 + 50 * 4);
                anim_bar_pop_in_Animation(ui_BarValue3,     200 + 50 * 5);
                anim_bar_pop_in_Animation(ui_BarBanner4,    200 + 50 * 6);
                anim_bar_pop_in_Animation(ui_BarValue4,     200 + 50 * 7);
            }


            void PageManager_t::go_to_page(uint8_t pageNum)
            {
                /* Clear all anims */
                lv_anim_del_all();

                if (pageNum != 4) {
                    /* Create a simple page */
                    _simple_page.create(pageNum, this);
                }
                else {
                    /* Create a dash board page */
                    _dashboard_page.create(this);
                }


                /* Update current */
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


        void CCMeter::updatePageValue(const std::array<std::string, 4>& valueList)
        {
            /* In simple pages */
            if (_page._current_page_num != 4) {
                lv_label_set_text(_page._simple_page.label_value, valueList[_page._current_page_num].c_str());
            }
            /* In dashboard page */
            else {
                lv_label_set_text(_page._dashboard_page.label_value_1, valueList[0].c_str());
                lv_label_set_text(_page._dashboard_page.label_value_2, valueList[1].c_str());
                lv_label_set_text(_page._dashboard_page.label_value_3, valueList[2].c_str());
                lv_label_set_text(_page._dashboard_page.label_value_4, valueList[3].c_str());
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



