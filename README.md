# Octo-Valley-Randomizer-Patches
This repo contains the source code to the patches for my Splatoon 1 Octo Valley randomizer mod, based on my "Gambit Uncranked" modding framework.
> [!IMPORTANT]  
> If you're looking for the randomizer itself, go [here](https://github.com/techmuse8/Octo-Valley-Randomizer) instead.
>
>
## Features
To be written

## Build Instructions
Install [Tachyon](https://github.com/Zenith-Team/Tachyon) (requires [Node.js](https://nodejs.org/) v24+)
```yml
npm i -g --allow-remote=root https://github.com/Zenith-Team/Tachyon/releases/latest/download/tachyon.tgz
```
Build and run the project for your region (example with `US`)
```rb
tachyon pm install
tachyon compile US -X"-Werror"
tachyon launch US
```
> [!NOTE]
`-Werror` is meant to be excluded from the compilation flags until I get around to updating the headers to be C++23 compatiable.

## Credits
- [AboodXD](https://github.com/aboood40091) - Formerly CafeLoader Project Compiler, sead headers, sead decompilation for restoring missing functions, advice, inspiration
- [Zenith Team](https://github.com/Zenith-Team) - [Telkin](https://github.com/Zenith-Team/DynamicLibs/Telkin) for code injection, [Tsuru](https://github.com/Zenith-Team/Tsuru) as a nice reference, sead headers, general inspiration, build instructions
- [Rambo6Glaz](https://github.com/EpicUsername12) - Project structure based on [ctgp-cafe](https://github.com/EpicUsername12/ctgp-cafe), types.h
- [Pirlo](https://twitter.com/0x1CAA9C5C) - Answering some of my questions regarding Splatoon's internals
- [Shadów](https://github.com/shadowninja108) - Author of the GameSceneMemDisp restoration patches which was used as a base for my custom textwriters, documentation
- [open-ead](https://github.com/open-ead/) - sead headers
- [STUPID Modder](https://github.com/stupidestmodder) - sead headers, inspiration
- [Project-Gamblitz](https://github.com/Project-Gamblitz) - Inspiration

## Special Thanks
- [Luminyx](https://github.com/Luminyx1)
- [jhmaster2000](https://github.com/jhmaster2000)
- [Swiftshine](https://github.com/Swiftshine)
- [Fruityloops](https://github.com/fruityloops1)
- AboodXD
- [Archipelago Discord Server](https://discord.gg/8Z65BR2)
- ...and you for reading this!
