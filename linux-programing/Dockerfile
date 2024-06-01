# Dockerfile
FROM ubuntu:latest

# 環境変数の設定
ENV DEBIAN_FRONTEND=noninteractive

# 基本的なパッケージのインストール
RUN apt-get update && apt-get install -y \
    software-properties-common \
    build-essential \
    python3 \
    python3-pip \
    git \
    curl

# 作業ディレクトリの設定
WORKDIR /workspace

# コンテナ起動時に実行するコマンド
CMD ["bash"]
