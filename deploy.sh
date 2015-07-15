#!/bin/sh
bundle exec jekyll build
rsync -rav --progress --partial _site/ patater.com:/var/www/patater.com/htdocs/
