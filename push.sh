#!/bin/bash

# file pull.sh
# brief USed to push apache content to a remote server using rsync
# author williamkloppenberg
# Lab 9 Scheduled Tasks
# date 11/2/2020

# Constants
AWSHOST="ec2-54-91-185-163.compute-1.amazonaws.com"
AWSUSER="push-web"
LOCALDIR="web-content"

# Change to working directory
cd /root/cron-lab

# Rsync
# TODO:   Content for key path
rsync -e "ssh -i keys/push-web" -vra0 --no-perms --delete --chmod=660 --chown=push-web:www-data "${LOCALDIR}/" "${AWSUSER}@${AWSHOST}":
# Write an entry to syslog
echo "web content pushed to ${AWSHOST}" | mail -s "Scheduled Tasks" william.kloppenberg@mymail.champlain.edu
