#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static lv_meter_scale_t * scale0;
static lv_meter_indicator_t * indicator1;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 172, 320);
    {
        lv_obj_t *parent_obj = obj;
        {
            // lbl_dashboard
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_dashboard = obj;
            lv_obj_set_pos(obj, 47, 9);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Dashboard");
        }
        {
            // bar_temperatur
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.bar_temperatur = obj;
            lv_obj_set_pos(obj, 11, 294);
            lv_obj_set_size(obj, 150, 10);
            lv_bar_set_range(obj, 0, 50);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfffffc27), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffff27b8), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // lbl_temperatur_value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_temperatur_value = obj;
            lv_obj_set_pos(obj, 76, 270);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "20 ");
        }
        {
            // lbl_temperatur
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_temperatur = obj;
            lv_obj_set_pos(obj, 43, 254);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Temperatur");
        }
        {
            // meter_volt
            lv_obj_t *obj = lv_meter_create(parent_obj);
            objects.meter_volt = obj;
            lv_obj_set_pos(obj, 15, 75);
            lv_obj_set_size(obj, 143, 143);
            {
                lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                scale0 = scale;
                lv_meter_set_scale_ticks(obj, scale, 41, 1, 5, lv_color_hex(0xffa0a0a0));
                lv_meter_set_scale_major_ticks(obj, scale, 8, 3, 10, lv_color_hex(0xff02ef90), 10);
                lv_meter_set_scale_range(obj, scale, 0, 12, 300, 120);
                {
                    lv_meter_indicator_t *indicator = lv_meter_add_needle_line(obj, scale, 3, lv_color_hex(0xffff0045), 0);
                    indicator1 = indicator;
                    lv_meter_set_indicator_value(obj, indicator, 0);
                }
            }
        }
        {
            // lbl_volt
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_volt = obj;
            lv_obj_set_pos(obj, 73, 56);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Volt");
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}
