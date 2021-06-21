[[ $- != *i* ]] && return

# Alias
LS="ls --color"
alias diff='diff --color=auto'
alias grep='grep --color=auto'
alias ip='ip -color=auto'

alias ls="$LS -1F"
alias la="$LS -Alh"
alias ll="$LS -alhF"

# Коли українська розкладка
alias ді="ls"
alias дф="la"
alias дд="ll"

alias кь="rm"

alias св="cd"

alias dotfiles='/usr/bin/git --git-dir=$HOME/.dotfiles/ --work-tree=$HOME'

# Prompt
PS1='\[\033[0;31m\][\[\033[0;32m\]\u\[\033[0;33m\]@\[\033[0;35m\]\h \[\033[1;34m\]\W\[\033[0;31m\]]\[\033[00m\]\$ '
