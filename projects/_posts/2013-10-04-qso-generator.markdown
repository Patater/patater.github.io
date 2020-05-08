---
layout: post
published: true
permalink: /qso-generator/
id: tag:www.patater.com,2013-10-04:/qso-generator/
title: A Random QSO Generator
shorttitle: QSO Generator
author: Jaeden Amero
date: 2013-10-04 23:43:51
updated: 2013-10-04 23:43:51
sitemappriority: 0.5
tags: project blarg lisp programming qso morse-code markov-chains
description: Existing Koch-method Morse code training software waits until all symbols are learned before giving a Morse code student practice with Morse code conversations (known QSOs in amateur radio parlance). The point of this program is to generate random QSOs given a subset of symbols, so that the student can gain practice with the QSO format even before they know all the Morse code symbols.
featured: true
language: en
graphic: /projects/qso-generator.png
graphicalt: A screenshot of qso-generator.rkt running the sample programs
download: https://github.com/Patater/qso-generator/archive/master.zip
downloadstring: Download QSO Generator from GitHub
filetype: zip
---
<h3>Purpose</h3>
<p>Existing Koch-method Morse code training software waits until all symbols are learned before giving a Morse code student practice with Morse code conversations (known QSOs in amateur radio parlance). The point of this program is to generate random QSOs given a subset of symbols, so that the student can gain practice with the QSO format even before they know all the Morse code symbols.</p>

<!--break-->

<h3>Function</h3>
<p>Using functions from this program, we can generate random callsigns; word-level similar texts; letter-level similar texts; texts that resemble the original, but are created with a subset of the original alphabet; and random QSOs given partial alphabets.</p>

<h3>Motivation</h3>
<p>I was reading <a href="http://lambda-the-ultimate.org/">Lambda the
Ultimate</a> one evening and found out about a programming competition called
<a href="http://lispinsummerprojects.org/">Lisp in Summer Projects</a>. They were giving a free t-shirt to all participants, so I thought, "Why not?" I decided to give the ancient language Lisp a try.</p>

<p>I heard Lisp was good at natural language processing (NLP) tasks, so I decided to do a project that involves NLP. <i>A Random QSO Generator</i> is my one and only entry into the competition.</p>

<h3>Audience</h3>
<p>I wrote this for myself, for later use as part of a Morse code training program that uses the Koch method of learning.</p>

<h3>How it Works</h3>
<p>The program works by following a set of production rules to produce a random QSO.</p>

<p>A QSO usually contains the callsigns of those involved in the QSO.The first thing the program does, when asked to produce a random QSO via generate-random-qso, is generate two callsigns, one for each participant in the conversation.</p>

<p>Callsigns are generated according to another set of production rules. They are made up of a country prefix, a separating numeral, and a suffix. As best as can be done given a partial alphabet, we attempt to create a callsign-looking string according to rules imposed upon us by the official callsign format.</p>

<p>After the callsigns are generated, we generate the body (main text) of the QSO. We construct a hierarchical Markov chain from our QSO corpus. The hierarchical Markov chain is composed of a 2-word Markov chain, a 1-word Markov chain, a 3-letter Markov chain, a 2-letter Markov chain, and a 1-letter Markov chain.</p>

<p>We use a hierarchical Markov chain so that if there is no valid transition (i.e. a transition to a new state that remains within our alphabet) at the highest level Markov chain, we will fall back onto the lower level chain to see if there is a valid transition there. If none of the chains have a valid transition, we will select a random symbol from our alphabet to be used to compose the next state. This allows us to make a best effort to generate text that looks like a QSO while remaining within our alphabet.</p>

<p>In order to combat repetitious looking output and to give more exposure to all symbols within the alphabet (for the sake of practice), we will, with a 20% chance, fall back to a lower level chain, even when the higher level chain contains a valid transition.</p>

<p>It is also possible for us to progress back up from a lower level chain to a higher level chain. The program keeps track of a history for each level of the hierarchical chain, no matter which chain is actually used to transition to the next state. The next time the hierarchical Markov chain is used, it checks for valid transitions starting from the highest level chain, which allows for getting back up into the higher order chains.</p>

<p>The hierarchical Markov chain history is generated as follows:
<ul>
<li>For word-level chains when a word is generated:<br/>
The new history for the chain is the new word appended to the previous history with the first word removed.</li>
<li>For letter-level chains when a word is generated:<br/>
The new history for the chain is last n letters of the previous history with all letters of the new word appended to it, where n is the size of the previous history (which is only one state back, no more).</li>
<li>For word-level chains when a letter is generated:<br/>
The new history for the chain is the previous history with the new letter appended to the last word of the previous history. If the new letter is a space, then a new blank word is appended to the previous history with the first word removed.</li>
<li>For letter-level chains when a letter is generated:<br/>
The new history for the chain is the new letter appended to the previous history with the first letter removed.</li>
</ul></p>

<p>After the hierarchical Markov chain is created, we the value of generate-random-qso as a new string composed from the introduction of the QSO, the main body of the QSO, and the conclusion of the QSO.</p>

<h3>Retrospective</h3>
<p>Letter substitutions would also help to create a more similar text. For instance, instead of emitting a disallowed letter C, we could allow a K where the C would have been used. The issue with this is that the history and context information would need to be maintained as if a C were actually emitted. This sounds a bit tricky.</p>

