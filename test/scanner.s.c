/* Generated by re2c */
#line 1 "scanner.s.re"
/* Id: scanner.re,v 1.37 2006/02/25 12:41:41 helly Exp */
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include "scanner.h"
#include "parser.h"
#include "y.tab.h"
#include "globals.h"
#include "dfa.h"

extern YYSTYPE yylval;

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

#define	BSIZE	8192

#define	YYCTYPE		char
#define	YYCURSOR	cursor
#define	YYLIMIT		lim
#define	YYMARKER	ptr
#define	YYFILL(n)	{cursor = fill(cursor);}

#define	RETURN(i)	{cur = cursor; return i;}

namespace re2c
{

Scanner::Scanner(std::istream& i, std::ostream& o)
	: in(i)
	, out(o)
	, bot(NULL), tok(NULL), ptr(NULL), cur(NULL), pos(NULL), lim(NULL)
	, top(NULL), eof(NULL), tchar(0), tline(0), cline(1), iscfg(0)
{
    ;
}

char *Scanner::fill(char *cursor)
{
	if(!eof)
	{
		uint cnt = tok - bot;
		if(cnt)
		{
			memcpy(bot, tok, lim - tok);
			tok = bot;
			ptr -= cnt;
			cursor -= cnt;
			pos -= cnt;
			lim -= cnt;
		}
		if((top - lim) < BSIZE)
		{
			char *buf = new char[(lim - bot) + BSIZE];
			memcpy(buf, tok, lim - tok);
			tok = buf;
			ptr = &buf[ptr - bot];
			cursor = &buf[cursor - bot];
			pos = &buf[pos - bot];
			lim = &buf[lim - bot];
			top = &lim[BSIZE];
			delete [] bot;
			bot = buf;
		}
		in.read(lim, BSIZE);
		if ((cnt = in.gcount()) != BSIZE )
		{
			eof = &lim[cnt]; *eof++ = '\0';
		}
		lim += cnt;
	}
	return cursor;
}

#line 95 "scanner.s.re"


int Scanner::echo()
{
    char *cursor = cur;
    bool ignore_eoc = false;

    if (eof && cursor == eof) // Catch EOF
	{
    	return 0;
	}

    tok = cursor;
echo:

#line 96 "scanner.s.c"
{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 11) YYFILL(11);
	yych = *YYCURSOR;
	if (yych <= ')') {
		if (yych <= 0x00) goto yy2;
		if (yych == '\n') goto yy6;
		goto yy4;
	} else {
		if (yych <= '*') goto yy8;
		if (yych == '/') goto yy9;
		goto yy4;
	}
yy2:
	++YYCURSOR;
#line 135 "scanner.s.re"
	{
					out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok) - 1); // -1 so we don't write out the \0
					if(cursor == eof) {
						RETURN(0);
					}
				}
#line 119 "scanner.s.c"
yy4:
	++YYCURSOR;
yy5:
#line 141 "scanner.s.re"
	{
					goto echo;
				}
#line 127 "scanner.s.c"
yy6:
	++YYCURSOR;
#line 130 "scanner.s.re"
	{
					out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok));
					tok = pos = cursor; cline++;
				  	goto echo;
				}
#line 136 "scanner.s.c"
yy8:
	yych = *++YYCURSOR;
	if (yych == '/') goto yy10;
	goto yy5;
yy9:
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '*') goto yy12;
	goto yy5;
yy10:
	++YYCURSOR;
#line 121 "scanner.s.re"
	{
					if (ignore_eoc) {
						ignore_eoc = false;
					} else {
						out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok));
					}
					tok = pos = cursor;
					goto echo;
				}
#line 157 "scanner.s.c"
yy12:
	yych = *++YYCURSOR;
	if (yych == '!') goto yy14;
yy13:
	YYCURSOR = YYMARKER;
	goto yy5;
yy14:
	yych = *++YYCURSOR;
	if (yych == 'm') goto yy15;
	if (yych == 'r') goto yy16;
	goto yy13;
yy15:
	yych = *++YYCURSOR;
	if (yych == 'a') goto yy17;
	goto yy13;
yy16:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy18;
	goto yy13;
yy17:
	yych = *++YYCURSOR;
	if (yych == 'x') goto yy19;
	goto yy13;
yy18:
	yych = *++YYCURSOR;
	if (yych == '2') goto yy20;
	goto yy13;
yy19:
	yych = *++YYCURSOR;
	if (yych == ':') goto yy21;
	goto yy13;
