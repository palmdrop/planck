Personal keymap for the Planck keyboard.

Inspired by https://github.com/Felerius/planck-layout

# TODO
- [X] use the repeat key: https://docs.qmk.fm/#/feature_repeat_key
- [X] add dual function for extended thumb keys
- [X] disable caps lock with escape
- [X] add layer-lock key for certain layers
- [X] try sentence case: https://getreuer.info/posts/keyboards/sentence-case/index.html
  - [-] alternatively, try the next sentence macro: https://getreuer.info/posts/keyboards/macros/index.html#next-sentence-macro
- [X] try word selection feature: https://getreuer.info/posts/keyboards/select-word/index.html
  - [-] alternatively, using macros: https://getreuer.info/posts/keyboards/macros/index.html#select-word-macro
- [X] home row mods on all (relevant) layers
- [X] special typing mode for camelcase, underscore for spaces, caps etc
- [X] remove select word feature in favor of vim mode
- [X] type "~"  without having to press space (use macro?)
- [X] macros on the fly by "recording" a keysequence, then executing that using command?
- [ ] match leader sequences eagerly, i.e if a sequence no longer matches, execute the LONGEST matching sequence and send the other presses as regular key codes.
- [ ] scavenge https://github.com/drootz/qmk_firmware/tree/dz65_drootz/keyboards/dztech/dz65rgb/keymaps/drootz#LEADER-KEY-BINDINGS for goodness.
- [ ] record dynamic macro all the time, stop with escape, then swap to recording the next one. Alternate, then easily replay. Might be possible to replicate the vim repeat behavior.
- [ ] left-handed command layer access and easy backspace with left hand
- [ ] try this https://docs.qmk.fm/#/feature_advanced_keycodes?id=alt-escape-for-alt-tab
- [ ] try using key combos to trigger åäö

# ISSUES
- ~~enter sometimes blocks input and then inputs many enters after a while. Issue started when introducing repeat key.~~
- ~~binding space to nav layer causes accidental nav layer presses~~

# NOTES
* To make dynamic macros work, I had to make some changes from the documentation: https://github.com/qmk/qmk_firmware/blob/bade8be66c3440cc91db1d56d3a29a5b5af226dc/readme.md#dynamic-macros-record-and-replay-macros-in-runtime
  * `process_record_dynamic_macro` should be `process_dynamic_macro`
  * `Escape` can be used to stop recording using a variant of this: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_dynamic_macros.md#dynamic_macro_user_call

# ADDITIONAL FEATURES
* layer lock from https://getreuer.info/posts/keyboards/layer-lock/index.html
* qmk vim from https://github.com/andrewjrae/qmk-vim

# EXPERIMENTS
* adapt permissive hold and tapping term for S key to avoid triggering ALT unintentionally.
* tri-layer alternative by entering a layer from another layer, allowing me to add additional functionality when tapping layer-in-layer keys.
* qmk vim support
* oneshot shift on right thumb (RAISE) for easy capitalization of letters
* oneshot caps word on second right thumb key
* leader keys for complex shortcuts and one-handed modifiers
* special layers for variable name input in different conventions. Probably totally unnecessary but slightly fun.
* sentence case feature
* ~~hold space to enter navigation layer~~