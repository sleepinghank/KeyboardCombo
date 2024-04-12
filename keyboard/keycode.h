#ifndef _KEYCODE_H_
#define _KEYCODE_H_

typedef enum
{
    NO_KEY_UPDATE = 0,
    KEY_UPDATE = 1,
    GHOST_KEY = 2,
} key_update_st_t;

typedef enum
{
    N_KEY_TYPE = 0x0000,        // normal key type
    M_KEY_TYPE = 0x1000,        // Media key type
    C_KEY_TYPE = 0x2000,        // Combo key type
    S_KEY_TYPE = 0x4000,        // Special key type
} key_category_t;

typedef enum
{
    KB_NO_EVT =  0x0000,
    KB_ERR_ROLL_OVER =  0x0001,
    KB_POST_FAIL =  0x0002,
    KB_ERR_UNDEFINED =  0x0003,
    KB_A =  0x0004,
    KB_B =  0x0005,
    KB_C =  0x0006,
    KB_D =  0x0007,
    KB_E =  0x0008,
    KB_F =  0x0009,
    KB_G =  0x000A,
    KB_H =  0x000B,
    KB_I =  0x000C,
    KB_J =  0x000D,
    KB_K =  0x000E,
    KB_L =  0x000F,
    KB_M =  0x0010,
    KB_N =  0x0011,
    KB_O =  0x0012,
    KB_P =  0x0013,
    KB_Q =  0x0014,
    KB_R =  0x0015,
    KB_S =  0x0016,
    KB_T =  0x0017,
    KB_U =  0x0018,
    KB_V =  0x0019,
    KB_W =  0x001A,
    KB_X =  0x001B,
    KB_Y =  0x001C,
    KB_Z =  0x001D,
    KB_1 =  0x001E,
    KB_2 =  0x001F,
    KB_3 =  0x0020,
    KB_4 =  0x0021,
    KB_5 =  0x0022,
    KB_6 =  0x0023,
    KB_7 =  0x0024,
    KB_8 =  0x0025,
    KB_9 =  0x0026,
    KB_0 =  0x0027,
    KB_ENTER =  0x0028,
    KB_ESCAPE =  0x0029,
    KB_DELETE_BACKSPACE =  0x002A,
    KB_TAB =  0x002B,
    KB_SPACEBAR =  0x002C,
    KB_MINUS_N_UNDERSCORE =  0x002D,                         // - and _
    KB_EQUAL_N_PLUS =  0x002E,                               // = and +
    KB_OPEN_BRACKET_N_BRANCE =  0x002F,                      // [ and {
    KB_CLOSE_BRACKET_N_BRANCE =  0x0030,                     // ] and }
    KB_BACK_SPLASH_N_VERTICAL_BAR =  0x0031,                 // \ and |
    KB_EUROPE_1 =  0x0032,
    KB_SEMICOLON_N_COLON =  0x0033,                          // keyboard ; and :
    KB_SINGLE_QUOTE_N_QUOTE =  0x0034,                       // keyboard ' and "
    KB_GRAVE_ACCENT_N_TILDE =  0x0035,                       // keyboard ` and ~
    KB_COMMA_N_LESS_THAN =  0x0036,                          // keyboard , and <
    KB_DOT_N_GREATER_THAN =  0x0037,                         // keyboard . and >
    KB_FORWARD_SPLASH_N_QUESTION_MARK =  0x0038,             // keyboard / and ?
    KB_CAPS_LOCK =  0x0039,
    KB_F1 =  0x003A,
    KB_F2 =  0x003B,
    KB_F3 =  0x003C,
    KB_F4 =  0x003D,
    KB_F5 =  0x003E,
    KB_F6 =  0x003F,
    KB_F7 =  0x0040,
    KB_F8 =  0x0041,
    KB_F9 =  0x0042,
    KB_F10 =  0x0043,
    KB_F11 =  0x0044,
    KB_F12 =  0x0045,
    KB_PRINT_SCREEN =  0x0046,
    KB_SCROLL_LOCK =  0x0047,
    KB_PAUSE =  0x0048,
    KB_INSERT = 0x0049,
    KB_HOME = 0x004A,
    KB_PAGEUP = 0x004B,
    KB_DELETE_FORWARD = 0x004C,
    KB_END = 0x004D,
    KB_PAGEDOWN = 0x004E,
    KB_RIGHT_ARROW = 0x004F,
    KB_LEFT_ARROW = 0x0050,
    KB_DOWN_ARROW = 0x0051,
    KB_UP_ARROW = 0x0052,
    KP_NUM_LOCK_N_CLEAR = 0x0053,
    KP_FORWARD_SPLASH = 0x0054,                              // keypad /
    KP_ASTERISK = 0x0055,                                    // keypad *
    KP_MINUS  = 0x0056,                                      // keypad -
    KP_PLUS = 0x0057,                                        // keypad +
    KP_ENTER  = 0x0058,
    KP_1_N_END  = 0x0059,
    KP_2_N_DOWN_ARROW  = 0x005A,
    KP_3_N_PAGEDN  = 0x005B,
    KP_4_N_LEFT_ARROW  = 0x005C,
    KP_5  = 0x005D,
    KP_6_N_RIGHT_ARROW  = 0x005E,
    KP_7_N_HOME = 0x005F,
    KP_8_N_UP_ARROW = 0x0060,
    KP_9_N_PAGEUP  = 0x0061,
    KP_0_N_INSERT  = 0x0062,
    KP_DOT_N_DELETE = 0x0063,
    KB_EUROPE_2 = 0x0064,
    KB_APPLICATION = 0x0065,
    KB_POWER  = 0x0066,
    KP_EQUAL  = 0x0067,                                      // keypad =
    KB_F13  = 0x0068,
    KB_F14 = 0x0069,
    KB_F15 = 0x006A,
    KB_F16 = 0x006B,
    KB_F17 = 0x006C,
    KB_F18 = 0x006D,
    KB_F19 = 0x006E,
    KB_F20 = 0x006F,
    KB_F21 = 0x0070,
    KB_F22 = 0x0071,
    KB_F23 = 0x0072,
    KB_F24 = 0x0073,
    KB_EXECUTE = 0x0074,
    KB_HELP = 0x0075,
    KB_MENU = 0x0076,
    KB_SELECT = 0x0077,
    KB_STOP = 0x0078,
    KB_AGAIN = 0x0079,
    KB_UNDO = 0x007A,
    KB_CUT = 0x007B,
    KB_COPY = 0x007C,
    KB_PASTE = 0x007D,
    KB_FIND = 0x007E,
    KB_MUTE = 0x007F,
    KB_VOLUME_UP = 0x0080,
    KB_VOLUME_DOWN = 0x0081,
    KB_LOCKING_CAPS_LOCK = 0x0082,
    KB_LOCKING_NUM_LOCK = 0x0083,
    KB_LOCKING_SCROLL_LOCK = 0x0084,
    KP_COMMA = 0x0085,
    KP_EQUAL_SIGN = 0x0086,
    KB_INTERNATIONAL_1 = 0x0087,
    KB_INTERNATIONAL_2 = 0x0088,
    KB_INTERNATIONAL_3 = 0x0089,
    KB_INTERNATIONAL_4 = 0x008A,
    KB_INTERNATIONAL_5 = 0x008B,
    KB_INTERNATIONAL_6 = 0x008C,
    KB_INTERNATIONAL_7 = 0x008D,
    KB_INTERNATIONAL_8 = 0x008E,
    KB_INTERNATIONAL_9 = 0x008F,
    KB_LANG_1 = 0x0090,
    KB_LANG_2 = 0x0091,
    KB_LANG_3 = 0x0092,
    KB_LANG_4 = 0x0093,
    KB_LANG_5 = 0x0094,
    KB_LANG_6 = 0x0095,
    KB_LANG_7 = 0x0096,
    KB_LANG_8 = 0x0097,
    KB_LANG_9 = 0x0098,
    KB_ALTERNATE_ERASE = 0x0099,
    KB_SYS_REQ_N_ATTENTION = 0x009A,
    KB_CANCEL = 0x009B,
    KB_CLEAR = 0x009C,
    KB_PRIOR = 0x009D,
    KB_RETURN = 0x009E,
    KB_SEPARATOR = 0x009F,
    KB_OUT  =   0x00A0,
    KB_OPER =   0x00A1,
    KB_CLEAR_N_AGAIN    =   0x00A2,
    KB_CR_SEL_N_PROPS   =   0x00A3,
    KB_EX_SEL   =   0x00A4,
    //  Reserved : 0x00A5-0x00AF
    KP_00   =   0x00B0,
    KP_000  =   0x00B1,
    THOUSANDS_SEPARATOR =   0x00B2,
    DECIMAL_SEPARATOR   =   0x00B3,
    CURRENCY_UNIT   =   0x00B4,
    CURRENCY_SUB_UNIT   =   0x00B5,
    KP_OPEN_PARENTHESIS =   0x00B6,                          // keypad (
    KP_CLOSE_PARENTHESIS    =   0x00B7,                      // keypad )
    KP_OPEN_BRANCE  =   0x00B8,                              // keypad {
    KP_CLOSE_BRANCE =   0x00B9,                              // keypad }
    KP_TAB  =   0x00BA,
    KP_BACKSPACE    =   0x00BB,
    KP_A    =   0x00BC,
    KP_B    =   0x00BD,
    KP_C    =   0x00BE,
    KP_D    =   0x00BF,
    KP_E    =   0x00C0,
    KP_F    =   0x00C1,
    KP_XOR  =   0x00C2,
    KP_CARAT    =   0x00C3,                                  // keypad ^
    KP_PERCENT  =   0x00C4,                                  // keypad %
    KP_LESS_THAN    =   0x00C5,                              // keypad <
    KP_GREATER_THAN =   0x00C6,                              // keypad >
    KP_AND  =   0x00C7,                                      // keypad &
    KP_DOUBLE_AND   =   0x00C8,                              // keypad &&
    KP_VERTICAL_BAR =   0x00C9,                              // keypad |
    KP_DOUBLE_VERTICAL_BAR  =   0x00CA,                      // keypad ||
    KP_COLON    =   0x00CB,                                  // keypad :
    KP_HASH =   0x00CC,                                      // keypad #
    KP_SPACE    =   0x00CD,                                  // keypad Space
    KP_AT   =   0x00CE,                                      // keypad @
    KP_EXCLAMATION_MARK =   0x00CF,                          // keypad !
    KP_MEMORY_STORE =   0x00D0,
    KP_MEMORY_RECALL    =   0x00D1,
    KP_MEMORY_CLEAR =   0x00D2,
    KP_MEMORY_ADD   =   0x00D3,
    KP_MEMORY_SUBTRACT  =   0x00D4,
    KP_MEMORY_MULTIPLY  =   0x00D5,
    KP_MEMORY_DIVIDE    =   0x00D6,
    KP_PLUS_N_MINUS =   0x00D7,                              // keypad +/-
    KP_CLEAR    =   0x00D8,
    KP_CLEAR_ENTRY  =   0x00D9,
    KP_BINARY   =   0x00DA,
    KP_OCTAL    =   0x00DB,
    KP_DECIMAL  =   0x00DC,
    KP_HEX  =   0x00DD,
    //  Reserved : 0x00DE-0x00DF
    KB_L_CTRL   =   0x00E0,
    KB_L_SHIFT  =   0x00E1,
    KB_L_ALT    = 0x00E2,
    KB_L_GUI    =   0x00E3,
    KB_R_CTRL   =   0x00E4,
    KB_R_SHIFT  =   0x00E5,
    KB_R_ALT    =   0x00E6,
    KB_R_GUI    =   0x00E7,
    //  Reserved : 0x00E8-0xFFFF
    KB_FN_KEY   =   0x00E8,
    KB_CHANNEL_KEY0 = 0x00E9,
    KB_CHANNEL_KEY1 = 0x00EA,
    KB_CHANNEL_KEY2 = 0x00EB,
} non_modifier_keycode_t;

