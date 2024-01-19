Inpsired by https://github.com/Felerius/planck-layout

# TODO
- [X] use the repeat key: https://docs.qmk.fm/#/feature_repeat_key
- [X] add dual function for extended thumb keys
- [X] macros on the fly by "recording" a keysequence, then executing that using command?
- [X] disable caps lock with escape
- [ ] home row mods on all layers
- [ ] special typing mode for camelcase, underscore for spaces, caps etc
- [ ] record dynamic macro all the time, stop with escape, then swap to recordingthe next one. Alternate, then easily replay. Might be possible to replicate the vim repeat behavior.
- [X] type "~"  without having to press space (use macro?)
- [ ] try this https://docs.qmk.fm/#/feature_advanced_keycodes?id=alt-escape-for-alt-tab
- [ ] switch to https://qmk.github.io/qmk_distro_wsl/
  * compilation without WSL is way too slow

# ISSUES
- ~~enter sometimes blocks input and then inputs many enters after a while. Issue started when introducing repeat key.~~

# NOTES
* To make dynamic macros work, I had to make some changes from the documentation: https://github.com/qmk/qmk_firmware/blob/bade8be66c3440cc91db1d56d3a29a5b5af226dc/readme.md#dynamic-macros-record-and-replay-macros-in-runtime
  * `process_record_dynamic_macro` should be `process_dynamic_macro`
  * `Escape` can be used to stop recording using a variant of this: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_dynamic_macros.md#dynamic_macro_user_call

# EXPERIMENTS
* oneshot shift on right thumb (RAISE) for easy capitalization of letters
* leader keys for complex shortcuts and one-handed modifiers
* ~~hold space to enter navigation layer~~