# Prototype 2 Korean RCF Patcher for iPhone

**Experimental / 실험판.** Standalone iOS app for creating a new Prototype 2 `audio_german.rcf` archive from the user's own Korean translation ZIP and original game data. This project does **not** distribute games, translation assets, or modified commercial game archives.

## 사용법
1. 앱에서 `한글패치.zip` 선택
2. `audio_german.rcf` 선택
3. 결과 파일 저장 폴더 선택
4. **패치 시작** 누르기

Creates `audio_german_korean.rcf` separately. Never modifies the original archive automatically. Back up original RCF and saves before replacing game files.

## Implementation

- Existing RCF v2.1 index and stored file paths are inspected.
- Korean P3D from `audio/german/AudioFile` in the user-supplied ZIP is matched by path/hash to RCF entries.
- A streamed copy of the original RCF is written, then matched replacement entries appended and the copied index adjusted.
- CRC checked for ZIP entries, no ZIP64 support. Large patches may exceed the RCF 32-bit offset limit.
- At least ~2GB additional storage space is required for output, potentially more.
- Translation itself is **not** performed by this app. The game might use another language slot for live subtitles.
- The entire source has **not** yet been validated on an actual 1.97GB game archive or iPhone; an artificial RCF regression test was used during development.

The `rcf_patcher_ios/code_part_01.txt` through `04.txt` are base64+xz split code payloads for `main.m` and `rcf_patcher.c` bundled from the original developer source. The GitHub Actions workflow verifies SHA-256 then extracts these during compilation. `rcf_patcher.h` and `Info.plist` are checked in as ordinary text.

## CI
Build workflow: [.github/workflows/build-ios.yml](.github/workflows/build-ios.yml). After a successful run, download **P2-Korean-RCF-Patcher-unsigned-IPA** from its Artifacts section. Install and sign using your own sideloading setup (e.g. LiveContainer/SideStore).

No game files, translation ZIP, personal Apple IDs or certificates should be committed here.
