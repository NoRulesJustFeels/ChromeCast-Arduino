ChromeCast-Arduino
==================

<p><img src="http://chromecast.entertailion.com/chromecastanimation100.gif"/></p>

<p>This Arduino sketch allows you to send YouTube videos to a <a href="https://www.google.com/intl/en/chrome/devices/chromecast/">ChromeCast</a> device when a motion sensor is triggered.</p>

<p>This sketch requires an Arduino Ethernet shield and a <a href="http://www.ladyada.net/learn/sensors/pir.html">PIR motion sensor</a>.</p>
 
<p>To customize this sketch for your own YouTube video:
<ol>
<li>Determine the IP address of your ChromeCast device and change the chromecast variable value in the sketch.</li>
<li>Get the YouTube ID from the web site. It will be the URL parameter value after "v" (e.g. for http://www.youtube.com/watch?v=GWXLPu8Ky9k, v is "GWXLPu8Ky9k").</li>
<li>Put the YouTube ID in the youtube variable value.</li>
</ol>
</p>

<p>Use the Arduino IDE to upload the code onto an Arduino device. The code currently only loads the video once after the motion sensor is triggered, but it can easily be modified to trigger repeatedly.</p>

<p>Watch this <a href="http://youtu.be/p001_m73-5I">video</a> to see the sketch in action.</p>

<p>Other apps developed by Entertailion:
<ul>
<li><a href="https://github.com/entertailion/Fling">Fling</a>: Share local media files with a ChromeCast device</li>
<li><a href="https://play.google.com/store/apps/details?id=com.entertailion.android.tvremote">Able Remote for Google TV</a>: The ultimate Google TV remote</li>
<li><a href="https://play.google.com/store/apps/details?id=com.entertailion.android.launcher">Open Launcher for Google TV</a>: The ultimate Google TV launcher</li>
<li><a href="https://play.google.com/store/apps/details?id=com.entertailion.android.overlay">Overlay for Google TV</a>: Live TV effects for Google TV</li>
<li><a href="https://play.google.com/store/apps/details?id=com.entertailion.android.overlaynews">Overlay News for Google TV</a>: News headlines over live TV</li>
<li><a href="https://play.google.com/store/apps/details?id=com.entertailion.android.videowall">Video Wall</a>: Wall-to-Wall Youtube videos</li>
<li><a href="https://play.google.com/store/apps/details?id=com.entertailion.android.tasker">GTV Tasker Plugin</a>: Control your Google TV with Tasker actions</li>
</ul>
</p>
