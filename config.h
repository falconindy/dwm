/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-*-nu-*-*-*-*-11-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#333333";
static const char normbgcolor[]     = "#262729"; 
static const char normfgcolor[]     = "#ffffff"; 
static const char selbordercolor[]  = "#f6ee09";
static const char selbgcolor[]      = "#262729"; 
static const char selfgcolor[]      = "#659fdb"; 
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "web", "term", "foo", "vbox", "misc", "s" };

static const Rule rules[] = {
    /* class                 instance       title           tags mask     isfloating   monitor */
    { "Chromium",            NULL,          NULL,           1 << 0,        False,       -1 },
    { "URxvt",               "werk",        NULL,           1 << 1,        False,       -1 },
    { "URxvt",               "tmux",        NULL,           1 << 1,        False,       -1 },
    { "URxvt",               "htop",        NULL,           1 << 2,        False,       -1 },
    { "URxvt",               "ncmpcpp",     NULL,           1 << 2,        False,       -1 },
    { "VirtualBox",          NULL,          NULL,           1 << 3,        True,        -1 },
    { "qemu",                NULL,          NULL,           1 << 3,        True,        -1 },
    { "OpenOffice.org 3.2",  NULL,          NULL,           1 << 4,        False,       -1 },
    { "URxvt",               "Scratchpad",  "Scratchpad",   1 << 5,        True,        -1 },
    { "Zenity",              NULL,          NULL,           0,             True,        -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
    { "TTT",      bstack },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[]      = { "dmenu_launch.sh", NULL };
static const char *termcmd[]       = { "urxvtc", NULL };
static const char *scratchpadcmd[] = { "urxvt", "-name", "Scratchpad", "-geometry", "273x15", NULL };
static const char *printscrncmd[]  = { "printscreen.sh", NULL };

/* audio */
static const char *volup[]         = { "volOSD", "alsa", "PCM", "+5", NULL };
static const char *voldown[]       = { "volOSD", "alsa", "PCM", "-5", NULL };
static const char *voltoggle[]     = { "volOSD", "alsa", "PCM", "toggle", NULL };
static const char *mpcnext[]       = { "mpc", "next", NULL };
static const char *mpcprev[]       = { "mpc", "prev", NULL };
static const char *mpctoggle[]     = { "mpc", "toggle", NULL };

/* screen lock */
static const char *xscreenlock[]   = { "xscreensaver-command", "-lock", NULL };

static Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY|ControlMask,           XK_s,      spawn,          {.v = scratchpadcmd } },
    { MODKEY,                       XK_grave,  toggleview,     {.ui = 1 << 5} },
    { MODKEY,                       XK_Print,  spawn,          {.v = printscrncmd } },
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,                       XK_x,      spawn,          {.v = volup } },
    { MODKEY,                       XK_z,      spawn,          {.v = voldown } },
    { MODKEY,                       XK_c,      spawn,          {.v = voltoggle } },
    { MODKEY,                       XK_q,      spawn,          {.v = mpcprev } },
    { MODKEY,                       XK_w,      spawn,          {.v = mpctoggle } },
    { MODKEY,                       XK_e,      spawn,          {.v = mpcnext } },
    { MODKEY|ControlMask,           XK_l,      spawn,          {.v = xscreenlock } },
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
    { MODKEY,                       XK_y,      setlayout,      {.v = &layouts[3]} },
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

