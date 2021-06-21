/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "UW ttyp0:pixelsize=11" };
static const char dmenufont[]       = "UW ttyp0:pixelsize=11";
static const char colorname[16][8]     = {
	/* solarized dark */
	"#073642",  /*  0: black    */
	"#dc322f",  /*  1: red      */
	"#859900",  /*  2: green    */
	"#b58900",  /*  3: yellow   */
	"#268bd2",  /*  4: blue     */
	"#d33682",  /*  5: magenta  */
	"#2aa198",  /*  6: cyan     */
	"#eee8d5",  /*  7: white    */
	"#002b36",  /*  8: brblack  */
	"#cb4b16",  /*  9: brred    */
	"#586e75",  /* 10: brgreen  */
	"#657b83",  /* 11: bryellow */
	"#839496",  /* 12: brblue   */
	"#6c71c4",  /* 13: brmagenta*/
	"#93a1a1",  /* 14: brcyan   */
	"#fdf6e3",  /* 15: brwhite  */
};
static const char *colors[][3]      = {
	/*               fg             bg             border   */
	[SchemeNorm] = { colorname[12], colorname[8],  colorname[0] },
	[SchemeSel]  = { colorname[8],  colorname[12], colorname[3]  },
	[SchemeUrg]  = { colorname[8],  colorname[1],  colorname[5]  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5;  /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
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
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", colorname[8], "-nf", colorname[12], "-sb", colorname[12], "-sf", colorname[8], NULL };
static const char *termcmd[]  = { "st", NULL };
/* volume control */
static const char *upvol[]   = { "amixer", "-q", "set", "Master", "1%+", "unmute", NULL };
static const char *downvol[] = { "amixer", "-q", "set", "Master", "1%-", "unmute", NULL };
static const char *mutevol[] = { "amixer", "-q", "set", "Master", "toggle", NULL };
/* music control */
static const char *prevmus[] = { "mpc", "prev", NULL };
static const char *nextmus[] = { "mpc", "next", NULL };
static const char *playmus[] = { "mpc", "toggle", NULL };
/* brightness control */
static const char *upbrigh[]   = { "xbacklight", "-inc", "5", NULL };
static const char *downbrigh[] = { "xbacklight", "-dec", "5", NULL };
/* power */
static const char *shutdown[] = { "shutdown", "-h", "now", NULL };
static const char *reboot[]   = { "reboot", NULL };

#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
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
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ 0,                            XF86XK_AudioRaiseVolume,   spawn, {.v = upvol} },
	{ 0,                            XF86XK_AudioLowerVolume,   spawn, {.v = downvol} },
	{ 0,                            XF86XK_AudioMute,          spawn, {.v = mutevol} },
	{ 0,                            XF86XK_MonBrightnessUp,    spawn, {.v = upbrigh} },
	{ 0,                            XF86XK_MonBrightnessDown,  spawn, {.v = downbrigh} },
	{ 0,                            XF86XK_AudioPrev,          spawn, {.v = prevmus} },
	{ 0,                            XF86XK_AudioNext,          spawn, {.v = nextmus} },
	{ 0,                            XF86XK_AudioPlay,          spawn, {.v = playmus} },
	{ 0,                            XK_Print,                  spawn, SHCMD("~/scripts/screenshot") },
	{ ShiftMask,                    XK_Print,                  spawn, SHCMD("~/scripts/screenshot full") },
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
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = shutdown} },
	{ MODKEY|ShiftMask,             XK_r,      spawn,          {.v = reboot} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
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

