import requests
from bs4 import BeautifulSoup
import os 
import re

headers = {'User-Agent' : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/129.0.0.0 Safari/537.36'}

folder_path = os.path.dirname(os.path.realpath(__file__))
files = os.listdir(folder_path)
pattern = re.compile(r'^(\d+)\.cpp$')

for fileName in files : 
    match = pattern.match(fileName)
    if (match) :
        url = 'https://www.acmicpc.net/problem/' + (str(fileName))[:-4]
        data = requests.get(url, headers=headers)

        soup = BeautifulSoup(data.text, 'html.parser')

        old_file_path = os.path.join(folder_path, fileName)

        title = str(soup.find('title'))

        title = title.replace("번: ", '_')

        new_file_name = ((title)[7:-8] + '.cpp').replace(' ', '_')

        if any(c in new_file_name for c in '\\/:*?"<>|'):
            print(new_file_name)
            print("문자열에 금지된 문자가 포함되어 있습니다.")
            continue

        if new_file_name != fileName:
            print(f"Renamed '{fileName}' to '{new_file_name}'")
            
        new_file_path = os.path.join(folder_path, new_file_name)
        os.rename(old_file_path, new_file_path)
        # print(old_file_path, '\n', new_file_path)