yy20:
	yych = *++YYCURSOR;
	if (yych == 'c') goto yy22;
	goto yy13;
yy21:
	yych = *++YYCURSOR;
	if (yych == 'r') goto yy24;
	goto yy13;
yy22:
	++YYCURSOR;
#line 110 "scanner.s.re"
	{ 
					out.write((const char*)(tok), (const char*)(&cursor[-7]) - (const char*)(tok));
					tok = cursor;
					RETURN(1);
				}
#line 205 "scanner.s.c"
yy24:
	yych = *++YYCURSOR;
	if (yych != 'e') goto yy13;
	yych = *++YYCURSOR;
	if (yych != '2') goto yy13;
	yych = *++YYCURSOR;
	if (yych != 'c') goto yy13;
	++YYCURSOR;
#line 115 "scanner.s.re"
	{
					out << "#define YYMAXFILL " << maxFill << std::endl;
					tok = pos = cursor;
					ignore_eoc = true;
					goto echo;
				}
#line 221 "scanner.s.c"
}
#line 144 "scanner.s.re"

}


int Scanner::scan()
{
    char *cursor = cur;
    uint depth;

scan:
    tchar = cursor - pos;
    tline = cline;
    tok = cursor;
	if (iscfg == 1)
	{
		goto config;
	}
	else if (iscfg == 2)
	{
   		goto value;
    }

#line 246 "scanner.s.c"
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	if ((YYLIMIT - YYCURSOR) < 5) YYFILL(5);
	yych = *YYCURSOR;
	if (yych <= '/') {
		if (yych <= '!') {
			if (yych <= '\f') {
				if (yych <= 0x08) goto yy31;
				if (yych <= '\t') goto yy33;
				if (yych <= '\n') goto yy36;
			} else {
				if (yych <= '\r') goto yy38;
				if (yych == ' ') goto yy33;
			}
		} else {
			if (yych <= ')') {
				if (yych <= '"') goto yy39;
				if (yych <= '&') goto yy31;
				if (yych <= '\'') goto yy41;
				goto yy43;
			} else {
				if (yych <= '+') {
					if (yych <= '*') goto yy45;
					goto yy47;
				} else {
					if (yych <= '-') goto yy31;
					if (yych <= '.') goto yy48;
					goto yy50;
				}
			}
		}
	} else {
		if (yych <= 'Z') {
			if (yych <= '=') {
				if (yych == ';') goto yy43;
				if (yych >= '=') goto yy43;
			} else {
				if (yych == '?') goto yy47;
				if (yych >= 'A') goto yy51;
			}
		} else {
			if (yych <= 'q') {
				if (yych <= '[') goto yy54;
				if (yych <= '\\') goto yy43;
				if (yych >= 'a') goto yy51;
			} else {
				if (yych <= 'z') {
					if (yych <= 'r') goto yy56;
					goto yy51;
				} else {
					if (yych <= '{') goto yy57;
					if (yych <= '|') goto yy43;
				}
			}
		}
	}
yy31:
	++YYCURSOR;
yy32:
#line 241 "scanner.s.re"
	{ std::ostringstream msg;
				  msg << "unexpected character: ";
				  prtChOrHex(msg, *tok);
				  fatal(msg.str().c_str());
				  goto scan;
				}
#line 314 "scanner.s.c"
yy33:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\t') goto yy33;
	if (yych == ' ') goto yy33;
#line 234 "scanner.s.re"
	{ goto scan; }
#line 323 "scanner.s.c"
yy36:
	++YYCURSOR;
#line 236 "scanner.s.re"
	{ if(cursor == eof) RETURN(0);
				  pos = cursor; cline++;
				  goto scan;
	    			}
#line 331 "scanner.s.c"
yy38:
	yych = *++YYCURSOR;
	if (yych == '\n') goto yy36;
	goto yy32;
yy39:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych != '\n') goto yy60;
yy40:
#line 183 "scanner.s.re"
	{ fatal("unterminated string constant (missing \")"); }
#line 343 "scanner.s.c"
yy41:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych != '\n') goto yy66;
yy42:
#line 184 "scanner.s.re"
	{ fatal("unterminated string constant (missing ')"); }
#line 351 "scanner.s.c"
yy43:
	++YYCURSOR;
yy44:
#line 196 "scanner.s.re"
	{ RETURN(*tok); }
#line 357 "scanner.s.c"
yy45:
	yych = *++YYCURSOR;
	if (yych == '/') goto yy70;
