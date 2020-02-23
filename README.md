GUNTANK01-PROJECT
- ラズパイでガンタンクを動かすプロジェクト

# 1.GUNTANKプロジェクトのインストール
当ソースプログラムをgit cloneする。
```
$ cd
$ git clone https://github.com/nevernothingjp/guntank01.git
```

# 2.カメラの設定
## 2-1.標準カメラの接続

- ラズパイの標準カメラをラズパイ本体に接続する。
- raspi-configでカメラを有効にする。
- ラズパイを起動しカメラが使用できる状態か調べる。
```
vcgencmd get_camera
```
を実行する。
```
supported=1 detected=1
```
と表示されればカメラは使用できる。

## 2-2.ストリーミングアプリ
mjpg-streamerをラズパイ標準カメラで使用できるようにしたmjpg-streamer-experimentalを使う。

### インストールの仕方
```
$ sudo apt-get install libjpeg9-dev cmake
$ git clone http://github.com/jacksonliam/mjpg-streamer.git mjpg-streamer
$ cd mjpg-streamer/mjpg-streamer-experimental
$ make
$ cd
$ sudo mv mjpg-streamer/mjpg-streamer-experimental /opt/mjpg-streamer
```

### ストリーミングアプリの自動起動
/etc/rc.local の最後の exit 0 の前に以下を挿入する。
```
sh /home/ユーザ名/guntank01/stream/stream_start.sh
```

カメラ画像は
```
http://ラズパイのアドレス:8010/
```
で視ることができる。

ストリーミングを停止させる場合は
```
sh /home/ユーザ名/guntank01/stream/stream_stop.sh
```
を実行する。

# 3.WebIOPiのインストール
```
$ wget https://sourceforge.net/projects/webiopi/files/WebIOPi-0.7.1.tar.gz
$ tar zxvf WebIOPi-0.7.1.tar.gz
$ cd WebIOPi-0.7.1/
$ wget https://raw.githubusercontent.com/doublebind/raspi/master/webiopi-pi2bplus.patch
$ patch -p1 -i webiopi-pi2bplus.patch
$ sudo ./setup.sh
```
Do you want to access WebIOPi over Internet ? [y/n]と聞いてきたら「n」と応える。

```
$ sudo vi /etc/webiopi/config
```

以下の編集をする。

```
(略)
myscript = /home/ユーザ名/guntank01/app/guntank.py
(略)
port = 8030
(略)
doc-root = /home/ユーザ名/guntank01/html
(略)
welcome-file = index.html
```

自動起動するようにする。
```
$ sudo systemctl enable webiopi.service
```

ラズパイを再起動する。

ブラウザで
```
http://ラズパイのアドレス:8030/
```
を開き動作確認をする。











