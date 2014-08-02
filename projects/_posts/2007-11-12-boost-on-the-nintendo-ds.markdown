---
layout: post
published: true
permalink: /boost-on-the-nintendo-ds
id: tag:www.patater.com,2007-11-12:/boost-on-the-nintendo-ds
title: Boost on the Nintendo DS
author: Jaeden Amero
date: 2007-11-12 23:00:43
updated: 2010-12-19 03:36:44
sitemappriority: 0.5
tags: project blarg nds nintendo-ds howto boost c++
description: Ever wonder how to get boost working on your Nintendo DS? Here's how.
graphic: /images/boost-nds.png
language: en
---
<h2>About</h2>
<p>The following guide will help you to compile Boost for the Nintendo DS using
devkitARM on Linux or Mac OS X (using the bash shell).  Many Boost libraries
are header only and don't require linking with a built Boost component. That
said, if the library you want to use isn't header only, this guide will be your
guide. It assumes you have <code>$DEVKITARM</code> and <code>$DEVKITPRO</code>
environment variables already set-up properly. Thanks to <a
href="http://davr.org/">davr</a> for working with me to get boost
compiling.</p>
<!--break-->

<h2>Some Environment Variables</h2>
<p>First, you must set up some environment variables.</p>
<code class="block">
export PATH=$PATH:$DEVKITARM/arm-eabi/bin:$DEVKITARM/bin
</code>

<h2>Compiling bjam</h2>
<p>The boost source code comes with some bjam source code, too. We build it for
our host platform (your PC) using the included bootstrap.sh script.  In the
root of the boost directory, do the following.</p>
<code class="block">
./bootstrap.sh
</code>

<h2>Configuring and Building Boost</h2>
<p>Edit the generated project-config.jam file. We are telling jam to build
boost with gcc 4.5.1 arm-eabi-g++. This is the version that devkitARM r32
provides. As devkitARM is changed, this too will need to change.</p>
<code class="block">
using gcc : 4.5.1 : arm-eabi-g++ ;
</code>

<p>Next, we have to make sure that $OUTDIR exists and is writable. We can do
that by creating one. Finally, we use the freshly built bjam binary to build
for our target platform, the Nintendo DS, a non-thread-safe statically linkable
boost library.</p>
<code class="block">
mkdir $DEVKITPRO/boost
export OUTDIR=$DEVKITPRO/boost
./bjam --toolset=gcc --prefix=$OUTDIR threading=single link=static install
</code>

<h2>In the End</h2>
<p>Your compile should take a little while. Boost is quite big. Note that as
the DS doesn't have an operating system to provide threads, anything that
depends on threading will fail. In the end, you should get a message that looks
similar to the following. <a href="/contact">Let me know</a> if it turns out
different for you.</p>
<code class="block">
...failed updating 40 targets...
...skipped 165 targets...
...updated 8369 targets...
</code>

<div>
<h2>Download</h2>
<a href="http://static.patater.com/projects/boost-1.45.0_devkitarm-r32.zip">Boost for Nintendo DS Precompiled</a>
</div>
