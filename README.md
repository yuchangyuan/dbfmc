# Intro

A CLI client communicate with ``dbfmd``.

**NOTE**
Currently, ``dbfmc`` only support connect to local ``dbfmd``, which listen to 2 fixed port(12677 & 12678). Code modification is necessary for use ``dbfmc`` to connect to alternative ``dbfmd`` instance.

# Usage
* ``dbfmc info``: get the information of current track.
* ``dbfmc skip``: skip current track.
* ``dbfmc rate``: rate/unrate current track.
* ``dbfmc trash``: delete current track.
* ``dbfmc switch`` *ch_id*: switch to channel with an id of *ch_id*, which is an integer.
* ``dbfmc monitor``: monitor player status change, will not exit until hit *Ctrl-C*.
* ``dbfmc play``: play current track.
* ``dbfmc pause``: pause current track.
