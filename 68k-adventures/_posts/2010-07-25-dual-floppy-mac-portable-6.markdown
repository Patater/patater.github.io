---
layout: post
published: true
permalink: /dual-floppy-mac-portable-6
title: Building a Dual Floppy Mac Portable - Part 6
author: Jaeden Amero
date: 2010-07-25 20:40:43
updated: 2011-02-04 04:54:43
sitemappriority: 0.5
categories: 68k-adventures
tags: 68k-adventures blarg 68k 68000 mac macintosh macintosh-portable dual floppy
description: Have you ever seen a dual floppy Macintosh Portable? I haven't. Let's make one, part 6.
language: en
---
<p>I've learned that the PowerBook 100 adapter is good for charging as well as running without the battery. I've also verified that it is a switching type.</p>

<p>There doesn't seem to be any special rigging required in order to run off of a 9V supply. I was able to boot into a sad mac with just the 9V battery. A lot of 9V supplies are meant to replace 9V batteries and so come with a 9V battery connector on them. The only 9V power supply I have is a 300mA type, so that won't do me any good on this. With my PowerBook 100 adapter dead, I'm now on the market for a compatible power adapter.</p>

<p>I had this 6V battery laying around, so I decided to hook it up. The cables for the Macintosh Portable battery didn't give me much slack, but I was able to hook it up and run the machine without the case on. This experiment should validate whether or not the sad mac is due to flaky power.</p>

<a href="/files/pictures/macportable-battery_connection_1.jpg"><img src="/files/pictures/thumb/macportable-battery_connection_1.jpg" alt="Battery Connection 1" /></a>

<a href="/files/pictures/macportable-battery_connection_2.jpg"><img src="/files/pictures/thumb/macportable-battery_connection_2.jpg" alt="Battery Connection 2" /></a>

<a href="/files/pictures/macportable-without_case.jpg" class="postlink"><img src="/files/pictures/thumb/macportable-without_case.jpg" alt="Without Case" /></a>

<p>Unfortunately, I still get the sad mac. However, the code is pretty consistently 03001300:00001FFA. This $1300 code might be a CPU exception code, indicating that I'm receiving an interrupt too early in the boot process (<a href="http://myoldmac.net/FAQ/SADerror-portable.htm">as per myoldmac</a>). That in turn might mean that an interrupt line is being permanently asserted. As I'm not sure which caps are in the interrupt path (if any). I'll just look over all my work again carefully and hopefully I'll find something.</p>
