//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025

#include "touchscreen.h"
#include "ui.h"

static void button_event_cb(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);

  if(code == LV_EVENT_CLICKED){
    static uint8_t counter = 0;
    counter ++;

    lv_label_set_text_fmt(objects.lbl_bottom_ichkanngeaendertwerden, "Hier wurde %d geklicked", counter);
  }
}

void setup() {
  touchscreen_setup();
  ui_init();
  
  lv_obj_add_event_cb(objects.btn_green_clickme, button_event_cb, LV_EVENT_ALL, NULL);
}

void loop() {
  lv_task_handler();
  lv_tick_inc(5);
  delay(5);
}
