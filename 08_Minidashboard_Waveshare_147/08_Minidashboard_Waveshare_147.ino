//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025

#include "Display_ST7789.h"
#include "LVGL_Driver.h"
#include "ui.h"

extern lv_meter_indicator_t *indicator1;

void setup() {
  LCD_Init();
  Lvgl_Init();
  ui_init();

  // lv_meter_set_indicator_value(objects.meter_volt, indicator1, 8);
  // lv_bar_set_value(objects.bar_temperatur, 35, LV_ANIM_OFF);
}

void loop() {
  static uint32_t last_update = 0;
  if (millis() - last_update >= 2000) {
    last_update = millis();

    int voltage = random(0, 13);
    int temperature = random(0, 51);

    lv_meter_set_indicator_value(objects.meter_volt, indicator1, voltage);
    lv_bar_set_value(objects.bar_temperatur, temperature, LV_ANIM_OFF);
    lv_label_set_text(objects.lbl_temperatur_value, String(temperature).c_str());
  }


  Timer_Loop();
  delay(5);
}
