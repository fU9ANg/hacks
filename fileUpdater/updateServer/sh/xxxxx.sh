#!/bin/sh

#
# ecServer re-start script
# no client connection to server, that ecServer re-start 
#

SLEEP_SECOND=3
RESTART_FLAGS=1

while true
do
    STAT=`netstat -lanp | grep 9999 | wc -l`
    echo $STAT
    if [ $STAT -eq 0 ]
    then
        cd ~/ecServer
        ./server -d &
        nohup ./uploadfile.py &
    elif [ $STAT -eq 1 ]
    then
        if [ $RESTART_FLAGS -eq 1 ]
        then
            cd ~
            echo "\033[32;49;1m [kill and restart server...] \033[39;49;0m"
            echo "RESTART SERVER:"`date`>>restart_log
            killall server
            killall uploadfile.py
            cd ~/ecServer
            sleep 1
            ./server -d &
            nohup ./uploadfile.py &
            RESTART_FLAGS=0
        fi
    else
        echo "\033[32;49;1m [client connection...] \033[39;49;0m"
        RESTART_FLAGS=1
    fi

    sleep $SLEEP_SECOND
done
exit 0