yy46:
#line 198 "scanner.s.re"
	{ yylval.op = *tok;
				  RETURN(CLOSE); }
#line 365 "scanner.s.c"
yy47:
	++YYCURSOR;
	goto yy46;
yy48:
	++YYCURSOR;
#line 229 "scanner.s.re"
	{ cur = cursor;
				  yylval.regexp = mkDot();
				  return RANGE;
				}
#line 376 "scanner.s.c"
yy50:
	yych = *++YYCURSOR;
	if (yych == '*') goto yy72;
	goto yy44;
yy51:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy52:
	if (yych <= '@') {
		if (yych <= '/') goto yy53;
		if (yych <= '9') goto yy51;
	} else {
		if (yych <= 'Z') goto yy51;
		if (yych <= '`') goto yy53;
		if (yych <= 'z') goto yy51;
	}
yy53:
#line 225 "scanner.s.re"
	{ cur = cursor;
				  yylval.symbol = Symbol::find(token());
				  return ID; }
#line 399 "scanner.s.c"
yy54:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '\n') goto yy55;
	if (yych == '^') goto yy79;
	goto yy75;
yy55:
#line 194 "scanner.s.re"
	{ fatal("unterminated range (missing ])"); }
#line 409 "scanner.s.c"
yy56:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy81;
	goto yy52;
yy57:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= '/') {
		if (yych == ',') goto yy82;
	} else {
		if (yych <= '0') goto yy84;
		if (yych <= '9') goto yy85;
	}
yy58:
#line 166 "scanner.s.re"
	{ depth = 1;
				  goto code;
				}
#line 428 "scanner.s.c"
yy59:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy60:
	if (yych <= '!') {
		if (yych != '\n') goto yy59;
	} else {
		if (yych <= '"') goto yy62;
		if (yych == '\\') goto yy64;
		goto yy59;
	}
yy61:
	YYCURSOR = YYMARKER;
	if (yyaccept <= 3) {
		if (yyaccept <= 1) {
			if (yyaccept == 0) {
				goto yy40;
			} else {
				goto yy42;
			}
		} else {
			if (yyaccept == 2) {
				goto yy55;
			} else {
				goto yy58;
			}
		}
	} else {
		if (yyaccept <= 5) {
			if (yyaccept == 4) {
				goto yy83;
			} else {
				goto yy53;
			}
		} else {
			goto yy107;
		}
	}
yy62:
	++YYCURSOR;
#line 175 "scanner.s.re"
	{ cur = cursor;
				  yylval.regexp = strToRE(token());
				  return STRING; }
#line 474 "scanner.s.c"
yy64:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy61;
	goto yy59;
yy65:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy66:
	if (yych <= '&') {
		if (yych == '\n') goto yy61;
		goto yy65;
	} else {
		if (yych <= '\'') goto yy67;
		if (yych == '\\') goto yy69;
		goto yy65;
	}
yy67:
	++YYCURSOR;
#line 179 "scanner.s.re"
	{ cur = cursor;
				  yylval.regexp = strToCaseInsensitiveRE(token());
				  return STRING; }
#line 500 "scanner.s.c"
yy69:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy61;
	goto yy65;
yy70:
	++YYCURSOR;
#line 172 "scanner.s.re"
	{ tok = cursor;
				  RETURN(0); }
#line 512 "scanner.s.c"
yy72:
	++YYCURSOR;
#line 169 "scanner.s.re"
	{ depth = 1;
				  goto comment; }
#line 518 "scanner.s.c"
yy74:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy75:
	if (yych <= '[') {
		if (yych == '\n') goto yy61;
		goto yy74;
	} else {
		if (yych <= '\\') goto yy76;
		if (yych <= ']') goto yy77;
		goto yy74;
	}
yy76:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy61;
	goto yy74;
yy77:
	++YYCURSOR;
#line 190 "scanner.s.re"
	{ cur = cursor;
				  yylval.regexp = ranToRE(token());
				  return RANGE; }
#line 544 "scanner.s.c"
yy79:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '[') {
		if (yych == '\n') goto yy61;
		goto yy79;
	} else {
		if (yych <= '\\') goto yy87;
		if (yych <= ']') goto yy88;
		goto yy79;
	}
yy81:
	yych = *++YYCURSOR;
	if (yych == '2') goto yy90;
	goto yy52;
yy82:
	++YYCURSOR;
