#!/bin/sh
bundle exec jekyll build
rsync -rav -e "ssh -p 2200" --progress --partial _site/ root@patater.net:/jail/www/usr/local/www/patater.com/htdocs/
