## Xaml-Fasa [50pts]

`A friend of Rafiki... RSS is the magic Word. The flag is located at /opt/flag.txt`

So this is the chall that we got.
First of all the description talk about rss so directly with think about xxe vuln so let try it
First i test a basic xxe injection not to exploit but just to detect

```xml
<!--?xml version="1.0" ?-->
<!DOCTYPE replace [<!ENTITYexample "Doe"> ]>
 <userInfo>
  <firstName>John</firstName>
  <lastName>&example;</lastName>
 </userInfo>
```

![First attempt](img/burp1.png)

We got nothing but the description say rss so let try a real rss flux

```xml
<?xml version="1.0" encoding="UTF-8"?>
<rss version="2.0">
  <channel>
    <title>My Example Blog</title>
    <link>https://www.example.com/blog/</link>
    <description>The latest updates from My Example Blog.</description>
    <language>en-us</language>
    <lastBuildDate>Fri, 08 Nov 2025 20:46:00 +0000</lastBuildDate>
    <generator>Custom RSS Generator</generator>
    <item>
      <title>Second Blog Post</title>
      <link>https://www.example.com/blog/second-post/</link>
      <description>This is the content of my second blog post.</description>
      <pubDate>Wed, 06 Nov 2025 15:30:00 +0000</pubDate>
      <guid isPermaLink="true">https://www.example.com/blog/second-post/</guid>
    </item>

  </channel>
</rss>
```

We can see the result
![Second request with a valid rss format](img/burp2.png)
alright now let inject our payload i think the server display only  the link tag so let see if it's right
![Payload injected](img/burp3.png)

Nice final step let's  try to get the flag

for the moment just check if we can read system file
![System file readed](img/burp4.png)

Very nice and then the flag
![Flag](img/flag1.png)
