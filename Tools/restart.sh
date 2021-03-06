#!/usr/bin/expect -f

#
#  VI: set ts=4; set expandtab; retab
#
#  SSH auto login to ssh-server.
#
#  Written 2010 by <H. F. G. fU9ANg>
#  Email:  62 62 2E 6E 65 77 6C 69 66 65 \	
#          40 67 6D 61 69 6C 2E 63 6F 6D
#

#  Auto ssh login
set timeout 10
#spawn ssh $argv -l sxkj20 -p 2222 
spawn ssh xxx.xxx.xxx.xxx -l username -p port
expect {
    "(yes/no)?" {
        send "yes\r"
        expect "password:"
        send "*****\r"
    }
    "password:" {
        send "*****\r"
    }
}
expect "]*"
send "date\r"
send "cd ecServer\r"
send "killall server\r"
send "killall uploadfile.py\r"
send "sleep 1\r"
send "./server -d &\r"
send "nohup ./uploadfile.py &\r"
send "exit\r"
interact


# END
