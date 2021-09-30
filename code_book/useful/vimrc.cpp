set nu
set relativenumber
set autoindent
set smartindent
set cindent
set backspace=2
set confirm
set mouse=a
set tabstop=4
set softtabstop=4
set smarttab
set shiftwidth=4
set hlsearch
set cursorline
set cursorcolumn
set showmatch
set ruler
syntax on
set expandtab " for python code "
inoremap ( ()<Esc>i
inoremap () ()<Esc>i
inoremap [ []<Esc>i
inoremap {<CR> {<CR>}<Esc>O
inoremap " ""<Esc>i
colorscheme ron

" if accidentlt Ctrl + s, then use Ctrl + q to solve
