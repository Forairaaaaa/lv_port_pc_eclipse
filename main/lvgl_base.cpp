/**
 * @file lvgl_base.cpp
 * @author Forairaaaaa
 * @brief 
 * @version 0.1
 * @date 2023-05-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <lvgl.h>
#include <lv_demos.h>
#include <lv_examples.h>
#include <tp_ft3168.hpp>
#include <LovyanGFX.hpp>




#define MY_DISP_HOR_RES 368
#define MY_DISP_VER_RES 448
#define LV_VER_RES_MAX  448
#define delay(ms) vTaskDelay(pdMS_TO_TICKS(ms))



/// 独自の設定を行うクラスを、LGFX_Deviceから派生して作成します。
class LGFX_Monica : public lgfx::LGFX_Device {
    // 接続するパネルの型にあったインスタンスを用意します。
    lgfx::Panel_SH8601Z     _panel_instance;
    // パネルを接続するバスの種類にあったインスタンスを用意します。
    lgfx::Bus_QSPI      _bus_instance;

    public:
        // コンストラクタを作成し、ここで各種設定を行います。
        // クラス名を変更した場合はコンストラクタも同じ名前を指定してください。
        LGFX_Monica(void)
        {
            { // バス制御の設定を行います。
                auto cfg = _bus_instance.config();    // バス設定用の構造体を取得します。

                // SPIバスの設定
                cfg.spi_host = SPI3_HOST;     // 使用するSPIを選択  ESP32-S2,C3 : SPI2_HOST or SPI3_HOST / ESP32 : VSPI_HOST or HSPI_HOST
                // ※ ESP-IDFバージョンアップに伴い、VSPI_HOST , HSPI_HOSTの記述は非推奨になるため、エラーが出る場合は代わりにSPI2_HOST , SPI3_HOSTを使用してください。
                cfg.spi_mode = 1;             // SPI通信モードを設定 (0 ~ 3)
                //   cfg.freq_write = 1*1000*1000;    // 送信時のSPIクロック (最大80MHz, 80MHzを整数で割った値に丸められます)
                //   cfg.freq_write = 10*1000*1000;
                cfg.freq_write = 40*1000*1000;  
                cfg.freq_read  = 16000000;    // 受信時のSPIクロック
                cfg.spi_3wire  = true;        // 受信をMOSIピンで行う場合はtrueを設定
                cfg.use_lock   = true;        // トランザクションロックを使用する場合はtrueを設定
                cfg.dma_channel = SPI_DMA_CH_AUTO; // 使用するDMAチャンネルを設定 (0=DMA不使用 / 1=1ch / 2=ch / SPI_DMA_CH_AUTO=自動設定)

                cfg.pin_sclk    = 15;
                cfg.pin_io0     = 13;
                cfg.pin_io1     = 14;
                cfg.pin_io2     = 17;
                cfg.pin_io3     = 16;
                // cfg.pin_dc      = -1;

                _bus_instance.config(cfg);    // 設定値をバスに反映します。
                _panel_instance.setBus(&_bus_instance);      // バスをパネルにセットします。
            }

            { // 表示パネル制御の設定を行います。
                auto cfg = _panel_instance.config();    // 表示パネル設定用の構造体を取得します。

                cfg.pin_cs           =    12;  // CSが接続されているピン番号   (-1 = disable)
                cfg.pin_rst          =    18;  // RSTが接続されているピン番号  (-1 = disable)
                cfg.pin_busy         =    -1;  // BUSYが接続されているピン番号 (-1 = disable)

                // ※ 以下の設定値はパネル毎に一般的な初期値が設定されていますので、不明な項目はコメントアウトして試してみてください。

                cfg.panel_width      =   368;  // 実際に表示可能な幅
                cfg.panel_height     =   448;  // 実際に表示可能な高さ
                cfg.offset_x         =     0;  // パネルのX方向オフセット量
                cfg.offset_y         =     0;  // パネルのY方向オフセット量
                cfg.offset_rotation  =     0;  // 回転方向の値のオフセット 0~7 (4~7は上下反転)
                cfg.dummy_read_pixel =     8;  // ピクセル読出し前のダミーリードのビット数
                cfg.dummy_read_bits  =     1;  // ピクセル以外のデータ読出し前のダミーリードのビット数
                cfg.readable         =  true;  // データ読出しが可能な場合 trueに設定
                cfg.invert           = true;  // パネルの明暗が反転してしまう場合 trueに設定
                cfg.rgb_order        = true;  // パネルの赤と青が入れ替わってしまう場合 trueに設定
                cfg.dlen_16bit       = false;  // 16bitパラレルやSPIでデータ長を16bit単位で送信するパネルの場合 trueに設定
                cfg.bus_shared       =  true;  // SDカードとバスを共有している場合 trueに設定(drawJpgFile等でバス制御を行います)

                // 以下はST7735やILI9163のようにピクセル数が可変のドライバで表示がずれる場合にのみ設定してください。
                cfg.memory_width     =   480;  // ドライバICがサポートしている最大の幅
                cfg.memory_height    =   480;  // ドライバICがサポートしている最大の高さ

                _panel_instance.config(cfg);
            }
            setPanel(&_panel_instance); // 使用するパネルをセットします。
        }
};
static LGFX_Monica lcd;
static FT3168::tp_ft3168 tp;





#define PWR_EN  7
#define TE      8




void lv_port_disp_init();
void lv_port_indev_init();



extern "C" void app_main(void)
{


    gpio_reset_pin(GPIO_NUM_7);
    gpio_set_direction(GPIO_NUM_7, GPIO_MODE_OUTPUT);
    gpio_set_pull_mode(GPIO_NUM_7, GPIO_PULLUP_PULLDOWN);
    gpio_set_level(GPIO_NUM_7, 1);
    delay(10);


    gpio_reset_pin(GPIO_NUM_8);
    gpio_set_direction(GPIO_NUM_8, GPIO_MODE_INPUT);
    delay(10);




    lcd.init();
    lcd.setColorDepth(16);
    // lcd.setColorDepth(24);
    lcd.setBrightness(255);
    // lcd.fillScreen(TFT_RED);


    auto cfg = tp.config();
    cfg.pull_up_en = true;
    tp.config(cfg);
    tp.init(3, 4, 2, 1, true, 400000);



    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();



    lv_demo_widgets();
    // lv_demo_benchmark();
    
    
    // lv_example_arc_1();
    // lv_example_gif_1();
    // lv_example_btn_2();
    // lv_example_btn_3();





    // lcd.fillScreen(TFT_RED);
    // delay(200);
    // lcd.fillScreen(TFT_GREEN);
    // delay(200);
    // lcd.fillScreen(TFT_BLUE);
    // delay(200);
    // // lcd.fillScreen(TFT_WHITE);
    // delay(200);



    



    while (1) {
        lv_timer_handler();
        delay(15);
    }


}










/*Flush the content of the internal buffer the specific area on the display
 *You can use DMA or any hardware acceleration to do this operation in the background but
 *'lv_disp_flush_ready()' has to be called when finished.*/
