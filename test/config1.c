/* Generated by re2c */
#line 1 "config1.re"
#define	NULL		((char*) 0)
#define	YYCTYPE		char
#define	YYCURSOR	p
#define	YYLIMIT		p
#define	YYMARKER	q
#define	YYFILL(n)

char *scan0(char *p)
{
	char *q;

#line 15 "config1.c"
{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy4;
	default:	goto yy2;
	}
yy2:
	++YYCURSOR;
#line 14 "config1.re"
	{ return NULL; }
#line 37 "config1.c"
yy4:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy4;
	default:	goto yy6;
	}
yy6:
#line 13 "config1.re"
	{ return YYCURSOR; }
#line 58 "config1.c"
}
#line 15 "config1.re"

}

char *scan1(char *p)
{
	char *q;

#line 68 "config1.c"
	{
		YYCTYPE yych;
		if (YYLIMIT <= YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':	goto yy11;
		default:	goto yy9;
		}
yy9:
		++YYCURSOR;
#line 24 "config1.re"
		{ return NULL; }
#line 90 "config1.c"
yy11:
		++YYCURSOR;
		if (YYLIMIT <= YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':	goto yy11;
		default:	goto yy13;
		}
yy13:
#line 23 "config1.re"
		{ return YYCURSOR; }
#line 111 "config1.c"
	}
#line 25 "config1.re"

}

char *scan(char *p)
{
	char *q;

#line 121 "config1.c"
	{
		YYCTYPE yych;
		if (YYLIMIT <= YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':	goto yy18;
		default:	goto yy16;
		}
yy16:
		++YYCURSOR;
#line 33 "config1.re"
		{ return NULL; }
#line 143 "config1.c"
yy18:
		++YYCURSOR;
		if (YYLIMIT <= YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':	goto yy18;
		default:	goto yy20;
		}
yy20:
#line 32 "config1.re"
		{ return YYCURSOR; }
#line 164 "config1.c"
	}
#line 34 "config1.re"

}
