import re
import time
import os
import requests
from bs4 import BeautifulSoup


# def get_links(vgm_url):
#     html_text = requests.get(vgm_url).text
#     soup = BeautifulSoup(html_text, 'html.parser')
#     links_list = []
#     for link in soup.find_all('a'):
#         links_list.append(link.get('href'))
#
#     [print(x) for x in links_list]
#     return links_list


def main_sort():
    """
    gets links from
    :return:
    """
    vgm_url = 'http://www.samgabrielvo.com/'
    html_text = requests.get(vgm_url).text
    soup = BeautifulSoup(html_text, 'html.parser')
    links_list = []
    for link in soup.find_all('a'):
        links_list.append(link.get('href'))

    casts = []
    feeds = []
    categories = []
    not_casts = []
    # uberlist = [casts, feeds, categories, not_casts]

    for item in links_list:
        if vgm_url in str(item):
            if "https" in str(item):
                item = "http" + item.split("https")[1]
            if "www" not in str(item):
                item = item.split("//")[0] + "//www." + item.split("//")[1]
            if "casts" in str(item):
                if ".mp3" in str(item):
                    print(item)
                    item = item.rpartition('/')[0]
                    print(item)
                if item[-1] != "/":
                    item = item + "/"
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

    # [print(x) for x in uberlist]

    write_links(casts, "wanted_files.txt")


def misc_sort():
    """
    sorts through /misc and groups files by type, writing them to file
    :return:
    """
    vgm_url = 'http://www.samgabrielvo.com/misc'
    html_text = requests.get(vgm_url).text
    soup = BeautifulSoup(html_text, 'html.parser')
    links_misc = []

    for link in soup.find_all('a'):
        links_misc.append(link.get('href'))

    # def misc_sort(links_misc):

    misc_folders = []
    misc_zips = []
    misc_audio = []
    misc_video = []
    misc_images = []
    misc_files = []
    misc_reaper = []
    misc_other = []
    uberlist = [misc_audio, misc_video, misc_images, misc_files]
    uberlist_names = ["misc_audio", "misc_video", "misc_images", "misc_files"]

    for item in links_misc: # sorts based on file type
        if "/" in str(item):
            if item != "/":
                item = 'http://www.samgabrielvo.com/misc/' + item
                misc_folders.append(item[:-1])
        elif ".zip" in item or ".rar" in item:
            misc_zips.append(item)
        elif ".wav" in item or ".mp3" in item:
            misc_audio.append(item)
        elif ".mov" in item or ".mp4" in item or ".avi" in item:
            misc_video.append(item)
        elif ".RfxChain" in item or ".rpp" in item or ".pk" in item:
            misc_reaper.append(item)
        elif ".png" in item or ".jpg" in item:
            misc_images.append(item)
        elif ".txt" in item or ".pdf" in item or ".odt" in item or ".rtf" in item:
            misc_files.append(item)
        else:
            misc_other.append(item)

    print("\n\nMisc Folders:")
    [print(x) for x in misc_folders]
    print("\n\nMisc Archives:")
    [print(x) for x in misc_zips]
    print("\n\nMisc Audio:")
    [print(x) for x in misc_audio]
    print("\n\nMisc Images:")
    [print(x) for x in misc_images]
    print("\n\nMisc Files:")
    [print(x) for x in misc_files]
    print("\n\nMisc Video:")
    [print(x) for x in misc_video]
    print("\n\nMisc Other:")
    [print(x) for x in misc_other]

    write_links(misc_folders, "misc_folders.txt")

    for k in uberlist:
        write_links_expand(k, "wanted_files_misc.txt", vgm_url)



def art_sort():
    """
    gets art urls and writes them to a file
    :return:
    """
    vgm_url = 'http://samgabrielvo.com/coverart'
    html_text = requests.get(vgm_url).text
    soup = BeautifulSoup(html_text, 'html.parser')
    links_art = []
    art = []

    for link in soup.find_all('a'):
        links_art.append(link.get('href'))

    for j in links_art:
        if "g" in j:
            art.append(j)

    write_links_expand(art, "coverart.txt", vgm_url)


