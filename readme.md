# QK Judge

[QK Judge](https://judge.tqk.blue)

ここは問題 サーバー: [qkjudge](https://github.com/tqkoh/qkjudge) クライアント: [qkjudge-UI](https://github.com/tqkoh/qkjudge-UI)


### 問題追加/更新について メモ

- dist ブランチを更新すると自動で更新される
- `qkjudge.yaml` に問題のパスのリストを書く
- `{problem}/problem.yaml` にタイトルなどの情報書く
- `{problem}/in/{nanka}.in` , `{problem}/out/{nanka}.in` にテストケースを入れる

rime を使ってる ディレクトリ構造は CPCTF 式 手元の操作↓

問題更新 たしかこんな感じ:

同じ感じで statement, generator, validator, solution などを書く<br>
rime test でテストケースが生成される<br>

```
{problem}$ rime test
{problem}$ python3 ../pack.py
```

デプロイ

```
$ source deploy.sh
```

なぜか用意されてるスクリプトが python と bash ...
