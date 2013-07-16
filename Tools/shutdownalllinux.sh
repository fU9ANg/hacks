#!/usr/bin/expect -f

#
#  VI: set ts=4; set expandtab; retab
#
#  A script for shutdown all linux operation system
#
#  Written 2013 by <H. F. G. fU9ANg>
#  Email:  62 62 2E 6E 65 77 6C 69 66 65 \	
#          40 67 6D 61 69 6C 2E 63 6F 6D
#

#  Auto ssh login

#  timeout
set timeout 10

#  access ip '253' with username is 'sxkj5'
spawn ssh 192.168.0.253 -l sxkj5 -p 22 
expect {
    "(yes/no)?" {
        send "yes\r"
        expect "password:"
        send "root\r"
    }
    "password:" {
        send "root\r"
    }
}
expect "]*"
send "date\r"
send "ls\r"
send "exit\r"
interact


#  access ip '194' with username is 'sxkj4'
spawn ssh 192.168.0.194 -l sxkj4 -p 22 
expect {
    "(yes/no)?" {
        send "yes\r"
        expect "password:"
        send "root\r"
    }
    "password:" {
        send "root\r"
    }
}
expect "]*"
send "sudo poweroff\r"
expect {
    "password for sxkj4:" {
        send "root\r"
    }
}
interact


#  access ip '193' with username is 'sxkj1'
spawn ssh 192.168.0.193 -l sxkj1 -p 22 
expect {
    "(yes/no)?" {
        send "yes\r"
        expect "password:"
        send "root\r"
    }
    "password:" {
        send "root\r"
    }
}
expect "]*"
send "sudo poweroff\r"
expect {
    "password for sxkj1:" {
        send "root\r"
    }
}
interact


#  access ip '103' with username is 'sxkj6'
spawn ssh 192.168.0.103 -l sxkj6 -p 22 
expect {
    "(yes/no)?" {
        send "yes\r"
        expect "password:"
        send "root\r"
    }
    "password:" {
        send "root\r"
    }
}
expect "]*"
send "sudo poweroff\r"
expect {
    "password for sxkj6:" {
        send "root\r"
    }
}
interact


#  access ip '145' with username is 'sxkj7'
spawn ssh 192.168.0.145 -l sxkj7 -p 22 
expect {
    "(yes/no)?" {
        send "yes\r"
        expect "password:"
        send "root\r"
    }
    "password:" {
        send "root\r"
    }
}
expect "]*"
send "sudo poweroff\r"
expect {
    "password for sxkj7:" {
        send "root\r"
    }
}
interact


#  access ip '195' with username is 'sxkj8'
spawn ssh 192.168.0.195 -l sxkj8 -p 22 
expect {
    "(yes/no)?" {
        send "yes\r"
        expect "password:"
        send "root\r"
    }
    "password:" {
        send "root\r"
    }
}
expect "]*"
send "sudo poweroff\r"
expect {
    "password for sxkj8:" {
        send "root\r"
    }
}
interact


# END
