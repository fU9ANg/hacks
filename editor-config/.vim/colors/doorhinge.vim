" Vim color file - doorhinge
" Generated by http://bytefluent.com/vivify 2012-07-20
set background=dark
if version > 580
	hi clear
	if exists("syntax_on")
		syntax reset
	endif
endif

set t_Co=256
let g:colors_name = "doorhinge"

hi IncSearch guifg=#FF9911 guibg=#804000 guisp=#804000 gui=NONE ctermfg=208 ctermbg=3 cterm=NONE
hi WildMenu guifg=#FF9911 guibg=#000000 guisp=#000000 gui=NONE ctermfg=208 ctermbg=NONE cterm=NONE
"hi SignColumn -- no settings --
hi SpecialComment guifg=#FF9911 guibg=#0d0d0d guisp=#0d0d0d gui=NONE ctermfg=208 ctermbg=232 cterm=NONE
hi Typedef guifg=#80C9FF guibg=NONE guisp=NONE gui=NONE ctermfg=117 ctermbg=NONE cterm=NONE
hi Title guifg=#add8e6 guibg=NONE guisp=NONE gui=NONE ctermfg=152 ctermbg=NONE cterm=NONE
hi Folded guifg=#CCCCCC guibg=#25345F guisp=#25345F gui=NONE ctermfg=252 ctermbg=17 cterm=NONE
hi PreCondit guifg=#999999 guibg=NONE guisp=NONE gui=NONE ctermfg=246 ctermbg=NONE cterm=NONE
hi Include guifg=#999999 guibg=NONE guisp=NONE gui=NONE ctermfg=246 ctermbg=NONE cterm=NONE
"hi TabLineSel -- no settings --
hi StatusLineNC guifg=#CCCCCC guibg=#25345F guisp=#25345F gui=NONE ctermfg=252 ctermbg=17 cterm=NONE
"hi CTagsMember -- no settings --
hi NonText guifg=#add8e6 guibg=#4d4d4d guisp=#4d4d4d gui=bold ctermfg=152 ctermbg=239 cterm=bold
"hi CTagsGlobalConstant -- no settings --
hi DiffText guifg=NONE guibg=#ff0000 guisp=#ff0000 gui=bold ctermfg=NONE ctermbg=196 cterm=bold
hi ErrorMsg guifg=#ffffff guibg=#A50000 guisp=#A50000 gui=NONE ctermfg=15 ctermbg=124 cterm=NONE
hi Ignore guifg=#333333 guibg=NONE guisp=NONE gui=NONE ctermfg=236 ctermbg=NONE cterm=NONE
hi Debug guifg=#FF9911 guibg=#0d0d0d guisp=#0d0d0d gui=NONE ctermfg=208 ctermbg=232 cterm=NONE
hi PMenuSbar guifg=NONE guibg=#848688 guisp=#848688 gui=NONE ctermfg=NONE ctermbg=102 cterm=NONE
hi Identifier guifg=#BBBBBB guibg=NONE guisp=NONE gui=NONE ctermfg=250 ctermbg=NONE cterm=NONE
hi SpecialChar guifg=#FF9911 guibg=#0d0d0d guisp=#0d0d0d gui=NONE ctermfg=208 ctermbg=232 cterm=NONE
hi Conditional guifg=#80C9FF guibg=NONE guisp=NONE gui=NONE ctermfg=117 ctermbg=NONE cterm=NONE
hi StorageClass guifg=#80C9FF guibg=NONE guisp=NONE gui=NONE ctermfg=117 ctermbg=NONE cterm=NONE
hi Todo guifg=#ff4500 guibg=#eeee00 guisp=#eeee00 gui=NONE ctermfg=202 ctermbg=11 cterm=NONE
hi Special guifg=#FF9911 guibg=#0d0d0d guisp=#0d0d0d gui=NONE ctermfg=208 ctermbg=232 cterm=NONE
hi LineNr guifg=#25345F guibg=NONE guisp=NONE gui=NONE ctermfg=17 ctermbg=NONE cterm=NONE
hi StatusLine guifg=#FFFFFF guibg=#25345F guisp=#25345F gui=NONE ctermfg=15 ctermbg=17 cterm=NONE
hi Normal guifg=#DDDDDD guibg=#405871 guisp=#405871 gui=NONE ctermfg=253 ctermbg=60 cterm=NONE
hi Label guifg=#80C9FF guibg=NONE guisp=NONE gui=NONE ctermfg=117 ctermbg=NONE cterm=NONE
"hi CTagsImport -- no settings --
hi PMenuSel guifg=#FFFFFF guibg=#25345F guisp=#25345F gui=NONE ctermfg=15 ctermbg=17 cterm=NONE
hi Search guifg=#25345F guibg=#FFFFFF guisp=#FFFFFF gui=NONE ctermfg=17 ctermbg=15 cterm=NONE
"hi CTagsGlobalVariable -- no settings --
hi Delimiter guifg=#FF9911 guibg=#0d0d0d guisp=#0d0d0d gui=NONE ctermfg=208 ctermbg=232 cterm=NONE
hi Statement guifg=#FFFFFF guibg=NONE guisp=NONE gui=bold ctermfg=15 ctermbg=NONE cterm=bold
"hi SpellRare -- no settings --
"hi EnumerationValue -- no settings --
hi Comment guifg=#80C9FF guibg=NONE guisp=NONE gui=NONE ctermfg=117 ctermbg=NONE cterm=NONE
hi Character guifg=#FF9911 guibg=NONE guisp=NONE gui=NONE ctermfg=208 ctermbg=NONE cterm=NONE
"hi Float -- no settings --
hi Number guifg=#FF9911 guibg=NONE guisp=NONE gui=NONE ctermfg=208 ctermbg=NONE cterm=NONE
hi Boolean guifg=#FFFFFF guibg=NONE guisp=NONE gui=bold ctermfg=15 ctermbg=NONE cterm=bold
hi Operator guifg=#80C9FF guibg=NONE guisp=NONE gui=NONE ctermfg=117 ctermbg=NONE cterm=NONE
"hi CursorLine -- no settings --
"hi Union -- no settings --
"hi TabLineFill -- no settings --
hi Question guifg=#FF9911 guibg=NONE guisp=NONE gui=bold ctermfg=208 ctermbg=NONE cterm=bold
hi WarningMsg guifg=#ffffff guibg=#A50000 guisp=#A50000 gui=NONE ctermfg=15 ctermbg=124 cterm=NONE
hi VisualNOS guifg=NONE guibg=NONE guisp=NONE gui=bold,underline ctermfg=NONE ctermbg=NONE cterm=bold,underline
hi DiffDelete guifg=#0000ff guibg=#008b8b guisp=#008b8b gui=bold ctermfg=21 ctermbg=30 cterm=bold
hi ModeMsg guifg=NONE guibg=NONE guisp=NONE gui=bold ctermfg=NONE ctermbg=NONE cterm=bold
"hi CursorColumn -- no settings --
hi Define guifg=#999999 guibg=NONE guisp=NONE gui=NONE ctermfg=246 ctermbg=NONE cterm=NONE
hi Function guifg=#BBBBBB guibg=NONE guisp=NONE gui=NONE ctermfg=250 ctermbg=NONE cterm=NONE
hi FoldColumn guifg=#FFFFFF guibg=#25345F guisp=#25345F gui=NONE ctermfg=15 ctermbg=17 cterm=NONE
hi PreProc guifg=#999999 guibg=NONE guisp=NONE gui=NONE ctermfg=246 ctermbg=NONE cterm=NONE
"hi EnumerationName -- no settings --
hi Visual guifg=#E5ECFF guibg=#25345F guisp=#25345F gui=NONE ctermfg=189 ctermbg=17 cterm=NONE
hi MoreMsg guifg=#FF9911 guibg=NONE guisp=NONE gui=bold ctermfg=208 ctermbg=NONE cterm=bold
"hi SpellCap -- no settings --
hi VertSplit guifg=#CCCCCC guibg=#25345F guisp=#25345F gui=NONE ctermfg=252 ctermbg=17 cterm=NONE
hi Exception guifg=#80C9FF guibg=NONE guisp=NONE gui=NONE ctermfg=117 ctermbg=NONE cterm=NONE
hi Keyword guifg=#80C9FF guibg=NONE guisp=NONE gui=NONE ctermfg=117 ctermbg=NONE cterm=NONE
hi Type guifg=#80C9FF guibg=NONE guisp=NONE gui=NONE ctermfg=117 ctermbg=NONE cterm=NONE
hi DiffChange guifg=NONE guibg=#8b008b guisp=#8b008b gui=NONE ctermfg=NONE ctermbg=90 cterm=NONE
hi Cursor guifg=#000000 guibg=#BFE4FF guisp=#BFE4FF gui=NONE ctermfg=NONE ctermbg=153 cterm=NONE
"hi SpellLocal -- no settings --
"hi Error -- no settings --
hi PMenu guifg=#CCCCCC guibg=#25345F guisp=#25345F gui=NONE ctermfg=252 ctermbg=17 cterm=NONE
hi SpecialKey guifg=#00ffff guibg=NONE guisp=NONE gui=NONE ctermfg=14 ctermbg=NONE cterm=NONE
hi Constant guifg=#FF9911 guibg=NONE guisp=NONE gui=NONE ctermfg=208 ctermbg=NONE cterm=NONE
"hi DefinedName -- no settings --
hi Tag guifg=#006400 guibg=NONE guisp=NONE gui=NONE ctermfg=22 ctermbg=NONE cterm=NONE
hi String guifg=#FF9911 guibg=NONE guisp=NONE gui=NONE ctermfg=208 ctermbg=NONE cterm=NONE
hi PMenuThumb guifg=NONE guibg=#25345F guisp=#25345F gui=NONE ctermfg=NONE ctermbg=17 cterm=NONE
"hi MatchParen -- no settings --
"hi LocalVariable -- no settings --
hi Repeat guifg=#80C9FF guibg=NONE guisp=NONE gui=NONE ctermfg=117 ctermbg=NONE cterm=NONE
"hi SpellBad -- no settings --
"hi CTagsClass -- no settings --
hi Directory guifg=#CCCCFF guibg=NONE guisp=NONE gui=NONE ctermfg=189 ctermbg=NONE cterm=NONE
hi Structure guifg=#80C9FF guibg=NONE guisp=NONE gui=NONE ctermfg=117 ctermbg=NONE cterm=NONE
hi Macro guifg=#999999 guibg=NONE guisp=NONE gui=NONE ctermfg=246 ctermbg=NONE cterm=NONE
"hi Underlined -- no settings --
hi DiffAdd guifg=NONE guibg=#00008b guisp=#00008b gui=NONE ctermfg=NONE ctermbg=18 cterm=NONE
"hi TabLine -- no settings --
hi mbenormal guifg=#cfbfad guibg=#2e2e3f guisp=#2e2e3f gui=NONE ctermfg=187 ctermbg=237 cterm=NONE
hi perlspecialstring guifg=#c080d0 guibg=#404040 guisp=#404040 gui=NONE ctermfg=176 ctermbg=238 cterm=NONE
hi doxygenspecial guifg=#fdd090 guibg=NONE guisp=NONE gui=NONE ctermfg=222 ctermbg=NONE cterm=NONE
hi mbechanged guifg=#eeeeee guibg=#2e2e3f guisp=#2e2e3f gui=NONE ctermfg=255 ctermbg=237 cterm=NONE
hi mbevisiblechanged guifg=#eeeeee guibg=#4e4e8f guisp=#4e4e8f gui=NONE ctermfg=255 ctermbg=60 cterm=NONE
hi doxygenparam guifg=#fdd090 guibg=NONE guisp=NONE gui=NONE ctermfg=222 ctermbg=NONE cterm=NONE
hi doxygensmallspecial guifg=#fdd090 guibg=NONE guisp=NONE gui=NONE ctermfg=222 ctermbg=NONE cterm=NONE
hi doxygenprev guifg=#fdd090 guibg=NONE guisp=NONE gui=NONE ctermfg=222 ctermbg=NONE cterm=NONE
hi perlspecialmatch guifg=#c080d0 guibg=#404040 guisp=#404040 gui=NONE ctermfg=176 ctermbg=238 cterm=NONE
hi cformat guifg=#c080d0 guibg=#404040 guisp=#404040 gui=NONE ctermfg=176 ctermbg=238 cterm=NONE
hi lcursor guifg=#000000 guibg=#255A70 guisp=#255A70 gui=NONE ctermfg=NONE ctermbg=6 cterm=NONE
hi cursorim guifg=NONE guibg=#660066 guisp=#660066 gui=NONE ctermfg=NONE ctermbg=53 cterm=NONE
hi doxygenspecialmultilinedesc guifg=#ad600b guibg=NONE guisp=NONE gui=NONE ctermfg=130 ctermbg=NONE cterm=NONE
hi taglisttagname guifg=#808bed guibg=NONE guisp=NONE gui=NONE ctermfg=105 ctermbg=NONE cterm=NONE
hi doxygenbrief guifg=#fdab60 guibg=NONE guisp=NONE gui=NONE ctermfg=215 ctermbg=NONE cterm=NONE
hi mbevisiblenormal guifg=#cfcfcd guibg=#4e4e8f guisp=#4e4e8f gui=NONE ctermfg=252 ctermbg=60 cterm=NONE
hi user2 guifg=#87cefa guibg=#021a39 guisp=#021a39 gui=bold ctermfg=117 ctermbg=17 cterm=bold
hi user1 guifg=#00ff8b guibg=#3e3e5e guisp=#3e3e5e gui=NONE ctermfg=48 ctermbg=60 cterm=NONE
hi doxygenspecialonelinedesc guifg=#ad600b guibg=NONE guisp=NONE gui=NONE ctermfg=130 ctermbg=NONE cterm=NONE
hi doxygencomment guifg=#ad7b20 guibg=NONE guisp=NONE gui=NONE ctermfg=130 ctermbg=NONE cterm=NONE
hi cspecialcharacter guifg=#c080d0 guibg=#404040 guisp=#404040 gui=NONE ctermfg=176 ctermbg=238 cterm=NONE
"hi clear -- no settings --
hi menu guifg=#fff8dc guibg=#233b5a guisp=#233b5a gui=NONE ctermfg=230 ctermbg=17 cterm=NONE
hi scrollbar guifg=NONE guibg=#233b5a guisp=#233b5a gui=NONE ctermfg=NONE ctermbg=17 cterm=NONE
hi pmenum guifg=#585858 guibg=#1c1c1c guisp=#1c1c1c gui=NONE ctermfg=240 ctermbg=234 cterm=NONE
hi normal guifg=#4d4d4d guibg=#d8d4d4 guisp=#d8d4d4 gui=NONE ctermfg=239 ctermbg=188 cterm=NONE
hi sql_statement guifg=#9400d3 guibg=NONE guisp=NONE gui=NONE ctermfg=92 ctermbg=NONE cterm=NONE
hi cics_statement guifg=#4e9a06 guibg=NONE guisp=NONE gui=NONE ctermfg=64 ctermbg=NONE cterm=NONE
hi namespace guifg=#006400 guibg=NONE guisp=NONE gui=NONE ctermfg=22 ctermbg=NONE cterm=NONE
hi builtin guifg=#1e90ff guibg=NONE guisp=NONE gui=NONE ctermfg=33 ctermbg=NONE cterm=NONE
hi tablinefillsel guifg=#0000ff guibg=NONE guisp=NONE gui=NONE ctermfg=21 ctermbg=NONE cterm=NONE
hi foldecolumn guifg=#535353 guibg=#202020 guisp=#202020 gui=bold ctermfg=239 ctermbg=234 cterm=bold
hi special guifg=#e9b96e guibg=NONE guisp=NONE gui=NONE ctermfg=179 ctermbg=NONE cterm=NONE
hi statement guifg=#ffffff guibg=NONE guisp=NONE gui=bold ctermfg=15 ctermbg=NONE cterm=bold
hi cppstltype guifg=#729fcf guibg=NONE guisp=NONE gui=bold ctermfg=110 ctermbg=NONE cterm=bold
hi identifier guifg=#729fcf guibg=NONE guisp=NONE gui=NONE ctermfg=110 ctermbg=NONE cterm=NONE
hi function guifg=#ad7fa8 guibg=NONE guisp=NONE gui=NONE ctermfg=139 ctermbg=NONE cterm=NONE
hi cursor guifg=#000000 guibg=#ffffff guisp=#ffffff gui=NONE ctermfg=NONE ctermbg=15 cterm=NONE
hi vimfold guifg=#FFFFFF guibg=#000000 guisp=#000000 gui=bold ctermfg=15 ctermbg=NONE cterm=bold
hi htmltag guifg=#755C3B guibg=NONE guisp=NONE gui=NONE ctermfg=101 ctermbg=NONE cterm=NONE
hi underlined guifg=#ad7fa8 guibg=NONE guisp=NONE gui=underline ctermfg=139 ctermbg=NONE cterm=underline
hi number guifg=#fce94f guibg=NONE guisp=NONE gui=NONE ctermfg=227 ctermbg=NONE cterm=NONE
hi cdefine guifg=#0000ff guibg=NONE guisp=NONE gui=NONE ctermfg=21 ctermbg=NONE cterm=NONE
hi cinclude guifg=#ffffff guibg=NONE guisp=NONE gui=NONE ctermfg=15 ctermbg=NONE cterm=NONE
hi htmlitalic guifg=#000000 guibg=#ffffff guisp=#ffffff gui=italic ctermfg=NONE ctermbg=15 cterm=NONE
hi htmlboldunderlineitalic guifg=#000000 guibg=#ffffff guisp=#ffffff gui=bold,italic,underline ctermfg=NONE ctermbg=15 cterm=bold,underline
hi htmlbolditalic guifg=#000000 guibg=#ffffff guisp=#ffffff gui=bold,italic ctermfg=NONE ctermbg=15 cterm=bold
hi htmlunderlineitalic guifg=#000000 guibg=#ffffff guisp=#ffffff gui=italic,underline ctermfg=NONE ctermbg=15 cterm=underline
hi htmlbold guifg=#000000 guibg=#ffffff guisp=#ffffff gui=bold ctermfg=NONE ctermbg=15 cterm=bold
hi htmlboldunderline guifg=#000000 guibg=#ffffff guisp=#ffffff gui=bold,underline ctermfg=NONE ctermbg=15 cterm=bold,underline
hi htmlunderline guifg=#000000 guibg=#ffffff guisp=#ffffff gui=underline ctermfg=NONE ctermbg=15 cterm=underline
"hi default -- no settings --
hi comment guifg=#8A9184 guibg=NONE guisp=NONE gui=italic ctermfg=65 ctermbg=NONE cterm=NONE
hi rubypredefinedvariable guifg=#666666 guibg=NONE guisp=NONE gui=NONE ctermfg=241 ctermbg=NONE cterm=NONE
hi string guifg=#8D9902 guibg=NONE guisp=NONE gui=NONE ctermfg=100 ctermbg=NONE cterm=NONE
hi rubyexception guifg=#8C4D38 guibg=NONE guisp=NONE gui=NONE ctermfg=95 ctermbg=NONE cterm=NONE
hi repeat guifg=#480000 guibg=NONE guisp=NONE gui=NONE ctermfg=52 ctermbg=NONE cterm=NONE
hi type guifg=#907800 guibg=NONE guisp=NONE gui=NONE ctermfg=94 ctermbg=NONE cterm=NONE
hi rubypredefinedidentifier guifg=#666666 guibg=NONE guisp=NONE gui=NONE ctermfg=241 ctermbg=NONE cterm=NONE
hi rubyaccess guifg=#939264 guibg=NONE guisp=NONE gui=NONE ctermfg=101 ctermbg=NONE cterm=NONE
hi rubypredefinedconstant guifg=#666666 guibg=NONE guisp=NONE gui=NONE ctermfg=241 ctermbg=NONE cterm=NONE