typedef enum
{
    M_SCAN_NEXT_TRACK       = M_KEY_TYPE | 0x00B5,
    M_SCAN_PREVIOUS_TRACK   = M_KEY_TYPE | 0x00B6,
    M_STOP                  = M_KEY_TYPE | 0x00B7,
    M_PLAY_N_PAUSE          = M_KEY_TYPE | 0x00CD,
    M_MUTE                  = M_KEY_TYPE | 0x00E2,
    M_BASS_BOOST            = M_KEY_TYPE | 0x00E5,
    M_LOUDNESS              = M_KEY_TYPE | 0x00E7,
    M_VOLUME_UP             = M_KEY_TYPE | 0x00E9,
    M_VOLUME_DOWN           = M_KEY_TYPE | 0x00EA,
    M_BASS_UP               = M_KEY_TYPE | 0x0152,
    M_BASS_DOWN             = M_KEY_TYPE | 0x0153,
    M_TREBLE_UP             = M_KEY_TYPE | 0x0154,
    M_TREBLE_DWON           = M_KEY_TYPE | 0x0155,
    M_MEDIA_SEL             = M_KEY_TYPE | 0x0183,
    M_MAIL                  = M_KEY_TYPE | 0x018A,
    M_CALCULATOR            = M_KEY_TYPE | 0x0192,
    M_MY_COMPUTER           = M_KEY_TYPE | 0x0194,
    M_WWW_SEARCH            = M_KEY_TYPE | 0x0221,
    M_WWW_HOME              = M_KEY_TYPE | 0x0223,
    M_WWW_BACK              = M_KEY_TYPE | 0x0224,
    M_WWW_FORWARD           = M_KEY_TYPE | 0x0225,
    M_WWW_STOP              = M_KEY_TYPE | 0x0226,
    M_WWW_REFRESH           = M_KEY_TYPE | 0x0227,
    M_WWW_FAVOURITES        = M_KEY_TYPE | 0x022A,
    M_POWER                 = M_KEY_TYPE | 0x0030,
    M_IOS_VIRTUAL_KEYBOARD  = M_KEY_TYPE | 0x00B8,
    M_BACKLIGHT_UP          = M_KEY_TYPE | 0x006F,
    M_BACKLIGHT_DOWN        = M_KEY_TYPE | 0x0070,
    M_EARTH                 = M_KEY_TYPE | 0x029D,

} media_keycode_t;

