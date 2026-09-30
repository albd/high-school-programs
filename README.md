# High-school programs (2008), running again

Two C++ programs I wrote in high school in 2008 with Turbo C++ on DOS, back on screen and playable in the browser.

**▶ Play: https://albertdavies.com/high-school-programs/**

| Program | Written | What it does | Run | Source |
|---|---|---|---|---|
| Electric field lines | Aug 2008 | Place up to five point charges on the screen and it traces the electric field lines out of each one. | [play](https://albertdavies.com/high-school-programs/play.html?p=field) | [FIELD.cpp](src/field/FIELD.cpp), [FUNCTION.cpp](src/field/FUNCTION.cpp) |
| Tic-tac-toe vs. computer | Sep 2008 | You play X; the computer answers using a small scoring heuristic. | [play](https://albertdavies.com/high-school-programs/play.html?p=tictactoe) | [ALBB4.cpp.txt](src/tictactoe/ALBB4.cpp.txt), [FUNCTION.cpp](src/tictactoe/FUNCTION.cpp) |

## The one rule: the 2008 code is not touched

Nothing here is a rewrite. The `.cpp` files in [`src/`](src/) are byte-for-byte the files I wrote in 2008, CRLF line
endings and all. They include `void main()`, `<iostream.h>`, pre-standard `for`-loop scoping, and an uninitialised
variable that decides whether the input loop runs at all.

| File | sha256 |
|---|---|
| `src/field/FIELD.cpp` | `a0a0f3dfa7f0db30f6d0798db1763fdb0beedc877419eb6df72f7dfb8102b812` |
| `src/*/FUNCTION.cpp` | `903155480e458e277f8299058741cef9d7082aa5e28c0088c5fd61b96f7db951` |
| `src/tictactoe/ALBB4.cpp.txt` | `fc5dd053f32b180b6608ec1918eaf8ad13cf1a8f5791832ea6a94e2b2354ab14` |

## How it runs

1. **Compiled by the real compiler.** Each program is compiled by Borland **Turbo C++ 1.01** (1990), running inside
   DOSBox on my machine. `FUNCTION.cpp` is my little helper library, a graphics wrapper plus the credits screen, so it goes
   onto the include path as `FUNCTION.H`, just as it did in 2008. The build is reproducible: `FIELD.EXE` always comes out
   with sha256 `a03a0813bb09e77afb94f83dd6f079dbac2bc1dc45fc8492b3808ec99ac8cdcb`.
2. **Packaged.** Each compiled `.EXE` and Borland's `EGAVGA.BGI` graphics driver go into a small
   [js-dos](https://js-dos.com) bundle ([`bundles/`](bundles/)), laid out like a 2008 `C:\TC` folder.
3. **Played in the browser.** [js-dos](https://js-dos.com) runs **DOSBox compiled to WebAssembly**, entirely in your
   browser. There is no server-side code, and every visitor gets their own virtual PC. What you see is what a 2008 PC showed:
   VGA mode 12h graphics, the BIOS font for `cout` text written straight onto the graphics screen, and the same quirks.

The page adds a few helpers *around* the emulator, and the programs never know they're there:
- **Guides:** a coordinate grid for the field lines (y counts up from the bottom, as the program reads it), and
  tappable, numbered squares for tic-tac-toe.
- **Input:** an on-screen keypad and phone-keyboard support.
- **Pausing:** the emulator pauses when it scrolls out of view.

The compiler itself isn't in this repository. Borland's Turbo C++ 1.01 is available from Embarcadero's "Antique
Software" museum for personal use only.

## Embedding

`play.html?p=<id>&embed=1` is a compact, click-to-start view for an `<iframe>`:

```html
<iframe src="https://albertdavies.com/high-school-programs/play.html?p=field&embed=1"
        style="width:100%;max-width:760px;height:640px;border:0" allow="fullscreen" loading="lazy"></iframe>
```

The embedded page posts its height as `{type: "high-school-programs:height", id, height}`, so a host page can size the
iframe exactly.

## Run it locally

Any static file server works, for example:

```sh
python3 -m http.server 8000
# then open http://localhost:8000/
```

## Layout

```
index.html, play.html, style.css, programs.js   the player
bundles/*.jsdos                                 compiled programs + BGI driver (zip archives for js-dos)
src/<program>/                                  the original 2008 source, unmodified
posters/                                        click-to-start images (real DOSBox screenshots)
js-dos/                                         js-dos 8.5.0 runtime (GPL-2.0), unmodified
```

This repository is exported from my private workspace by a build script, so the published files are exactly what was
built and tested.

## Credits and licences

- My programs and the player code: see [LICENSE](LICENSE).
- Third-party parts (js-dos/DOSBox under GPL-2.0, and Borland's runtime library and BGI driver inside the compiled
  programs): see [NOTICE.md](NOTICE.md).
