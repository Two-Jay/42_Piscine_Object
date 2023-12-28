#!/bin/bash

# 매개변수 확인
if [ "$#" -ne 2 ]; then
    echo "사용법: $0 [목표 경로] [새 폴더 이름]"
    exit 1
fi

# 매개변수 저장
DEST_PATH=$1
NEW_FOLDER_NAME=$2

# template 폴더가 있는지 확인
if [ ! -d "template" ]; then
    echo "현재 경로에 'template' 폴더가 없습니다."
    exit 1
fi

# 목표 경로에 동일한 이름의 폴더/파일이 있는지 확인
if [ -e "$DEST_PATH/$NEW_FOLDER_NAME" ]; then
    echo "'$DEST_PATH/$NEW_FOLDER_NAME'에 이미 파일이나 폴더가 존재합니다."
    exit 1
fi

# 복사 실행
cp -r template "$DEST_PATH/$NEW_FOLDER_NAME"
chmod -R 744 "$DEST_PATH/$NEW_FOLDER_NAME"

# 완료 메시지
echo "'template' 폴더가 '$DEST_PATH/$NEW_FOLDER_NAME'으로 복사되었습니다."
