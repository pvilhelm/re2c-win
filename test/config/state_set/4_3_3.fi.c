/* Generated by re2c */
/* autogen */
// re2c:define:YYSETSTATE = "setstate_ÿ;";
// re2c:define:YYSETSTATE@state = "ÿ";
// re2c:define:YYSETSTATE:naked = 1;



	switch (YYGETSTATE()) {
	default: goto yy0;
	case 0: goto yyFillLabel0;
	}
yy0:
	setstate_0;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
yyFillLabel0:
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy4;
	default:	goto yy2;
	}
yy2:
	++YYCURSOR;
	{ def }
yy4:
	++YYCURSOR;
	{ code }

