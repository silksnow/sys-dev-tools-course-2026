#!/bin/sh
for f in *.m3u
do
 grep -qi 'hq.*mp3' "$f" \
  && ehco -e "Playlist $f contains a HQ file in mp3 format"
done
