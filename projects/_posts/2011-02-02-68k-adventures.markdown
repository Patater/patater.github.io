---
layout: post
published: true
id: tag:www.patater.com,2011-02-02:/68k-adventures
permalink: /68k-adventures
title: 68K Adventures
tags: project blarg nes asm tutorial
author: Jaeden Amero
description: Come check out what I've done with some crazy old junk!
date: 2011-02-02 03:34:24
updated: 2011-02-02 03:34:24
graphic: http://static.patater.com/images/simasimacse30-420.jpg
---
<p>I've had this habit of fixing up old Macintosh computers. Whenever I
resurrect a dead mac, or upgrade one to be super awesome, I'll document the
project in this series. I'll document some of my past projects, too.</p>

<ul class="posts">
{% for post in (site.tags.68k-adventures | sort: 'title') %}
  <li><span>{{ post.date | date: "%Y-%b-%d" }}</span> &raquo; <a href="{{ post.url }}">{{ post.title }}</a></li>
{% endfor %}
</ul>
