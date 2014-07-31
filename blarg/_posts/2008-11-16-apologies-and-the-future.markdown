---
layout: post
published: true
permalink: /blarg/apologies-and-the-future
id: tag:www.patater.com,2008-11-16:/blarg/apologies-and-the-future
title: Apologies and the Future
author: Jaeden Amero
date: 2008-11-16 17:33:30
updated: 2010-12-19 03:36:44
sitemappriority: 0.5
language: en
---

This downtime has been the longest that this site has experienced. For that, I
apologize.

It is quite surprising when you see a user on your server that you know isn't
supposed to be privileged running about eight wget and eight sendmail processes
simultaneously (new ones being created and destroyed all the time), using up a
good portion of my CPU time. I came to the obvious conclusion that I had my
server broken into (electronically) and immediately shut down the server,
locking everyone out, even me.

I contacted my kick ass host and had them send me an archive of my box in a tar
ball (tgz). They were very empathetic and set me up a new box with a clean OS
install. The response was quick and the transactions smooth. From there, I
spend the last few weeks rebuilding my server.

I began researching more deeply into computer security during my rebuild. I've
been reading the NSA's guide to securing my operating system and hope that my
implementation of many of its recommendations will benefit this site's
security. That said, be nice and don't test it maliciously please. But feel
free to <a href="/contact">alert me</a> if you find anything that looks a bit
off, if you do feel like auditing this site.

On a lighter note, it looks like devkitPro is going to be updating a lot of
their toolchains and libraries, devkitARM and libnds included. The
*Introduction to Nintendo DS Programming* manual is alive and well and far from
the deadness this site has been in. It is being updated to support the new
toolchain and libraries. If you feel you need a certain feature of the new
library (perhaps the use of the FIFO, aside from its uses for sound or perhaps
libwifi or libfat) covered or feel that something was left out in the previous
(currently shipping) version of the manual, <a href="/contact">I'm open and
able to implement some new ideas at this time</a>.

Thanks to nyarla of #dsdev for putting up a copy of the manual for people to
download during the downtime.
