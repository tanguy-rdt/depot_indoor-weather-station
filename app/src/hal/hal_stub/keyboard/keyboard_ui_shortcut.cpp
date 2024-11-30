/**
 * @file KeyboardUiShortcut
 * @brief [Description]
 * @author Tanguy Roudaut
 * @date 29/11/2024
 */

#include "keyboard_ui_shortcut.h"

#include "hal_conf_internal.h"
#include "log.h"

static void eventHandler(lv_event_t *event) {
	lv_event_code_t code = lv_event_get_code(event);
	lv_obj_t* obj = lv_event_get_target(event);

	const auto instance = static_cast<KeyboardUiShortcut*>(lv_event_get_user_data(event));
	const auto btn = (KeyboardUiShortcut::BtnType)(uintptr_t)lv_obj_get_user_data(obj);

	if (instance)
		instance->treatEventHandler(btn, code);
}

KeyboardUiShortcut::KeyboardUiShortcut(EventManager *eventManager)
	: _eventManager(eventManager) {

	_container = lv_obj_create(lv_scr_act());
	lv_obj_set_size(_container, HAL_SCREEN_WIDTH, HAL_SCREEN_HEIGHT);
	lv_obj_align(_container, LV_ALIGN_BOTTOM_LEFT, 0, 0);
	lv_obj_set_scroll_dir(_container, LV_DIR_NONE);
	lv_obj_set_style_pad_gap(_container, 0, 0);

	_okBtn = lv_btn_create(_container);
	lv_obj_set_size(_okBtn, 30, 30);
	lv_obj_set_align(_okBtn, LV_ALIGN_TOP_RIGHT);
	lv_obj_add_event_cb(_okBtn, eventHandler, LV_EVENT_ALL, this);
	lv_obj_set_user_data(_okBtn, (void*)(uintptr_t)BtnType::OK_BTN);
	_labelOkBtn = lv_label_create(_okBtn);
	lv_obj_set_align(_labelOkBtn, LV_ALIGN_CENTER);
	lv_obj_set_style_text_color(_labelOkBtn, lv_color_white(), 0);
	lv_label_set_text(_labelOkBtn, LV_SYMBOL_OK);

	_leftBtn = lv_btn_create(_container);
	lv_obj_set_size(_leftBtn, 30, 30);
	lv_obj_set_align(_leftBtn, LV_ALIGN_BOTTOM_LEFT);
	lv_obj_add_event_cb(_leftBtn, eventHandler, LV_EVENT_ALL, this);
	lv_obj_set_user_data(_leftBtn, (void*)(uintptr_t)BtnType::LEFT_BTN);
	_labelLeftBtn = lv_label_create(_leftBtn);
	lv_obj_set_align(_labelLeftBtn, LV_ALIGN_CENTER);
	lv_obj_set_style_text_color(_labelLeftBtn, lv_color_white(), 0);
	lv_label_set_text(_labelLeftBtn, LV_SYMBOL_LEFT);

	_rightBtn = lv_btn_create(_container);
	lv_obj_set_size(_rightBtn, 30, 30);
	lv_obj_set_align(_rightBtn, LV_ALIGN_BOTTOM_RIGHT);
	lv_obj_add_event_cb(_rightBtn, eventHandler, LV_EVENT_ALL, this);
	lv_obj_set_user_data(_rightBtn, (void*)(uintptr_t)BtnType::RIGHT_BTN);
	_labelRightBtn = lv_label_create(_rightBtn);
	lv_obj_set_align(_labelRightBtn, LV_ALIGN_CENTER);
	lv_obj_set_style_text_color(_labelRightBtn, lv_color_white(), 0);
	lv_label_set_text(_labelRightBtn, LV_SYMBOL_RIGHT);
}

void KeyboardUiShortcut::renewParent() const {
	lv_obj_set_parent(_container, lv_scr_act());
}

void KeyboardUiShortcut::treatEventHandler(BtnType btn, lv_event_code_t event) const {
	if (event == LV_EVENT_CLICKED) {
		btn == BtnType::OK_BTN    ? _eventManager->emit(EventManager::Signal::OK_BUTTON_PRESSED)    :
		btn == BtnType::LEFT_BTN  ? _eventManager->emit(EventManager::Signal::LEFT_BUTTON_PRESSED)  :
		btn == BtnType::RIGHT_BTN ? _eventManager->emit(EventManager::Signal::RIGHT_BUTTON_PRESSED) : (void)0;
	}
}

