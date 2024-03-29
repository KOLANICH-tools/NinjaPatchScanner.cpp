NinjaPatchScanner.cpp [![Unlicensed work](https://raw.githubusercontent.com/unlicense/unlicense.org/master/static/favicon.png)](https://unlicense.org/)
===================
[![Libraries.io Status](https://img.shields.io/librariesio/github/KOLANICH-tools/NinjaPatchScanner.cpp.svg)](https://libraries.io/github/KOLANICH-tools/NinjaPatchScanner.cpp)

**We have moved to https://codeberg.org/KOLANICH-tools/NinjaPatchScanner.cpp , grab new versions there.**

Under the disguise of "better security" Micro$oft-owned GitHub has [discriminated users of 1FA passwords](https://github.blog/2023-03-09-raising-the-bar-for-software-security-github-2fa-begins-march-13/) while having commercial interest in success of [FIDO 1FA specifications](https://fidoalliance.org/specifications/download/) and [Windows Hello implementation](https://support.microsoft.com/en-us/windows/passkeys-in-windows-301c8944-5ea2-452b-9886-97e4d2ef4422) which [it promotes as a replacement for passwords](https://github.blog/2023-07-12-introducing-passwordless-authentication-on-github-com/). It will result in dire consequencies and is competely inacceptable, [read why](https://codeberg.org/KOLANICH/Fuck-GuanTEEnomo).

If you don't want to participate in harming yourself, it is recommended to follow the lead and migrate somewhere away of GitHub and Micro$oft. Here is [the list of alternatives and rationales to do it](https://github.com/orgs/community/discussions/49869). If they delete the discussion, there are certain well-known places where you can get a copy of it. [Read why you should also leave GitHub](https://codeberg.org/KOLANICH/Fuck-GuanTEEnomo).

---

[`Ninja` build system](https://github.com/ninja-build/ninja) relies on external scanners to provide info on the files generated by build process. These files are mentioned in [so called `dyndep` files](https://ninja-build.org/manual.html#_tarball_extraction) (I don't think the name is a good one). These files are supposed to be generated by external tools.

This is the tool to generate dyndef files for the files modified by patch files.

It uses https://codeberg.org/KOLANICH-libs/ParsePatch.cpp library to parse patch file. In order to build this tool you need to install it.
