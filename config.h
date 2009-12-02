/* See LICENSE file for copyright and license details. */

/* Addons */
#include "push.c"

/* appearance */
//static const char font[]            = "-*-terminus-medium-r-normal-*-14-*-*-*-*-*-*-*";
static const char font[]            = "-*-bitstream vera sans mono-medium-r-normal-*-10-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#333333";
static const char normbgcolor[]     = "#051121"; 
static const char normfgcolor[]     = "#FFFFFF"; 
static const char selbordercolor[]  = "#F6EE09"; /* "#3465A4"; */
static const char selbgcolor[]      = "#3465A4"; 
static const char selfgcolor[]      = "#FFFFFF"; 
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "web", "term", "pidgin", "vbox", "misc" };

static const Rule rules[] = {
	/* class                 instance    title       tags mask     isfloating   monitor */
	{ "Firefox",             NULL,       NULL,       1 << 0,            True,        -1 },
	{ "Chrome",              NULL,       NULL,       1 << 0,            True,        -1 },
	{ "URxvt",               NULL,       NULL,       1 << 1,            False,       -1 },
	{ "Pidgin",              NULL,       NULL,       1 << 2,            True,        -1 },
	{ "Hamster-applet",      NULL,       NULL,       1 << 2,            True,        -1 },
	{ "VirtualBox",          NULL,       NULL,       1 << 3,            True,        -1 },
	{ "OpenOffice.org 3.1",  NULL,       NULL,       1 << 4,            False,       -1 },
	{ "Gimp",                NULL,       NULL,       1 << 4,            True,        -1 },
	{ "MPlayer",             NULL,       NULL,       1 << 4,            True,        -1 },
	{ "Pymp.pyc",            NULL,       NULL,       1 << 3,            True,        -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-b", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "urxvtc", NULL };

/* General Sound */
static const char *volup[] = { "amixer", "-q", "set", "PCM", "5+" };
static const char *voldown[] = { "amixer", "-q", "set", "PCM", "5-" };

/* ncmpcpp specific */
static const char *mpcnext[] = { "ncmpcpp", "next" };
static const char *mpcprev[] = { "ncmpcpp", "prev" };
static const char *mpctoggle[] = { "ncmpcpp", "toggle" };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_x,      spawn,          {.v = volup } },
	{ MODKEY,                       XK_z,      spawn,          {.v = voldown } },
	{ MODKEY,                       XK_q,      spawn,          {.v = mpcprev } },
	{ MODKEY,                       XK_w,      spawn,          {.v = mpctoggle } },
	{ MODKEY,                       XK_e,      spawn,          {.v = mpcnext } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_k,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask,           XK_k,      pushdown,       {0} },
	{ MODKEY|ControlMask,           XK_j,      pushup,         {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

