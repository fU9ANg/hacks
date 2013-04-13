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
set timeout 30
spawn ssh $argv -l root
expect "password:"
send "111111\r"
interact

# END