def misc_sub_dir_magic(infile):
    """
    gets list of folders from file and iterates the urls and writes them to a file
    :param infile:
    :return:
    """
    with open('misc_folders.txt') as f:
        links = f.readlines()
        if not os.path.exists("misc"):
            os.mkdir("misc")
        for i in links:
            vgm_url = str(i[:-1])
            html_text = requests.get(vgm_url).text
            soup = BeautifulSoup(html_text, 'html.parser')
            links_art = []
            links_art2 = []

            for link in soup.find_all('a'):
                links_art.append(link.get('href'))

            print(f"{vgm_url.split('/')[4]}.txt")
            print("url: " + vgm_url)
            for thingy in links_art:
                if thingy[-1] == "/" and thingy != "/misc/":
                    print(thingy)
                    html_text = requests.get(vgm_url + "/" + str(thingy)).text
                    soup = BeautifulSoup(html_text, 'html.parser')
                    for link2 in soup.find_all('a'):
                        # print(link2.get('href'))
                        links_art2.append(link2.get('href'))
                    for item in links_art2:
                        if "." in str(item):
                            with open(f"misc/{vgm_url.split('/')[4]}.txt", "a") as f2:
                                f2.write(str(vgm_url) + "/" + str(thingy) + str(item) + "\n")
                            print("/" + str(thingy) + item)
                    print(links_art2)
                if "." in str(thingy):
                    with open(f"misc/{vgm_url.split('/')[4]}.txt", "a") as f2:
                        f2.write(str(vgm_url) + "/" + str(thingy) + "\n")
                    print(str(thingy))

            # print(links_art)


def write_links(link_list, file_name):
    with open(file_name, "a") as f:
        f.writelines("%s\n" % l for l in link_list)


def write_links_expand(link_list, file_name, url):
    with open(file_name, "a") as f:
        f.writelines(f"{url}/%s\n" % l for l in link_list)


def download_files(infile):
    """
    gets list of urls from a file and downloads them
    :param infile: input file
    :return: s: list of times in seconds
    """
    s = []
    with open(infile, "r") as f:
        k = f.readlines()
    # print(k)
    # print(str(infile).split(".")[0].split("/")[-1])
    if str(infile).split(".")[0].split("/")[-2] == "misc":
        folder = str(infile).split(".")[0].split("/")[-2]+"/"+str(infile).split(".")[0].split("/")[-1]
    else:
        folder = str(infile).split(".")[0].split("/")[-1]
    if not os.path.exists(folder):
        os.mkdir(folder)
    for i in k:
        download_url = str(i[:-1])
        # print(f"{download_url.rsplit('/')[-1]}")
        print(f"{download_url.rsplit('/')[-1]}")
        time_s_2 = time.time()
        r = requests.get(download_url, allow_redirects=True)
        with open(f"{folder}/{download_url.rsplit('/')[-1]}", 'wb+') as f2:
            f2.write(r.content)
        time_e_2 = time.time()
        times = time_e_2 - time_s_2
        print(times)
        s.append(times)
    return s


def get_cast_urls(infile):
    """
    gets list of urls to download and writes them to a file
    :param infile: input file
    :return:
    """
    with open(infile, "r") as f:
        links = f.readlines()
        if not os.path.exists("casts"):
            os.mkdir("casts")
        for i in links:
            vgm_url = str(i[:-1])
            print(vgm_url)
            html_text = requests.get(vgm_url).text
            soup = BeautifulSoup(html_text, 'html.parser')
            links_art = []

            for link in soup.find_all('a'):
                links_art.append(link.get('href'))

            print(f"{vgm_url.split('/')[3]}.txt")
            print("url: " + vgm_url)
            for thingy in links_art:
                if "." in str(thingy): # files only
                    with open(f"casts/{vgm_url.split('/')[3]}.txt", "a") as f2:
                        f2.write(str(vgm_url) + "/" + str(thingy) + "\n")
                    print(str(thingy))

            # print(links_art)


if __name__ == "__main__":

    # time_s_1=time.time()
    # get os
    # if win
    # if kali
    home_dir = "/home/kali/PycharmProjects/sams_shit" # absolute path to working dir
    target_dir = "www.samgabrielvo.com" # sam's site local location
    if not os.getcwd() == home_dir:
        os.chdir(f"{home_dir}")

    # main_sort()
    # art_sort()
    # misc_sort()
    # sub_dir_magic()
    # get_cast_urls('wanted_files.txt')

    if not os.getcwd() == home_dir+"/"+target_dir: # if not in sam's folder move there
        if not os.path.exists(f"{home_dir}/{target_dir}"): # make sam's folder if it doesn't exist
            os.mkdir(f"{home_dir}/{target_dir}")
        os.chdir(f"{home_dir}/{target_dir}")

    t = download_files(f"{home_dir}/casts/onecasts.txt")
    #
    # # for i in t:
    # #     print(i)
    #
    # time_e_1 = time.time()
    # total = time_e_1 - time_s_1
    # print(total)

