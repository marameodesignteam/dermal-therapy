<?php

/*
ssh u781-dokrqb835gyy@dermaltherapy.com.au -p18765

LIVE
git remote add sg_live ssh://u781-dokrqb835gyy@dermaltherapy.com.au:18765/home/u781-dokrqb835gyy/www/dermaltherapy.com.au/live.dermal.git
git push sg_live
ssh u781-dokrqb835gyy@dermaltherapy.com.au -p18765 'cd /home/u781-dokrqb835gyy/www/dermaltherapy.com.au/public_html && drush cc all'

DEV
git remote add sg_dev ssh://u781-dokrqb835gyy@dermaltherapy.com.au:18765/home/u781-dokrqb835gyy/www/dev.dermaltherapy.com.au/dev.dermal.git
git push sg_dev
ssh u781-dokrqb835gyy@dermaltherapy.com.au -p18765 'cd /home/u781-dokrqb835gyy/www/dev.dermaltherapy.com.au/public_html && drush cc all'
