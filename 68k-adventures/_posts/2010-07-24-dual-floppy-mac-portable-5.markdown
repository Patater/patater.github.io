---
layout: post
published: true
permalink: /dual-floppy-mac-portable-5
title: Building a Dual Floppy Mac Portable - Part 5
author: Jaeden Amero
date: 2010-07-24 16:17:55
updated: 2011-02-04 04:46:55
sitemappriority: 0.5
categories: 68k-adventures
tags: 68k-adventures blarg 68k 68000 mac macintosh macintosh-portable dual floppy
description: Have you ever seen a dual floppy Macintosh Portable? I haven't. Let's make one, part 5.
language: en
---
<p>When the computer first boots up, it displays a funky pattern on the screen. This pattern goes away in less than a second. This is probably a typical memory check or something.</p>

<a href="http://static.patater.com/files/pictures/macportable-transient_boot_1.jpg"><img src="http://static.patater.com/files/pictures/thumb/macportable-transient_boot_1.jpg" alt="Transient Boot 1" /></a>

<p>In attempting to photograph that, I discovered that some other sad mac codes are displayed before the final code is reached. These transient codes do seem to have a meaning, but maybe not one that makes sense; do they really matter or are they just noise before the correct code is shown?</p>

<a href="http://static.patater.com/files/pictures/macportable-transient_boot_2.jpg"><img src="http://static.patater.com/files/pictures/thumb/macportable-transient_boot_2.jpg" alt="Transient Boot 2" /></a>

<a href="http://static.patater.com/files/pictures/macportable-transient_boot_3.jpg" class="postlink"><img src="http://static.patater.com/files/pictures/thumb/macportable-transient_boot_3.jpg" alt="Transient Boot 3" /></a>

<p>I've found that a few different codes are displayed over my few attempts to start up the machine. The code is of the form &quot;0030017xx:00001FFA&quot;, where xx can be one of 01, 38, 39, 3E. This major code 17 doesn't seem to be documented anyplace, but perhaps I just don't know how to read these errors. This is one of a few possible final sad mac codes.</p>

<a href="http://static.patater.com/files/pictures/macportable-mystery_sad_mac.jpg"><img src="http://static.patater.com/files/pictures/thumb/macportable-mystery_sad_mac.jpg" alt="Mystery Sad Mac" /></a>

<p>Here is my best guess. One of the sad mac major codes shown is 14. I suspect that because I'm attempting to boot from the 9V battery, the power manager is complaining. Because there isn't much power available, the sad mac changes around until it reaches some equilibrium on some invalid code. I'll have to try with a new battery and power adapter to see if this not enough power guess is on the right path.</p>

<p>I'll be thankful for any <a href="/contact">guesses you have or recommendations for tests I should run</a>.</p>

<p>Sad mac is depressed.</p>
