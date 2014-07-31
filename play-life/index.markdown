---
layout: default
published: true
title: Conway's Game of Life
shorttitle: GPU Life
author: Jaeden Amero
date: 2012-08-27 16:02:11
updated: 2012-08-27 16:02:11
sitemappriority: 0.5
tags: life gpu conway gpgpu
description: Play it now.
language: en
---
<div id="content">
      <canvas id="content-canvas" width="512" height="512"/>
    </div>
    <div id="status">
      <div id="messages"></div>
      <span id="fps"></span>
    </div>

    <script id="vertex-shader" type="x-shader/x-vertex">
      #ifdef GL_ES
        precision mediump float;
      #endif
      attribute vec3 position;
      attribute vec2 a_uv;
      varying vec2 uv;

      void main() {
        gl_Position = vec4(position, 1.0);
        uv = a_uv;
      }
    </script>
    <script id="compute" type="x-shader/x-fragment">
      #ifdef GL_ES
        precision mediump float;
      #endif
      varying vec2 uv;
      uniform sampler2D sampler;
      uniform sampler2D mod_sampler;
      uniform float dx;
      uniform float dy;

      const float cool_down_rate = 0.05;

      int count_neighbors(void)
      {
        int neighbors = 0;
        // N
        if (texture2D(sampler, uv + vec2(0., dy)).a == 1.) neighbors++;
        // NE
        if (texture2D(sampler, uv + vec2(dx, dy)).a == 1.) neighbors++;
        // E
        if (texture2D(sampler, uv + vec2(dx, 0.)).a == 1.) neighbors++;
        // SE
        if (texture2D(sampler, uv + vec2(dx, -dy)).a == 1.) neighbors++;
        // S
        if (texture2D(sampler, uv + vec2(0., -dy)).a == 1.) neighbors++;
        // SW
        if (texture2D(sampler, uv + vec2(-dx, -dy)).a == 1.) neighbors++;
        // W
        if (texture2D(sampler, uv + vec2(-dx, 0.)).a == 1.) neighbors++;
        // NW
if (texture2D(sampler, uv + vec2(-dx, dy)).a == 1.) neighbors++;

        return neighbors;
      }

      void main(void) {
        float state = texture2D(sampler, uv).a;
        float cool = state - cool_down_rate;
        float mod_state = texture2D(mod_sampler, uv).a;

        // Handle mouse clicks on our pixels.
        if (mod_state > 0.) {
          if (state == 1.) {
            // Don't fire any more.
            gl_FragColor = vec4(0., 0., 0., cool);
          } else {
            // Start firing.
            gl_FragColor = vec4(0., 0., 0., 1.);
          }
        } else {
          int neighbors = count_neighbors();
          if (state == 1.) {
            // Alive
            if (neighbors < 2 || neighbors > 3) {
              // Die
              gl_FragColor = vec4(0., 0., 0., cool);
            } else {
              gl_FragColor = vec4(0., 0., 0., 1.);
            }
          } else {
            // Dead
            if (neighbors == 3) {
              gl_FragColor = vec4(0., 0., 0., 1.);
            } else {
              gl_FragColor = vec4(0., 0., 0., cool);
            }
          }
        }
      }
    </script>

    <script id="display" type="x-shader/x-fragment">
      #ifdef GL_ES
        precision mediump float;
      #endif
      varying vec2 uv;
      uniform sampler2D sampler;

      const float pink_r = 1.;
      const float pink_g = 0.;
      const float pink_b = 139. / 255.;

      void main(void) {
        float state = texture2D(sampler, uv).a;
        if (state == 1.) {
          // Firing
          gl_FragColor = vec4(1., 1., 1., 1.);
        } else {
          // Refractory
          gl_FragColor = vec4(state, 0, pink_b * state, 1.);
        }
      }
    </script>

    <script>
