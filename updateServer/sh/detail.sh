#!/bin/sh

#
#   display detail information.
#

echo "\033[32;49;1m [--- ps -ef | grep xxxxx.sh ---] \033[39;49;0m"
ps -ef | grep xxxxx.sh
echo "\033[32;49;1m [--- ps -ef | grep server ---] \033[39;49;0m"
ps -ef | grep server
echo "\033[32;49;1m [--- ps -ef | grep uploadfile.py ---] \033[39;49;0m"
ps -ef | grep uploadfile.py
echo "\033[32;49;1m [--- ps -ef | grep yyyyy.sh ---] \033[39;49;0m"
ps -ef | grep yyyyy.sh
echo "\033[32;49;1m [--- ps -ef | grep SERVER ---] \033[39;49;0m"
ps -ef | grep SERVER
echo "\033[32;49;1m [--- netstat -lanp | grep 8888 ---] \033[39;49;0m"
netstat -lanp | grep 8888
echo "\033[32;49;1m [--- netstat -lanp | grep 9999 ---] \033[39;49;0m"
netstat -lanp | grep 9999
echo "\033[32;49;1m [--- netstat -lanp | grep 8080 ---] \033[39;49;0m"
netstat -lanp | grep 8080
