---
layout: post
title: Google indexing github page
date: 2020-12-06 20:30
---

I'm using [Pixyll](https://github.com/johno/pixyll) to deploy [my github page](https://amoskong.github.io/).
A /sitemap.xml in root directory is generated automatically, and it's added to /robots.txt.
So I only need to submit the sitemap to Google.

[Documentications] Build sitemap and submit it to Google

- [https://developers.google.com/search/docs/advanced/sitemaps/build-sitemap](https://developers.google.com/search/docs/advanced/sitemaps/build-sitemap)
- [Advance SEO: https://developers.google.com/search/docs/advanced/crawling/ask-google-to-recrawl](https://developers.google.com/search/docs/advanced/crawling/ask-google-to-recrawl)

## Simply way to get your site to be indexed by Google

- Use the exiting sitemap or build the sitemap by yourself
- Add the sitemap to robots.txt
	  - `Sitemap: https://amoskong.github.io/sitemap.xm`
- Submit the sitemap by ping tool
	  - [https://www.google.com/ping?sitemap=https://amoskong.github.io/sitemap.xml](https://www.google.com/ping?sitemap=https://amoskong.github.io/sitemap.xml)
- You can also submit the sitemap by [https://search.google.com/search-console](https://search.google.com/search-console)
	- Add your site as a property
	- Download a verify file and upload to your site
	- Verify your site in Google Search Console
	- Submit your sitemap: [https://search.google.com/search-console/sitemaps](https://search.google.com/search-console/sitemaps)

![add_your_site_as_a_property.png](/images/add_your_site_as_a_property.png)
![verify_site_in_google_search_console.png](/images/verify_site_in_google_search_console.png)

