---
layout: post
published: true
permalink: /cache-control
id: tag:www.patater.com,2010-12-14:/minimal-mario
title: Cache Control
author: Jaeden Amero
date: 2012-04-22 20:54:23
updated: 2012-04-22 20:54:23
sitemappriority: 0.5
tags: project 68k-adventures blarg 68k macintosh mac macplus
description: Are you sick of the cache included with your old Macintosh? Probably not, but if so, you can disable it with this nice utility.
graphic: http://static.patater.com/images/cache-control-icon.png
graphicalt: Cache Control Icon
thumb: http://static.patater.com/images/cache-control-icon.png
featured: true
language: en
---
<p>Are you sick of the cache included with your old Macintosh? Probably not, but if so, you can disable it with this nice utility.</p>

<img src="http://static.patater.com/images/cache-control-ui.png" alt="A Screenshot of Cache Control Running on a Macintosh" />

<p>There are a number of reasons you might want to disable the cache. One such use is to see how much slower a Dhrystone benchmark gets when run with the cache disabled. Caches add non-deterministic behavior to systems, too. If you are running some real-time control application, you may want to disable the cache in order to achieve better determinism (at the expense of average execution speed). Some software bugs only rear their ugly heads when a cache is present; there are probably some old Macintosh programs that don't work well with the caches present in newer systems. Another reason might be that you feel your Macintosh is has been running too quickly of late and you just want to slow things down and take it easy.

<p>When the application starts, you'll notice a File menu (and not much else). You can enable and disable the cache from that menu. Keyboard shortcuts are provided, too.</p>

<p>Cache Control works by calling SwapInstructionCache and SwapDataCache, as documented in Apple Technical Note HW06 "Cache as Cache Can". It should work on any Macintosh where that technical note applies.</p>

<p>I hope you find this program to be fun, if not somewhat useful.</p>

<p>Cache Control is released under the MIT License. Source code is provided.</p>

<div>
<h2>Download</h2>
<a href="http://static.patater.com/projects/cache-control.sit">Cache
Control</a>
</div>
