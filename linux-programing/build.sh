#!/bin/bash

# プロジェクトの特定ディレクトリ (/workspaces/linux) を指定
TARGET_DIR="/workspaces/linux"

# コンパイルするCソースファイルのパス
SOURCE_FILE=$1

# ビルドするディレクトリ
BUILD_DIR="$TARGET_DIR/build"

# ソースファイルのベース名 (拡張子なし)
BASE_NAME=$(basename "$SOURCE_FILE" .c)

# 出力ファイルのパス
OUTPUT_FILE="$BUILD_DIR/$BASE_NAME"

# ビルドディレクトリが存在しない場合は作成
if [ ! -d "$BUILD_DIR" ]; then
  mkdir -p "$BUILD_DIR"
fi

# コンパイルコマンド
gcc "$SOURCE_FILE" -o "$OUTPUT_FILE"

# 結果の確認
if [ $? -eq 0 ]; then
  echo "Build successful: $OUTPUT_FILE"
else
  echo "Build failed"
fi
