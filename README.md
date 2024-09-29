# c-yasunori-lang


# Spec

```
1. `y` ポインタをインクリメントする。ポインタをptrとすると、C言語の「ptr++;」に相当する。
2. `a` ポインタをデクリメントする。C言語の「ptr--;」に相当。
3. `s` ポインタが指す値をインクリメントする。C言語の「(*ptr)++;」に相当。
4. `u` ポインタが指す値をデクリメントする。C言語の「(*ptr)--;」に相当。
5. `n` ポインタが指す値を出力に書き出す。C言語の「putchar(*ptr);」に相当。
6. `o` 入力から1バイト読み込んで、ポインタが指す先に代入する。C言語の「*ptr=getchar();」に相当。
7. `r` ポインタが指す値が0なら、対応する `i` の直後にジャンプする。C言語の「while(*ptr){」に相当。
8. `i` ポインタが指す値が0でないなら、対応する `r` （の直後）にジャンプする。C言語の「}」に相当。
```
by takeokunn at vim-jp Slack


# Example

Get some brainf*ck code.


```
$ cat > sample/helloworld.bf
++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.
```

`yasunorize` it.

```
cat sample/helloworld.bf | ./yasunorize > sample/helloworld.ys
```

Compile.

```
make yasunori
```

Run.

```
$ ./yasunori sample/helloworld.ys
Hello World!
```


# Nix

- `nix fmt`: format files
- `nix build`: build; `result/bin/yasunori` and `yasunorize` is the executable
- `nix shell`: enter shell
