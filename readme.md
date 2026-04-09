# Keychron-Only QMK Firmware Tree

This repository is a locally trimmed copy of `qmk_firmware` that keeps only the Keychron keyboard definitions under `keyboards/`.

The goal is to make the tree easier to navigate when working only on Keychron boards, keymaps, and firmware builds.

## What Is Kept

- Core QMK build system and shared libraries
- `keyboards/keychron/` and its subfolders
- Shared folders such as `layouts/`, `quantum/`, `tmk_core/`, `drivers/`, `platforms/`, `modules/`, and `users/`

## What Was Removed

All non-Keychron keyboard vendor folders under `keyboards/` were deleted from this local copy to reduce clutter.

## Keychron Boards

Available board definitions live in:

```text
keyboards/keychron/
```

This includes families such as:

- `C` series
- `K HE`, `K Max`, and `K Pro`
- `Q`, `Q HE`, and `Q Max` variants present in this tree
- `S`, `V`, and `X` series models

## Typical Build Commands

Build a firmware target with either `make` or the QMK CLI.

Examples:

```bash
make keychron/q1_he/ansi:keychron
make keychron/k8_pro/ansi/rgb:keychron
```

Or:

```bash
qmk compile -kb keychron/q1_he/ansi -km keychron
qmk compile -kb keychron/k8_pro/ansi/rgb -km keychron
```

To flash after building:

```bash
make keychron/q1_he/ansi:keychron:flash
```

## Finding The Right Target

Each board folder usually contains its own `readme.md` with the exact supported targets and example commands.

Examples:

- `keyboards/keychron/q1_he/readme.md`
- `keyboards/keychron/k8_pro/readme.md`
- `keyboards/keychron/v1_max/readme.md`

## Notes

- This is a convenience checkout, not an official upstream layout.
- Some QMK scripts may assume the full upstream repository is present.
- If you sync from upstream later, non-Keychron keyboard folders may come back unless you remove them again.
