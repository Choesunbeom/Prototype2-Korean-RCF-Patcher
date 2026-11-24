# P2 Dialogue Scanner v0.2 (experimental)

Standalone iOS app: select game folder/ZIP/RAR and translation folder/ZIP/RAR; search game dialogue candidates across extracted resources and RCF metadata; match by canonical full relative path; output KoreanDialogueMod ZIP and JSON report to chosen folder.

No game files, translations, certificates or saves committed. Exact-match only. It does not itself translate English text or modify the original game. An exported ZIP is a loose-file mod; user must extract it into a game mod location and enable it manually. The active in-game subtitle locale may not match available German-localized assets.

ZIP/RAR support provided by libarchive v3.7.4 bundled statically during GitHub Actions macOS iOS compilation. Password-protected and unusual RAR features may be unsupported. Archive-contained RCFs require additional temporary storage of the RCF size, but the scanner never loads 2GB into RAM. RCF 2.1 metadata parsing is experimental and has only passed synthetic tests. Folder/ZIP basic match and nested RCF tests passed locally on Linux. Original RCF is not repacked in v0.2.

Output of >1000 audio mods at once has previously caused black loading in the user's Prototype 2 port. The v0.2 output may be too large to activate safely; first test small subsets and back up saves and config. Device behavior untested.
