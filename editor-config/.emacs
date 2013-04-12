;;;
;;;  This code is GPL.
;;; .emacs file(configure for the plugin of emacs)
;;;
;;;  Uncomment this line to disable loading 
;;;  of "default.el" at startup.
;;;
;;;  Written 2007-2010 by <H. F. G. fU9ANg>
;;;  E-Mail: bb.newlife@gmail.com
;;;  Hacker Fellowship Group
;;;

;; (setq inhibit-default-init t)

;; enable visual feedback on selections
;(setq transient-mark-mode t)

;; default to better frame titles
(setq frame-title-format
      (concat  "%b - emacs@" (system-name)))

;; default to unified diffs
(setq diff-switches "-u")



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;         common configure for Emacs        ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;(cua-mode '(t nil (cua-base)))            ; 启动cua复制粘贴模式
;;(tool-bar-mode nil)                       ; 去丢工具栏
;;(column-number-mode t)                    ; 显示列号
;;(global-font-lock-mode t)                 ; 语法高亮
;;(show-paren-mode t)                       ; 显示括号匹配
;;(transient-mark-mode t)                   ; 高亮被选择的区域
;;(mouse-avoidance-mode 'animate)           ; 鼠标指针自动避开光标
;;
;;(setq inhibit-splash-screen t)            ; 禁止开机画面
;;(setq make-backup-files nil)              ; 不产生备份文件
;;(setq visible-bell t)                     ; 关闭喇叭
;;(setq kill-whole-line t)                  ; 在行首C-k时，同时删除该行
;;(setq x-select-enable-clipboard t)        ; 支持emacs和外部程序的复制粘贴
;;(setq default-major-mode 'text-mode)      ; 一打开就启用text模式
;;(setq default-tab-width 8)                ; 设置tab长度
;;(setq default-fill-column 80)             ; 设置默认列数
;;(setq-default indent-tabs-mode nil)       ; 用空格代替tab
;;(setq kill-ring-max 200)                  ; 设置删除纪录
;;(setq require-final-newline t)            ; 文件必须以空行结束
;;(setq show-paren-style 'parentheses)      ; 设置括号匹配的方式
;;(setq dired-recursive-deletes t)          ; 可以递归地删除目录
;;(setq dired-recursive-copies t)           ; 可以递归地进行目录拷贝
;;(setq bookmark-save-flag t)               ; 自动保存/读取书签 


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;        configure Emacs Environment        ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; load the path what i wanted
(add-to-list 'load-path "~/.emacs-site-lisp")
(load-library "multi-gud.el")
(load-library "multi-gdb-ui.el")

;; display emacs line number
(require 'linum)
(global-linum-mode t)

;; load my scheme interpreter
(setq scheme-program-name "mzscheme")

;;turn on text mode and auto fill mode
(setq default-major-mode 'text-mode)
(add-hook 'text-mode-hook 'turn-on-auto-fill)

;;prohibition was laid on the key of "ESC ESC" and "C-x C-u"
(global-unset-key "\C-x\C-u")

;;set the "C-x ?" is online help
(define-key global-map "\C-x?" 'help-command)

;;always do syntax highlighting
;;(global-font-lock-mode 1)

;;also highlight parens
(setq show-paren-delay 0
      show-paren-style 'parenthesis)
(show-paren-mode 1)

;(require 'quack)

;; color of Environment
;(require 'color-theme)
;(color-theme-hober)
;(setq color-theme-is-cumulative t)
;(require 'color-theme-maker)

;; language of Environment
(setq locale-coding-system 'utf-8)
(set-terminal-coding-system 'utf-8)
(set-keyboard-coding-system 'utf-8)
(set-selection-coding-system 'utf-8)
(prefer-coding-system 'utf-8)

;; customize Keybind on Key-borad for Environment
(global-set-key [(f3)] 'ansi-term)
(global-set-key [(f5)] 'compile)
(setq-default compile-command "make")
(global-set-key [(f6)] 'gdb)
(global-set-key [C-f7] 'previous-error)
(global-set-key [f7] 'next-error)

;; set Environment font
;(set-default-font "15x15")  ;; Then run Emacs, a error: Font '15x15' is not defined

;; set gdb many winow
(setq gdb-many-windows t)

;; uncomment for CJK utf-8 support for non-Asian users
;(require 'un-define)

;; always end a file with a newline
;(setq require-final-newline 'query)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;         configure Cedet in Emacs          ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; load cedet
(setq load-path (append load-path '("~/.emacs-site-lisp/cedet")))
(load-file "~/.emacs-site-lisp/cedet/common/cedet.el")

;; set indexing arrange
(setq semanticdb-project-roots
(list (expand-file-name "/")))
(global-set-key [(control tab)] 'semantic-ia-complete-symbol-menu)

;; Enabling various SEMANTIC minor modes.  See semantic/INSTALL for more ideas.
;; Select one of the following:

;; * This enables the database and idle reparse engines
;(semantic-load-enable-minimum-features)

;; * This enables some tools useful for coding, such as summary mode
;;   imenu support, and the semantic navigator
;(semantic-load-enable-code-helpers)

;; * This enables even more coding tools such as the nascent intellisense mode
;;   decoration mode, and stickyfunc mode (plus regular code helpers)
;(semantic-load-enable-guady-code-helpers)

;; * This turns on which-func support (Plus all other code helpers)
(semantic-load-enable-excessive-code-helpers)

;; This turns on modes that aid in grammar writing and semantic tool
;; development.  It does not enable any other features such as code
;; helpers above.
(semantic-load-enable-semantic-debugging-helpers)

;; hotkey for speedbar
(global-set-key [(f4)] 'speedbar-get-focus)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;         configure Ecb in Emacs            ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; load ecb
(add-to-list 'load-path
                     "~/.emacs-site-lisp/ecb")
(load-file "~/.emacs-site-lisp/ecb/ecb.el")
(require 'ecb-autoloads)

;; hotkey for ecb
;  move focus from one to other (change windows)
(global-set-key [M-left] 'windmove-left)
(global-set-key [M-right] 'windmove-right)
(global-set-key [M-up] 'windmove-up)
(global-set-key [M-down] 'windmove-down)

; hide and show windows of ecb
(define-key global-map [(control f1)] 'ecb-hide-ecb-windows)
(define-key global-map [(control f2)] 'ecb-show-ecb-windows)

; maxmize window (directories, sources, methods and history window)
(define-key global-map "\C-c1" 'ecb-maximize-window-directories)
(define-key global-map "\C-c2" 'ecb-maximize-window-sources)
(define-key global-map "\C-c3" 'ecb-maximize-window-methods)
(define-key global-map "\C-c4" 'ecb-maximize-window-history)

; restore defualt window size
(define-key global-map "\C-c`" 'ecb-restore-default-window-sizes)

; emacs Environment auto create
(custom-set-variables
  ;; custom-set-variables was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 '(ecb-layout-window-sizes nil)
 '(ecb-options-version "2.40")
 '(show-paren-mode t))
(custom-set-faces
  ;; custom-set-faces was added by Custom.
  ;; If you edit it by hand, you could mess it up, so be careful.
  ;; Your init file should contain only one such instance.
  ;; If there is more than one, they won't work right.
 '(default ((t (:inherit nil :stipple nil :background "#ffffff" :foreground "#000000" :inverse-video nil :box nil :strike-through nil :overline nil :underline nil :slant normal :weight normal :height 120 :width normal :foundry "microsoft" :family "Trebuchet MS")))))



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;        configure Cscope in Emacs          ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; require xcscope in emacs
(require 'xcscope)

;; hotkey for cscope
(define-key global-map [(control f3)]  'cscope-set-initial-directory)
(define-key global-map [(control f4)]  'cscope-unset-initial-directory)
(define-key global-map [(control f5)]  'cscope-find-this-symbol)
(define-key global-map [(control f6)]  'cscope-find-global-definition)
(define-key global-map [(control f7)]
'cscope-find-global-definition-no-prompting)
(define-key global-map [(control f8)]  'cscope-pop-mark)
(define-key global-map [(control f9)]  'cscope-next-symbol)
(define-key global-map [(control f10)] 'cscope-next-file)
(define-key global-map [(control f11)] 'cscope-prev-symbol)
(define-key global-map [(control f12)] 'cscope-prev-file)
(define-key global-map [(meta f9)]  'cscope-display-buffer)
(define-key global-map [(meta f10)] 'cscope-display-buffer-toggle)



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;        configure Cc-mode in Emacs         ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(add-to-list 'load-path "~/.emacs-site-lisp/cc-mode")
;; require cc-mode in emacs
(require 'cc-mode)

(c-set-offset 'inline-open 0)
(c-set-offset 'friend '-)
(c-set-offset 'substatement-open 0)
(defun my-c-mode-common-hook()
  (setq tab-width 4 indent-tabs-mode nil)
  ;;; hungry-delete and auto-newline
;  (c-toggle-auto-hungry-state 1)
 
  (define-key c-mode-base-map [(control \`)] 'hs-toggle-hiding)
 ;; (define-key c-mode-base-map [(return)] 'newline-and-indent)
;;  (define-key c-mode-base-map [(f6)] 'compile)
  (define-key c-mode-base-map [(meta \`)] 'c-indent-command)
;;  (define-key c-mode-base-map [(tab)] 'hippie-expand)
  (define-key c-mode-base-map [(tab)] 'my-indent-or-complete)
  (define-key c-mode-base-map [(meta ?/)] 'semantic-ia-complete-symbol-menu)
 
  (setq c-macro-shrink-window-flag t)
  (setq c-macro-preprocessor "cpp")
  (setq c-macro-cppflags " ")
  (setq c-macro-prompt-flag t)
  (setq hs-minor-mode t)
  (setq abbrev-mode t)
)
(add-hook 'c-mode-common-hook 'my-c-mode-common-hook)

(defun my-c++-mode-hook()
  (setq tab-width 4 indent-tabs-mode nil)
  (c-set-style "stroustrup")
;;  (define-key c++-mode-map [f3] 'replace-regexp)
)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;     column-marker of Emacs Environment    ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(require 'column-marker)

;;examples : Highlight column 80 in foo mode:
(add-hook 'foo-mode-hook (lambda () (interactive) (column-marker-1 80)))

;;Use ‘C-c m’ interactively to highlight with ‘column-marker-1-face’:
(global-set-key [?\C-c ?m] 'column-marker-1)

;;C-u 80 M-x column-marker-1
;;Defining Additional Column Markers
;;This is all you need to do, to create an additional column marker:
;;(column-marker-create column-marker-4 my-favorite-face)


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;          configure Mew in Emacs           ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(setq load-path (cons "~/.emacs-site-lisp/share/emacs/site-lisp/mew" load-path))
(autoload 'mew "mew" nil t)
(autoload 'mew-send "mew" nil t)
(setq mew-icon-directory "/usr/local/share/emacs/site-lisp/mew/etc")
(setq mew-use-cached-passwd t)
(if (boundp 'read-mail-command)
    (setq read-mail-command 'mew))
(autoload 'mew-user-agent-compose "mew" nil t)
(if (boundp 'mail-user-agent)
    (setq mail-user-agent 'mew-user-agent))
(if (fboundp 'define-mail-user-agent)
    (define-mail-user-agent
       'mew-user-agent
       'mew-user-agent-compose
       'mew-draft-send-message
       'mew-draft-kill
       'mew-send-hook))
(setq mew-pop-size 0)
(setq mew-smtp-auth-list nil)
(setq toolbar-mail-reader 'Mew)
(set-default 'mew-decode-quoted 't) 
(when (boundp 'utf-translate-cjk)
      (setq utf-translate-cjk t)
      (custom-set-variables
         '(utf-translate-cjk t)))
(if (fboundp 'utf-translate-cjk-mode)
    (utf-translate-cjk-mode 1))

(load-file "~/.emacs-site-lisp/mew.el")

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;     configure min/max window in Emacs     ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(global-set-key [f11] 'my-fullscreen)

;; fullscreen
(defun my-fullscreen ()
  (interactive)
  (x-send-client-message
   nil 0 nil "_NET_WM_STATE" 32
   '(2 "_NET_WM_STATE_FULLSCREEN" 0))
)

;; maximized
(defun my-maximized ()
  (interactive)
  (x-send-client-message
   nil 0 nil "_NET_WM_STATE" 32
   '(2 "_NET_WM_STATE_MAXIMIZED_HORZ" 0))
  (x-send-client-message
   nil 0 nil "_NET_WM_STATE" 32
   '(2 "_NET_WM_STATE_MAXIMIZED_VERT" 0))
)
;; autorun 'Max' window
(my-maximized)
