# RakuRakuFormat  
楽々フォーマットくん、略して楽フォーくんです。PTAだったりのプリントのマークアップ言語もどきです。  
## 概要
このフォーマットシステムは文法に沿ったテキストファイルを整形済みのHTMLに変換するものです。  
HTMLはワードなどでPDFに変換してください。  
(ワード等で見た際にHTMLの表示が崩れている場合がありますが仕様です)  
## 使い方  
1. 「入力.txt」と言う名前で文法通りのテキストを書く。
2. 「入力.txt」をこのシステムのフォルダに入れる。
3. exeファイルをダブルクリックして実行する。(linuxはコマンドラインから)
4. 「出力.html」というファイルができているので、ワードでPDFに変換する。
## 文法
このシステムは基本的に各行の最初の2文字を使って文書のフォーマットをします。  
現時点では以下の機能が実装されています。  
- 機能 : 最初の2文字
- タイトル : ##
- 発行人 : >>
- 宛先 : <<
- 箇条書き : --
- マクロ : $$[マクロ名(4文字)]
- 本文 : なし

書き方の例です:  

##コレがタイトルになります  
\>\>コレが発行人です  
<<宛先です  
$$TIME  
ここが本文になります  

## ダウンロード
やっとまともに動くようになったのでこちらです
https://github.com/mdc-Sirasera/RakuRakuFormat/releases/latest

## 動作環境(予定)
Windows 7,8,10 (64bit)  
Linux
