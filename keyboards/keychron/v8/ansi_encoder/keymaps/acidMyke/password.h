#define PASSWORD_1 "INL9HRU"
#define PASSWORD_2 "jun_jie_yong_from.NCS@iras.gov.sg"
#define PASSWORD_3 "Jj@7255227"
#define PASSWORD_4 "JSMM1@qF@YjLtglH"
#define PASSWORD_5 "iR!N3p3TAD3f4ult22"
#define PASSWORD_7 "IRAS\\INL9HRU"
#define PASSWORD_8 "jun_jie_yong_from.NCS"

#define PASSWORD_9 "StvyX_T%m%l_F!sv"

enum {
	SS_PASS_1 = SAFE_RANGE,
	SS_PASS_2,
	SS_PASS_3,
	SS_PASS_4,
	SS_PASS_5,
	SS_PASS_6,
	SS_PASS_7,
	SS_PASS_8,
	SS_PASS_9,
	SS_PASS_0,
	SAFE_RANGE_AFTER_SS_PASS
};

#ifndef PASSWORD_1
#define PASSWORD_1 ""
#endif
#ifndef PASSWORD_2
#define PASSWORD_2 ""
#endif
#ifndef PASSWORD_3
#define PASSWORD_3 ""
#endif
#ifndef PASSWORD_4
#define PASSWORD_4 ""
#endif
#ifndef PASSWORD_5
#define PASSWORD_5 ""
#endif
#ifndef PASSWORD_6
#define PASSWORD_6 ""
#endif
#ifndef PASSWORD_7
#define PASSWORD_7 ""
#endif
#ifndef PASSWORD_8
#define PASSWORD_8 ""
#endif
#ifndef PASSWORD_9
#define PASSWORD_9 ""
#endif
#ifndef PASSWORD_0
#define PASSWORD_0 ""
#endif

bool process_record_password(uint16_t keycode, keyrecord_t *record) {
	if (!record->event.pressed) {
		return true;
	}

	switch (keycode) {
		case SS_PASS_1:
			SEND_STRING_DELAY(PASSWORD_1, 17);
			return false;
		case SS_PASS_2:
			SEND_STRING_DELAY(PASSWORD_2, 17);
			return false;
		case SS_PASS_3:
			SEND_STRING_DELAY(PASSWORD_3, 17);
			return false;
		case SS_PASS_4:
			SEND_STRING_DELAY(PASSWORD_4, 17);
			return false;
		case SS_PASS_5:
			SEND_STRING_DELAY(PASSWORD_5, 17);
			return false;
		case SS_PASS_6:
			SEND_STRING_DELAY(PASSWORD_6, 17);
			return false;
		case SS_PASS_7:
			SEND_STRING_DELAY(PASSWORD_7, 17);
			return false;
		case SS_PASS_8:
			SEND_STRING_DELAY(PASSWORD_8, 17);
			return false;
		case SS_PASS_9:
			SEND_STRING_DELAY(PASSWORD_9, 17);
			return false;
		case SS_PASS_0:
			SEND_STRING_DELAY(PASSWORD_0, 17);
			return false;
	}
	return true;
}