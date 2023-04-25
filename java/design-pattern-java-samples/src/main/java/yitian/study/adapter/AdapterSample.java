package yitian.study.adapter;

import yitian.study.Sample;

public class AdapterSample implements Sample {
    @Override
    public void run() {
        MusicPlayer musicPlayer = new MyMusicPlayer();
        VideoPlayer videoPlayer = new MyVideoPlayer();

        MediaPlayer player1 = new MediaPlayerAdapter(musicPlayer);
        player1.play();

        MediaPlayer player2 = new MediaPlayerAdapter(videoPlayer);
        player2.play();
    }
}