var a=!0,e=null,f=!1,g=f,h=a,i=128,j=128,k,l,m,n,o,p,q,r,s=[],u=[],v=0,w=1,x=0,y=(new Date).getTime(),z=1/i,A=1/j,B,D,E=f,F=f,G,H=2;requestAnimFrame=function(){window.setTimeout(I,100)};window.init=J;
function J(){var b=document.getElementById("vertex-shader").textContent,c=document.getElementById("compute").textContent,d=document.getElementById("display").textContent;k=document.getElementById("fps");p=document.getElementById("messages");l=document.getElementById("content-canvas");try{m=l.getContext("experimental-webgl",{depth:f})}catch(t){}m?(n=K(b,c),o=K(b,d),n==e||o==e||(m.useProgram(n),n.position=m.getAttribLocation(n,"position"),m.enableVertexAttribArray(n.position),n.a=m.getAttribLocation(n,
"a_uv"),m.enableVertexAttribArray(n.a),n.c=m.getUniformLocation(n,"sampler"),n.f=m.getUniformLocation(n,"mod_sampler"),n.d=m.getUniformLocation(n,"dx"),n.e=m.getUniformLocation(n,"dy"),m.useProgram(o),o.position=m.getAttribLocation(o,"position"),m.enableVertexAttribArray(o.position),o.a=m.getAttribLocation(o,"a_uv"),m.enableVertexAttribArray(o.a),o.c=m.getUniformLocation(o,"sampler"),q=m.createBuffer(),m.bindBuffer(m.ARRAY_BUFFER,q),b=new Float32Array([-1,-1,0,1,-1,0,-1,1,0,1,1,0]),m.bufferData(m.ARRAY_BUFFER,
b,m.STATIC_DRAW),q.b=3,q.count=4,r=m.createBuffer(),m.bindBuffer(m.ARRAY_BUFFER,r),b=new Float32Array([0,0,1,0,0,1,1,1]),m.bufferData(m.ARRAY_BUFFER,b,m.STATIC_DRAW),r.b=2,r.count=4,b=L(),s[0]=M(b),s[1]=M(b),u[0]=N(s[0]),u[1]=N(s[1]),B=L(),G=L(),s[H]=M(B),D=a,O("Draw in the box.\n"),l.addEventListener("mousedown",P,f),l.addEventListener("mouseover",Q,f),g&&setInterval(R,500),I())):alert("Experimental WebGL is not supported.")}function Q(){l.style.cursor="url(http://static.patater.com/8x8_block.png), default"}
function P(b){F||(F=a);var c=(b.clientX-l.offsetLeft+window.pageXOffset)/(l.width/i)>>0,d=(b.clientY-l.offsetTop+window.pageYOffset)/(l.height/j)>>0;S(c,d);S(c+1,d);S(c,d+1);S(c+1,d+1);D=a;document.addEventListener("mousemove",T,f);document.addEventListener("mouseup",U,f);b.preventDefault()}
function T(b){var c=(b.clientX-l.offsetLeft+window.pageXOffset)/(l.width/i)>>0,d=(b.clientY-l.offsetTop+window.pageYOffset)/(l.height/j)>>0;S(c,d);S(c+1,d);S(c,d+1);S(c+1,d+1);D=a;b.preventDefault()}function U(){document.removeEventListener("mousemove",T,f);document.removeEventListener("mouseup",U,f)}function L(){for(var b=[],c=0;c<i;c++)for(var d=0;d<j;d++)b.push(0,0,0,0);return b}
function S(b,c){var d=B;0>b||(0>c||b>i||c>j)||(d[4*(c*i+b)]=255,d[4*(c*i+b)+1]=255,d[4*(c*i+b)+2]=255,d[4*(c*i+b)+3]=255)}
function M(b){var c=m.createTexture();m.bindTexture(m.TEXTURE_2D,c);m.pixelStorei(m.UNPACK_ALIGNMENT,1);m.texImage2D(m.TEXTURE_2D,0,m.RGBA,i,j,0,m.RGBA,m.UNSIGNED_BYTE,new Uint8Array(b));m.texParameteri(m.TEXTURE_2D,m.TEXTURE_MIN_FILTER,m.NEAREST);m.texParameteri(m.TEXTURE_2D,m.TEXTURE_MAG_FILTER,m.NEAREST);b=h&&(0<i?0==(i&i-1):f)&&(0<j?0==(j&j-1):f);h&&!b&&O("Please use power of two sized width and height ifyou want wrap around.");b?(m.texParameteri(m.TEXTURE_2D,m.TEXTURE_WRAP_S,m.REPEAT),m.texParameteri(m.TEXTURE_2D,
m.TEXTURE_WRAP_T,m.REPEAT)):(m.texParameteri(m.TEXTURE_2D,m.TEXTURE_WRAP_S,m.CLAMP_TO_EDGE),m.texParameteri(m.TEXTURE_2D,m.TEXTURE_WRAP_T,m.CLAMP_TO_EDGE));return c}function N(b){var c=m.createFramebuffer();m.bindFramebuffer(m.FRAMEBUFFER,c);m.framebufferTexture2D(m.FRAMEBUFFER,m.COLOR_ATTACHMENT0,m.TEXTURE_2D,b,0);return c}
function K(b,c){var d=m.createProgram(),t=V(b,m.VERTEX_SHADER),C=V(c,m.FRAGMENT_SHADER);if(t==e||C==e)return e;m.attachShader(d,t);m.attachShader(d,C);m.deleteShader(t);m.deleteShader(C);m.linkProgram(d);return!m.getProgramParameter(d,m.LINK_STATUS)?(O("Error "+m.getProgramParameter(o,m.VALIDATE_STATUS)+"\n"+m.getError()),e):d}
function V(b,c){var d=m.createShader(c);m.shaderSource(d,b);m.compileShader(d);return!m.getShaderParameter(d,m.COMPILE_STATUS)?(O("Error with "+(c==m.VERTEX_SHADER?"VERTEX":"FRAGMENT")+" SHADER\n"+m.getShaderInfoLog(d)),e):d}function O(b){var c=document.createElement("p");c.textContent=b;p.appendChild(c)}
function I(){requestAnimFrame();if(n){m.viewport(0,0,i,j);m.useProgram(n);m.bindFramebuffer(m.FRAMEBUFFER,u[w]);m.bindBuffer(m.ARRAY_BUFFER,r);m.vertexAttribPointer(n.a,r.b,m.FLOAT,f,0,0);m.activeTexture(m.TEXTURE0);m.bindTexture(m.TEXTURE_2D,s[v]);m.uniform1i(n.c,0);m.uniform1f(n.d,z);m.uniform1f(n.e,A);var b=v;v=w;w=b;m.activeTexture(m.TEXTURE1);m.bindTexture(m.TEXTURE_2D,s[H]);D?(m.pixelStorei(m.UNPACK_FLIP_Y_WEBGL,a),m.texImage2D(m.TEXTURE_2D,0,m.RGBA,i,j,0,m.RGBA,m.UNSIGNED_BYTE,new Uint8Array(B)),
B=G.slice(),E=a,D=f):E&&(m.pixelStorei(m.UNPACK_FLIP_Y_WEBGL,a),m.texImage2D(m.TEXTURE_2D,0,m.RGBA,i,j,0,m.RGBA,m.UNSIGNED_BYTE,new Uint8Array(B)),E=f);m.uniform1i(n.f,1);m.bindBuffer(m.ARRAY_BUFFER,q);m.vertexAttribPointer(n.position,q.b,m.FLOAT,f,0,0);m.drawArrays(m.TRIANGLE_STRIP,0,q.count);m.flush()}o&&(m.viewport(0,0,l.width,l.height),m.useProgram(o),m.bindFramebuffer(m.FRAMEBUFFER,e),m.bindBuffer(m.ARRAY_BUFFER,r),m.vertexAttribPointer(o.a,r.b,m.FLOAT,f,0,0),m.activeTexture(m.TEXTURE0),m.bindTexture(m.TEXTURE_2D,
s[v]),m.uniform1i(o.c,0),m.bindBuffer(m.ARRAY_BUFFER,q),m.vertexAttribPointer(o.position,q.b,m.FLOAT,f,0,0),m.drawArrays(m.TRIANGLE_STRIP,0,q.count),m.flush());x++}function R(){var b=(new Date).getTime(),c=Math.round(1E3*x/(b-y));x=0;y=b;k.textContent="fps: "+c};
window.onload = window.init;
    </script>

