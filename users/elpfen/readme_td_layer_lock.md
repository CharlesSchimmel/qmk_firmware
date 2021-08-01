# Overview
Sometimes it would be nice to be able to toggle or "lock in" a layer that you 
usually hold with LT(_LAYER, KC_KEY). This will set up a tap-dance that will act 
as your layer-tap and a macro that will lock in your current layer.

# How To Use
First, either link to `td_layer_lock.h` or copy the contents of 
`td_layer_lock.c` and `td_layer_lock.h` into your keymap.

You'll need:
- The layer you want to shift to
- A tap dance
- A new macro

In my case, my layer is `_NAV`, my macro is `LOCK_NAV`, and my tap dance is 
`TD_NAV`. It looks a little something like this:

```c
// layers
enum {
  _BASE,
  _NAV
}

// tap dances
enum {
  TD_NAV,
};

// macros
enum custom_keycodes {
  LOCK_NAV = SAFE_RANGE
};
```

Put `TD(TD_NAV)` on the key that you want to act as your layer-tap, and 
`LOCK_NAV` on the key in your layer that you want to act as your "lock".

You'll also need a global bool:

```c
static bool nav_lock = false;
```

Create a couple functions to handle tap-dance finish and tap-dance reset. This 
is also where you'll specify what key you want to act as your tapped key and 
what layer you want to shift to when held. In my case, I have it as `KC_Z` on 
tap, `_NAV` when held:


```c
void Z_NAV_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_layer_lock_finished(state, KC_Z, _NAV, &nav_lock);
}

void nav_lock_reset(qk_tap_dance_state_t *state, void *user_data) {
    td_layer_lock_reset(state, nav_lock, _NAV);
}
```

Next, add the macro handler to your `process_record_user`:

```c
bool process_record_user(uint16_t current_keycode, keyrecord_t *record) {
    // your other macro/key handling stuff

    return m_layer_lock(
      current_keycode,
      record,
      &nav_lock, // your global lock var. Note the '&' that will pass this value
                 // by reference!
      LOCK_NAV,  // your macro key
      _NAV       // the layer you want to lock
    ) && true;
}

```

Finally add your tap-dance to your tap-dance section

```c
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_NAV] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, Z_NAV_finished, nav_lock_reset, 100)
};
```

And you should be good to go!

## Details
We need to use a tap-dance to create our mod-tap so that we can catch the keyup 
of the held key. Otherwise there's no way to tell it to not shift out of layer 
on keyup.
