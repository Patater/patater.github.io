---
layout: post
published: true
permalink: /blarg/new-devkitarm-toolchain-new-introduction-nintendo-ds-programming-underway
id: tag:www.patater.com,2008-12-13:/blarg/new-devkitarm-toolchain-new-introduction-nintendo-ds-programming-underway
title: New devkitARM toolchain. New Introduction to Nintendo DS Programming underway.
author: Jaeden Amero
date: 2008-12-13 02:35:10
updated: 2010-12-19 03:36:44
sitemappriority: 0.5
language: en
---
The new version (r24) of <a href="http://www.devkitpro.org/">devkitARM</a> is
here. Along with it comes the highly anticipated libnds 1.3.1 release. A new
libnds means a broken *Introduction to Nintendo DS Programming* and a lot more
other broken source code.

This new release of libnds introduces more high-level APIs and some all new low
level APIs. This release renames some registers, preventing the source code
included with *Introduction to Nintendo DS Programming* from building
successfully. It also changes how the interrupt system is initialized, no
longer requiring (and breaking if you do use) <code>irqInit</code> in
<code>main</code>. I do like the new register names, as they match the names as
documented in <a href="http://nocash.emubase.de/gbatek.htm">GBATEK</a>.

One reason I started writing the manual was because all the other tutorials
(all two of them, at that time) were out of date. I feel strongly about having
fresh information available to potential members of the homebrew community; an
out of date tutorial is very useless and can be very frustrating. Users of such
tutorials blame themselves for the failures and have no idea where to go next,
as everything explaining to them where to go no longer applies. Without some
positive reinforcement (in the form of a successful build and a graphic on the
screen), many would be community members give up. As such, I'm working on
updating the *Introduction to Nintendo DS Programming* source code and will
have a new release out soon.