typedef enum
{
    C_EMOJI_MAKE        = C_KEY_TYPE | 0x0001,
    C_EMOJI_BREAK       = C_KEY_TYPE | 0x0002,
    C_DESKTOP           = C_KEY_TYPE | 0x0003,
    C_OFFICE            = C_KEY_TYPE | 0x0004,
    C_LOCK              = C_KEY_TYPE | 0x0005,
    C_ACTION_CENTER     = C_KEY_TYPE | 0x0006,
    C_SETTING           = C_KEY_TYPE | 0x0007,
} combination_keycode_t;

typedef enum
{
    S_PAIRING   = S_KEY_TYPE | 0x0001,
    S_FN_KEY    = S_KEY_TYPE | 0x0002,
} special_keycode_t;
#define U32BIT(s)			((uint32_t)1<<(s))
#define BIT(s)				((uint8_t)1<<(s))

#define BIT0					0x01
#define BIT1					0x02
#define BIT2					0x04
#define BIT3					0x08
#define BIT4					0x10
#define BIT5					0x20
#define BIT6					0x40
#define BIT7					0x80
#define BIT8					0x100
#define BIT9					0x200
#define BIT10					0x400
#define BIT11					0x800
#define BIT12					0x1000
#define BIT13					0x2000
#define BIT14					0x4000
#define BIT15					0x8000
#define BIT16					0x10000
#define BIT17					0x20000
#define BIT18 					0x40000
#define BIT19					0x80000
#define BIT20					0x100000
#define BIT21					0x200000
#define BIT22					0x400000
#define BIT23					0x800000
#define BIT24					0x1000000
#define BIT25					0x2000000
#define BIT26					0x4000000
#define BIT27					0x8000000
#define BIT28					0x10000000
#define BIT29					0x20000000
#define BIT30					0x40000000
#define BIT31					0x80000000
#define BITALL					0xFFFFFFFF

typedef enum
{
    L_CTRL  = BIT0,
    L_SHIFT = BIT1,
    L_ALT   = BIT2,
    L_GUI   = BIT3,
    R_CTRL  = BIT4,
    R_SHIFT = BIT5,
    R_ALT   = BIT6,
    R_GUI   = BIT7,
} modifier_key_t;

#endif //_KEYCODE_H_
