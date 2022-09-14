# QK Judge

[QK Judge](https://judge.tqk.blue)

サーバー: [qkjudge](https://github.com/tqkoh/qkjudge)<br>
クライアント: [qkjudge-UI](https://github.com/tqkoh/qkjudge-UI)<br>
問題(:koko:): [qkjudge-problems](https://github.com/tqkoh/qkjudge-problems)<br>

### 問題追加/更新について メモ

rime を使ってる ディレクトリ構造は大体 CPCTF 式

- dist ブランチを更新すると webhook がサーバーに飛び自動で更新される
- `qkjudge.yaml` に問題のパスのリストを書く
- `{problem}/problem.yaml` にタイトルなどの情報書く
- `{problem}/in/{nanka}.in` , `{problem}/out/{nanka}.in` にテストケースを入れる
