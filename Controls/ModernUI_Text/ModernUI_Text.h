#ifdef __cplusplus
extern "C" {
#endif

#ifdef _MSC_VER     // MSVC compiler
#define MUI_EXPORT __declspec(dllexport) __fastcall
#else
#define MUI_EXPORT
#endif


//------------------------------------------------------------------------------
// ModernUI_Text Prototypes
//------------------------------------------------------------------------------

void MUI_EXPORT MUITextRegister(); // Use 'ModernUI_Text' as class in RadASM custom class control
HWND MUI_EXPORT MUITextCreate(HWND hWndParent, LPCSTR *lpszText, QWORD xpos, QWORD ypos, QWORD qwWidth, QWORD qwHeight, QWORD qwResourceID, QWORD qwStyle);
unsigned int MUI_EXPORT MUITextSetProperty(HWND hModernUI_Text, QWORD qwProperty, QWORD qwPropertyValue);
unsigned int MUI_EXPORT MUITextGetProperty(HWND hModernUI_Text, QWORD qwProperty);
bool MUI_EXPORT MUITextSetBufferSize(HWND hModernUI_Text, QWORD qwBufferSize);


//------------------------------------------
// ModernUI_Text Styles
//------------------------------------------

; Font size - AND 0Fh to get value                          : 0000 0000 0000 XXXX
MUITS_7PT               1  // 7pt
MUITS_8PT               0  // 8pt
MUITS_9PT               2  // 9pt
MUITS_10PT              3  // 10pt
MUITS_11PT              4  // 11pt
MUITS_12PT              5  // 12pt
MUITS_13PT              6  // 13pt
MUITS_14PT              7  // 14pt
MUITS_15PT              8  // 15pt
MUITS_16PT              9  // 16pt
MUITS_18PT              10 // 18pt
MUITS_20PT              11 // 20pt
MUITS_22PT              12 // 22pt
MUITS_24PT              13 // 24pt
MUITS_28PT              14 // 28pt
MUITS_32PT              15 // 32pt

// Font familty - AND 0F0h shr 4 to get value                : 0000 0000 0XXX 0000
MUITS_FONT_DIALOG       0 shl 4 // 0000 0000 0000 0000
MUITS_FONT_SEGOE        1 shl 4 // 0000 0000 0001 0000
MUITS_FONT_TAHOMA       2 shl 4 // 0000 0000 0010 0000
MUITS_FONT_ARIAL        3 shl 4 // 0000 0000 0011 0000
MUITS_FONT_TIMES        4 shl 4 // 0000 0000 0100 0000
MUITS_FONT_COURIER      5 shl 4 // 0000 0000 0101 0000
MUITS_FONT_VERDANA      6 shl 4 // 0000 0000 0110 0000

// Text alignment - AND 300h shr 8 to get value              : 0000 00XX 0000 0000
MUITS_ALIGN_LEFT        0 shl 8 // 0000 0000 0000 0000
MUITS_ALIGN_RIGHT       1 shl 8 // 0000 0001 0000 0000
MUITS_ALIGN_CENTER      2 shl 8 // 0000 0010 0000 0000
MUITS_ALIGN_JUSTIFY     3 shl 8 // same as align left

// Font special - direct AND with and check value            : 000X XX00 0000 0000
MUITS_FONT_NORMAL       0 shl 10 // 0000 0000 0000 0000
MUITS_FONT_BOLD         1 shl 10 // 0000 0100 0000 0000
MUITS_FONT_ITALIC       1 shl 11 // 0000 1000 0000 0000
MUITS_FONT_UNDERLINE    1 shl 12 // 0001 0000 0000 0000

// Misc options - direct AND with and check value            : XXX0 0000 0000 0000
MUITS_SINGLELINE        1 shl 13 // 0010 0000 0000 0000
MUITS_HAND              1 shl 14 // 0100 0000 0000 0000 - Show a hand instead of an arrow when mouse moves over text
MUITS_LORUMIPSUM        1 shl 15 // 1000 0000 0000 0000 - Show lorum ipsum in text box - for demo purposes etc.

MUITS_UTF8              1 shl 7
MUITS_HTMLCODE          (MUITS_LORUMIPSUM or MUITS_ALIGN_JUSTIFY or MUITS_FONT_NORMAL)  // only use one or other
MUITS_BBCODE            (MUITS_LORUMIPSUM or MUITS_ALIGN_JUSTIFY or MUITS_FONT_BOLD)    // dont use both options


//------------------------------------------------------------------------------
// ModernUI_Text Properties: Use with MUITextSetProperty / MUITextGetProperty or
// MUI_SETPROPERTY / MUI_GETPROPERTY msgs
//------------------------------------------------------------------------------
#define TextFont               0       // hFont
#define TextColor              8       // COLORREF
#define TextColorAlt           16      // COLORREF
#define TextColorDisabled      24      // COLORREF
#define TextBackColor          32      // COLORREF, -1 = transparent
#define TextBackColorAlt       40      // COLORREF
#define TextBackColorDisabled  48      // COLORREF




#ifdef __cplusplus
}
#endif