static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{
    // if(disp_flush_enabled) {
    //     /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one*/

    //     int32_t x;
    //     int32_t y;
    //     for(y = area->y1; y <= area->y2; y++) {
    //         for(x = area->x1; x <= area->x2; x++) {
    //             /*Put a pixel to the display. For example:*/
    //             /*put_px(x, y, *color_p)*/
    //             color_p++;
    //         }
    //     }
    // }

    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );


    // lcd.setAddrWindow( area->x1, area->y1, w, h );
    // lcd.setWindow(area->x1, area->y1, area->x2, area->y2);
    // _lcd->pushColors( ( uint16_t * )&color_p->full, w * h, true);
    // lcd.startWrite();
    // lcd.writePixels((uint16_t*)&color_p->full, w * h, true);
    // lcd.pushColors((uint16_t*)&color_p->full, w * h, true);
    // lcd.endWrite(); 

    // lcd.writeColor(color_p->full, w * h);
    // lcd.pushColors((uint16_t*)&color_p->full, w * h, true);
    // lcd.pushPixels(&color_p->full, w * h, true);


    // lcd.drawPixel(area->x1, area->y1, TFT_YELLOW);
    // lcd.fillCircle(area->x1, area->y1, 2, TFT_YELLOW);


    lcd.startWrite();
    lcd.setWindow(area->x1, area->y1, area->x2, area->y2);
    lcd.pushPixels(&color_p->full, w * h, true);
    lcd.endWrite();



    // lcd.pushImage(0, 0, w, h, &color_p->full);



    /*IMPORTANT!!!
     *Inform the graphics library that you are ready with the flushing*/
    lv_disp_flush_ready(disp_drv);
}



