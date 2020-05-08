---
layout: post
published: true
id: tag:www.patater.com,2011-02-02:/68k-adventures/
permalink: /68k-adventures/
title: 68K Adventures
tags: project blarg nes asm tutorial
author: Jaeden Amero
description: Come check out what I've done with some crazy old junk!
date: 2011-02-02 03:34:24
updated: 2011-02-02 03:34:24
graphic: /images/simasimacse30-420.jpg
graphicalt: Simasimac SE/30
---
<p>I've had this habit of fixing up old Macintosh computers. Whenever I
resurrect a dead mac, or upgrade one to be super awesome, I'll document the
project in this series. I'll document some of my past projects, too.</p>

<!--break-->

<ul class="posts">
{% assign sorted = site.tags['68k-adventures'] | sort: 'date' %}
{% for post in sorted %}
  <li><a href="{{ post.url }}">{{ post.title }}</a></li>
{% endfor %}
</ul>