yy83:
#line 216 "scanner.s.re"
	{ fatal("illegal closure form, use '{n}', '{n,}', '{n,m}' where n and m are numbers"); }
#line 566 "scanner.s.c"
yy84:
	yych = *++YYCURSOR;
	if (yych == ',') goto yy91;
	goto yy86;
yy85:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
yy86:
	if (yych <= '/') {
		if (yych == ',') goto yy94;
		goto yy61;
	} else {
		if (yych <= '9') goto yy85;
		if (yych == '}') goto yy92;
		goto yy61;
	}
yy87:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy61;
	goto yy79;
yy88:
	++YYCURSOR;
#line 186 "scanner.s.re"
	{ cur = cursor;
				  yylval.regexp = invToRE(token());
				  return RANGE; }
#line 596 "scanner.s.c"
yy90:
	yych = *++YYCURSOR;
	if (yych == 'c') goto yy95;
	goto yy52;
yy91:
	yyaccept = 4;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= '/') goto yy83;
	if (yych <= '9') goto yy96;
	if (yych == '}') goto yy98;
	goto yy83;
yy92:
	++YYCURSOR;
#line 204 "scanner.s.re"
	{ yylval.extop.minsize = atoi((char *)tok+1);
				  yylval.extop.maxsize = atoi((char *)tok+1);
				  RETURN(CLOSESIZE); }
#line 614 "scanner.s.c"
yy94:
	yyaccept = 4;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= '/') goto yy83;
	if (yych <= '9') goto yy96;
	if (yych == '}') goto yy100;
	goto yy83;
yy95:
	yyaccept = 5;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == ':') goto yy102;
	goto yy52;
yy96:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '/') goto yy61;
	if (yych <= '9') goto yy96;
	if (yych == '}') goto yy103;
	goto yy61;
yy98:
	++YYCURSOR;
#line 201 "scanner.s.re"
	{ yylval.op = '*';
				  RETURN(CLOSE); }
#line 640 "scanner.s.c"
yy100:
	++YYCURSOR;
#line 212 "scanner.s.re"
	{ yylval.extop.minsize = atoi((char *)tok+1);
				  yylval.extop.maxsize = -1;
				  RETURN(CLOSESIZE); }
#line 647 "scanner.s.c"
yy102:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '@') goto yy61;
	if (yych <= 'Z') goto yy105;
	if (yych <= '`') goto yy61;
	if (yych <= 'z') goto yy105;
	goto yy61;
yy103:
	++YYCURSOR;
#line 208 "scanner.s.re"
	{ yylval.extop.minsize = atoi((char *)tok+1);
				  yylval.extop.maxsize = MAX(yylval.extop.minsize,atoi(strchr((char *)tok, ',')+1));
				  RETURN(CLOSESIZE); }
#line 663 "scanner.s.c"
yy105:
	yyaccept = 6;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'Z') {
		if (yych <= '9') {
			if (yych >= '0') goto yy105;
		} else {
			if (yych <= ':') goto yy102;
			if (yych >= 'A') goto yy105;
		}
	} else {
		if (yych <= '_') {
			if (yych >= '_') goto yy105;
		} else {
			if (yych <= '`') goto yy107;
			if (yych <= 'z') goto yy105;
		}
	}
yy107:
#line 218 "scanner.s.re"
	{ cur = cursor;
				  tok+= 5; /* skip "re2c:" */
				  iscfg = 1;
				  yylval.str = new Str(token());
				  return CONFIG;
				}
#line 692 "scanner.s.c"
}
#line 247 "scanner.s.re"


code:

#line 699 "scanner.s.c"
{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych <= '&') {
		if (yych <= '\n') {
			if (yych >= '\n') goto yy112;
		} else {
			if (yych == '"') goto yy114;
		}
	} else {
		if (yych <= '{') {
			if (yych <= '\'') goto yy115;
			if (yych >= '{') goto yy116;
		} else {
			if (yych == '}') goto yy118;
		}
	}
yy110:
	++YYCURSOR;
yy111:
#line 263 "scanner.s.re"
	{ goto code; }
#line 723 "scanner.s.c"
yy112:
	++YYCURSOR;
#line 259 "scanner.s.re"
	{ if(cursor == eof) fatal("missing '}'");
				  pos = cursor; cline++;
				  goto code;
				}
#line 731 "scanner.s.c"
yy114:
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '\n') goto yy111;
	goto yy121;
yy115:
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '\n') goto yy111;
	goto yy125;
