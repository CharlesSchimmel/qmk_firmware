# Base Layer

```
┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    `         1       2        3        4        5                                   6        7        8        9        0        \
├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    `         '       ,        .        P        Y                                   F        G        C        R        L        /
├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
 Ctl/Esc      A       O        E        U        I                                   D        H        T        N        S      Ctl/-
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
 Sh/Tab    Nav/;    Alt/Q      J        K        X       GUI               GUI       B        M        W      Alt/V    Nav/Z   Sh/BckSp
└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                Fnc/App    LGUI   Sym/Entr                   Sym/Spce   RGUI   Fnc/App
                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
```

# Symbols (SYM)

- SwFnc: Switchboard to the FNC layer. This will toggle on the FNC layer and
    deactivate it when the SYM layer is deactivated.

```
┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    F12     F 1      F 2      F 3      F 4      F 5                                 F 6      F 7      F 8      F 9      F10      F11
├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
             1        2        3        4        5                                   6        7        8        9        0        \
├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
             [        {        (        -        <                                   >        =        )        }        [
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                                                                                            SwFnc                              Sh/Delet
└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                                  OOOOOOO                    OOOOOOO
                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
```

# Navigation/Vimmish (NAV)

Vimmish navigation and operations.

- SwMouse: Switchboard to the Mouse layer. This will toggle on the Mouse layer and
    deactivate it when the NAV layer is deactivated.
- ⇈⇊ : Double tap for document home, tap for document end

```
  ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
                                         End                                                                              Home
  ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                                        Paste     Yank                                          ⇈⇊               Redo      →
  ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                                         Undo                                         Cut       ←
  ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             NavLok    LCtl      ↓        ↑                                         BackWord SwMouse  ForWord    RCtl    NavLok
  └────────┴~~~~~~~~┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴~~~~~~~~┴────────┘

                                 └────────┴────────┴────────┘                 └────────┴────────┴────────┘
```
# Functions/Utility (FNC)

- VMBDn/Up/Mut: Volume on regular tap, media on ctl+tap, brightness on
    shift-tap. On the pointy brace keys and which sorta point in the right
    directions
- Lock: Win-L on L key for mnemonic "Lock"
- CAD/Unlok: Ctl-Alt-Delete on U for "Unlock"
- Sleep: on S key for "Sleep"
- CtShEsc: Ctl-Sh-Esc on somewhat close to Escape
- PrntScr: PrntScr on G for "screenGrab"

```
┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
 CtShEsc
├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           VMBDn    VMBUp    VMBMut                                                        PrntScr                     Lock
├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                                     CAD/Unlk                                                                          Sleep
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                                                                                                      Wake
└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                 RESET
                               └~~~~~~~~┴────────┴────────┘                 └────────┴────────┴~~~~~~~~┘
```

# Adjust/Window Management (ADJ)

This layer has "layer-sticky" modifiers: Modifiers will stay activated until the
layer is deactivated. Super useful for scolling through tabs and windows with
Alt-Tab and Ctl-Tab.

This layer is a lenient tri-layer with NAV and SYM: It is activated when both
NAV and SYM are activated but is deactivated only when both NAV and SYM are
deactivated (unlike the usual tri-layer that is deactivated when either of its
parent layers are deactivated). This means that once it is activated, one of the
layer-taps can be let go.

Window management in Windows and Xmonad

- Gui1-9: Open taskbar items in Windows, switch to different workspaces in
    Xmonad
- GuiH, GuiL: Cycle through panes (xmonad), move windows (windows)

```
┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐

├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            Gui1     Gui2     Gui3     Gui4     Gui5                                Gui6     Gui7     Gui8     Gui9    Gui-L
├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
                                                                                            Gui-H
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   LSft              LAlt    ShfTab    Tab                                                            RCtl     RAlt              RSft
└────────┴~~~~~~~~┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴~~~~~~~~┴────────┘

                               └────────┴────────┴~~~~~~~~┘                 └~~~~~~~~┴────────┴────────┘
```

# Mouse

It's perhaps a little odd that I have mouse navigation not only not on HJKL like
all of my other navigation, but also on my non-dominant hand. I don't know why,
but this configuration feels the most natural.

I mostly use this layer for switching window focus when focus is captured by a
dialog or something.

```
┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐

├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           WhlUp    Mous1      ↑      Mouse2
├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           WhlDn      ←        ↓        →
├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤

└────────┴~~~~~~~~┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴~~~~~~~~┴────────┘

                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
```