<p>We have some structure to the QSO, but we could have done better.
The generated text sounds like somebody schizophrenic with very short term memory loss. They say, "GOOD COPY EDWARD. MY NAME IS VICKY. MY NAME IS LARRY. HOW COPY JOHNNY." messing up names so much. Markov chains are famous for being bad at this sort of thing, so I might have to help it out a bit similar to how how I helped with the callsigns. To do this, I could use hierarchical Markov chains not for the entire text, but for chunks, where the chunks are approximately: "the radio I am using", "my name", "you name", "where I live", "what the weather is like", "how well I am copying you", "asking how I am being copied".</p>

<p>As for the language, Lisp, I really liked describing my program as a set of production rules. As a C programmer with experience using Bison, it was a breath of fresh air to be have my main source code resemble EBNF as opposed to only the source code consumed by Bison resembling EBNF. It's nice to have the ability to express the higher level ideas in the main language of the program, instead of scattered about in various other languages.</p>

<p>I made an attempt to make the Markov functions as general as possible and not limited to just strings, but for the sake of time I just implemented the hierarchical Markov chain history code to work with lists that contain only strings. Everything else was intended to be general enough to work with heterogeneous lists.</p>

<p>I started out writing unit tests for most of my functions, but after I started creating functions that used variables from their parent scope, I found it much more difficult to write tests for everything. I also didn't like having to choose between running the unit tests all the time in my main program, and having to export internal-use-only functions for my test program to use. There must be a better way to unit test that I'm not yet aware of. <a href="/contact">Feel free to contact me if you have some advice on this problem.</a></p>

<h3>Instructions</h3>
<h4>Build Instructions</h4>
<p>The program runs interactive with <a href="http://racket-lang.org/">DrRacket</a>, so all that needs to be done is to press the run button in <a href="http://racket-lang.org/">DrRacket</a>.</p>

<h4>Test Instructions</h4>
<p>Run any of the *-test.rkt files in DrRacket to test *.</p>

<h3>Fun Things</h3>

<p>Here are some fun things you can do with it. Open "qso-generate.rkt" and run it. Then run some of these commands.</p>

<p>Generate new, 20-word long, text in the style of the included QSO corpus, using a typical word-level Markov-chain (size 2).</p>

<pre>(display (string-join (generate-similar-corpus 2 (string-split (file->string
"corpora/qso.txt") " ") 20) " "))</pre>
<br/>
<p>Generate new text in the style of three different texts using a typical word-level Markov-chain (size 2).</p>
<pre>(display (string-join (generate-similar-corpus 2 (string-split (string-append
(file->string "corpora/navy-seal-copypasta.txt") (file->string
"corpora/dont-copy-that-floppy.txt") (file->string "corpora/bel-air.txt")) " ")
200) " "))</pre>
<br/>
<p>Generate a line that is similar to any line from a text file, but without using the letter E or e, using hierarchical Markov chains.</p>
<pre>
(display (generate-random-text
 (build-hierarchical-markov-chain-from-file "corpora/king-lear.txt")
 '(#\A #\B #\C #\D #\F #\G #\H #\I #\J #\K #\L #\M #\N #\O #\P #\Q #\R #\S #\T
 #\U #\V #\W #\X #\Y #\Z #\a #\b #\c #\d #\f #\g #\h #\i #\j #\k #\l #\m #\n
 #\o #\p #\q #\r #\s #\t #\u #\v #\w #\x #\y #\z #\. #\, #\' #\; #\? #\!
 #\space)
 200
 ))</pre>
<br/>
<p>Aside from all those other fun things, here's the main point of this program. Generate a random QSO-like message with a few differently sized alphabets. The alphabets are in N1IRZ's learning order.</p>

<pre>(display (generate-random-qso '(#\K #\M)))</pre><br/>

<pre>(display (generate-random-qso '(#\K #\M #\R #\S #\U #\A #\P #\T #\L #\O)))</pre><br/>

<pre>(display (generate-random-qso '(#\K #\M #\R #\S #\U #\A #\P #\T #\L #\O #\W #\I
#\. #\N #\J #\E #\F #\0 #\Y #\V)))</pre><br/>

<pre>(display (generate-random-qso '(#\K #\M #\R #\S #\U #\A #\P #\T #\L #\O #\W #\I
#\. #\N #\J #\E #\F #\0 #\Y #\V #\, #\G #\5 #\/ #\Q #\9 #\Z #\H #\3 #\8)))</pre><br/>

<pre>(display (generate-random-qso '(#\K #\M #\R #\S #\U #\A #\P #\T #\L #\O #\W #\I
#\. #\N #\J #\E #\F #\0 #\Y #\V #\, #\G #\5 #\/ #\Q #\9 #\Z #\H #\3 #\8 #\B #\?
#\4 #\2 #\7 #\C #\1 #\D #\6 #\X)))</pre><br/>

<pre>(display (generate-random-qso '(#\K #\M #\R #\S #\U #\A #\P #\T #\L #\O #\W #\I
#\. #\N #\J #\E #\F #\0 #\Y #\V #\, #\G #\5 #\/ #\Q #\9 #\Z #\H #\3 #\8 #\B #\?
#\4 #\2 #\7 #\C #\1 #\D #\6 #\X #\# #\@ #\! #\$)))</pre><br/>

<h3>Thanks</h3>
<p>Thanks to Lisp In Summer Projects of the LispNYC for getting me off my butt and finally taking the time to learn a Lispy language.</p>

<p>A special thanks goes out to Dave Finley, N1IRZ, for the QSO corpus and for helping me to learn morse code.<p>

<h2>Source Code</h2>
<a href="https://github.com/Patater/qso-generator">Grab the source code from GitHub</a>
