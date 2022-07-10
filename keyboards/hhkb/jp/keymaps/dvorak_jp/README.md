# Keymaps with both Dvorak layout and QWER layout for HHKB JP.
> This keymap was forked from "sh_jp", and arranged by ywake.

1. The default layout is Dvorak.
1. Use this keymap as us(ansi) keyboard.
2. Use `Tog` to toggle between Dvorak and QWER
3. Holding `Cmd`, will activate the `NewCmd` layer which means `NewCmd+key` is the same as `Cmd+key` in normal QWER layout.<sup>[1](#cmdTab)</sup>
  - For example, no matter you are in Dvorak layout or QWER layout, you can use `Cmd+s` to save a currently editing file.
4. The same also applies to `Ctrl`.
5. `Spc+key` equals to `LShft+key` while using `Spc` alone will yield a space as usual. (AKA SandS)
6. There's an extra `Tab` in the last line.

## How to install
```
make hhkb/jp:dvorak_jp:dfu
```
or
```
qmk compile -kb hhkb/jp -km dvorak_jp
```

## Layout
```
Layer DVOR:
,-----------------------------------------------------------.
|Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  :|  ^|  ¥|Del|
|-----------------------------------------------------------|
|Tab  |  @|  ,|  .|  P|  Y|  F|  G|  C|  R|  L|  ;|  [|     |
|------------------------------------------------------` Ent|
|Ctrl  |  A|  O|  E|  U|  I|  D|  H|  T|  N|  S|  -|  ]|    |
|-----------------------------------------------------------|
|LShft  |  /|  Q|  J|  K|  X|  B|  M| W|  V|  Z|  _| Up|RSft|
|-----------------------------------------------------------|
|FN||Tog|Cmd|Alt|Ctr+Spc|  Spc  |Ent|Bsp|Alt|FN||Lft|Dwn|Rgh|
`-----------------------------------------------------------'
```

```
Layer QWER:
,-----------------------------------------------------------.
|Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  ^|  ¥|Del|
|-----------------------------------------------------------|
|Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  @|  [|     |
|------------------------------------------------------` Ent|
|Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  ]|    |
|-----------------------------------------------------------|
|Shft   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  _| Up|Sft|
|-----------------------------------------------------------|
|FN||Tog|Cmd|Alt|Ctr+Spc|  Spc  |Ent|Bsp|Alt|FN||Lft|Dwn|Rgh|
`-----------------------------------------------------------'
```

```
Layer FUNC: HHKB mode (HHKB Fn)
,-----------------------------------------------------------.
|Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
|-----------------------------------------------------------|
|Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   |     |
|------------------------------------------------------`    |
|      |VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig|   |    |
|-----------------------------------------------------------|
|       |   |   |   |   |   |  +|  -|End|PgD|Dow|   |   |   |
|-----------------------------------------------------------|
|   ||   |   |   |   |         |   |   |   |   ||   |   |   |
`-----------------------------------------------------------'
```
<!--
```
Empty Layer:
,-----------------------------------------------------------.
|   |   |   |   |   |   |   |   |   |   |  |   |   |   |    |
|-----------------------------------------------------------|
|     |   |   |   |   |   |   |   |   |   |   |   |   |     |
|------------------------------------------------------`    |
|      |   |   |   |   |   |   |   |   |   |   |   |   |    |
|-----------------------------------------------------------|
|       |   |   |   |   |   |   |   |   |   |   |   |   |   |
|-----------------------------------------------------------|
|  |  |    |      |    |       |    |   |   |   |   |   |   |
`-----------------------------------------------------------'
```
-->
<a name="cmdTab">1</a>: `NewCmd + Tab` does not work, you can use `RCmd+Tab` to switch among applications.
