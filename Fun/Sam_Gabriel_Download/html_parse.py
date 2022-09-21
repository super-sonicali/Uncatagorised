import re

import requests
from bs4 import BeautifulSoup


vgm_url = 'http://samgabrielvo.com'
html_text = requests.get(vgm_url).text
soup = BeautifulSoup(html_text, 'html.parser')
links_list = []
for link in soup.find_all('a'):
    links_list.append(link.get('href'))

uberlist = []
casts = []
feeds = []
categories = []
not_casts = []

for item in links_list:
    if "samgabrielvo.com" in str(item):
        if "https" in str(item):
           item = "http"+item.split("https")[1]
        if "www" not in str(item):
            item = item.split("//")[0]+"//www."+item.split("//")[1]
        if "casts" in str(item):
            if ".mp3" in str(item):
               print(item)
               item=item.rpartition('/')[0]
            if item[-1] != "/":
                item = item +"/"
            if item not in casts:
                casts.append(item)
        elif "feed" in str(item):
            if item not in feeds:
                feeds.append(item)
        elif "category" in str(item):
            if item not in categories:
                categories.append(item)
        else:
            not_casts.append(item)

print("\n\nCasts:")
[print(x) for x in casts]
print("\n\nFeeds:")
[print(x) for x in feeds]
print("\n\nCategories:")
[print(x) for x in categories]
print("\n\nOther:")
[print(x) for x in not_casts]


vgm_url = 'http://samgabrielvo.com/misc'
html_text = requests.get(vgm_url).text
soup = BeautifulSoup(html_text, 'html.parser')
links_misc = []

for link in soup.find_all('a'):
    links_misc.append(link.get('href'))

misc_folders = []
misc_zips = []
misc_audio = []
misc_video = []
misc_other = []

for item in links_misc:
    if "/" in str(item):
        item = 'http://www.samgabrielvo.com/misc/'+item
        misc_folders.append(item)
    elif ".zip" in item or ".rar" in item:
        misc_zips.append(item)
    elif ".wav" in item or ".mp3" in item:
        misc_audio.append(item)
    else:
        misc_other.append(item)

print("\n\nMisc Folders:")
[print(x) for x in misc_folders]
print("\n\nMisc Archives:")
[print(x) for x in misc_zips]
print("\n\nMisc Audio:")
[print(x) for x in misc_audio]
print("\n\nMisc Other:")
[print(x) for x in misc_other]
   
