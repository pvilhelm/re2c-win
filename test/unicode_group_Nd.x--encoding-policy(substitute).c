/* Generated by re2c */
#line 1 "unicode_group_Nd.x--encoding-policy(substitute).re"
#include <stdio.h>
#include "utf16.h"
#define YYCTYPE unsigned short
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
Nd:
	
#line 13 "unicode_group_Nd.x--encoding-policy(substitute).c"
{
	YYCTYPE yych;
	yych = *YYCURSOR;
	if (yych <= 0x17E9) {
		if (yych <= 0x0BE5) {
			if (yych <= 0x0965) {
				if (yych <= 0x0669) {
					if (yych <= '/') goto yy2;
					if (yych <= '9') goto yy4;
					if (yych >= 0x0660) goto yy4;
				} else {
					if (yych <= 0x06F9) {
						if (yych >= 0x06F0) goto yy4;
					} else {
						if (yych <= 0x07BF) goto yy2;
						if (yych <= 0x07C9) goto yy4;
					}
				}
			} else {
				if (yych <= 0x0A6F) {
					if (yych <= 0x09E5) {
						if (yych <= 0x096F) goto yy4;
					} else {
						if (yych <= 0x09EF) goto yy4;
						if (yych >= 0x0A66) goto yy4;
					}
				} else {
					if (yych <= 0x0AEF) {
						if (yych >= 0x0AE6) goto yy4;
					} else {
						if (yych <= 0x0B65) goto yy2;
						if (yych <= 0x0B6F) goto yy4;
					}
				}
			}
		} else {
			if (yych <= 0x0E59) {
				if (yych <= 0x0CE5) {
					if (yych <= 0x0BEF) goto yy4;
					if (yych <= 0x0C65) goto yy2;
					if (yych <= 0x0C6F) goto yy4;
				} else {
					if (yych <= 0x0D65) {
						if (yych <= 0x0CEF) goto yy4;
					} else {
						if (yych <= 0x0D6F) goto yy4;
						if (yych >= 0x0E50) goto yy4;
					}
				}
			} else {
				if (yych <= 0x103F) {
					if (yych <= 0x0ED9) {
						if (yych >= 0x0ED0) goto yy4;
					} else {
						if (yych <= 0x0F1F) goto yy2;
						if (yych <= 0x0F29) goto yy4;
					}
				} else {
					if (yych <= 0x108F) {
						if (yych <= 0x1049) goto yy4;
					} else {
						if (yych <= 0x1099) goto yy4;
						if (yych >= 0x17E0) goto yy4;
					}
				}
			}
		}
	} else {
		if (yych <= 0xA61F) {
			if (yych <= 0x1A8F) {
				if (yych <= 0x194F) {
					if (yych <= 0x180F) goto yy2;
					if (yych <= 0x1819) goto yy4;
					if (yych >= 0x1946) goto yy4;
				} else {
					if (yych <= 0x19D9) {
						if (yych >= 0x19D0) goto yy4;
					} else {
						if (yych <= 0x1A7F) goto yy2;
						if (yych <= 0x1A89) goto yy4;
					}
				}
			} else {
				if (yych <= 0x1BB9) {
					if (yych <= 0x1B4F) {
						if (yych <= 0x1A99) goto yy4;
					} else {
						if (yych <= 0x1B59) goto yy4;
						if (yych >= 0x1BB0) goto yy4;
					}
				} else {
					if (yych <= 0x1C49) {
						if (yych >= 0x1C40) goto yy4;
					} else {
						if (yych <= 0x1C4F) goto yy2;
						if (yych <= 0x1C59) goto yy4;
					}
				}
			}
		} else {
			if (yych <= 0xABEF) {
				if (yych <= 0xA909) {
					if (yych <= 0xA8CF) {
						if (yych <= 0xA629) goto yy4;
					} else {
						if (yych <= 0xA8D9) goto yy4;
						if (yych >= 0xA900) goto yy4;
					}
				} else {
					if (yych <= 0xA9D9) {
						if (yych >= 0xA9D0) goto yy4;
					} else {
						if (yych <= 0xAA4F) goto yy2;
						if (yych <= 0xAA59) goto yy4;
					}
				}
			} else {
				if (yych <= 0xD804) {
					if (yych <= 0xD800) {
						if (yych <= 0xABF9) goto yy4;
					} else {
						if (yych <= 0xD801) goto yy6;
						if (yych >= 0xD804) goto yy7;
					}
				} else {
					if (yych <= 0xD835) {
						if (yych >= 0xD835) goto yy8;
					} else {
						if (yych <= 0xFF0F) goto yy2;
						if (yych <= 0xFF19) goto yy4;
					}
				}
			}
		}
	}
yy2:
	++YYCURSOR;
yy3:
#line 13 "unicode_group_Nd.x--encoding-policy(substitute).re"
	{ return YYCURSOR == limit; }
#line 154 "unicode_group_Nd.x--encoding-policy(substitute).c"
yy4:
	++YYCURSOR;
#line 12 "unicode_group_Nd.x--encoding-policy(substitute).re"
	{ goto Nd; }
#line 159 "unicode_group_Nd.x--encoding-policy(substitute).c"
yy6:
	yych = *++YYCURSOR;
	if (yych <= 0xDC9F) goto yy3;
	if (yych <= 0xDCA9) goto yy4;
	goto yy3;
yy7:
	yych = *++YYCURSOR;
	if (yych <= 0xDC65) goto yy3;
	if (yych <= 0xDC6F) goto yy4;
	goto yy3;
yy8:
	yych = *++YYCURSOR;
	if (yych <= 0xDFCD) goto yy3;
	if (yych <= 0xDFFF) goto yy4;
	goto yy3;
}
#line 14 "unicode_group_Nd.x--encoding-policy(substitute).re"

}
static const unsigned int chars_Nd [] = {0x30,0x39,  0x660,0x669,  0x6f0,0x6f9,  0x7c0,0x7c9,  0x966,0x96f,  0x9e6,0x9ef,  0xa66,0xa6f,  0xae6,0xaef,  0xb66,0xb6f,  0xbe6,0xbef,  0xc66,0xc6f,  0xce6,0xcef,  0xd66,0xd6f,  0xe50,0xe59,  0xed0,0xed9,  0xf20,0xf29,  0x1040,0x1049,  0x1090,0x1099,  0x17e0,0x17e9,  0x1810,0x1819,  0x1946,0x194f,  0x19d0,0x19d9,  0x1a80,0x1a89,  0x1a90,0x1a99,  0x1b50,0x1b59,  0x1bb0,0x1bb9,  0x1c40,0x1c49,  0x1c50,0x1c59,  0xa620,0xa629,  0xa8d0,0xa8d9,  0xa900,0xa909,  0xa9d0,0xa9d9,  0xaa50,0xaa59,  0xabf0,0xabf9,  0xff10,0xff19,  0x104a0,0x104a9,  0x11066,0x1106f,  0x1d7ce,0x1d7ff,  0x0,0x0};
static unsigned int encode_utf16 (const unsigned int * ranges, unsigned int ranges_count, unsigned short * s)
{
	unsigned short * const s_start = s;
	for (unsigned int i = 0; i < ranges_count; i += 2)
		for (unsigned int j = ranges[i]; j <= ranges[i + 1]; ++j)
		{
			if (j <= re2c::utf16::MAX_1WORD_RUNE)
				*s++ = j;
			else
			{
				*s++ = re2c::utf16::lead_surr(j);
				*s++ = re2c::utf16::trail_surr(j);
			}
		}
	return s - s_start;
}

int main ()
{
	YYCTYPE * buffer_Nd = new YYCTYPE [842];
	unsigned int buffer_len = encode_utf16 (chars_Nd, sizeof (chars_Nd) / sizeof (unsigned int), buffer_Nd);
	if (!scan (reinterpret_cast<const YYCTYPE *> (buffer_Nd), reinterpret_cast<const YYCTYPE *> (buffer_Nd + buffer_len)))
		printf("test 'Nd' failed\n");
	delete [] buffer_Nd;
	return 0;
}