yy116:
	++YYCURSOR;
#line 257 "scanner.s.re"
	{ ++depth;
				  goto code; }
#line 745 "scanner.s.c"
yy118:
	++YYCURSOR;
#line 251 "scanner.s.re"
	{ if(--depth == 0){
					cur = cursor;
					yylval.token = new Token(token(), tline);
					return CODE;
				  }
				  goto code; }
#line 755 "scanner.s.c"
yy120:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy121:
	if (yych <= '!') {
		if (yych != '\n') goto yy120;
	} else {
		if (yych <= '"') goto yy110;
		if (yych == '\\') goto yy123;
		goto yy120;
	}
yy122:
	YYCURSOR = YYMARKER;
	goto yy111;
yy123:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy122;
	goto yy120;
yy124:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy125:
	if (yych <= '&') {
		if (yych == '\n') goto yy122;
		goto yy124;
	} else {
		if (yych <= '\'') goto yy110;
		if (yych != '\\') goto yy124;
	}
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy122;
	goto yy124;
}
#line 264 "scanner.s.re"


comment:

#line 800 "scanner.s.c"
{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych <= ')') {
		if (yych == '\n') goto yy131;
	} else {
		if (yych <= '*') goto yy133;
		if (yych == '/') goto yy134;
	}
	++YYCURSOR;
yy130:
#line 279 "scanner.s.re"
	{ if(cursor == eof) RETURN(0);
				  goto comment; }
#line 816 "scanner.s.c"
yy131:
	++YYCURSOR;
#line 275 "scanner.s.re"
	{ if(cursor == eof) RETURN(0);
				  tok = pos = cursor; cline++;
				  goto comment;
				}
#line 824 "scanner.s.c"
yy133:
	yych = *++YYCURSOR;
	if (yych == '/') goto yy135;
	goto yy130;
yy134:
	yych = *++YYCURSOR;
	if (yych == '*') goto yy137;
	goto yy130;
yy135:
	++YYCURSOR;
#line 268 "scanner.s.re"
	{ if(--depth == 0)
					goto scan;
				    else
					goto comment; }
#line 840 "scanner.s.c"
yy137:
	++YYCURSOR;
#line 272 "scanner.s.re"
	{ ++depth;
				  fatal("ambiguous /* found");
				  goto comment; }
#line 847 "scanner.s.c"
}
#line 281 "scanner.s.re"


config:

#line 854 "scanner.s.c"
{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 0x1F) {
		if (yych == '\t') goto yy143;
	} else {
		if (yych <= ' ') goto yy143;
		if (yych == '=') goto yy146;
	}
	++YYCURSOR;
#line 290 "scanner.s.re"
	{ fatal("missing '='"); }
#line 868 "scanner.s.c"
yy143:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\t') goto yy143;
	if (yych == ' ') goto yy143;
#line 285 "scanner.s.re"
	{ goto config; }
#line 877 "scanner.s.c"
yy146:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\t') goto yy146;
	if (yych == ' ') goto yy146;
#line 286 "scanner.s.re"
	{ iscfg = 2;
				  cur = cursor;
				  RETURN('='); 
				}
#line 889 "scanner.s.c"
}
#line 291 "scanner.s.re"


value:

#line 896 "scanner.s.c"
{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych <= '&') {
		if (yych <= '\r') {
			if (yych <= 0x08) goto yy152;
			if (yych <= '\n') goto yy151;
			if (yych <= '\f') goto yy152;
		} else {
			if (yych <= ' ') {
				if (yych <= 0x1F) goto yy152;
			} else {
				if (yych == '"') goto yy154;
				goto yy152;
			}
		}
	} else {
		if (yych <= '/') {
			if (yych <= '\'') goto yy156;
			if (yych == '-') goto yy158;
			goto yy152;
		} else {
			if (yych <= '9') {
				if (yych <= '0') goto yy159;
				goto yy161;
			} else {
				if (yych != ';') goto yy152;
			}
		}
	}
yy151:
#line 300 "scanner.s.re"
	{ cur = cursor;
				  yylval.str = new Str(token());
				  iscfg = 0;
				  return VALUE;
				}
#line 935 "scanner.s.c"
yy152:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy153:
	if (yych <= '\r') {
		if (yych <= 0x08) goto yy152;
		if (yych <= '\n') goto yy151;
		if (yych <= '\f') goto yy152;
		goto yy151;
	} else {
		if (yych <= ' ') {
			if (yych <= 0x1F) goto yy152;
			goto yy151;
		} else {
			if (yych == ';') goto yy151;
			goto yy152;
		}
	}
