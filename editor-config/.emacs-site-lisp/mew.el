(setq mew-fcc "+sent")
(setq mew-demo-picture nil)
(setq mew-pop-size 0)
;;(setq mew-imap-prefix-list '("#mh/" "#mhinbox"))
(setq mew-auto-get t)
(setq toolbar-mail-reader 'Mew)
(setq mew-use-cached-passwd t)
(setq mew-passwd-timer-unit 999)
(setq mew-passwd-lifetime 999)
(set-default 'mew-decode-quoted 't)  
(setq mew-prog-pgp "gpg")
(setq mew-pop-delete nil)
(setq mew-config-alist 
;;Gmail
	'(("default"
	("name"		. "fU9ANg")
	("user"		. "bb.newlife")
	("mail-domain"	. "gmail.com")
	("proto"	. "+")
	("pop-ssl"	. t)
	("pop-ssl-port"	. "995")
	("prog-ssl"	. "/usr/sbin/stunnel")
	("pop-auth"	. pass)
	("pop-user"	. "bb.newlife@gmail.com")
	("pop-server"	. "pop.gmail.com")
	("smtp-ssl"	. t)
	("smtp-ssl-port". "465")
	("smtp-auth-list" . ("PLAIN" "LOGIN" "CRAM-MD5"))
	("smtp-user"	. "bb.newlife@gmail.com")
	("smtp-server"	. "smtp.gmail.com")
	)
  ("IMAP"
	("name"	. "fU9ANg")
	("user"	. "bb.newlife")
	("mail-domain" . "gmail.com")
	("proto" . "%")
	("imap-server"	. "server address")
	("imap-ssh-server"	. "SSH server address")
	("imap-user"	. "IMAP login name")
	("imap-size"	. 0)
	("smtp-ssl"	. t)
	("smtp-ssl-port". "465")
	("smtp-auth-list" . ("PLAIN" "LOGIN" "CRAM-MD5"))
	("smtp-user"	. "SMTP login name")
	("smtp-server"	. "SMTP server address")
	("imap-delete" . t)
	("imap-queue-folder" . "%queue") 
	("imap-trash-folder" . "%INBOX.Trash") ;; This must be in concile with your IMAP box setup
	)
 ))
(setq mew-ssl-verify-level 0)
(setq mew-prog-ssl "/usr/sbin/stunnel")

(setq mew-refile-guess-alist
  '(("To:"
      ("xiyoulinux@googlegroups.com" . "+xiyoulinux")
      ("linux-kernel@zh-kernel.org"   . "+zh-kernel")
      ("zeuux-universe@zeuux.org"     . "+zeuux")
      ("linux-kernel@vger.kernel.org" . "+lkml"))
    ("Cc:"
      ("xiyoulinux@googlegroups.com" . "+xiyoulinux")
      ("linux-kernel@zh-kernel.org"   . "+zh-kernel")
      ("zeuux-universe@zeuux.org"     . "+zeuux")
      ("linux-kernel@vger.kernel.org" . "+lkml"))
    (nil . "+inbox")))

;;Biff
(setq mew-use-biff t) ;; nil
(setq mew-use-biff-bell t) ;; nil
(setq mew-pop-biff-interval 10) ;; 5 (minutes)

;;Reply
(setq mew-reply-sender-alist
  '(("Reply-To:"
      ("To:" "Reply-To:" "From:"))
    (t
      ("To:" "From:"))))
(setq mew-reply-all-alist
  '((("Followup-To:" "poster")
       ("To:" "From:"))
     ("Followup-To:"
       ("Newsgroups:" "Followup-To:"))
     ("Newsgroups:"
       ("Newsgroups:" "Newsgroups:"))
     ("Reply-To:"
       ("To:" "Reply-To:"))
     (t
       ("To:" "From:")
       ("Cc:" "To:" "Cc:" "Apparently-To:"))))

;;cite
(setq mew-cite-fields '("From:" "Subject:" "Date:" "Message-ID:"))
(setq mew-cite-format "From: %s\nSubject: %s\nDate: %s\nMessage-ID: %s\n\n")
(setq mew-cite-prefix-function 'mew-cite-prefix-username)

;;signature
(setq mew-signature-file "~/.signature")
(setq mew-signature-insert-last t)

;;Thread
(setq mew-prog-imls-arg-list '("--thread=yes" "--indent=2"))
(setq mew-use-fancy-thread t)
(setq mew-fancy-thread-indent-strings  [" +" " +" " |" "  "] )
(setq mew-use-thread-separator nil)
(setq mew-thread-separator "--")

;;Sort
(setq mew-sort-default-key-alist
      '(("+inbox" . "date")
        ("+xiyoulinux". "subject")
        ("+zh-kernel". "subject")
        ("+zeuux". "subject")
        ("+lkml" . "subject")))

;;Forward
(setq mew-field-delete-for-forwarding '("Received:" "Return-Path:"))

;; w 写信
;; M-TAB 补齐收信人信息
;; Q 退出mew
;; i 收信
;; g 跳转邮箱
;; o 对邮件进行分类
;; d 把邮件标记为删除
;; * 作星号标记
;; u 清除标记
;; x 对所有标记进行处理
;; a 不带引用的回复，不建议使用
;; A 带引用的回复，推荐
;; f 转发邮件
;; y 保存邮件，会提示是保存整个邮件和是仅保存正文
;; SPACE 阅读邮件
;; ENTER 让阅读的邮件向上滚动一行
;; - 向下滚动一行
;; n 下一封邮件
;; p 前一封邮件
;; j 跳到某一封邮件
;; N 下一封带星号的邮件
;; P 上一封带星号的邮件
;; S 按某个指定项目对邮件排序
;; / 按指定条件搜索邮件，并进入虚拟模式
;; tt 进入虚拟模式，根据线索查看，普通模式下是不可以的
;; C 如果设置了多个邮箱，用此切换
;; C-cC-m 编辑新邮件，放入草稿中
;; C-cC-c 发送邮件
;; C-cC-q 取消草稿
;; C-cC-a 插入附件
;; C-cTAB 插入签名
;; C-cC-l 转换当前邮件的编码格式
;; C-cC-y 复制部分邮件，带引用前缀
;; C-cC-t 复制部分邮件，不带引用前缀
;; C-cC-a 把当前的发信人加入地址薄
;; C-uC-cC-a 比C-cC-a多加入昵称和名字，推荐
