#!/bin/sh

wallpaper=$HOME/Pictures/Wallpapers/1610796062978.jpg

userresources=$HOME/.Xresources
usermodmap=$HOME/.Xmodmap
sysresources=/etc/X11/xinit/.Xresources
sysmodmap=/etc/X11/xinit/.Xmodmap

# merge in defaults and keymaps

if [ -f $sysresources ]; then







    xrdb -merge $sysresources

fi

if [ -f $sysmodmap ]; then
    xmodmap $sysmodmap
fi

if [ -f "$userresources" ]; then







    xrdb -merge "$userresources"

fi

if [ -f "$usermodmap" ]; then
    xmodmap "$usermodmap"
fi

# start some nice programs

if [ -d /etc/X11/xinit/xinitrc.d ] ; then
 for f in /etc/X11/xinit/xinitrc.d/?*.sh ; do
  [ -x "$f" ] && . "$f"
 done
 unset f
fi


xset s off
xset dpms 600 600 600

setxkbmap -layout us,ua -option grp:caps_toggle
xset r rate 450 30

sleep 2

# xrandr
~/scripts/xrandrrc
dunst&
~/scripts/dwmstatus&
xcompmgr&
xwallpaper --stretch $wallpaper
wal -i $wallpaper -a 92

exec dwm