yy154:
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= ' ') {
		if (yych <= '\n') {
			if (yych <= 0x08) goto yy154;
			if (yych <= '\t') goto yy163;
			goto yy151;
		} else {
			if (yych == '\r') goto yy163;
			if (yych <= 0x1F) goto yy154;
			goto yy163;
		}
	} else {
		if (yych <= ':') {
			if (yych == '"') goto yy152;
			goto yy154;
		} else {
			if (yych <= ';') goto yy163;
			if (yych == '\\') goto yy166;
			goto yy154;
		}
	}
yy156:
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= ' ') {
		if (yych <= '\n') {
			if (yych <= 0x08) goto yy156;
			if (yych <= '\t') goto yy167;
			goto yy151;
		} else {
			if (yych == '\r') goto yy167;
			if (yych <= 0x1F) goto yy156;
			goto yy167;
		}
	} else {
		if (yych <= ':') {
			if (yych == '\'') goto yy152;
			goto yy156;
		} else {
			if (yych <= ';') goto yy167;
			if (yych == '\\') goto yy169;
			goto yy156;
		}
	}
yy158:
	yych = *++YYCURSOR;
	if (yych <= '0') goto yy153;
	if (yych <= '9') goto yy161;
	goto yy153;
yy159:
	yych = *++YYCURSOR;
	if (yych <= '\r') {
		if (yych <= 0x08) goto yy152;
		if (yych <= '\n') goto yy160;
		if (yych <= '\f') goto yy152;
	} else {
		if (yych <= ' ') {
			if (yych <= 0x1F) goto yy152;
		} else {
			if (yych != ';') goto yy152;
		}
	}
yy160:
#line 295 "scanner.s.re"
	{ cur = cursor;
				  yylval.number = atoi(token().to_string().c_str());
				  iscfg = 0;
				  return NUMBER;
				}
#line 1028 "scanner.s.c"
yy161:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 0x1F) {
		if (yych <= '\n') {
			if (yych <= 0x08) goto yy152;
			goto yy160;
		} else {
			if (yych == '\r') goto yy160;
			goto yy152;
		}
	} else {
		if (yych <= '9') {
			if (yych <= ' ') goto yy160;
			if (yych <= '/') goto yy152;
			goto yy161;
		} else {
			if (yych == ';') goto yy160;
			goto yy152;
		}
	}
yy163:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '!') {
		if (yych != '\n') goto yy163;
	} else {
		if (yych <= '"') goto yy170;
		if (yych == '\\') goto yy171;
		goto yy163;
	}
yy165:
	YYCURSOR = YYMARKER;
	goto yy151;
yy166:
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '\r') {
		if (yych <= '\t') {
			if (yych <= 0x08) goto yy154;
			goto yy163;
		} else {
			if (yych <= '\n') goto yy151;
			if (yych <= '\f') goto yy154;
			goto yy163;
		}
	} else {
		if (yych <= ' ') {
			if (yych <= 0x1F) goto yy154;
			goto yy163;
		} else {
			if (yych == ';') goto yy163;
			goto yy154;
		}
	}
yy167:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '&') {
		if (yych == '\n') goto yy165;
		goto yy167;
	} else {
		if (yych <= '\'') goto yy170;
		if (yych == '\\') goto yy172;
		goto yy167;
	}
yy169:
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '\r') {
		if (yych <= '\t') {
			if (yych <= 0x08) goto yy156;
			goto yy167;
		} else {
			if (yych <= '\n') goto yy151;
			if (yych <= '\f') goto yy156;
			goto yy167;
		}
	} else {
		if (yych <= ' ') {
			if (yych <= 0x1F) goto yy156;
			goto yy167;
		} else {
			if (yych == ';') goto yy167;
			goto yy156;
		}
	}
yy170:
	++YYCURSOR;
	goto yy151;
yy171:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy165;
	goto yy163;
yy172:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy165;
	goto yy167;
}
#line 305 "scanner.s.re"

}

void Scanner::fatal(uint ofs, const char *msg) const
{
	out.flush();
	std::cerr << "re2c: error: "
		<< "line " << tline << ", column " << (tchar + ofs + 1) << ": "
		<< msg << std::endl;
   	exit(1);
}

} // end namespace re2c

re2c: warning: line 300: rule matches empty string [-Wmatch-empty-string]
