---
layout: post
published: true
permalink: /blarg/manual-on-github
title: Introduction to Nintendo DS Programming is Now on GitHub
shorttitle: The Manual is Now on GitHub
author: Jaeden Amero
date: 2013-05-30 12:54:21
updated: 2013-05-30 12:54:21
sitemappriority: 0.5
tags: nintendo-ds manual programming github source code
description: After all these years, I finally got around to releasing the manuscript.
featured: true
graphic: /images/rocket-code.png
graphicalt: Orange Spaceship flying over code
language: en
---
<p>After all these years, I finally got around to releasing the manuscript for the Introduction to Nintendo DS Programming. I converted the manual from Subversion to git and <a href="https://github.com/Patater/manual">placed it up on GitHub</a>. I hope that it brings some more life to the document, as I haven't updated it in years. It's been a good resource for the Nintendo DS homebrew community, but it wasn't fair for me to be a bottleneck on all change and updates to the manual; that's a recipe for going out of date.</p>

<p>I've specified the license as <a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/deed.en_US">Creative Commons Attribution-ShareAlike 3.0 Unported License</a>. It's my hope that the manual will provide a good starting point for anyone in the community to use to document homebrew Nintendo DS programming.</p>

<img src="//static.patater.com/images/reposturgeon.png" alt="The reposurgeon" />

<p>The conversion from Subversion to git went very well. I'm thankful to Eric S. Raymond (esr) and his <a href="http://www.catb.org/esr/reposurgeon/reposurgeon.html">reposurgeon</a> tool. With it, I was able to convert the entire history of the manual (with all its dirty warts) to git in just a few hours. This was my first time using <a href="http://www.catb.org/esr/reposurgeon/reposurgeon.html">reposurgeon</a>, and I found it to have a bit of a learning curve. It all clicked when I figured out that the arguments to <a href="http://www.catb.org/esr/reposurgeon/reposurgeon.html">reposurgeon</a> are just a list of commands to execute, and that changes are kept in memory until written with the "write" command.</p>

<p>If you are curious how the conversion was done, please have a look at my <a href="//static.patater.com/projects/manual-conversion.xz">manual conversion archive</a>. I basically followed <a hre="http://www.catb.org/esr/dvcs-migration-guide.html">esr's guide</a>. I modified his <a href="http://catb.org/~esr/reposurgeon/conversion.mk">conversion.mk</a> file to suit my needs (setting some options and renaming it to Makefile) and wrote a script called "manual.lift" to massage the Subversion history into beauty. All the details are in the <a href="//static.patater.com/projects/manual-conversion.xz">manual conversion archive</a>.</p>

<p>Share and enjoy!</p>
