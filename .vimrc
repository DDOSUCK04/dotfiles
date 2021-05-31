" color
syntax on
colorscheme peachpuff


" other
set mouse=a
set clipboard=unnamedplus
set nofoldenable
set exrc
set secure
set nocompatible
set lazyredraw
set ttyfast


" move
let mapleader   = ","
let g:mapleader = ","
set backspace=indent,eol,start
set langmap=ФИСВУАПРШОЛДЬТЩЗЙКІЕГМЦЧНЯ;ABCDEFGHIJKLMNOPQRSTUVWXYZ,фисвуапршолдьтщзйкіегмцчня;abcdefghijklmnopqrstuvwxyz
set noesckeys

"" delete and cut
nnoremap d "_d
nnoremap c "_c
nnoremap x "_x

nnoremap D "_D
nnoremap C "_C
nnoremap X "_X

vnoremap d "_d
vnoremap c "_c

vnoremap D "_D
vnoremap C "_C

nnoremap <leader>d d
nnoremap <leader>c c
nnoremap <leader>x x

nnoremap <leader>D D
nnoremap <leader>C C
nnoremap <leader>X X

vnoremap <leader>d d
vnoremap <leader>c c

vnoremap <leader>D D
vnoremap <leader>C C

"" buffer
map <silent> <C-j> :bn<CR>
map <silent> <C-k> :bp<CR>

"" new lines
map <silent> <leader>o :call append(line("."), repeat([""], v:count1))<CR>
map <silent> <leader>O :call append(line(".") - 1, repeat([""], v:count1))<CR>

"" other
map <silent> <CR> :noh<CR>
map Y y$


" look
set number relativenumber
set nowrap
set ruler
set showcmd
set showmatch
set noeb vb t_vb=

" search
set hlsearch
set incsearch


" complete
set completeopt=menuone,noselect
set wildmenu


" scroll
set sidescroll=1
set sidescrolloff=3
set scrolloff=3


" files
set writebackup
set nobackup
set undofile


" buffer
set hidden


" indent
set cindent
set autoindent
