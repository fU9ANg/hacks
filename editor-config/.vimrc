set nu
set ts=4
set sw=4
set expandtab
set cursorline
set hlsearch
set expandtab

"设置颜色
colorscheme inkpot

"let &termencoding=&encoding
set fileencodings=utf-8,gbk,ucs-bom,cp936
set statusline=%{&fileformat}\ \ \ ASCII=\%03b,HEX=\%03B\ \ \ Row=%04l,Column=%03c%V\ %p%%\ \ \ [\ %L\ lines\ in\ all\ ]
set cmdheight=1
set laststatus=2
"" allow to using backspace
set backspace=indent,eol,start

syntax enable
set  cindent
set  autoindent
set  tabstop=4 
set  shiftwidth=4
set  syntax=on
filetype plugin on

"map  <F10>   :  !ctags  -R  --c++-kinds=+p   --fields=+iaS  --extra=+q   .<CR>
"补全
let OmniCpp_SelectFirstItem=2
let OmniCpp_MayCompleteScpe=1
let OmniCpp_NamespaceSearch=1
let OmniCpp_ShowPrototypeInAbbr=1
let OmniCpp_ShowScopeInAbbr=1
set completeopt=menu

"set tags +=$HOME/.vim/tags_usr_include_c++

"Tag List
map <F12> : Tlist <CR>
map <F3> :bp <CR>
map <F2> :bn <CR>
let Tlist_Show_One_File = 1
let Tlist_Exit_OnlyWindow = 1
"设置标签子窗口的宽度
let Tlist_WinWidth=30
""标签列表窗口显示或隐藏不影响整个gvim窗口大小
let Tlist_Inc_Winwidth=0

let g:miniBufExplMapWindowNavVim = 1 
let g:miniBufExplMapWindowNavArrows = 1 
let g:miniBufExplMapCTabSwitchBufs = 1 
let g:miniBufExplModSelTarget = 1

colorscheme default
