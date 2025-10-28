# import requests
# from bs4 import BeautifulSoup
# import os 
# import re

# headers = {'User-Agent' : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/129.0.0.0 Safari/537.36'}

# folder_path = os.path.dirname(os.path.realpath(__file__))
# files = os.listdir(folder_path)
# pattern = re.compile(r'^(\d+)\.cpp$')

# for fileName in files : 
#     match = pattern.match(fileName)
#     if (match) :
#         url = 'https://www.acmicpc.net/problem/' + (str(fileName))[:-4]
#         data = requests.get(url, headers=headers)

#         soup = BeautifulSoup(data.text, 'html.parser')

#         old_file_path = os.path.join(folder_path, fileName)

#         title = str(soup.find('title'))

#         title = title.replace("번: ", '_')

#         new_file_name = ((title)[7:-8] + '.cpp').replace(' ', '_')

#         if any(c in new_file_name for c in '\\/#:*?!"<>|'):
#             print(new_file_name)
#             print("문자열에 금지된 문자가 포함되어 있습니다.")
#             continue

#         if new_file_name != fileName:
#             print(f"Renamed '{fileName}' to '{new_file_name}'")
            
#         new_file_path = os.path.join(folder_path, new_file_name)
#         os.rename(old_file_path, new_file_path)
#         # print(old_file_path, '\n', new_file_path)

#!/usr/bin/env python3
import argparse
import os
import re
from pathlib import Path

PATTERN = re.compile(r'^(\d+)(?:_(.+))?\.cpp$')  # 그룹1: 숫자, 그룹2: '_' 뒤 문자열(있을 수도 있음)

def plan_changes(directory: Path):
    changes = []
    for entry in directory.iterdir():
        if not entry.is_file():
            continue
        m = PATTERN.fullmatch(entry.name)
        if not m:
            continue
        num, tail = m.group(1), m.group(2)
        # 규칙 1: (정수).cpp 는 그대로
        if tail is None:
            continue
        # 규칙 2: (정수)_(...) .cpp -> (정수).cpp
        target = directory / f"{num}.cpp"
        if target == entry:
            continue
        # 덮어쓰기 방지: 이미 존재하면 스킵하도록 표시
        if target.exists():
            changes.append((entry, target, "skip_exists"))
        else:
            changes.append((entry, target, "rename"))
    return changes

def main():
    parser = argparse.ArgumentParser(
        description="Rename *.cpp files: 'NNN_xxx.cpp' -> 'NNN.cpp' (no overwrite)"
    )
    parser.add_argument(
        "-d", "--dir", default=".", help="작업할 디렉터리 (기본: 현재 디렉터리)"
    )
    parser.add_argument(
        "--apply", action="store_true", help="실제 변경 적용 (기본은 드라이런)"
    )
    args = parser.parse_args()

    directory = Path(args.dir).resolve()
    if not directory.exists() or not directory.is_dir():
        print(f"[에러] 디렉터리를 찾을 수 없습니다: {directory}")
        return

    changes = plan_changes(directory)

    if not changes:
        print("변경 대상 파일이 없습니다.")
        return

    print(f"대상 디렉터리: {directory}")
    for src, dst, action in changes:
        if action == "rename":
            print(f"RENAME  : {src.name}  ->  {dst.name}")
        elif action == "skip_exists":
            print(f"SKIP    : {src.name}  ->  {dst.name} (이미 존재하여 건너뜀)")

    if not args.apply:
        print("\n드라이런 모드입니다. 실제로 변경하려면 --apply 옵션을 추가하세요.")
        return

    # 실제 적용
    applied = 0
    skipped = 0
    for src, dst, action in changes:
        if action == "rename":
            try:
                os.rename(src, dst)  # 같은 파일시스템 내 안전함
                applied += 1
            except OSError as e:
                print(f"[에러] {src.name} -> {dst.name} 실패: {e}")
        else:
            skipped += 1

    print(f"\n완료: 변경 {applied}개, 건너뜀 {skipped}개")

if __name__ == "__main__":
    main()