void lv_port_disp_init()
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/

    /*-----------------------------
     * Create a buffer for drawing
     *----------------------------*/

    /**
     * LVGL requires a buffer where it internally draws the widgets.
     * Later this buffer will passed to your display driver's `flush_cb` to copy its content to your display.
     * The buffer has to be greater than 1 display row
     *
     * There are 3 buffering configurations:
     * 1. Create ONE buffer:
     *      LVGL will draw the display's content here and writes it to your display
     *
     * 2. Create TWO buffer:
     *      LVGL will draw the display's content to a buffer and writes it your display.
     *      You should use DMA to write the buffer's content to the display.
     *      It will enable LVGL to draw the next part of the screen to the other buffer while
     *      the data is being sent form the first buffer. It makes rendering and flushing parallel.
     *
     * 3. Double buffering
     *      Set 2 screens sized buffers and set disp_drv.full_refresh = 1.
     *      This way LVGL will always provide the whole rendered screen in `flush_cb`
     *      and you only need to change the frame buffer's address.
     */

    // /* Example for 1) */
    // static lv_disp_draw_buf_t draw_buf_dsc_1;
    // static lv_color_t buf_1[MY_DISP_HOR_RES * 10];                          /*A buffer for 10 rows*/
    // lv_disp_draw_buf_init(&draw_buf_dsc_1, buf_1, NULL, MY_DISP_HOR_RES * 10);   /*Initialize the display buffer*/

    // /* Example for 2) */
    // static lv_disp_draw_buf_t draw_buf_dsc_2;
    // static lv_color_t buf_2_1[MY_DISP_HOR_RES * 10];                        /*A buffer for 10 rows*/
    // static lv_color_t buf_2_2[MY_DISP_HOR_RES * 10];                        /*An other buffer for 10 rows*/
    // lv_disp_draw_buf_init(&draw_buf_dsc_2, buf_2_1, buf_2_2, MY_DISP_HOR_RES * 10);   /*Initialize the display buffer*/

    /* Example for 3) also set disp_drv.full_refresh = 1 below*/
    static lv_disp_draw_buf_t draw_buf_dsc_3;
    // static lv_color_t buf_3_1[MY_DISP_HOR_RES * MY_DISP_VER_RES];            /*A screen sized buffer*/
    // static lv_color_t buf_3_2[MY_DISP_HOR_RES * MY_DISP_VER_RES];            /*Another screen sized buffer*/

    /* Try to get buffer from PSRAM */
    // lv_color_t * buf_3_1 = (lv_color_t *)ps_malloc(MY_DISP_HOR_RES * MY_DISP_VER_RES * sizeof(lv_color_t));
    // lv_color_t * buf_3_2 = (lv_color_t *)ps_malloc(MY_DISP_HOR_RES * MY_DISP_VER_RES * sizeof(lv_color_t));
    lv_color_t * buf_3_1 = (lv_color_t *)heap_caps_malloc(MY_DISP_HOR_RES * MY_DISP_VER_RES * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);
    lv_color_t * buf_3_2 = (lv_color_t *)heap_caps_malloc(MY_DISP_HOR_RES * MY_DISP_VER_RES * sizeof(lv_color_t), MALLOC_CAP_SPIRAM);



    /* If failed */
    if ((buf_3_1 == NULL) || (buf_3_2 == NULL)) {
        printf("[LVGL] malloc buffer from PSRAM fialed\n");
        while (1)
            delay(1000);
    } else {
        printf("[LVGL] malloc buffer from PSRAM successful\n");
        printf("[LVGL] free PSRAM: %d\r\n", heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
    }

    lv_disp_draw_buf_init(&draw_buf_dsc_3, buf_3_1, buf_3_2,
                          MY_DISP_VER_RES * LV_VER_RES_MAX);   /*Initialize the display buffer*/

    /*-----------------------------------
     * Register the display in LVGL
     *----------------------------------*/

    static lv_disp_drv_t disp_drv;                         /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv);                    /*Basic initialization*/

    /*Set up the functions to access to your display*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = MY_DISP_HOR_RES;
    disp_drv.ver_res = MY_DISP_VER_RES;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = disp_flush;

    /*Set a display buffer*/
    disp_drv.draw_buf = &draw_buf_dsc_3;

    /*Required for Example 3)*/
    // disp_drv.full_refresh = 1;

    /* Fill a memory array with a color if you have GPU.
     * Note that, in lv_conf.h you can enable GPUs that has built-in support in LVGL.
     * But if you have a different GPU you can use with this callback.*/
    //disp_drv.gpu_fill_cb = gpu_fill;

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}



static FT3168::TouchPoint_t tpp;

/*Will be called by the library to read the touchpad*/
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    // static lv_coord_t last_x = 0;
    // static lv_coord_t last_y = 0;

    // /*Save the pressed coordinates and the state*/
    // if(touchpad_is_pressed()) {
    //     touchpad_get_xy(&last_x, &last_y);
    //     data->state = LV_INDEV_STATE_PR;
    // }
    // else {
    //     data->state = LV_INDEV_STATE_REL;
    // }

    tp.getTouchRaw(tpp);
    if(tpp.x != -1) {
        // printf("%d %d\n", tpp.x, tpp.y);
        data->point.x = tpp.x;
        data->point.y = tpp.y;
        data->state = LV_INDEV_STATE_PR;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }

    /*Set the last pressed coordinates*/
    // data->point.x = last_x;
    // data->point.y = last_y;
}



void lv_port_indev_init()
{
    /**
     * Here you will find example implementation of input devices supported by LittelvGL:
     *  - Touchpad
     *  - Mouse (with cursor support)
     *  - Keypad (supports GUI usage only with key)
     *  - Encoder (supports GUI usage only with: left, right, push)
     *  - Button (external buttons to press points on the screen)
     *
     *  The `..._read()` function are only examples.
     *  You should shape them according to your hardware
     */

    static lv_indev_drv_t indev_drv;

    /*------------------
     * Touchpad
     * -----------------*/

    /*Initialize your touchpad if you have*/

    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touchpad_read;
    // indev_touchpad = lv_indev_drv_register(&indev_drv);
    lv_indev_drv_register(&indev_drv);
}
