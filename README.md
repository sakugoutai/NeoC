# NeoC
Neo C Programming Environment Library

![](https://user-images.githubusercontent.com/85844095/125081210-b6ea7380-e100-11eb-9f34-0871e29de9cc.png)
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;__↑↑↑ examples/Theme.c ↑↑↑__

&emsp;&emsp;&emsp;__↓↓↓ Sample Code (examples/SampleCode.c) ↓↓↓__
```C
#include <NeoC.h>

void main() $_ {
   String_t *text = String.New(u8"NeoC is a Neo C Programming Environment Library !");
   Console.WriteLine(text);

   uint8_t target = 'i';
   try {
      defer {
         Map_t *map = Map.New() in (String_t *, Int32_t *);

         map->Put(map, String.New(u8"NeoC!    "), Int32.New(1));
         map->Put(map, String.New(u8"NeoC!!!  "), Int32.New(3));
         map->Put(map, String.New(u8"NeoC!!!!!"), Int32.New(5));

         for (int32_t i = 0; i < map->GetLength(map); i++) {
            Console.WriteLine(String.NewFormat(
               u8"%s : %s",
               String.Unpack( map->Get(map, i).Key ),
               Int32.GetExpr( map->Get(map, i).Value )
            ));
         }
      } set

      defer {
         Console.WriteLine(text);
         Console.NewLine();
      } set

      execute {
         int32_t fi = String.FirstIndexOf(text, target);
                   // text->FirstIndexOf(text, target);
         int32_t li = text->LastIndexOf(text, target);
                   // String.LastIndexOf(text, target);

         for (int32_t i = 0; i < String.GetLength(text); i++) {
            Console.WriteChar((i == fi || i == li)? '^' : ' ');
            System.USleep(50 * 1000);
         }
         Console.NewLine();
      } ret
   } catch (String.Failure) {
      Console.WriteErrorLine(String.NewFormat(u8"Target character '%c' not found.", target));
   } fin
} _$
```
<br><br>

## Build
Dependencies: **`Git` `CMake` `GNU Make` `GCC`**
<br><br>

### 1. NeoC Library
```fish
             $ git clone https://github.com/RotationE/NeoC.git
             $ cd NeoC
      [NeoC/]$ mkdir build
      [NeoC/]$ cd build
[NeoC/build/]$ cmake ..
[NeoC/build/]$ cmake .. -DCMAKE_C_COMPILER=/usr/bin/gcc # GCCの使用を明示
[NeoC/build/]$ cmake .. -DNEOC_BUILD_SHARED_LIBS=ON # 共有ライブラリとして出力
[NeoC/build/]$ cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$HOME/.local # インストール場所の指定
[NeoC/build/]$ make -j
```
**→ `NeoC/include/` `NeoC/build/lib/libNeoC.a`**
<br><br><br>

### 2. Examples
```fish
[NeoC/build/]$ make examples -j
```
**→ `NeoC/build/examples/*`**
<br><br><br>

## Clean
```fish
[NeoC/build/]$ make clean
```
<br><br>

## Usage
### 一時凌ぎの場合
```fish
$ gcc -Ipath-to-NeoC-include-directory -Lpath-to-NeoC-archive-file -lNeoC -lpthread Source.c -o Exec
```
**→** `./Exec`
<br><br>

## License
&emsp;[`AGPLv3`](https://www.gnu.org/licenses/agpl-3.0.html)
