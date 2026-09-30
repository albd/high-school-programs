# Third-party notices

## js-dos and DOSBox (GPL-2.0)

`js-dos/` contains unmodified files from the npm packages **js-dos 8.5.0** (`js-dos.js`, `js-dos.css`) and
**emulators 8.5.0** (`emulators/*`, including DOSBox compiled to WebAssembly). They are licensed under the GNU General
Public License, version 2. See [`js-dos/LICENSE`](js-dos/LICENSE), and [`js-dos/SOURCE.md`](js-dos/SOURCE.md) for the
corresponding source code.

## Borland Turbo C++ runtime and BGI driver

The programs in `bundles/*.jsdos` were compiled with Borland Turbo C++ 1.01 (© 1990 Borland International). The
compiled executables contain Borland's runtime and graphics library code, and each bundle includes Borland's `EGAVGA.BGI`
graphics driver (© Borland International). Borland's licence allowed programs compiled with its compilers to be given
away, together with the BGI driver files needed to run them. The driver is distributed only inside these bundles, not
on its own. The compiler, libraries and headers are **not** included in this repository.

Turbo C++ is a trademark of its respective owner. This project is not affiliated with or endorsed by Borland or
Embarcadero.
