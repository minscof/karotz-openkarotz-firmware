
UA="Mozilla/5.0 (Macintosh; Intel Mac OS X 10.7; rv:21.0) Gecko/20100101 Firefox/21.0"
 

function ispeech {
    voice_array=('eurfrenchfemale' 'eurfrenchmale' 'cafrenchfemale' 'cafrenchmale' 'usenglishfemale' 'usenglishmale' 'ukenglishfemale' 'ukenglishmale' 'eurgermanfemale' 'eurgermanmale' 'euritalianfemale' 'euritalianmale' 'eurspanishfemale' 'eurspanishmale')
 
    TTS=$1
    VOICE=$2
    NOCACHE=$3
    RVOICE=$4
    MUTE=$5
 
    MD5FILE=""
 
    MD5FILE=$(echo "$TTS$VOICE" | md5sum | cut -d ' ' -f 1)
    echo $( echo \"$TTS\" | UrlDecode)  > $CNF_DATADIR/Tmp/${MD5FILE}.txt                                             
    echo $( echo $RVOICE | UrlDecode)  > $CNF_DATADIR/Tmp/${MD5FILE}.voice
    eval $(echo "curl -A '${UA}' -o $CNF_DATADIR/Tmp/${MD5FILE}.mp3 'http://api.ispeech.org/api/rest?apikey=34b06ef0ba220c09a817fe7924575123&action=convert&voice=${voice_array[$RVOICE-1]}&speed=0&pitch=100&text=${TTS}'" )  >>/dev/null 2>>/dev/null               
 
    if [ "$5" != "1" ]; then
        Log "[TTS]"  "Playing sound ${MD5FILE}.mp3" 
        PlaySound $CNF_DATADIR/Tmp/${MD5FILE}.mp3
    fi
 
    if [ "$NOCACHE" == "1" ]; then
        rm -f $CNF_DATADIR/Tmp/${MD5FILE}.mp3   >>/dev/null 2>>/dev/null
        rm -f $CNF_DATADIR/Tmp/${MD5FILE}.txt   >>/dev/null 2>>/dev/null
    else
        Log "[TTS]"  "Storing sound ${MD5FILE}.mp3 to cache"
    fi
    echo ${MD5FILE}   
}
 
 
function GoogleTTS {
   TTS=$1 
 
   MD5FILE=$(echo "$TTS" | md5sum | cut -d ' ' -f 1)
   eval $(echo "curl -A '${UA}' -o $CNF_DATADIR/Tmp/${MD5FILE}.mp3 'http://translate.google.com/translate_tts?tl=fr&q=${TTS}'" )  >>/dev/null 2>>/dev/null
   echo $( echo "$RAW_TTS" | UrlDecode)  > $CNF_DATADIR/Tmp/${MD5FILE}.txt 
 
   PlaySound $CNF_DATADIR/Tmp/${MD5FILE}.mp3     
}
 
 
function ProsodyTTS {
  Log "[TTS]"  "Voice provider is no more working"
}

function AcapelaTTS {  
  Log "[TTS]"  "Voice provider is no more working"
}
 

          
