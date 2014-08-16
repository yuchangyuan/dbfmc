# Intro

A CLI client communicate with [dbfmd](https://github.com/yuchangyuan/dbfmd).

**Note**
Currently, ``dbfmc`` only support connect to local ``dbfmd``, which listen to 2 fixed port(12677 & 12678). Code modification is necessary for use ``dbfmc`` with alternative(non local or alternative port) ``dbfmd`` instance.

# Usage
* ``dbfmc info``: get the information of current track.
* ``dbfmc skip``: skip current track.
* ``dbfmc rate``: rate/unrate current track, with optional bool argument
* ``dbfmc trash``: delete current track.
* ``dbfmc switch`` *ch_id*: switch to channel with an id of *ch_id*, which is an integer.
* ``dbfmc monitor``: monitor player status change, will not exit until hit *Ctrl-C*.
* ``dbfmc play``: play current track.
* ``dbfmc pause``: pause current track.
