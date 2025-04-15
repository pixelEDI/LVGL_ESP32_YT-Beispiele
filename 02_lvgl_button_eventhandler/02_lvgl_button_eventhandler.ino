//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025

#include "touchscreen.h"

static void button_event_cb(lv_event_t * e){
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * button = (lv_obj_t*) lv_event_get_target(e);
  lv_obj_t * label = (lv_obj_t*) lv_event_get_user_data(e);

  if( code == LV_EVENT_CLICKED){
    static uint8_t counter = 0;
    counter++;
    if(counter>4){
      lv_label_set_text_fmt(label, "Boom %d",counter);
    }
    else {
      lv_label_set_text_fmt(label, "Counter: %d",counter);
    }
  }
}

void lv_gui_button() {
  lv_obj_t *label;
  lv_obj_t *btn1 = lv_button_create(lv_screen_active());
  // lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, NULL);
  lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -60);
  lv_obj_set_style_bg_color(btn1, lv_palette_main(LV_PALETTE_RED), 0);
  lv_obj_set_size(btn1, 190, 90);
  label = lv_label_create(btn1);
  lv_label_set_text(label, "Ich bin Rot");
  lv_obj_center(label);

  lv_obj_t *label2;
  lv_obj_t *btn2 = lv_button_create(lv_screen_active());
  // lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, NULL);
  lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 30);
  lv_obj_set_style_bg_color(btn2, lv_palette_main(LV_PALETTE_GREEN), 0);
  lv_obj_set_size(btn2, 90, 40);
  label2 = lv_label_create(btn2);
  lv_label_set_text(label2, "Green");
  lv_obj_center(label2);

  lv_obj_t * text_label_counter = lv_label_create(lv_screen_active());
  lv_label_set_text(text_label_counter, "Wie oft geklickt: 0");
  lv_obj_align(text_label_counter, LV_ALIGN_BOTTOM_MID, 0, -20);

  lv_obj_add_event_cb(btn1, button_event_cb, LV_EVENT_ALL, text_label_counter);
}

void setup() {
  touchscreen_setup();
  lv_gui_button();
}

void loop() {
  lv_task_handler();
  lv_tick_inc(5);
  delay(5);
}
