/**
 * @file KeyboardUiShortcut
 * @brief [Description]
 * @author Tanguy Roudaut
 * @date 29/11/2024
 */

#ifndef KEYBOARD_UI_SHORTCUT_H
#define KEYBOARD_UI_SHORTCUT_H

#include "lvgl.h"

#include "event_manager.h"

class KeyboardUiShortcut {
	public:
		KeyboardUiShortcut(EventManager *event_manager);
	    ~KeyboardUiShortcut();

		enum class BtnType {
			LEFT_BTN = 1,
			RIGHT_BTN,
			OK_BTN,
		};


        void renewParent() const;
		void treatEventHandler(BtnType btn, lv_event_code_t event) const;

    private:

      	EventManager *_eventManager;

		lv_obj_t*  _container;
		lv_obj_t*  _okBtn;
		lv_obj_t*  _labelOkBtn;
		lv_obj_t*  _leftBtn;
		lv_obj_t*  _labelLeftBtn;
		lv_obj_t*  _rightBtn;
		lv_obj_t*  _labelRightBtn;
};



#endif //KEYBOARD_UI_SHORTCUT_H
